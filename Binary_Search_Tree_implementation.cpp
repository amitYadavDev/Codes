#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
      data = value;
      left = NULL;
      right = NULL;
    }
};

class BTree {
  private: 
  Node *root;
  
  public:
  BTree() {
    root = NULL;
  }
  
  void insert(int value) {
    root = insertNode(root, value);
  }
  
  Node *insertNode(Node *root, int value) {
    if(!root) {
      root = new Node(value);
      return root;
    }
    if(value < root->data) {
       root->left = insertNode(root->left, value);
    }
    else {
       root->right = insertNode(root->right, value);
    }
    return root;
  }
  
  void inOrderTraverse() {
    printTree(root);
  }
  
  void printTree(Node *root) {
      if(!root) return;
      // cout << root->data << " "; // pre-order
      printTree(root->left);
      // cout << root->data << " "; // inordered
      printTree(root->right);
  } 
  
};

int main() {
  BTree tree;
  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(10);
  tree.insert(2);
  
  tree.inOrderTraverse();
}
