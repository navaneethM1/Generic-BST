#include <algorithm>
#include <vector>
#include "./include/bst.h"
#include "./include/date.h"

struct MyStringCompare
{
	bool operator()(string s1, string s2)
	{ return s1.length() < s2.length(); }
};

int main()
{
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
	//STL's
	cout << *min_element(bst.begin(), bst.end()) << "\n";
	cout << *max_element(bst.begin(), bst.end()) << "\n";
	// Implemented
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
	// STL's search
	auto itf = find(bst.begin(), bst.end(), 90);
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << "90" <<" not found\n\n";
	}

	cout << count(bst.begin(), bst.end(), 40) << "\n\n";

	itf = bst.search(150);
	if(itf != bst.end())
	{
		cout << *itf << " found\n\n";
	}
	else
	{
		cout << 150 <<" not found\n\n";
	}

	bst.preorder();
	bst.inorder();
	bst.postorder();
	cout << "\n";

	cout << "Leafcount: " << bst.leafcount() << "\n";
	cout << "Height: " << bst.height() << "\n\n";

	//remove node having both subtree
	bst.remove(70);
	cout << "After removing 70" <<"\n";
	bst.print();

	bst.remove(50);
	cout << "After removing 50" <<"\n";
	bst.print();

	bst.remove(20);
	bst.remove(40);
	cout << "After removing 20 and 40" <<"\n";
	bst.print();
	cout << "Leafcount: " << bst.leafcount() << "\n";
	cout << "Height: " << bst.height() << "\n\n";

	BST<int>::Iterator::value_type temp;
	temp = 10;

	#endif	

	#if 0
	//String with Explicit binary predicate(Comparator)
	BST<string, MyStringCompare> bst;
	bst.insert("rama");
	bst.insert("ashok");
	bst.insert("zebra");
	bst.insert("rama");
	bst.insert("zz");
	bst.insert("aa");
	bst.print();

	cout <<"After Copy constructor\n";
	BST<string,MyStringCompare> bst_copy(bst);
	bst_copy.print();
	#endif 
	
	#if 0
	//User Defined Data type : Date type 
	BST<Date> bst_date;
	bst_date.insert({11,11,2021});
	bst_date.insert({12,9,2021});
	bst_date.insert({1,1,2019});
	bst_date.insert({2,10,2020});
	bst_date.insert({21,11,2022});
	bst_date.insert({10,12,2021});
	bst_date.print();

	cout << "After Copy Assignment operator\n";
	BST<Date> bst_date_assignment;
	bst_date_assignment = bst_date;
	bst_date_assignment.print();
	#endif 

	return 0;
}
