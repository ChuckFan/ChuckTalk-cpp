#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
//pair��ģ��ʵ��
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

//map�Ķ��ֲ��뷽ʽ
//void testmap()
//{
//	map<string, string> m;
//	m.insert(pair<string, string>("peach", "����"));
//	m.insert(make_pair("banana", "�㽶"));
//	m["apple"] = "ƻ��";
//	//m.at("waterme") = "ˮ����";at���Ҳ����ڵ�keyֱ�ӱ��쳣
//	for (auto& e : m)
//	{
//		cout << e.first << "--->" << e.second << endl;
//	}
//}
//set
//void testset()
//{
//	//ʹ�����鹹��array
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	set<int> s(array, array+sizeof(array) / sizeof(array[0]));
//	cout << s.size();//����set����ЧԪ�ظ���
//	//ʹ�õ����������ӡset��Ԫ��
//	for (auto& e : s)
//	{
//		cout << e << " ";
//		cout << endl;
//	}
//	//ʹ�õ����������ӡset��Ԫ��
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//	{
//		cout << *it << " ";
//		cout << endl;
//	}
//	//set��ֵΪ3��Ԫ�س��ִ���
//	cout << s.count(3) << endl;
//	//��Ϊȥ�أ�set��countֻ��Ϊ0��1
//}


//����������ʵ��

//�����������
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
	//��ȡ�������������С���
	PNode rightmost();
	//��ȡ����������Ҽ������
private:
	PNode _phead;
};
//map�е�mapkeyofvalue
template<class k,class v>
struct mapkeyofvalue
{
	const k& operator()(const pair<k, v>& kv)
	{
		return kv.first;
	}
};
//set�е�setkeyofvalue
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