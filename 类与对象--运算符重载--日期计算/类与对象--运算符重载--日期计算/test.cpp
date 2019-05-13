#include "Date.h"

bool Date::operator>(const Date& d) const
{
	if (_year == d._year)
	{
		if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
			return false;
		}
		else if (_month > d._month)
		{
			return true;
		}
		return false;
	}
	else if (_year > d._year)
	{
		return true;
	}
	return false;
}
bool Date::operator>=(const Date& d) const
{
	if (_year == d._year)
	{
		if (_month == d._month)
		{
			if (_day < d._day)
			{
				return false;
			}
			return true;
		}
		if (_month < d._month)
		{
			return false;
		}
		return true;
	}
	else if (_year < d._year)
	{
		return false;
	}
	return true;
}
bool Date::operator<(const Date& d) const
{
	if (_year == d._year)
	{
		if (_month == d._month)
		{
			if (_day < d._day)
			{
				return ture;
			}
			return false;
		}
		else if (_month < d._month)
		{
			return true;
		}
		return false;
	}
	else if (_year < d._year)
	{
		return true;
	}
	return false;
}
bool Date::operator<=(const Date& d) const
{
	if (_year == d._year)
	{
		if (_month == d._month)
		{
			if (_day > d._day)
			{
				return false;
			}
			return true;
		}
		if (_month > d._month)
		{
			return false;
		}
		return true;
	}
	else if (_year > d._year)
	{
		return false;
	}
bool Date::operator==(const Date& d) const
{
	if ((_year == d._year)
		&&(_month==d._month)
		&&(_day==d._day))
	{
		return true;
	}
	return false;
}
bool Date::operator!=(const Date& d) const
{
	if ((_year == d._year)
		&& (_month == d._month)
		&& (_day == d._day))
	{
		return false;
	}
	return true;
}

// ++d
Date& Date::operator++()	// 前置++
{
	*this += 1;
	return *this;
}

// d++
Date Date::operator++(int) // 后置++
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//
Date Date::operator--()		// 前置--
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)	// 后置--
{
	Date ret = *this;
	*this -= 1;
	return ret;
}
Date Date::operator+(int day) const//加天数
{
	Date ret = *this;
	ret += day;
	return ret;
}

Date& Date::operator+=(int day)//加天数并赋值
{
	//if (day < 0)
	//	return *this -= -day;

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator-(int day) const
{
	Date ret = *this;
	ret -= day;
	return ret;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day<0)
	{
		_month--;
		_day = -(_day);
		_day -= GetMonthDay(_year, _month);
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
	}
	return *this;
}
//int Date::operator+(const Date&d),无意义
int Date::operator-(const Date&d)//返回天数
//1.从传入日期一直++直到为*this的日期，计算循环次数
//{
//	int i=0;
//	Date ret = d;
//	while (*this != ret)
//	{
//		++ret;
//		i++;
//	}
//	return i;
//}

//2.从*this日期一直--直到传入日期，计算循环次数
//{
//	int i = 0;
//	while (*this != d)
//	{
//		--*this;
//		i++;
//	}
//	return i;
//}

//2.用b=传入日期-1900，用a=*this-1900，a-b即为天数
{
	int i = 0; int j = 0; int k = 0;
	const Date d(1900, 1, 1);
	while (*this != d)
	{
		--*this;
		i++;
	}
	Date ret = d;
	while (ret != d)
	{
		--ret;
		j++;
	}
	k = i - j;
	return j;
}
