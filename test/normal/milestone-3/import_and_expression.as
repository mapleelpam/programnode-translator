// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ %t.cpp -o %t
package
{
	 public class Object
	{
	}
}
package
{
	 public class Number extends Object
	{
	}

}
package flash.geom
{
	 public class Matrix extends Object
	{
        static public function test() : int
        {
            return 1;
        }
        static public var test2 : int;
	}
}
package
{
	 public class String extends Object
	{
	}
}


package
{
    import flash.geom.Matrix;

    function echo( a:int ):int
    {
        return a;
    }
    function main():int
    {
        var m:Matrix;
        var t:int;
        m = new Matrix;        
        
        flash.geom.Matrix.test();
        t = flash.geom.Matrix.test2;
        t = Matrix.test2;
    }
}

function main():int
{

}
