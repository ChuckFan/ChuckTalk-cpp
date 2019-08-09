#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
//pair的模拟实现
//template<class T1,class T2>
//struct pair{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//	pair()
//		:first(T1())
//		, second(T2())
//	{}
//	pair(const T1& a, const T2& b)
//		:first(a)
//		, second(b)
//	{}
//};

//map

//map的多种插入方式
//void testmap()
//{
//	map<string, string> m;
//	m.insert(pair<string, string>("peach", "桃子"));
//	m.insert(make_pair("banana", "香蕉"));
//	m["apple"] = "苹果";
//	//m.at("waterme") = "水蜜桃";at查找不存在的key直接报异常
//	for (auto& e : m)
//	{
//		cout << e.first << "--->" << e.second << endl;
//	}
//}
//set
//void testset()
//{
//	//使用数组构造array
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	set<int> s(array, array+sizeof(array) / sizeof(array[0]));
//	cout << s.size();//返回set中有效元素个数
//	//使用迭代器正向打印set中元素
//	for (auto& e : s)
//	{
//		cout << e << " ";
//		cout << endl;
//	}
//	//使用迭代器逆向打印set中元素
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//	{
//		cout << *it << " ";
//		cout << endl;
//	}
//	//set中值为3的元素出现次数
//	cout << s.count(3) << endl;
//	//因为去重，set用count只能为0或1
//}


//二叉搜索树实现

//红黑树插入结点
template<class valuetype>
class retree{
public:
	bool insert(const valuetype& data)
	{
		PNode& proot = getroot();
		if (proot == nullptr)
		{
			proot = new Node(data, black);
			proot->_pparent = _phead;
			_phead->_pparent = proot;
		}
		proot->colour = black;
		_phead->_pleft = leftmost();
		_phead->_pright = rightmost();
		return ture;
	}
private:
	PNode& getroot(){ return _phead->_pparent; }
	PNode leftmost();
	//获取红黑树中最左即最小结点
	PNode rightmost();
	//获取红黑树中最右即最大结点
private:
	PNode _phead;
};
//map中的mapkeyofvalue
template<class k,class v>
struct mapkeyofvalue
{
	const k& operator()(const pair<k, v>& kv)
	{
		return kv.first;
	}
};
//set中的setkeyofvalue
template<class k>
struct setkeyofvalue
{
	const k& operator()(const k& k)
	{
		return k;
	}
};

int main()
{
	//testmap();
	//testset();
	system("pause");
	return 0;
}