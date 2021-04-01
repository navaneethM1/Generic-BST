#include <algorithm>
#include "bst.h"

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

	return 0;
#endif

}
