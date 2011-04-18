// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

package abc
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

    function main( ) : int
    {
        wprintf(" %d\n", sum(1,2)); // CHECK: 3
        wprintf(" %d\n", sub(2,1)); // CHECK: 1
        wprintf(" %d\n", multi(2,4)); // CHECK: 8
        wprintf(" %d\n", _div_(4,2)); // CHECK: 2
        wprintf(" %d\n", mod(7,3)); // CHECK: 1
    }
}
