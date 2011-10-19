// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp 
// RUN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX

package com
{

    public class Vector2D
    {
        private var NULL:int;
		
		function test():int
		{
			NULL = 0;
		}
    }
}
