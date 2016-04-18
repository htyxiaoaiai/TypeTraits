# TypeTraits
类型萃取实现顺序表
#include <iostream>
#include<string>
#include"TypeTraits.h"

using namespace std;

const int SIZE = 3;//构造对象的默认大小
const int DEAFAULT = 3;//每次扩容的大小
template<typename T>
class SeqList
{
public:
	//构造函数
	SeqList();
	//拷贝构造函数
	SeqList(const SeqList& l);
	//赋值
	SeqList<T> operator=(SeqList l);
	//析构函数
	~SeqList();
public:
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	void SortList();
	void Reverse();
	T* Find(const T& d);
	void Insert(int pos, const T& x);
	void Remove(T x);
	void RemoveAll(T x);
	void CheckCapacity();
	void Print();
private:
	void Copy(T* dest, const T* src, size_t size)
	{
		if (TypeTraits<T>::IsPoodType().Get())//类型萃取，内置类型
		{
			memcpy(dest, src, sizeof(T)*size);
		}
		else//非内置类型
		{
			for (size_t i = 0; i < size; i++)
			{
				dest[i] = src[i];
			}
		}
	}
private:
	T* _data;
	int _size;
	int _capacity;

};

template<typename T>
void SeqList<T>::Print()
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		cout << _data[i] << " ";
	}
	cout << endl;
}
template<typename T>
//构造函数
SeqList<T>::SeqList()
	:_data(new T[SIZE])
	, _size(0)
	, _capacity(SIZE)
{}
template<typename T>
//拷贝构造函数
SeqList<T>::SeqList(const SeqList& l)
{
	_data = new T[l._size];
	Copy(_data, l._data, l._size);
	/*int i = 0;
	for (i = 0; i < l._size; i++)
	{
		_data[i] = l._data[i];
	}*/
	_size = l._size;
	_capacity = _size;
}
template<typename T>
//赋值
SeqList<T> SeqList<T>:: operator=(SeqList l)
{
	swap(_data, l._data);
	_size = l._size;
	_capacity = l._capacity;
	return *this;
}
template<typename T>
//析构函数
SeqList<T>::~SeqList()
{
	if (_data != NULL)
	{
		delete[] _data;
		_data = NULL;
	}
}

template<typename T>
void SeqList<T>::CheckCapacity()
{
	if (_size == _capacity)
	{
		T* tmp = new T[_capacity + DEAFAULT];
		Copy(tmp, _data, _size);
		//memcpy(tmp, _data, sizeof(T)*_size);
		///*int i = 0;
		//for (i = 0; i < _size; i++)
		//{
		//tmp[i] = _data[i];
		//}*/
		delete[] _data;
		_data = tmp;
		_capacity += DEAFAULT;
	}
}
template<typename T>
void SeqList<T>::PushBack(const T& d)
{
	CheckCapacity();
	_data[_size] = d;
	_size++;
}
template<typename T>
void SeqList<T>::PopBack()
{
	if (_size == 0)
	{
		return;
	}
	_size--;
}
template<typename T>
void SeqList<T>::PushFront(const T& d)
{
	CheckCapacity();
	int i = 0;
	for (i = _size - 1; i >= 0; i--)
	{
		_data[i + 1] = _data[i];
	}
	_data[0] = d;
	_size++;
}
template<typename T>
void SeqList<T>::PopFront()
{
	if (_size == 0)
	{
		return;
	}
	int i = 0;
	for (i = 1; i < _size; i++)
	{
		_data[i - 1] = _data[i];
	}
	_size--;
}
template<typename T>
void SeqList<T>::SortList()
{
	int i = _size;
	bool flag = true;
	for (i = 1; i < _size && flag; i++)
	{
		int j = 0;
		flag = false;
		for (j = 0; j < _size - i; j++)
		{
			if (_data[j] > _data[j + 1])
			{
				flag = true;
				swap(_data[j], _data[j + 1]);
			}
		}
	}
}
template<typename T>
void SeqList<T>::Reverse()
{
	int left = 0;
	int right = _size;
	while (left < right)
	{
		swap(_data[left++], _data[right++]);
	}
}
template<typename T>
T* SeqList<T>::Find(const T& d)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		if (_data[i] == d)
		{
			return &_data[i];
		}
	}
	return NULL;
}
template<typename T>
void SeqList<T>::Insert(int pos, const T& x)
{
	if (pos > 0 && pos <= _size)
	{
		CheckCapacity();
		int i = 0;
		for (i = _size - 1; i >pos - 2; i--)
		{
			_data[i + 1] = _data[i];
		}
		_data[pos - 1] = x;
		_size++;
	}
}
template<typename T>
void SeqList<T>::Remove(T x)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		if (x == _data[i])
		{
			for (int j = i; j < _size - 1; j++)
			{
				_data[j] = _data[j + 1];
			}
			_size--;
			return;
		}
	}
}
template<typename T>
void SeqList<T>::RemoveAll(T x)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		if (x == _data[i])
		{
			Remove(x);
			i--;
		}
	}
}

void test1()
{
	//SeqList<string> l;
	//l.PushBack(1);
	//l.PushBack(2);
	//l.PushBack(3);
	//l.PushBack(4);
	//l.Print();
	//l.PopBack();
	//l.Print();
	//l.PopBack();
	//l.Print();
	//l.PopBack();
	//l.Print();
	//l.PushFront("11111");
	//l.PushFront("22222");
	//l.PushFront("333333333333333333333333333333333333");
	//l.PushFront("33333");
	//l.PushFront("44444");
	////l.PushFront("11111");
	//l.Print();
	SeqList <int> l2;
	l2.PushBack(1);
	l2.PushBack(2);
	l2.PushBack(3);
	l2.PushBack(4);
	l2.Print();

	/*cout << sizeof(string) << endl;*/
	//cout << l.Find("11111") << endl;
	////cout << l.Find(0) << endl;
	//l.Insert(4, "00000");
	//l.Print();
	//l.RemoveAll("11111");
	//l.Print();
	//l.SortList();
	////l.PopBack();
	//l.Print();
	//l.PopBack();
	//l.Print();
	//l.PopBack();
	//l.Print();
}
int main()
{
	test1();
	getchar();
	return 0;
}
