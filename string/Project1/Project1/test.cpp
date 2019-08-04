#include<string>
#include<stdlib.h>
#include<iostream>
using std::cout;
using std::endl;
using std::string;
void TestString() {
	//std:: string str;
	//str.push_back(' ');   // 在str后插入空格  
	//str.append("hello");  // 在str后追加一个字符"hello"   
	//str += 'b';           // 在str后追加一个字符'b'      
	//str += "it";          // 在str后追加一个字符串"it"   
	//cout << str << endl;
	//cout << str.c_str() << endl;
	/*string file1("string.cpp"); 
	size_t pos = file1.rfind('.');  
	string suffix(file1.substr(pos, file1.size() - pos)); 
	cout << suffix << endl;*/
	// 取出url中的域名    
	//string url("http://www.cplusplus.com/reference/string/string/find/"); 
	//cout << url << endl;
	//size_t start=url.find("://", 0);
	//if (start == string::npos)
	//{
	//	cout << "failed" << endl;
	//}
	//start += 3;
	//size_t finish = url.find('/', start);
	//string add = url.substr(start, finish - start);
	//cout << add << endl;


	//std::string s1("hello");
	//std::string s2(s1);
	//std::string s3 = s1;
	//std::string s4("world");
	//cout << s2<< endl;

	//s1 = s4;
	//cout << s1 << endl;

	//s1[4] = 'x';
	//for (size_t i = 0; i < s1.size(); ++i)
	//{
	//	cout << s1[i] << " ";
	//	cout << s1.at(i) << " ";

	//}
	//cout << endl;
	std::string str1;
	std::cin >> str1;
	cout << str1 << endl;

	std::string str2;
	std::cin >> str2;
	cout << str2 << endl;

	cout << (str1 < str2) << endl;
	cout << (str1 == str2) << endl;

	cout << str1 + "1111" << endl;
	cout << "1111" + str1 << endl;
}
int main()
{
	TestString();
	system("pause");
}