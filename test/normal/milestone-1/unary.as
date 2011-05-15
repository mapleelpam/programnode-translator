// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

    function unary_minus( a:int ):int
    {
        return -a;
    }
    function unary_plus( a:int ):int
    {
        return +a;
    }
    function unary_not( a:int ):int
    {
        return !a;
    }
    function unary_logical_not( a:int ):int
    {
        return ~a;
    }

    function main( ) : int
    {
        printf(" %d\n", unary_minus(1)); // CHECK: -1
        printf(" %d\n", unary_minus(-11)); // CHECK: 11
        printf(" %d\n", unary_minus(-4)); // CHECK: 4

        printf(" %d\n", unary_plus(1)); // CHECK: 1
        printf(" %d\n", unary_plus(-11)); // CHECK: -11
        printf(" %d\n", unary_plus(-4)); // CHECK: -4

        printf(" %d\n", unary_not(0)); // CHECK: 1
        printf(" %d\n", unary_logical_not(1)); // CHECK: -2
    }
