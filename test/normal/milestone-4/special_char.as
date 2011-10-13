// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// R U N: %t | FileCheck -input-file=- %s 

package com
{

    public class Vector2D
    {
        private var _x:int;
        private var _y:int;



        public static function angleBetween(v1:Vector2D, v2:Vector2D):int
        {
            printf("\t");
            printf("\a");
            printf("\n");
            printf("\?");
            printf("\\");
            printf("\f");
            printf("\"");
//            printf("\0");
//            printf("\v");
            printf("\'");
        }
    }
}
