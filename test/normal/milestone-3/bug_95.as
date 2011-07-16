// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// RUn: %t | FileCheck -input-file=- %s 


package com
{   
    public class Circle 
    {   
        public function get radius() : int
        {   
            return 123;
        }

        public function test() : int
        {   
            return radius;
        }
        public function truncate(max:int):int
        {
//TODO
            //SteerVehicle.test2( radius );
            
            return 0; 
        }
    }
}
package com
{   
    public class SteerVehicle
    {   
        public function test() : int
        {   
            var c: Circle;
            c = new Circle;

            return c.radius;
        }

        public static function test2( a:int ) : int
        {
            return a;
        }
    }
}

function main():int
{
    
    var c: com.Circle;
    c = new com.Circle;

    c.radius;


    var s: com.SteerVehicle;
    s = new com.SteerVehicle;
// TODO
//    s.test2( c.radius );
}
