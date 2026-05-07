// problem : https://www.geeksforgeeks.org/problems/check-if-subtree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
class Solution
{
public:
    bool same(Node *a, Node *b)
    {
        if (a == NULL && b == NULL)
            return true;
        if (a == NULL || b == NULL)
            return false;

        return a->data == b->data &&
               same(a->left, b->left) &&
               same(a->right, b->right);
    }

    bool isSubTree(Node *root1, Node *root2)
    {
        if (root2 == NULL)
            return true;
        if (root1 == NULL)
            return false;

        if (same(root1, root2))
            return true;

        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};