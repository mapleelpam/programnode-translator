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
        printf(" %d\n", sum(1,2)); // CHECK: 3
        printf(" %d\n", sub(2,1)); // CHECK: 1
        printf(" %d\n", multi(2,4)); // CHECK: 8
        printf(" %d\n", _div_(4,2)); // CHECK: 2
        printf(" %d\n", mod(7,3)); // CHECK: 1
    }
}
