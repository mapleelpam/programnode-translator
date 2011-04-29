// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// RUN: %t | FileCheck -input-file=- %s 

package math
{
    function sum( a:int, b:int ):int
    {
        return a+b;
    }
    function sub( a:int, b:int ):int
    {
        return a-b;
    }
    function multi( a:int, b:int ):int
    {
        return a*b;
    }
    function _div_( a:int, b:int ):int
    {
        return a/b;
    }
    function mod( a:int, b:int ):int
    {
        return a%b;
    }
}

function main( ) : int
{
    printf(" %d\n", math.sum(1,2)); // CHECK: 3
    printf(" %d\n", math.sub(2,1)); // CHECK: 1
    printf(" %d\n", math.multi(2,4)); // CHECK: 8
    printf(" %d\n", math._div_(4,2)); // CHECK: 2
    printf(" %d\n", math.mod(7,3)); // CHECK: 1
}
