// Find node in BST that fall in range [a b]
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  Node(int key) : key(key) 
  {
    left = nullptr;
    right = nullptr;
  }

  Node *left;
  Node *right;
  int   key;
};

Node *newNode(int key)
{
  return new Node(key);
}

void findNodes(Node *root, int a, int b, vector<int> &result)
{
  if (!root) return;

  if (root->key >= b)  
  {
    if (root->key == b)
      result.push_back(root->key);
    findNodes(root->left, a, b, result);
    return;
  }
  if (root->key > a && root->key < b) 
  {
    findNodes(root->left, a, b, result);
    result.push_back(root->key);
    findNodes(root->right, a, b, result);
    return;
  }
  if (root->key <= a) 
  {
    if (root->key == a)
      result.push_back(root->key);
    findNodes(root->right, a, b, result);
    return;
  }
}

int main()
{
  Node * root = newNode(3);
  root->left = newNode(2);
  root->right = newNode(4);
  root->left->left = newNode(1);
  root->right->right = newNode(5);

  vector<int> res;
  findNodes(root, 2,4, res);
  for (auto e : res)
    std::cout << e ;
  std::cout << std::endl;

  return 0;
}
