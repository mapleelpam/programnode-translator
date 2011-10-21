// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %BUILTIN_PN %t.pn -o %t.cpp
// R U N: g++ -o %t %t.cpp 
// R U N: %t | FileCheck -input-file=- %s 


function main() : int
{
    var str:String = "hello world";
    str.split("");
}

