// problem: https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1

// solution:

#include <bits/stdc++.h>
using namespace std;

// Structure of Binary Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    void ans(Node *r, int &anss, int curr)
    {
        if (!r)
            return;
        if (r->left && r->left->data - 1 == r->data)
        {
            anss = max(anss, curr + 1);
            ans(r->left, anss, curr + 1);
        }
        else
            ans(r->left, anss, 0);
        if (r->right && r->right->data - 1 == r->data)
        {
            anss = max(anss, curr + 1);
            ans(r->right, anss, curr + 1);
        }
        else
            ans(r->right, anss, 0);
    }
    int longestConsecutive(Node *root)
    {
        int anss = -1, curr = 0;
        ans(root, anss, curr);
        return anss == -1 ? -1 : 1 + anss;
    }
};

// Medium marked easy question

// time complexity : O(n) , we visit each node only once
// space complexity : O(height of tree) , due to stack calls (recursion stuff)