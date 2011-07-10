// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


class a.Maple
{
    function hello():Void
    {
    }
}


function main():int
{
    
    var m:a.Maple;
//    m = new a.Maple();
}
