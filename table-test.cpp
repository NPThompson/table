// table tests
#include"table.h"
#include<stdio.h>
#include<exception>


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
	// reading from a value not in the table should throw an exception

	try{
		table<const char*, int> mytable;
		int val = mytable["some-key-value"];
		printf("TEST #1: Did not throw an exception when attempting to read a non-existent value\n");
	}catch(exception &e)
	{
		// executed correctly
	}
	
	// test #2
	// after associating a value with a key, no exception should be thrown when we try to retrieve it using the same key
	
	try{
		table<const char*, int> mytable;
		mytable["foobar"] = 12345;
		int bar = mytable["foobar"];
	}catch(exception &e)
	{
		printf("TEST #2: Threw an exception when a value was associated with the key\n");
	}
	
	// test #3
	// associating a value with a key in the table should allow us to retrieve that value by using that same key
	
	{
		table<const char*, int> mytable;
		mytable["meaning-of-life"] = 42;
		if(mytable["meaning-of-life"] != 42)
			printf("TEST #3: Value associated with key was unequal to intended value\n");
	}
	
	return 0;
}
