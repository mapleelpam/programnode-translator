// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// RUn: %t | FileCheck -input-file=- %s 

package
{
    public class Math
    {
        public static function min( a:int, b:int ): int
        {
            return a;
        }
    } 
}

class Circle 
{   
    public function get radius() : int
    {   
        return 123;
    }
    public function set radius( l:int ) : void 
    {   
    }
    public function get me() : Circle
    {
        return this;
    }
    public function Test() : int
    {
        return 0;
    }
}

class TestParent extends Circle
{
    public function test( xyz:Circle )
    {
		super.Test();
    }

}

/*
function main():int
{
    if( true )
    {
        var c: Circle;
        c = new Circle;
        c.radius = Math.min( 1, 2);
        
    }
    
}
*/