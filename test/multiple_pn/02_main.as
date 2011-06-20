
function main() : int
{
	var instance_c : a.c;
	instance_c = new a.c();
	printf(" %d \n", instance_c.getE() ); // CHECK: 987
}

