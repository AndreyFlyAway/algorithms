// ! Remove define before submitting !
// #define local

#ifdef local
struct Node {  
  int value;  
  Node* left = nullptr;  
  Node* right = nullptr;
  Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};  
#endif

#ifndef local
#include "solution.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

/*
Дано BST. Надо вставить узел с заданным ключом. Ключи в дереве могут повторяться.
На вход функции подаётся корень корректного бинарного дерева поиска и ключ, который 
надо вставить в дерево. Осуществите вставку этого ключа. Если ключ уже есть в дереве, 
то его дубликаты уходят в правого сына. Таким образом вид дерева после вставки 
определяется однозначно. Функция должна вернуть корень дерева после вставки вершины.
Ваше решение должно работать за 
O(h), где h –— высота дерева.
На рисунках ниже даны два примера вставки вершин в дерево.
*/


Node* insert(Node* root, int key) {
  if (key < root->value) {
    if (root->left != nullptr) {
      insert(root->left, key);
    } else {
      root->left = new Node {nullptr, nullptr, key};
    }
  } else {
    if (root->right != nullptr) {
      insert(root->right, key);
    } else {
      root->right = new Node {nullptr, nullptr, key};
    }
  }
  return root;
}

#ifdef local
void test() {
    Node node1({nullptr, nullptr, 7});
    Node node2({&node1, nullptr, 8});
    Node node3({nullptr, &node2, 7});
    Node* newHead = insert(&node3, 6);
    assert(newHead->left->value == 6);
    assert(newHead == &node3);
}

int main() {
  test();
}
#endif