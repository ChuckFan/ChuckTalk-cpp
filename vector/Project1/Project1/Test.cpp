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

	// insert/erase导致的迭代器失效 
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

	//杨辉三角
	//class YH{
	//public:
	//	vector<vector<int>> generate(int numRows) {
	//		vector<vector<int>> vv; 
	//		// 先开辟杨辉三角的空间     
	//		vv.resize(numRows);  
	//		for(size_t i = 1; i <= numRows; ++i) 
	//		{          
	//			vv[i-1].resize(i, 0);     
	//			// 每一行的第一个和最后一个都是1  
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


//模拟实现vector
template<class T>

class my_vector{
public:
	//重定义迭代器
	//此处vector的迭代器iterator可直接用因为是一个原生指针
	typedef T* Iterator;
	typedef const T* ConstIterator;
	Iterator Begin(){ return _start };
	Iterator End(){ return _finish };
	ConstIterator CBegin(){ return _start; }
	ConstIterator CEnd(){ return _finish; }
	size_t Size() const{ return _finish - _start; }
	size_t Capacity() const{ return _endOfStorage - _start; }
	//构造函数
	my_vector()
		: _start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	my_vector(int n, const T& value = T())//第一个参数为开辟空间大小，第二个参数为初值
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
	// 这里如果使用Iterator做迭代器，就会导致初始化的迭代器区间[first,last]只能是Vector的迭代器      
	// 这里重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器区间。
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
	//拷贝构造
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

	//赋值运算符重载
	my_vector<T> &operator=(my_vector<T> v)
	{
		//c++11
		Swap(v);
		return *this;
	}
	//析构
	~my_vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}
	//改变capacity
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
	//将size+n个
	void Resize(size_t n, const T& value = T())
	{
		//1.n小于当前size，进行缩小
		if (n <= size)
		{
			_finish = _start + n;
		}
		//2.n大于capacity，调用Reserve
		if (n > Capacity())
		{
			Reserve(n);
		}
		//3.n大于当前size，但小于capacity,扩充到n用给的value填充
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
				// 如果发生了增容，需要重置pos      
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
		// 挪动数据进行删除    
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