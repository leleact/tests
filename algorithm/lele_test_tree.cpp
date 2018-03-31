#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
struct Node {
  Node *pleft_child;
  Node *pright_child;
  T data;
};

template <typename T = int>
Node<T> * BuildTree(vector<T> &, int);

template <typename T = int>
void PrintTreeByLevel(Node<T> *);

template<typename T>
int DeepOfTheTree(Node<T> *);

template<typename T>
void PreOrderTree(Node<T> *p_node);

template<typename T>
void InOrderTree(Node<T> *p_node);

template<typename T>
void PostOrderTree(Node<T> *p_node);

template<typename T>
void PreOrderTreeByLoop(Node<T> *p_node);

template<typename T>
void InOrderTreeByLoop(Node<T> *p_node);

template<typename T>
void PostOrderTreeByLoop(Node<T> *p_node);

int main(int argc, char **argv) {
  vector<int> vec;
  const int vec_size = 20;
  for (int i = 0; i < vec_size; ++i) {
    vec.push_back(i);
  }

  srand(time(nullptr));
  int index = 0;
  for (int i = vec_size - 1; i > 0; --i) {
    index = rand() % 2; 
    swap(vec[i], vec[index]);
  }
  index = 1;
  Node<int> *proot = BuildTree<int>(vec, index);
  PrintTreeByLevel(proot);
  int deep = DeepOfTheTree(proot);
  cout << "Deep of The Tree : " << deep << endl;

  cout << "先序遍历: ";
  PreOrderTree(proot);
  cout << endl;
  cout << "中序遍历: ";
  InOrderTree(proot);
  cout << endl;
  cout << "后序遍历: ";
  PostOrderTree(proot);
  cout << endl;
  cout << "先序遍历: ";
  PreOrderTreeByLoop(proot);
  cout << endl;
  cout << "中序遍历: ";
  InOrderTreeByLoop(proot);
  cout << endl;
  cout << "后序遍历: ";
  PostOrderTreeByLoop(proot);
  cout << endl;

  return 0;
}

template <typename T>
Node<T> * BuildTree(vector<T> &vec, int index) {

  if (index > static_cast<int>(vec.size()))
    return nullptr;

  Node<T> *p_node = new Node<T>();
  p_node->data =  vec[index - 1];
  p_node->pleft_child = BuildTree(vec, 2 * index);
  p_node->pright_child = BuildTree(vec, 2 * index + 1);

  return p_node;
}

// 分层遍历
template<typename T>
void PrintTreeByLevel(Node<T> *p_node) {
  vector<Node<T> *> vec;
  if (p_node == nullptr) {
    return;
  }

  vec.push_back(p_node);
  unsigned long  cur = 0;
  unsigned long  last = 1;
  while(cur < vec.size()) {
    last = vec.size();
    while(cur < last) {
      cout << vec[cur]->data << " " ;
      if (vec[cur]->pleft_child)
        vec.push_back(vec[cur]->pleft_child);

      if (vec[cur]->pright_child)
        vec.push_back(vec[cur]->pright_child);
      cur++;
    }
    cout << endl;
  }
}

template<typename T>
int DeepOfTheTree(Node<T> *p_node) {
  if (nullptr == p_node)
    return 0;

  int deep_left_tree = DeepOfTheTree(p_node->pleft_child);
  int deep_right_tree = DeepOfTheTree(p_node->pright_child);
  int deep = deep_left_tree > deep_right_tree ? deep_left_tree : deep_right_tree;

  return deep + 1;
}


template<typename T>
void PreOrderTree(Node<T> *p_node) {
  if (nullptr == p_node)
    return;
  cout << p_node->data << " ";
  PreOrderTree(p_node->pleft_child);
  PreOrderTree(p_node->pright_child);
}

template<typename T>
void InOrderTree(Node<T> *p_node) {
  if (nullptr == p_node)
    return;

  InOrderTree(p_node->pleft_child);
  cout << p_node->data << " ";
  InOrderTree(p_node->pright_child);
}

template<typename T>
void PostOrderTree(Node<T> *p_node) {
  if (nullptr == p_node)
    return;

  PostOrderTree(p_node->pleft_child);
  PostOrderTree(p_node->pright_child);
  cout << p_node->data << " ";
}

template<typename T>
void PreOrderTreeByLoop(Node<T> *p_node) {
  if (nullptr == p_node)
    return;

  stack<Node<T> *> node_stack;
  while(!node_stack.empty() || p_node) {
    while(p_node) {
      cout << p_node->data << " ";
      node_stack.push(p_node);
      p_node = p_node->pleft_child;
    }

    if (!node_stack.empty()) {
      p_node = node_stack.top();
      node_stack.pop();
      p_node = p_node->pright_child;
    }
  }
}

template<typename T>
void InOrderTreeByLoop(Node<T> *p_node) {
  if (nullptr == p_node)
    return;
  stack<Node<T> *> node_stack;
  while(p_node || !node_stack.empty()) {
    while(p_node) {
      node_stack.push(p_node);
      p_node = p_node->pleft_child;
    }

    if (!node_stack.empty()) {
      p_node = node_stack.top();
      cout << p_node->data << " ";
      node_stack.pop();
      p_node = p_node->pright_child;
    }
  }
}

template<typename T>
void PostOrderTreeByLoop(Node<T> *p_node) {
  if (nullptr == p_node)
    return;
  stack<Node<T> *> node_stack;
  Node<T> *pre = nullptr;
  while(p_node || !node_stack.empty()) {
    while(p_node) {
      node_stack.push(p_node);
      p_node = p_node->pleft_child;
    }

    p_node = node_stack.top();
    if (p_node->pright_child == nullptr || p_node->pright_child == pre) {
      cout << p_node->data << " ";
      node_stack.pop();
      pre = p_node;
      p_node = nullptr;
    } else {
      p_node = p_node->pright_child;
    }
  }
}
