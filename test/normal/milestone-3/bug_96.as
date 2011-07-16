// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// RUn: %t | FileCheck -input-file=- %s 

class Circle 
{   
    public function get radius() : int
    {   
        return 123;
    }
}


function main():int
{
    if( true )
    {
        var c: Circle;
        c = new Circle;
        c.radius;
        
    }
    
}
