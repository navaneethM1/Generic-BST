#ifndef DATE
#define DATE
#include<iostream>
using namespace std;

class Date
{
	private:
		int dd_;
		int mm_;
		int yy_;
	public:
		Date(int dd = 1, int mm = 1, int yy = 1970) : dd_(dd), mm_(mm), yy_(yy) { }
		friend ostream& operator<<(ostream& o, const Date& d);
		friend bool operator<(const Date& lhs, const Date& rhs);
};

ostream& operator<<(ostream& o, const Date& d)
{
	return o << d.dd_ << "-" << d.mm_ << "-" << d.yy_;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if(lhs.yy_ < rhs.yy_)
		return true;
	if(lhs.yy_ == rhs.yy_ && lhs.mm_ < rhs.mm_)
		return true;
	if(lhs.yy_ == rhs.yy_ && lhs.mm_ == rhs.mm_ && lhs.dd_ < rhs.dd_) 
		return true;
	return false;
}

#endif
