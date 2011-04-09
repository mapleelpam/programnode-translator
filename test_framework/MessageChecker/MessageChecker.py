#! /usr/bin/python2.6
import os, re, subprocess

class SourceParser:
    def __init__( self, filename ):
        self.messages = {}

        str_fatal = '//\ expected-fatal:'
        self.messages["fatal"] = self.__get_expects( filename, str_fatal ) 

        str_fatal = '//\ expected-warn:'
        self.messages["warn"] = self.__get_expects( filename, str_fatal ) 
        
    def __get_expects(self, file_name, pattern ):
        self.command = 'grep -n -o ' + pattern +".*"+ ' ' + file_name + '| sed s{' + pattern+ '{{ ' 
        process = subprocess.Popen(self.command, shell=True, stdout=subprocess.PIPE)
        expects = {}

        for output in process.communicate()[0:-1]:
            for code in output.split('\n'):
                if code == '':
                    continue;
                codes = code.split( ':', 1 )
                pure = re.search( '{{.*}}', codes[1] )

                if pure is not None:
                    expects[ int(codes[0]) ] = pure.group().replace("{{","").replace("}}","")
                else:
                    expects[ int(codes[0]) ] = True
            
        return expects 

class LogParser:
    def __init__( self, filename ):
        self.messages = {}
        f = open(filename, "r")
        logs = f.readlines()
        for line in logs:
            if line.find(":") != -1:
                info = line.split( ':', 4 )
                print info
                msg_type = info[3].strip()
                if not self.messages.has_key( msg_type ) :
                    self.messages[ msg_type ] = {}
                self.messages[ msg_type ][ int(info[1]) ] = info[4]

def CheckMessages( runtime, expected ):
    is_same = True
    for line in runtime.keys():
        if not expected.has_key( line ):
            print "(E) Unexpected info in line:"+str(line)+" :"+runtime[line]
            is_same = False
        elif not re.search( expected[line], runtime[line] ):
            print "(E) Expected info in line:"+str(line)+" is different"
            is_same = False

    for line in expected.keys():
        if not runtime.has_key( line ):
            print "(E) miss expected info: line:"+str(line)+" "+expected[line]
            is_same = False
        
    
    return is_same

def main():
    import sys
    from optparse import OptionParser
    usage = "MessageChecker.py [-l --log ] [-s --source]"
    opt_parser = OptionParser(usage=usage)
    opt_parser.add_option('-l', '--log', help="message log file",dest="log")
    opt_parser.add_option('-s', '--source', help="source code (which has expected error line)", dest="source")
    opt_parser.add_option('-d', '--debug', help="source code (which has expected error line)", action="store_true", dest="debug", default=False)

    if not sys.argv[1:] :
        opt_parser.print_usage()
        sys.exit(2)
    
    (options, restArgs) = opt_parser.parse_args()
    
    expected_msgs = SourceParser( options.source )
    runtime_msgs = LogParser( options.log )
    if options.debug :
        print "(Expected Fatals)"
        print expected_msgs.messages

        print "(Happend Logs)"
        print runtime_msgs.messages
        


    exit_code = 0
    for msg_type in expected_msgs.messages.keys():
        if len(expected_msgs.messages[msg_type]) > 0:
            if not CheckMessages( runtime_msgs.messages[msg_type], expected_msgs.messages[msg_type] ):
                exit_code = 1
        elif runtime_msgs.messages.has_key(msg_type) and len(runtime_msgs.messages[msg_type]) > 0:
            exit_code = 2

    sys.exit(exit_code)


if __name__ == "__main__":
    main()
