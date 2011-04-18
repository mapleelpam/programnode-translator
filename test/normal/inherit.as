// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 

package test1{

    public class A
    {
    }

    public class B extends A
    {
    }

    function main() : int
    {
        var a:A = new A;
        var b:B = new B;
    }
}

