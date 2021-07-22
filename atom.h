// atomic values can be one of three types:
//	string
//	integer
//	real



#include<string>



using namespace std;



class atom
{
	public:
		static atom parse(string);
		static atom parseReal(string);
		static atom parseInteger(string);
		
		atom();
		~atom();
		atom(const atom&);
		atom(int i);		
		atom(string s);
		atom(double d);
	
		string readString();
		int    readInteger();
		double readReal();
		
		atom operator=(const atom& other);
		
	private:
		union {
			string String;
			int	   Integer;
			double Real;
		};
		
		enum atomType
		{
			StringT = 0,
			IntegerT,
			RealT,
			UndefinedT
		};
		
		atomType type;
};