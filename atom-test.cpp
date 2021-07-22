//atom test



#include<string>
#include<stdio.h>
#include"atom.h"



int main(int argc, char** argv)
{
	//test #1
	// undefined atoms should throw an error when read from or assigned to other atoms
	{
		atom a1, a2;
		
		try{
			int x = a1.readInteger();
			printf("TEST #1: Did not throw exception when reading from undefined atom\n");
		}catch(...){}

		try{
			a2 = a1;
			printf("TEST #1: Did not throw exception when assigning from undefined atom\n");
		}catch(...){}
	}
	
	//test #2
	// we should be able to read values from properly initialized atoms
	{
		atom a1(10), a2("banannas!");
		try{
			int x = a1.readInteger();
		}catch(...)
		{
			printf("TEST #2: Did not read from properly initialized integer");
		}

		try{
			string s = a2.readString();
		}catch(...)
		{
			printf("TEST #2: Did not read from properly initialized string");
		}
	}
	

	
	//test #3
	// we should not be able to read values from improperly initialized atoms
	{
		atom a1(10), a2("banannas!");
		try{
			int x = a2.readInteger();
			printf("TEST #2: Did not throw exception when reading an integer from a string type\n");
		}catch(...)
		{
		}

		try{
			string s = a1.readString();
			printf("TEST #2: Did not throw an exception when reading a string from an integer type\n");
		}catch(...)
		{
		}
	}
	
	//test #4
	// attempting to parse unparseable input should throw exception
	{
		try{
			atom a1;
			a1 = atom::parse("");
			printf("TEST #4: Did not throw exception on parsing empty string\n");
		}catch(...)
		{
		}

		try{
			atom a1;
			a1 = atom::parse("1px");
			printf("TEST #4: Did not throw exception on parsing bad input\n");
		}catch(...)
		{
		}
	
	}
	
	//test #5
	// parsing good input should yield good values
	// {
		try{
			atom a1 = atom::parse(string("goodStringValue"));
			string s = a1.readString();
			if(s != string("goodStringValue"))
				printf("TEST #5: string input not parsed correctly\n");
		}catch(...)
		{
			printf("TEST #5: Did not parse good string input\n");
		}

		try{
			atom a1 = atom::parse("1024");
			int s = a1.readInteger();
			if(s != 1024)
				printf("TEST #5: integer input not parsed correctly\n");
		}catch(...)
		{
			printf("TEST #5: Did not parse good integer input\n");
		}
	// }
	
	return 0;
}