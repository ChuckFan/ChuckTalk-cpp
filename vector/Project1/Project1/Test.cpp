#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
using namespace std;

	/*vector<int> v{ 1, 2, 3, 4 };*/
	//v.push_back(6);
	/*v.push_back(6);*/
	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//v.insert(pos, 1);
	//v.erase(pos);
	//vector<string>::iterator it = v.begin();
	//while (it != v.end()) 
	//{
	//	cout << *it << " "; 
	//	++it;
	//}  

	//for (auto x : v)
	//{
	//	cout << x << endl;
	//}
	//cout << endl;

	// insert/erase���µĵ�����ʧЧ 
	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//		it=v.erase(it);
	//	else
	//	++it;
	//}
	//for (auto x : v)
	//{
	//	cout << x << " ";
	//}

	//�������
	//class YH{
	//public:
	//	vector<vector<int>> generate(int numRows) {
	//		vector<vector<int>> vv; 
	//		// �ȿ���������ǵĿռ�     
	//		vv.resize(numRows);  
	//		for(size_t i = 1; i <= numRows; ++i) 
	//		{          
	//			vv[i-1].resize(i, 0);     
	//			// ÿһ�еĵ�һ�������һ������1  
	//			vv[i-1][0] = 1;        
	//			vv[i-1][i-1] = 1;     
	//		}         
	//		for(size_t i = 0; i < vv.size(); ++i)    
	//		{          
	//			for(size_t j = 0; j < vv[i].size(); ++j)  
	//			{          
	//				if(vv[i][j] == 0)     
	//				{             
	//					vv[i][j] = vv[i-1][j-1] + vv[i-1][j];    
	//				}         
	//			}       
	//		}

	//		
	//			return vv;
	//	}
	//};
	//int main()
	//{
	//	YH yh;
	//	yh.generate(1);

	//	system("pause");
	//	return 0;
	//}


//ģ��ʵ��vector
template<class T>

class my_vector{
public:
	//�ض��������
	//�˴�vector�ĵ�����iterator��ֱ������Ϊ��һ��ԭ��ָ��
	typedef T* Iterator;
	typedef const T* ConstIterator;
	Iterator Begin(){ return _start };
	Iterator End(){ return _finish };
	ConstIterator CBegin(){ return _start; }
	ConstIterator CEnd(){ return _finish; }
	size_t Size() const{ return _finish - _start; }
	size_t Capacity() const{ return _endOfStorage - _start; }
	//���캯��
	my_vector()
		: _start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	my_vector(int n, const T& value = T())//��һ������Ϊ���ٿռ��С���ڶ�������Ϊ��ֵ
		: _start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		Reserve(n);
		while (n--)
		{
			Pushback(value);
		}
	}
	// �������ʹ��Iterator�����������ͻᵼ�³�ʼ���ĵ���������[first,last]ֻ����Vector�ĵ�����      
	// ������������������������������[first,last]���������������ĵ��������䡣
	template<class InputIterator>
	my_vector(InputIterator first, InputIterator end)
	{
		Reserve(end - first);
		while (first != end)
		{
			Pushback(*first);
			++first;
		}
	}
	//��������
	my_vector(const my_vector<T>& v)
		: _start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		Reserve(v.Capacity());
		Iterator it = Begin();
		ConstIterator vit = v.Begin();
		while (vit!=v.End())
		{
			*it = *vit;
		}
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}

	//��ֵ���������
	my_vector<T> &operator=(my_vector<T> v)
	{
		//c++11
		Swap(v);
		return *this;
	}
	//����
	~my_vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}
	//�ı�capacity
	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			T* tmp = new T[n];
			if (_start)
			{
				for (size_t i = 0; i < Size(); ++i)
				{
					tmp[i] = _start[i];
				}
			}
			_start = tmp;
			_finish = _start + Size();
			_endOfStorage = _start + n;
		}
	}
	//��size+n��
	void Resize(size_t n, const T& value = T())
	{
		//1.nС�ڵ�ǰsize��������С
		if (n <= size)
		{
			_finish = _start + n;
		}
		//2.n����capacity������Reserve
		if (n > Capacity())
		{
			Reserve(n);
		}
		//3.n���ڵ�ǰsize����С��capacity,���䵽n�ø���value���
		Iterator it = _finish;
		Iterator _finish = _finish + n;
		if (it != _finish)
		{
			*it = value;
			++it;
		}
	}

	void Swap(my_vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofstorge, v._endofstorge);
	}

	void Pushback(const T& x)
	{
		Insert(End(), x);
	}

	void Popback()
	{
		Erase(--End());
	}

	Iterator Insert(Iterator pos, const T& x)
	{
		assert(pos <= _finish);
		if (_finish == _endOfStorage) 
		{
			size_t size = Size();  
			size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
			Reserve(newCapacity);
				// ������������ݣ���Ҫ����pos      
			pos = _start + size;         
		}
				Iterator end = _finish - 1;      
				while (end >= pos)   
				{
					*(end + 1) = *end;     
					--end; 
				}
			*pos = x;   
			++_finish;   
			return pos;
	}
	Iterator Erase(Iterator pos)
	{
		// Ų�����ݽ���ɾ��    
		Iterator begin = pos + 1;
		while (begin != _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}
	T& operator[](size_t pos)   
	{ 
		return _start[pos];
	}
private:
	Iterator _start;
	Iterator _finish;
	Iterator _endOfStorage;
};
int main()
{
	return 0;
}