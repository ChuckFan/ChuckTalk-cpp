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
Date& Date::operator++()	// ǰ��++
{
	*this += 1;
	return *this;
}

// d++
Date Date::operator++(int) // ����++
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//
Date Date::operator--()		// ǰ��--
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)	// ����--
{
	Date ret = *this;
	*this -= 1;
	return ret;
}
Date Date::operator+(int day) const//������
{
	Date ret = *this;
	ret += day;
	return ret;
}

Date& Date::operator+=(int day)//����������ֵ
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
//int Date::operator+(const Date&d),������
int Date::operator-(const Date&d)//��������
//1.�Ӵ�������һֱ++ֱ��Ϊ*this�����ڣ�����ѭ������
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

//2.��*this����һֱ--ֱ���������ڣ�����ѭ������
//{
//	int i = 0;
//	while (*this != d)
//	{
//		--*this;
//		i++;
//	}
//	return i;
//}

//2.��b=��������-1900����a=*this-1900��a-b��Ϊ����
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
