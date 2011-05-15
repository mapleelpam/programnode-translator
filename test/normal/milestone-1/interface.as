// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


interface A
{
    function func_a():void;
    function func_b( x:int, y:int ):int;
}

class B implements A 
{
    function func_a():void
    {
    }
    function func_b( x:int, y:int ):int
    {
    }
}

function main() : int
{
//    var a:A = new A;
    var b:B = new B;
}
