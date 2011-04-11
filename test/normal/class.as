// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.c
// : gcc -o %t %t.c
// : %t | FileCheck -input-file=- %s 

package test1{

    public class Maple
    {
        public function badParameter(x:int)
        {
            var y:int;
        	return y;
        }

        public function test(y:int):int
        {

            var y:int;
            if( y == 0 )
            {   
                return abc;
            } else if( y == 1 ) {
            } else if( y == 2 ) { 
            }else
                return y;
        }
    }

    function main() : int
    {
        var m:Maple;
        m = new Maple();
    }
}

