#include"atom.h"
#include<ctype.h>
#include<algorithm>



// input is a token of unbroken text with no spaces 
atom atom::parse(string token)
{
	// null string -> undefined value
	if(token.length() == 0)
		throw "attempt to parse empty string";
	
	// leading digit -> number or real
	if(isdigit(token[0]))
	{
		// if contains a dot, parse as real
		if(token.find(".",0) != string::npos)
			return atom::parseReal(token);
		else
		// otherwise parse as integer
			return atom::parseInteger(token);
	}
	// otherwise a string
	return atom(token);
}



atom atom::parseInteger(string token)
{
	if(any_of(token.begin(), token.end(), [&](char c){return !isdigit(c);}))
		throw "bad integer input";
	
	int val;
	sscanf(token.c_str(), "%d", &val);
	return atom(val);
}



atom atom::parseReal(string token)
{
	throw "function not defined";
}



atom::atom(const atom& other)
{
	type = other.type;

	switch(other.type)
	{
		case StringT:
			String = other.String;
		break;
		
		case IntegerT:
			Integer = other.Integer;
		break;
		
		case RealT:
			Real = other.Real;
		break;
	}
}

atom::~atom()
{
	
}

atom::atom()
{
	type = UndefinedT;
}

atom::atom(int i)
{
	type = IntegerT;
	Integer = i;
}

atom::atom(string s)
{
	type = StringT;
	String = s;
}

atom::atom(double d)
{
	type = RealT;
	Real = d;
}

string atom::readString()
{
	if(type != StringT)
		throw "Attempt to read a string value from a non-string typed value";
	return String;
}

int atom::readInteger()
{
	if(type != IntegerT)
		throw "Attempt to read an integer value from a non-integer typed value";
	return Integer;
}

double atom::readReal()
{
	if(type != RealT)
		throw "Attempt to read a real number value from a non-real typed value";
	return Real;
}

atom atom::operator=(const atom& other)
{
	// if the other is undefined, that's an error
	if(other.type == UndefinedT)
		throw "Attempt to assign an undefined value";
	
	// if we're undefined, we take on any type
	if(type == UndefinedT)
		type = other.type;
	
	// if we already have a type that doesn't match theirs, that's an error
	if(type != other.type)
		throw "Attempt to assign value of different type";

	switch(other.type)
	{
		case StringT:
			String = other.String;
		break;
		
		case IntegerT:
			Integer = other.Integer;
		break;
		
		case RealT:
			Real = other.Real;
		break;
	}

	return *this;
}
