// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


class a.b.c.Maple
{
    function hello():void
    {
    }
}


function main():int
{
    
    var m:a.b.c.Maple;
//    m = new a.Maple();
}
