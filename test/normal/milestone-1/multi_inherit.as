// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp


interface A
{
    function func_a():void;
    function func_b( x:int, y:int ):int;
}
interface A_2
{
    function func_c():void;
    function func_d( x:int, y:int ):int;
}

class B implements A, A_2 
{
    function func_a():void
    {
    }
    function func_b( x:int, y:int ):int
    {
    }
    function func_c():void
    {
    }
    function func_d( x:int, y:int ):int
    {
    }
}

function main() : int
{
//    var a:A = new A;
    var b:B = new B;
}
