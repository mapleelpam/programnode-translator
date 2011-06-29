// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// RUN: %t | FileCheck -input-file=- %s 


function echo( a:int = 123 ):int
{
	if( a == null )
	    return a;
	else
		return 0;
}
    
function main( ) : int
{
    printf(" %d ", echo(0) ); // CHECK: 0
    printf(" %d ", echo() ); // CHECK: 0
}
