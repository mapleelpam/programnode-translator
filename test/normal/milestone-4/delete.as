// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc %t.pn -o %t.cpp
// RUN: g++  -c -o %t.o %t.cpp 
// R U n: %t | FileCheck -input-file=- %s 
class a
{
  public function a( i:int )
  {
    member = i;
  }
  public var member:int = 0;
}

class b extends a
{
   function b()
   { 
    //  member2 = super.member;
      super(1);

		var test: a = new a(1);
		delete test;

//        test.cde = "123";
        delete test.cde ;
   }

  public var member2:int = 0;
}
