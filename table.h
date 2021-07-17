// table.h


template<typename K, typename V> class table
{
	public:
		V& operator[](K key)
		{
	//		throw 0;
			return records[0];
		}
		
	private:
		V records[128];
};