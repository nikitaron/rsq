#pragma once
#include <vector>
struct node
{
	int summa, LeftPos, RightPos, add_value;// summa - is responsible for the amount, LeftPos - left border, RightPos - right border 
	node* Left, * Right; // Left - left subtree, Right - right 
};

node* build(std::vector<int>&, int, int);

int sum(node*, int, int);

void update(node*, int, int);

void add(node*, int, int, int);

void print(node*, int);
