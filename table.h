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



namespace hash
{
	unsigned int string(const char* key)
	{
		unsigned int sum = 0;
		while(*key != '\0')
			sum += *(key++);
		return sum;
	}
}



template<typename K, typename V, const unsigned int size = 128> class table
{
	public:
		V& operator[](K key)
		{
			throw missingElementException;
			return records[hash(key)];
		}
		
		unsigned int hash(K key)
		{
			return hash::string(key) % size;
		}
		
	private:
		V records[size];
};