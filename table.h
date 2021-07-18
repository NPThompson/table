// table.h
#include<exception>
#include<string>



using namespace std;







class tableMissingElementException : public exception
{
	virtual const char* what() const throw ()
	{
		return " no value associated with the key found in the table ";
	}
} missingElementException;



namespace hashf
{
	unsigned int constchar(const char* key)
	{
		unsigned int sum = 0;
		while(*key != '\0')
			sum += *(key++);
		return sum;
	}

	unsigned int string(string key)
	{
		unsigned int sum = 0;
		
		for(int i = 0; i < key.length(); i++)
			sum += key[i];
		
		return sum;
	}
};



template<typename K, typename V, const unsigned int size = 128> class table
{
	public:
	
		V& operator[](K key)
		{
			// where to find
			int index = hash(key);
			
			// if none found, set new key
			if(records[index].key != key)
				records[index].key = key;
			
			// return if found
			return records[index].val;
		}
		
		bool contains(K key)
		{
			return false;
		}
		
		unsigned int hash(K key)
		{
			return hashf::string(key) % size;
		}
		
	private:
		
		struct { K key; V val; } records[size];
};