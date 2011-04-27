// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

package abc
{
    function sum_add_one( a:int, b:int ):int
    {
        var tmp:int;
        tmp = 1;
        return a+b+tmp;
    }

    function main( ) : int
    {
        printf(" %d ", sum_add_one(1,2)); // CHECK: 4
        printf(" %d ", sum_add_one(10,2)); // CHECK: 13
    }
}
