// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


    class Maple
    {
        private function badParameter(x:int) : int
        {
            var y:int;
        	return y;
        }

        public function test(y:int):int
        {

            var x:int;
            if( y == 0 )
            {   
                return 123;
            } else if( y == 1 ) {
            } else if( y == 2 ) { 
            }else
                return y;
        }


        public function getType():int
        {
            return m_type;
        } 

        private var m_type:int;
        public var member2:int = 2;

    }

    function main() : int
    {
        var m:Maple;
        m = new Maple();

        m.test( 123 );
    }
