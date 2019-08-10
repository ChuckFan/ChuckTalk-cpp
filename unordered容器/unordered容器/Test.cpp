//用unorderedmap计算重复N次的元素
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//class solution{
//public:
//	static int repeatedtimes(vector<int> &a)
//	{
//		size_t N = a.size() / 2;
//		unordered_map<int, int> m;
//		for (auto x : a)
//		{
//			m[x]++;
//		}
//		for (auto& x : m)
//		{
//			if (x.second == N)
//			{
//				return x.first;
//			}
//		}
//	}
//};
//int main()
//{
//	vector<int> a={1, 2, 3, 3};
//	int b=solution::repeatedtimes(a);
//	cout << b << endl;
//	system("pause");
//	return 0;
//}

//两个数组的交集
vector<int> abc(vector<int> &a, vector<int> &b)
{
	unordered_set<int> m1;
	for (auto x : a)
	{
		m1.insert(x);
	}
	unordered_set<int> m2;
	for (auto x : b)
	{
		m2.insert(x);
	}
	vector<int> ret;
	for (auto x : m1)
	{
		if (m2.find(x) != m2.end())
		{
			ret.push_back(x);
		}
	}
	return ret;
}

//哈希只存key
template<class T> class DefHashF { public:    size_t operator()(const T& val)    { return val; } };

// key为字符串类型，需要将其转化为整形 
class Str2Int { 
public:   
	size_t operator()(const string& s)   
	{     
		const char* str = s.c_str();  
		unsigned int seed = 131; 
		// 31 131 1313 13131 131313    
		unsigned int hash = 0;       
		while (*str)       
		{          
			hash = hash * seed + (*str++);  
		}             
		return (hash & 0x7FFFFFFF);   
	}
};

// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
template<class K, class V, class HF> class HashTable { 
	// …… 
private: 
	size_t HashFunc(const K& key)    { 
		return HF()(key)%_ht.capacity();  
	}
};