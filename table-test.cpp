// table tests
#include"table.h"
#include<stdio.h>
#include<string>
#include<exception>



using namespace std;



/* If this program produces no output, all the tests passed.
 * If it does produce output, it will tell you which test failed,
 * and how that failure contradicts the intended behaviour.
 *
 * e.g. if we expected the function to return 0, and it returns 1,
 * we'd say something like: "TEST #N: function returned wrong value"
 */

int main(int argc, char** argv)
{


	// test #1
	// associating a value with a key in the table should allow us to retrieve that value by using that same key
	
	{
		table<string, int> mytable;
		mytable["meaning-of-life"] = 42;
		if(mytable["meaning-of-life"] != 42)
			printf("TEST #1: Value associated with key was unequal to intended value\n");
	}
	
	return 0;
}
