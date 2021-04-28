# Generic-BST
Generic Binary Search Tree implementation using C++ templates and Compare predicate

Bst.h: header file along with implementation - cant separate into .h and .cpp because templates have to be declared & defined in the same file

Client.cpp: client file

# Requirements for T type
1. Default Constructor : new TreeNode<T>(T())
2. Optionally provide binary predicate for < comparision : cmp(x, curr->data)
3. Must provide << operator : cout << *it
