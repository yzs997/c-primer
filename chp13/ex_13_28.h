#include <string>

#pragma once

class TreeNode
{
public:
	TreeNode(const std::string s = std::string()) : value(s), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
	TreeNode &operator=(const TreeNode &rhs);
	~TreeNode();
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree &rhs) : root(new TreeNode(*rhs.root)) {}
	BinStrTree &operator=(const BinStrTree &rhs);
	~BinStrTree() { delete root; }
private:
	TreeNode *root;
};
inline TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
	++*rhs.count;
	if (--*count == 0)
	{
		delete count;
		delete left;
		delete right;
	}
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
}

inline TreeNode::~TreeNode()
{
	if (--*count == 0)
	{
		delete count;
		delete left;
		delete right;
	}
}

inline
BinStrTree &BinStrTree::operator=(const BinStrTree &rhs)
{
	TreeNode *new_node = new TreeNode(*rhs.root);
	delete root;
	root = new_node;
	return *this;
}
