// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pn-translator %t.pn -o %t.c

package abc
{
    function sum( a:int, b:int ):int
    {
        return a+b;
    }
}
