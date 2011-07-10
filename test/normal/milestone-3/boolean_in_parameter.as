// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// RUN: %t | FileCheck -input-file=- %s 


function echo( a:Boolean = false ):int
{
    if( a )
        return 1;
    else
        return 2;
}

function echo2( a:Boolean = true ):int
{
    if( a )
        return 1;
    else
        return 2;
}
    
function main( ) : int
{
    printf(" %d ", echo() ); // CHECK: 2
    printf(" %d ", echo(true) ); // CHECK: 1
    printf(" %d ", echo2() ); // CHECK: 1
    printf(" %d ", echo2(false) ); // CHECK: 2
}
