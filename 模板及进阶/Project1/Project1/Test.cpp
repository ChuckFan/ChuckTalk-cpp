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


//������ȡ
// ������������ 
struct TrueType 
{    
	static bool Get() 
	{       
		return true ; 
	} 
};

// �����Զ�������
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

//ʵ�ֶ���������������
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
//1. ģ��ᵼ�´����������⣬Ҳ�ᵼ�±���ʱ��䳤 
//2. ����ģ��������ʱ��������Ϣ�ǳ����ң����׶�λ����

//���������ʵ��n��
//ģ����ػ�,�ݹ�
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

//�ù��캯��ʵ��
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
//	//����n������
//	add a[100];
//	cout << sum << endl;
//}