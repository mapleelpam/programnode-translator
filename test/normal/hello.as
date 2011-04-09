// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

package abc
{
    function main( ) : int
    {
        printf(" hello world"); // CHECK: hello world
    }
}
