#pragma once

#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

class Date
{
public:
	//确定当月天数
	inline int GetMonthDay(int year, int month) const
	{
		static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((month == 2)
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;//闰年
		}

		return monthArray[month];
	}

	Date(int year, int month, int day)//构造函数
	{
		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			//assert(false);
			cout << "非法日期" << endl;
		}
	}

	// 作业中：实现一下拷贝赋值 + 析构  熟悉他们的用法

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//运算符重载声明
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();		// 前置++
	Date operator++(int);	// 后置++

	Date operator--();		// 前置--
	Date operator--(int);	// 后置--

	Date operator+(int day) const;
	Date operator-(int day) const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	int operator-(const Date&d);
private://成员变量一般为私有，数据隐蔽
	int _year;
	int _month;
	int _day;
};
