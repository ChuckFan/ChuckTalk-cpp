#define D_SCL_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//template<class T> 
//bool IsEqual(T& left, T& right) 
//{
//	return left == right;
//}

//void Test() 
//{
//	char* p1 = "hello"; 
//	char* p2 = "world";
//
//	if (IsEqual(p1, p2))   
//		cout << p1 << endl; 
//	else      
//		cout << p2 << endl;
//}


//类型萃取
// 代表内置类型 
struct TrueType 
{    
	static bool Get() 
	{       
		return true ; 
	} 
};

// 代表自定义类型
struct FalseType 
{     
	static bool Get() 
	{     
		return false ; 
	}
};
template<class T> 
struct TypeTraits 
{ 
	typedef FalseType IsPODType;
};

//实现对内置类型特例化
template<>
struct TypeTraits<char> 
{ 
	typedef TrueType IsPODType; 
};
template<> 
struct TypeTraits<short>
{ 
	typedef TrueType IsPODType; 
};

template<> 
struct TypeTraits<int>
{ 
	typedef TrueType IsPODType; 
};

template<> 
struct TypeTraits<long> 
{ 
	typedef TrueType IsPODType; 
};

template<class T>
void copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
	{
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size;++i)
		{
			dst[i] = src[i];
		}
	}
}
int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int a2[10]; 
	copy(a2, a1, 10);

	string s1[] = { "1111", "2222", "3333", "4444" };  
	string s2[4]; 
	copy(s2, s1, 4);

	//Test();
	system("pause");
	return 0;
}
//1. 模板会导致代码膨胀问题，也会导致编译时间变长 
//2. 出现模板编译错误时，错误信息非常凌乱，不易定位错误

//不用运算符实现n！
//模板的特化,递归
//template<size_t n>
//class sum{
//public:
//	enum
//	{
//		ret = n + sum<n - 1>::ret
//	};
//};
//template<>
//class sum<1>{
//public:
//	enum
//	{
//		ret = 1
//	};
//};

//用构造函数实现
//int sum = 0;
//class add{
//public:
//	add()
//	{
//		n++;
//		sum += n;
//	}
//	static int n;
//};
//int add::n = 0;
//int main()
//{
//	//构造n个对象
//	add a[100];
//	cout << sum << endl;
//}