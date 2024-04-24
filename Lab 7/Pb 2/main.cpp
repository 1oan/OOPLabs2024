#include <stdio.h>
#include "Template.h"
#include <iostream>

using namespace std;

int main()
{
	Tree<int> copac(4);

	Node<int>* node1 = nullptr;
	Node<int>* node2 = nullptr;

	copac.add_node(nullptr, 10);
	copac.add_node(copac.root, 20);
	copac.add_node(copac.root, 30);
	copac.add_node(copac.root, 40);

	node1 = copac.root->children;
	node2 = copac.root->children+1;

	copac.add_node(node1, 15);
	copac.add_node(node1, 25);

	copac.add_node(node2, 35);
	copac.add_node(node2, 45);


	copac.sort(copac.root,sortare);
	copac.delete_node(node1);

	return 0;
}