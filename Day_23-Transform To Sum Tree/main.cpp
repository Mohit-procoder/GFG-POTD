// problem : https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

// solution :

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
  public:
  int solve(Node * root){
      if(!root)return 0;
      int a = solve(root->left), b = solve(root->right), z = root->data;
       root->data = a+b;
       return a+b+z;
  }
    void toSumTree(Node *root) {
        solve(root);
    }
};