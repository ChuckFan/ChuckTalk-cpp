#include<string>
#include<assert.h>
#include<string.h>
#include<utility>
#include<iostream>
using namespace std;

class String{
public:
	String(const char* str="")
	{
		if (str == nullptr)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//��������
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	//��ֵ���������
	String& operator=(const String& s)    
	{
		if (this != &s)        
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}                
		return *this;
	}
	//��������
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};