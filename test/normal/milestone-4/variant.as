// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// R UN: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// R UN: %t | FileCheck -input-file=- %s 

package com
{

    public class LIST
    {

        public function push( ...rest ) : int
        {
        }
    }
}
