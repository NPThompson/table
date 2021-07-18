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
	
	// test #2
	// if a value is in the table, the contains() method should tell us 
	
	{
		table<string, int> mytable;
		if(mytable.contains("blah"))
			printf("TEST #2: mytable says it contains values it does not");
		mytable["blah"] = 1999;
		if(!mytable.contains("blah"))
			printf("TEST #2: mytable says it does not contain values that it does");
	}
	
	// test #3
	// we should be able to overwrite previous values in the table by assigning a new value to the same key
	
	{
		table<string, int> mytable;
		mytable["foobar"] = 10;
		mytable["foobar"] = 20;
		
		if(mytable["foobar"] != 20)
			if(mytable["foobar"] == 10)
				printf("TEST #3: table entry still contains old value");
			else
				printf("TEST #3: failed to overwrite table entry");
	}
	
	return 0;
}
