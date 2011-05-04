// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// RUN: %t | FileCheck -input-file=- %s 


class Test
{
}

function main() : int
{
    var m1:Test;
    var m2:Test;
    m1 = new Test();
    m2 = new Test();

    if( m1 == m2 )
    {
        printf("1");
    }
    else
    {
        printf("2");    //CHECK:    2
    }
}
