// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp 
// RUN: %t | FileCheck -input-file=- %s 

package a
{
    function b() : int
    {
        return 456;
    }
    class c 
    {
        static public function d() : int
        {
            return 789;
        }
    }
}

function main() : int
{
        a.b();
        a.c.d();
        printf(" %d \n", a.b() ); // CHECK: 456
        printf(" %d \n", a.c.d() ); // CHECK: 789
}

