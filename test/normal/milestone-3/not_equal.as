// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.c
// RUN: gcc -o %t %t.c
// RUN: %t | FileCheck -input-file=- %s 

    function sum_add_one( a:int, b:int ):int
    {
        var tmp:int;
        tmp = 1;
        if( a != 0 )
        return a+b+tmp;
        else
        return 0;
    }

    function main( ) : int
    {
        printf(" %d ", sum_add_one(1,2)); // CHECK: 4
        printf(" %d ", sum_add_one(10,2)); // CHECK: 13
    }
