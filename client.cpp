#include <algorithm>
#include <vector>
#include "./include/bst.h"
#include "./include/date.h"

#if 0
struct MyStringCompare
{
	bool operator()(string s1, string s2)
	{ return s1.length() < s2.length(); }
};
#endif

int main()
{

#if 0
	BST<string> bst;
	// BST<string, MyStringCompare> bst;
	bst.insert("rama");
	bst.insert("ashok");
	bst.insert("zebra");
	bst.insert("rama");
	bst.insert("zz");
	bst.insert("aa");

	bst.print();
	cout << bst.totalcount() << "\n\n";

	cout << *min_element(bst.begin(), bst.end()) << "\n";
	cout << *max_element(bst.begin(), bst.end()) << "\n";
	cout << *bst.min_element() << "\n";
	cout << *bst.max_element() << "\n";
	cout << "\n";

	cout << "Inorder\n";
	disp(bst.begin(), bst.end());
	cout << "\n";

	cout << "Reverse Order\n";
	auto it = bst.end();
	--it;
	while(it != bst.begin())
	{
		cout << *it << "\t";
		--it;
	}
	cout << *it;
	cout << "\n\n";

	auto itf = find(bst.begin(), bst.end(), "zebra");
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "not found\n\n";
	}

	cout << count(bst.begin(), bst.end(), "nothing") << "\n\n";

	itf = bst.search("ashok");
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "not found\n\n";
	}

	bst.preorder();
	bst.inorder();
	bst.postorder();
	cout << "\n";

	cout << "Leafcount: " << bst.leafcount() << "\n";
	cout << "Height: " << bst.height() << "\n\n";

	return 0;
#endif

#if 0
	// BST<string> bst;
	// BST<string, MyStringCompare> bst;
	vector<string> v = { "rama", "ashok", "zebra", "rama", "zz", "aa" };
	// bst.insert("rama");
	// bst.insert("ashok");
	// bst.insert("zebra");
	// bst.insert("rama");
	// bst.insert("zz");
	// bst.insert("aa");
	BST<string> bst1(v.begin(), v.end());
	BST<string> bst;
	cout << "Copy assignment\n";
	bst = bst1;
	cout << "\n";
	bst.print();
	cout << bst.totalcount() << "\n\n";

	cout << *min_element(bst.begin(), bst.end()) << "\n";
	cout << *max_element(bst.begin(), bst.end()) << "\n";
	cout << *bst.min_element() << "\n";
	cout << *bst.max_element() << "\n";
	cout << "\n";

	cout << "Inorder\n";
	disp(bst.begin(), bst.end());
	cout << "\n";

	cout << "Reverse Order\n";
	auto it = bst.end();
	--it;
	while(it != bst.begin())
	{
		cout << *it << "\t";
		--it;
	}
	cout << *it;
	cout << "\n\n";

	auto itf = find(bst.begin(), bst.end(), "zebra");
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "not found\n\n";
	}

	cout << count(bst.begin(), bst.end(), "nothing") << "\n\n";

	itf = bst.search("ashok");
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "not found\n\n";
	}

	bst.preorder();
	bst.inorder();
	bst.postorder();
	cout << "\n";

	cout << "Leafcount: " << bst.leafcount() << "\n";
	cout << "Height: " << bst.height() << "\n\n";

	return 0;
#endif

#if 0
	BST<int> bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80);

	bst.print();
	cout << bst.totalcount() << "\n\n";

	cout << *min_element(bst.begin(), bst.end()) << "\n";
	cout << *max_element(bst.begin(), bst.end()) << "\n";
	cout << *bst.min_element() << "\n";
	cout << *bst.max_element() << "\n";
	cout << "\n";

	cout << "Inorder\n";
	disp(bst.begin(), bst.end());
	cout << "\n";

	cout << "Reverse Order\n";
	auto it = bst.end();
	--it;
	while(it != bst.begin())
	{
		cout << *it << "\t";
		--it;
	}
	cout << *it;
	cout << "\n\n";

	auto itf = find(bst.begin(), bst.end(), 90);
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "not found\n\n";
	}

	cout << count(bst.begin(), bst.end(), 40) << "\n\n";

	itf = bst.search(150);
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "not found\n\n";
	}

	bst.preorder();
	bst.inorder();
	bst.postorder();
	cout << "\n";

	cout << "Leafcount: " << bst.leafcount() << "\n";
	cout << "Height: " << bst.height() << "\n\n";

	return 0;
#endif

#if 0
	BST<Date> bst;
	bst.insert({11,11,2021});
	bst.insert({12,9,2021});
	bst.insert({1,1,2019});
	bst.insert({2,10,2020});
	bst.print();
	cout << *min_element(bst.begin(), bst.end()) << "\n";
	cout << *max_element(bst.begin(), bst.end()) << "\n";
	cout << *bst.min_element() << "\n";
	cout << *bst.max_element() << "\n";

	auto itf = bst.search({11,11,2021});
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "not found\n\n";
	}
	cout << "Reverse Order\n";
	auto it = bst.end();
	--it;
	while(it != bst.begin())
	{
		cout << *it << "\t";
		--it;
	}
	cout << *it;
	cout << "\n\n";

	return 0;
#endif

#if 1
	vector<int> a{10, 1, 3,20, 15};
	vector<int> b{12,4,2,54,121,50,52};
	BST<int> rhs(begin(a), end(a));
	BST<int> lhs(begin(b), end(b));
	// cout << rhs.height();
	cout << "First BST\n";
	rhs.print();
	cout << "Second BST\n";
	lhs.print();
	cout << "\nCopy Assignment\n";
	lhs = rhs;
	lhs.print();

	// cout << "\nCount " << lhs.totalcount() << "\n";
#endif

#if 0
	vector<int> b{12,4,2,54,121};
	BST<int> rhs(begin(b), end(b));
	cout << "rhs\n";
	rhs.print();
	BST<int> lhs(rhs);
	lhs.print();
#endif
}
