// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++ -o %t %t.cpp
// : %t | FileCheck -input-file=- %s 


class Maple
{

	public var a1:int;
	public var a2:Maple;

}

function main() : int
{
	var m:Maple;
	m = new Maple();

	m . a1 = 1; 
	m . a2 = new Maple();

//     m.a1;
	m . a2 . a1 = m.a1;
}
