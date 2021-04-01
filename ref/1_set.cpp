/*
set :
	unique elements
	ordered based on a predicate
	no control over the positioning - cannot insert at pos x
	
	
*/
#include <iostream>
using namespace std;
#include <set>
#include <string>
#include <algorithm>


template<typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
	while(first != last)
	{
		cout << *first << "\t";
		++first;
	}
	cout << "\n";
} 

template<typename T>
class MyLess
{
	public:
	bool operator()(const T& lhs, const T& rhs) { return lhs < rhs; }
};
struct What
{
	bool operator()(int lhs, int rhs) { return lhs % 10 < rhs % 10; }
};

struct MyStringCompare
{
	bool operator()(string s1, string s2)
	{ return s1.length() < s2.length(); }
};
int main()
{
	
	set<string, MyStringCompare> s10{"rama", "ashok", "zebra", "rama", "zz", "aa"};
	disp(s10.begin(), s10.end());
	cout << count(s10.begin(), s10.end(), "rama");
}

// member find:

// !(a < b) &&  !(b < a)   => a == b 









