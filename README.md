# Generic-BST
Generic Binary Search Tree implementation using C++ templates and Compare predicate

Bst.h: header file along with implementation - cant separate into .h and .cpp because templates have to be declared & defined in the same file

Client.cpp: client file

# Note
print function and printUtil function were copied from gfg!!

# Ref
1. 1_acc.cpp: sir’s code which shows how to implement Iterator class
2. 1_set.cpp: sir’s code which shows how to give a custom compare type
3. Bst.c: 3rd semester’s bst code - has logic for insert, remove, search, height, etc

# Requirements for T type
1. Default Constructor : new TreeNode<T>(T())
2. Optionally provide binary predicate for < comparision : cmp(x, curr->data)
3. Must provide << operator : cout << *it
