#include <vector>
#include <iostream>
#include "Header.h"

node* build(std::vector<int>& a, int L, int R) // build tree 
{
    /*if left side
      equals to the right -
      build a tree from one vertex */
    if (L == R)
    {
        node* obj = new node; // allocate dynamic memory for obj 

        obj->summa = a[L]; // assign summa the value of the left border 
        obj->add_value = 0;
        obj->Left = obj->Right = NULL; // assign left and right branches 0 
        obj->LeftPos = obj->RightPos = L; // assign the left and right borders to the left index 
        return obj;
    }

    int middle = (L + R) / 2; // find the middle of the tree 

    node* Left = build(a, L, middle); // build the left branch 
    node* Right = build(a, middle + 1, R); // build the right branch 

    node* tree = new node; // create the resulting Tree 
    tree->Left = Left;     // with the left 
    tree->Right = Right;   // and the right subtree 

    tree->summa = Left->summa + Right->summa;
    tree->add_value = 0;
    tree->LeftPos = Left->LeftPos;
    tree->RightPos = Right->RightPos;

    return tree;
}

int sum(node* tree, int L, int R) // tree sum 
{
    if (L < tree->LeftPos) // cut off in two "if" 
        L = tree->LeftPos; // segment [L; R] thus 

    if (R > tree->RightPos) // so that it is included in the segment 
        R = tree->RightPos; //[tree->LeftPos; tree->RightPos],
                  // which corresponds to the top of the tree "tree"
    if (L > R) // if the resulting segment turns out to be empty, then exit
        return 0;

    if ((tree->LeftPos == L) && (tree->RightPos == R)) // if the root of the tree tree matches the segment [L..R], 
        return tree->summa; // then return the value of the amount stored in this root

    int LeftSum = sum(tree->Left, L, R); // calculate the sum of the left subtree 
    int RightSum = sum(tree->Right, L, R); // calculate the sum of the right subtree

    return LeftSum + RightSum; // return the left subtree + right 
}

void update(node* tree, int L, int R)
{
    if (L < tree->LeftPos)
        L = tree->LeftPos;

    if (R > tree->RightPos)
        R = tree->RightPos;

    if (L > R)
        return;

    if ((tree->LeftPos == L) && (tree->RightPos == R) && (L == R))
        return;

    update(tree->Left, L, R); // modify recursively 
    update(tree->Right, L, R);// left and right subtree 

    tree->add_value = tree->Left->add_value + tree->Right->add_value;
}

void add(node* tree, int L, int R, int value) // add value to existing items value
{
    if (L < tree->LeftPos)
        L = tree->LeftPos;

    if (R > tree->RightPos)
        R = tree->RightPos;

    if (L > R)
        return;

    if ((tree->LeftPos == L) && (tree->RightPos == R) && (L == R))
    {
        tree->add_value += value;
        return;
    }
    add(tree->Left, L, R, value);
    add(tree->Right, L, R, value);
}

void print(node* curNode, int depth) { // the input is given the current vertex and the depth at which this vertex 

    if (curNode)
    {
        print(curNode->Left, depth + 1);

        for (int i = 0; i < depth * 4; i++)
        {
            std::cout << ' ';
        }

        std::cout << curNode->summa + curNode->add_value << std::endl;
        print(curNode->Right, depth + 1);
    }
}