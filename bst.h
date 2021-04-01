#include <iostream>
#include <functional>
using namespace std;

#define COUNT 10

void disp(auto first, auto last)
{
	while(first != last)
	{
		cout << *first << "\t";
		++first;
	}
	cout << "\n";
}


// Interface


template<typename T>
struct TreeNode
{
	T data;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(T data) : data(data), left(nullptr), right(nullptr), parent(nullptr) { }
};

template<typename T, typename Compare = less<T>>
class BST
{
	private:
	TreeNode<T> *root;
	TreeNode<T> *dummy;
	Compare cmp; // will have operator() overloaded for comparision
	int cnt;
	void release(TreeNode<T> *root);
	void printUtil(TreeNode<T> *root, int space);
	static TreeNode<T> *min(TreeNode<T> *node);
	static TreeNode<T> *max(TreeNode<T> *node);
	static TreeNode<T> *inorder_successor(TreeNode<T> *node);
	static TreeNode<T> *inorder_predecessor(TreeNode<T> *node);
	public:
	BST() : root(new TreeNode<T>(T())), dummy(nullptr), cmp(Compare()), cnt(0) { dummy = root; }
	~BST() { release(root); }
	BST(const BST&) = delete;
	BST& operator=(const BST&) = delete;
	class Iterator
	{
		private:
		TreeNode<T> *p_it_;
		public:
		Iterator(TreeNode<T> *p_it) : p_it_(p_it) { }
		Iterator& operator++() // pre
		{
			p_it_ = inorder_successor(p_it_);
			return *this;
		}
		Iterator operator++(int) // post
		{
			Iterator temp(*this);
			++*this;
			return temp;
		}
		Iterator& operator--() // pre
		{
			p_it_ = inorder_predecessor(p_it_);
			return *this;
		}
		Iterator operator--(int) // post
		{
			Iterator temp(*this);
			--*this;
			return temp;
		}
		const T& operator*()
		{
			return p_it_->data;
		}
		bool operator==(const Iterator& rhs) const
		{
			return p_it_ == rhs.p_it_;
		}
		bool operator!=(const Iterator& rhs) const
		{
			return !(*this == rhs);
		}
		typedef ptrdiff_t difference_type; // almost always ptrdiff_t
		typedef T value_type; // almost always T
		typedef const TreeNode<T>& reference; // almost always T& or const T&
		typedef const TreeNode<T>* pointer; // almost always T* or const T*
		typedef bidirectional_iterator_tag iterator_category;  // usually std::forward_iterator_tag or similar
	};
	void insert(T x);
	Iterator search(T x);
	void remove(T x);
	void preorder();
	void inorder();
	void postorder();
	int totalcount() { return cnt; }
	int leafcount();
	int height();
	void print();
	Iterator min_element() { return Iterator(min(root)); }
	Iterator max_element() { return cnt == 0 ? Iterator(dummy) : Iterator(max(root)->parent); }
	Iterator begin() { return Iterator(min(root)); }
	Iterator end() { return Iterator(dummy); }
};


// Implementation


template<typename T, typename Compare>
TreeNode<T> *BST<T, Compare>::min(TreeNode<T> *node)
{
	if(node == nullptr)
		return node;
	while(node->left)
		node = node->left;
	return node;
}

template<typename T, typename Compare>
TreeNode<T> *BST<T, Compare>::max(TreeNode<T> *node)
{
	if(node == nullptr)
		return node;
	while(node->right)
		node = node->right;
	return node;
}

template<typename T, typename Compare>
TreeNode<T> *BST<T, Compare>::inorder_successor(TreeNode<T> *node)
{
	if(node->right)
		return min(node->right);
	TreeNode<T> *p = node->parent;
	while(p && node == p->right)
	{
		node = p;
		p = p->parent;
	}
	return p;
}

template<typename T, typename Compare>
TreeNode<T> *BST<T, Compare>::inorder_predecessor(TreeNode<T> *node)
{
	if(node->left)
		return max(node->left);
	TreeNode<T> *p = node->parent;
	while(p && node == p->left)
	{
		node = p;
		p = p->parent;
	}
	return p;
}

template<typename T, typename Compare>
void BST<T, Compare>::insert(T x)
{
	if(root == dummy)
	{
		TreeNode<T> *temp = new TreeNode<T>(x);
		temp->right = dummy;
		dummy->parent = temp;
		root = temp;
		++cnt;
	}
	else
	{
		TreeNode<T> *prev = nullptr;
		TreeNode<T> *curr = root;
		while(curr && curr != dummy)
		{
			prev = curr;
			bool lesser = cmp(x, curr->data);
			if(!lesser && !cmp(curr->data, x))
			{
				return;
			}
			if(lesser)
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
		}
		++cnt;
		TreeNode<T> *temp = new TreeNode<T>(x);
		if(cmp(x, prev->data))
		{
			prev->left = temp;
		}
		else
		{
			prev->right = temp;
			if(curr == dummy)
			{
				temp->right = dummy;
				dummy->parent = temp;
			}
		}
		temp->parent = prev;
	}
}

template<typename T, typename Compare>
void BST<T, Compare>::release(TreeNode<T> *root)
{
	if(root)
	{
		release(root->left);
		release(root->right);
		delete root;
	}
	return;
}

template<typename T, typename Compare>
void BST<T, Compare>::printUtil(TreeNode<T> *root, int space) 
{ 
    // Base case 
    if (root == nullptr || root == dummy) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    printUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->data<<"\n"; 
  
    // Process left child 
    printUtil(root->left, space); 
}
 
template<typename T, typename Compare>
// Wrapper over printUtil()
void BST<T, Compare>::print() 
{ 
    // Pass initial space count as 0 
    printUtil(root, 0); 
    printf("\n");
}
