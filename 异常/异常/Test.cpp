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
void func()//�����쳣��try����
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


//throw����˴�����Ӧ�����ܻ��׳���tryΪʵ�ʴ������еĵط���
//����try�д������к�Ϊ�쳣����ֵ���Ҷ�Ӧcatch���д���
//
//�ں������������쳣ջչ��ƥ��ԭ�� :
//1. ���ȼ��throw�����Ƿ���try���ڲ���������ٲ���ƥ���catch��䡣
//�����ƥ��ģ������catch �ĵط����д���
//2. û��ƥ���catch���˳���ǰ����ջ�������ڵ��ú�����ջ�н��в���
//ƥ���catch��
//3. �������main������ջ������û��ƥ��ģ�����ֹ����
//����������ŵ���������ƥ���catch�Ӿ�Ĺ��̳�Ϊջչ����
//����ʵ�����������Ҫ��һ��catch(...)�����������͵��쳣��
//�������쳣û���񣬳���ͻ�ֱ����ֹ��
//4. �ҵ�ƥ���catch�Ӿ䲢�����Ժ󣬻��������catch�Ӿ�������ִ�С�
//
//�쳣��ȫ��
//���캯����ɶ���Ĺ���ͳ�ʼ������ò�Ҫ�ڹ��캯�����׳��쳣��������ܵ��¶���������û����ȫ��ʼ��
//����������Ҫ�����Դ��������ò�Ҫ�������������׳��쳣��������ܵ�����Դй©(�ڴ�й©���� ��δ�رյ�)
//C++���쳣�����ᵼ����Դй©�����⣬������new��delete���׳����쳣�������ڴ�й©����lock�� unlock֮���׳����쳣��������, C++����ʹ��RAII�������������



