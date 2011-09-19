// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %BUILTIN_PN %t.pn -o %t.cpp
// R U N: g++  -c -o %t.o %t.cpp -lruntime -D_LINUX
// R U N: %t | FileCheck -input-file=- %s 

package ker 
{
    public class TestXML
    {

        public function Test():Void
        {
			{
				var xml:XML = describeType(child);
				trace(xml.*);	
				trace(xml.@*);	
				trace(xml.@id);	

				//xml.item+=<item="123"/>;
			}
			{
				var myXML1:XML=<type name1='object'></type>;
				var myXML2:XML=<type name2='object'></type>;
				var xmlList:XMLList=myXML1+myXML2;
				xmlList+=<test name='test'/>;
				trace(xmlList);
			}
        }
    }
}
