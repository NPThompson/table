// table.h
#include<exception>
#include<string>



using namespace std;







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
		struct record
		{
			record(K k)
			{
				key = k;
				next = nullptr;
			}
			
			K key;
			V val;
			record* next;
		};
		

	public:
		table()
		{
			for(int i = 0; i < size; i++)
				records[i] = nullptr;
		}
		
		V& operator[](K key)
		{
			return get(key)->val;
		}
		
		bool contains(K key)
		{
			record* r = records[hash(key)];
			while(r != nullptr)
			{
				if(r->key == key)
					return true;
				r = r->next;
			}
			return false;
		}
		
		unsigned int hash(K key)
		{
			return hashf::string(key) % size;
		}
		
	private:
		record* get(K key)
		{
			// where to find
			int index = hash(key);

			// if non initialized
			if(records[index] == nullptr)
			{	
				records[index] = new record(key);
				return records[index];
			}
			
			// if hashes are the same
			record* bucket = records[index];
			
			while(true)
			{
				if(bucket->key == key)
					return bucket;
				
				if(bucket->next == nullptr)
				{
					bucket->next = new record(key);
					return bucket->next;
				}
				
				bucket = bucket->next;
			}
			
			return nullptr;
		}
		
		record* records[size];
};