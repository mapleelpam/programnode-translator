// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


class Maple
{

	public const a1:int= 0;

}

function main() : int
{
	var m:Maple;
	m = new Maple();

	printf("%d", m.a1);
}
