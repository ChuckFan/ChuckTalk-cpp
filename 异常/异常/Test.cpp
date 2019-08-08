#include<iostream>
using namespace std;
double abc(double a, double b)
{
	if (b == 0)
	{
		throw "zero error";
	}
	else
		return ((double) a / (double )b);
}
void func()//处理异常的try函数
{
	int len, time;
	cin >> len >> time;
	cout << abc(len, time) << endl;
}
int main()
{
	try
	{
		func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unknown error" << endl;
	}
	system("pause");
	return 0;
}

//
template<class T>
class smartptr(T* ptr = nullptr){

public:
	smartptr()
		:_ptr(ptr);
	{}
	~smartptr()
	{
		if (_ptr)
			delete(_ptr);
	}
	T& operator*(){ return *_ptr; }
	T* operator->(){ return _ptr; }
private:
	T* _ptr;
};


//throw代表此处函数应检查可能会抛出，try为实际带入运行的地方，
//若用try中代码运行后为异常返回值则找对应catch进行处理
//
//在函数调用链中异常栈展开匹配原则 :
//1. 首先检查throw本身是否在try块内部，如果是再查找匹配的catch语句。
//如果有匹配的，则调到catch 的地方进行处理。
//2. 没有匹配的catch则退出当前函数栈，继续在调用函数的栈中进行查找
//匹配的catch。
//3. 如果到达main函数的栈，依旧没有匹配的，则终止程序。
//上述这个沿着调用链查找匹配的catch子句的过程称为栈展开。
//所以实际中我们最后都要加一个catch(...)捕获任意类型的异常，
//否则当有异常没捕获，程序就会直接终止。
//4. 找到匹配的catch子句并处理以后，会继续沿着catch子句后面继续执行。
//
//异常安全：
//构造函数完成对象的构造和初始化，最好不要在构造函数中抛出异常，否则可能导致对象不完整或没有完全初始化
//析构函数主要完成资源的清理，最好不要在析构函数内抛出异常，否则可能导致资源泄漏(内存泄漏、句 柄未关闭等)
//C++中异常经常会导致资源泄漏的问题，比如在new和delete中抛出了异常，导致内存泄漏，在lock和 unlock之间抛出了异常导致死锁, C++经常使用RAII来解决以上问题



