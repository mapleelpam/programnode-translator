// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// RUn: %t | FileCheck -input-file=- %s 

package com
{

    public class Vector2D
    {
        private var _x:int;
        private var _y:int;

        public function clone():Vector2D
        {
//            return new Vector2D(_x, _y);
            return this;
        }

        public function normalize():Vector2D
        {
            return this;
        }


        public static function angleBetween(v1:Vector2D, v2:Vector2D):int
        {
            //if(!v1.isNormalized()) v1 = v1.clone().normalize();
            //if(!v2.isNormalized()) v2 = v2.clone().normalize();
            if(true) v1 = v1.clone().normalize();
            if(true) v2 = v2.clone().normalize();
            v2 = v2.clone().normalize();
            return 0;
//            return Math.acos(v1.dotProd(v2));
        }
    }
}
