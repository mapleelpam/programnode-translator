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
    function div( a:int, b:int ):int
    {
        return a/b;
    }
    function mod( a:int, b:int ):int
    {
        return a%b;
    }

    function main( ) : int
    {
        printf(" %d ", sum(1,2)); // CHECK: 3
        printf(" %d ", sub(2,1)); // CHECK: 1
        printf(" %d ", multi(2,4)); // CHECK: 8
        printf(" %d ", div(4,2)); // CHECK: 2
        printf(" %d ", mod(7,3)); // CHECK: 1
    }
}
