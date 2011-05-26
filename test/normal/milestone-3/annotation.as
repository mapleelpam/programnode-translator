// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// RUN: %t | FileCheck -input-file=- %s 

[native("DescribeTypeClass::getQualifiedClassName")]
function sum( a:int, b:int ):int
{
    return a+b;
}

[native(cls="TestClass", instance="TestObject", methods="auto")]
class Test
{
    
}

function main( ) : int
{
    printf(" %d ", sum(1,2)); // CHECK: 3
}
