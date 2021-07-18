// table.h
#include<exception>
using namespace std;



class tableMissingElementException : public exception
{
	virtual const char* what() const throw ()
	{
		return " no value associated with the key found in the table ";
	}
} missingElementException;



template<typename K, typename V> class table
{
	public:
		V& operator[](K key)
		{
			throw missingElementException;
			return records[0];
		}
		
	private:
		V records[128];
};