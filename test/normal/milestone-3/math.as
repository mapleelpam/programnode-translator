// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// RUn: %t | FileCheck -input-file=- %s 


package
{   
    //intrinsic public class Math
    public class Math
    {   
        public static function abs (val:int) : int
        {   
            return val;
        }

    }
}


function main():int
{
    
    printf(" %d ", Math.abs(456) );   // CHECK: 456
}
