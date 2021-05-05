#include <algorithm>
#include <vector>
#include "./include/bst_mod.h"
#include "./include/date.h"

struct MyStringCompare
{
	bool operator()(string s1, string s2)
	{ return s1.length() < s2.length(); }
};

int main()
{
	BST<int> bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(70);
	bst.insert(60);
	bst.insert(30);
	bst.insert(30);
	bst.insert(80);

	bst.print();

	auto lb = bst.lower_bound(30);
	cout << "Lower Bound of 30: " << *lb << "\n";
	lb = lower_bound(bst.begin(), bst.end(), 30);
	cout << "Lower Bound of 30: " << *lb << "\n";

	auto ub = bst.upper_bound(30);
	cout << "Upper Bound of 30: " << *ub << "\n";
	ub = upper_bound(bst.begin(), bst.end(), 30);
	cout << "Upper Bound of 30: " << *ub << "\n";

	auto eqr = bst.equal_range(30);
	disp(eqr.first, eqr.second);
	eqr = equal_range(bst.begin(), bst.end(), 30);
	disp(eqr.first, eqr.second);

	return 0;
}