/*
Дано бинарное дерево поиска, в котором хранятся ключи. Ключи — уникальные целые числа.
Найдите вершину с заданным ключом и удалите её из дерева так, чтобы дерево осталось 
корректным бинарным деревом поиска. Если ключа в дереве нет, то изменять дерево не надо.
На вход вашей функции подаётся корень дерева и ключ, который надо удалить. Функция
должна вернуть корень изменённого дерева. Сложность удаления узла должна составлять 
O(h), где h –— высота дерева. 

Создавать новые вершины (вдруг очень захочется) нельзя
*/

#ifndef REMOTE_JUDGE
struct Node {  
  int value;  
  Node* left = nullptr;  
  Node* right = nullptr;
  Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};  
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>
#include <iostream>
#include <string>

// Node* remove_child(Node* node, int key) {
//     Node* ret;
//     if (node == nullptr) {
//         ret = nullptr;
//     } else {
//         if (node->value == key) {
//             if(node->right == nullptr) { 
//                 return node->left;
//             } else {
//                 if (node->right->left == nullptr) {
//                     node->right->left = node;
//                     ret = node->right;
//                 } else {
//                     node->value = value_to_replace(node->right);
//                 }
//             }
//         } else if (key > node->value) {
//             ret = remove_child(node->right, key);
//         } else if (key < node->value) {
//             ret = remove_child(node->left, key);
//         }
//     }
//     return ret;
// }

int find_right(Node* node) {
    int ret;
    Node* nearest_left = node;
    while (nearest_left->left->left != nullptr)
    {
        nearest_left = nearest_left->left;
    }
    ret = nearest_left->left->value;
    nearest_left->left = nullptr;
    return ret;
}

void remove_child(Node* node, int key) {
    Node** parent_node;
    if(node == nullptr) {
        return;
    }
    Node* to_delete = nullptr;
    if (node->left != nullptr && node->left->value == key) {
        to_delete = node->left;
        parent_node = &(node->left);
    }
    if (node->right != nullptr && node->right->value == key) {
        to_delete = node->right;
        parent_node = &(node->right);
    }
    if(to_delete != nullptr) {
        if (to_delete->left == nullptr) {
            *parent_node = to_delete->right;
        } else if (to_delete->right == nullptr) {
            *parent_node = to_delete->left;
        } else {
            if(to_delete->right->left == nullptr && to_delete->right->right == nullptr) {
                to_delete->value = to_delete->right->value;
                to_delete->right = nullptr;
                return;
            } else {
                to_delete->value = find_right(to_delete->right);
            }
        }
        return;
    } else {
        remove_child(node->left, key);
        remove_child(node->right, key);
    }
    // return;
}


Node* remove_root(Node* root) {
    Node* ret = root;
    if (root->left == nullptr && root->right != nullptr) {
        ret = root->right;
    } else if (root->left != nullptr && root->right == nullptr) {
        ret = root->left;
    } else if (root->left == nullptr && root->right == nullptr) {
        ret = nullptr;
    } else {
        if (root->right->right == nullptr && root->right->left == nullptr){
            root->value = root->right->value;
            root->right = nullptr;
            ret = root;
        } else if (root->right->left == nullptr){
            ret = root->right;
            ret->left = root->left;
        } else {
            root->value = find_right(root->right);
            ret = root;
        }
    }
    return ret;
}

Node* remove(Node* root, int key) {
    Node* ret = root;
    if(root->value == key) {
        // if (root->left == nullptr && root->right != nullptr) {
        //     ret = root->right;
        // } else if (root->left != nullptr && root->right == nullptr) {
        //     ret = root->left;
        // } else if (root->left == nullptr && root->right == nullptr) {
        //     ret = nullptr;
        // } else {
        //     remove_child(root, key);
        // }
        // } else {
        //     Node* cur_res = remove_child(root->left, key);
        // }
        ret = remove_root(root);
    } else {
        remove_child(root, key);
    }
    return ret;
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({nullptr, nullptr, 2});
        Node node2({&node1, nullptr, 3});
        Node node3({nullptr, &node2, 1});
        Node node4({nullptr, nullptr, 6});
        Node node5({&node4, nullptr, 8});
        Node node6({&node5, nullptr, 10});
        Node node7({&node3, &node6, 5});
        Node* newHead = remove(&node7, 10);
        assert(newHead->value == 5);
        assert(newHead->right == &node5);
        assert(newHead->right->value == 8);
    }
    {
        Node node1({nullptr, nullptr, 2});
        Node node2({&node1, nullptr, 3});
        Node node3({nullptr, &node2, 1});
        Node node4({nullptr, nullptr, 6});
        Node node5({&node4, nullptr, 8});
        Node node6({&node5, nullptr, 10});
        Node node7({&node3, &node6, 5});
        Node* newHead = remove(&node7, 3);
        assert(newHead->value == 5);
        assert(newHead->right == &node6);
        assert(newHead->left->right == &node1);
    }
    {
        Node node1({nullptr, nullptr, 2});
        Node node2({&node1, nullptr, 3});
        Node node3({nullptr, &node2, 1});
        Node node6({nullptr, nullptr, 10});
        Node node7({&node3, &node6, 5});
        Node* newHead = remove(&node7, 10);
        assert(newHead->value == 5);
        assert(newHead->right == nullptr);
        // assert(newHead->right->value == 8);
    }
    {
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({nullptr, nullptr, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 10);
        assert(newHead->value == 21);
        assert(newHead->left == &node1);
        assert(newHead->right == nullptr);
    }
    {
        Node node6({nullptr, nullptr, 33});
        Node node5({nullptr, nullptr, 14});
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({&node5, &node6, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 10);
        assert(newHead->value == 14);
        assert(newHead->left == &node1);
        assert(newHead->right == &node2);
    }
    {
        Node node3({nullptr, nullptr, 33});
        Node node2({nullptr, nullptr, 14});
        Node node1({&node2, &node3, 21});
        Node node0({nullptr, &node1, 10});
        Node* newHead = remove(&node0, 10);
        assert(newHead->value == 21);
        assert(newHead->left == &node2);
        assert(newHead->right == &node3);
    }
    {
        Node node3({nullptr, nullptr, 33});
        Node node2({nullptr, nullptr, 14});
        Node node1({&node2, &node3, 21});
        Node node0({&node1, nullptr, 44});
        Node* newHead = remove(&node0, 44);
        assert(newHead->value == 21);
        assert(newHead->left == &node2);
        assert(newHead->right == &node3);
    }
    {
        Node node6({nullptr, nullptr, 33});
        Node node5({nullptr, nullptr, 14});
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({&node5, &node6, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 4);
        assert(newHead->value == 10);
        assert(newHead->left == &node1);
        assert(newHead->right == &node2);
        assert(newHead->left->right == &node4);
        assert(newHead->left->left == nullptr);
    }
    {
        Node node6({nullptr, nullptr, 33});
        Node node5({nullptr, nullptr, 14});
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({&node5, &node6, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 4);
        assert(newHead->value == 10);
        assert(newHead->left == &node1);
        assert(newHead->right == &node2);
        assert(newHead->left->right == &node4);
        assert(newHead->left->left == nullptr);
    }
}

int main() {
  test();
}
#endif