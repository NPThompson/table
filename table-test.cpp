// table tests
#include"table.h"
#include<stdio.h>
#include<exception>



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
}
