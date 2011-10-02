// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// : %t | FileCheck -input-file=- %s 


package 
{
    public class String 
    {
        public static var length : int;

    }

}
