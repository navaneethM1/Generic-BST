# Generic-BST
Generic Binary Search Tree implementation using C++ templates and Compare predicate

# Folder Structure
include
- bst.h - main header file having implementation of BST
- date.h - contains implementation of user defined Date class
- bst_mod.h - contains modified header file (after implementing lower_bound, upper_bound, and equal_range)

client.cpp - client program
client_mod.cpp - new client program making use of lower_bound, upper_bound, and equal_range

# Compile and run
```bash
g++ client.cpp
./a.out
```

# Requirements for T type
1. Default Constructor : new TreeNode\<T>(T())
2. Optionally provide binary predicate for < comparision : cmp(x, curr->data)
3. But must have a < comparision if binary predicate is not explicitly provided : less\<T> requires < to be defined for T type
4. Must provide copy assignment operator : curr->data = temp->data (in remove function)
5. Must provide << operator : cout << *it
