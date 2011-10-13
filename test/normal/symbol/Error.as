
// RUN: java -jar %ASC_JAR -x -z %t.pn  %s 
// RUN: pnc --symbol %t.pn -o %t.sym %BUILTIN_PN
// RUN: cat %t.sym | FileCheck -input-file=- %s 
package
{
	intrinsic public class TestError extends Error
	{
// CHECK: -class:TestError FQN->::TestError
// CHECK: -class:TestError ParentFQN->::Error
// CHECK: -class:TestError instance name->
// CHECK: no_reflection
	}
}
