/* номре посылки: */
/*
Принцип работы:
1. Если искомый элемент находится корне дерева, то происходят следующиее действия 
алгоритма:
    1.1. Если детей нет, то вернуть nullptr.
    1.2. Если правого ребенка нет, то вернуть левый ребенок.
    1.3. Если левого ребенка нет, то вернуть правой ребенок.
    1.3. Если у правого ребенка нет детей, то заменить значение корня значением
         из правого ребенка, удалить правую ссылку у нового корня.
    1.4. Если у правого ребенка есть дети, то в левом поддереве правого ребенка корня
         ищется самый нижний левый элемент, т.к. он будет меньше всех элементов слева 
         в текущем поддереве и боольше всех элементов в правом поддеревее от удаляемого узла.
2. Если искомый элемент не корневой - рекурсивно ищется требуемый узел
    2.1. Если элемент найден в правом поддереве ищется самый нижний левый элемент,
    т.к. он будет меньше всех элементов справа в текущем поддереве и боольше всех
    элементов в правом поддеревее от удаляемого узла.
3. Вернуть указател на корень дерева.

Врмененная сложность:
O(H) - где H - высота дерева.

Пространственна сложность:
O(1) -  дополнительная память выделяться только на переменные стека.
Точнее O(H) - где H - высота дерева (глубина рекурсии).

Доказательство коррекности:
Из пунктов 1.4 и 2.1 принципа работы следует, что удаленный элемент будет будет з
аменен крайнем левым элементом из правого поддерева, либо замене его правым
ребенком - оба случая будут сохранять верную структуру дерева.
*/

#include <iostream>
#include <algorithm>
#include <vector>

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

/* 
Поиск крайнего левого элемента дерева, запоминает его значение, удаляет его.
Возрващает найденное значение.
*/
int find_right(Node* node) {
    int ret;
    Node* nearest_left = node;
    Node** parent_left = &node->left;
    while (nearest_left->left->left != nullptr)
    {
        nearest_left = nearest_left->left;
        parent_left = &node->left;
    }
    ret = nearest_left->left->value;
    nearest_left->left = nearest_left->left->right;
    return ret;
}


/* 
Поиск и удаление требуемого узла, если найден.
*/
void remove_child(Node* node, int key) {
    int ret = 0;
    // parent_node хранит ссылку ссылки, которая указывает на удалемый узел, чтобы
    // после удаления узла у родителя заменить ссылку на новую
    Node** parent_node; 
    if(node == nullptr) {
        return;
    }

    /* следующие два условных оператора проверяет был ли надйен элемент */
    Node* to_delete = nullptr;
    if (node->left != nullptr && node->left->value == key) {
        to_delete = node->left;
        parent_node = &(node->left);
    }
    if (node->right != nullptr && node->right->value == key) {
        to_delete = node->right;
        parent_node = &(node->right);
    }
    if(to_delete != nullptr) { // найден узел для удаления
        if (to_delete->left == nullptr) {
            *parent_node = to_delete->right;
        } else if (to_delete->right == nullptr) {
            *parent_node = to_delete->left;
        } else {
            /* кейс если у правого ребенка удаляемого узла нет детей, то требуется просто 
               заменить значение и удалить этого ребенка. */
            if(to_delete->right->left == nullptr && to_delete->right->right == nullptr) {
                to_delete->value = to_delete->right->value;
                to_delete->right = nullptr;
                return;
            } else {
                /* иначе ищем крайний левый элемент у правого поддерева,
                   берем его значение для текущего узла, и удалем этот
                   крайний левый элемент. */
                if(to_delete->right->left == nullptr) { // если у правого ребенка нет детей, меньше его самого
                    to_delete->right->left = to_delete->left;
                    *parent_node = to_delete->right;
                } else {
                    to_delete->value = find_right(to_delete->right);
                }
                return;
            }
        }
    } else {
        if(node->value > key) {
            remove_child(node->left, key);
        } else {
            remove_child(node->right, key);
        }
        // if (remove_child(node->left, key) != 1) {
        //     ret = remove_child(node->right, key);
        // }
    }
    return;
}

/*
Заменить корень, если это искомый объект.
Возвращает новую ссылку на корень
*/
Node* remove_root(Node* root) {
    Node* ret = root;
    if (root->left == nullptr && root->right != nullptr) {  // если у корня нет детей 
        ret = root->right;
    } else if (root->left != nullptr && root->right == nullptr) { // если у корня нет левого ребеннка
        ret = root->left;
    } else if (root->left == nullptr && root->right == nullptr) { // если у корня нет правого ребеннка
        ret = nullptr;
    } else {
        if (root->right->right == nullptr && root->right->left == nullptr){ // если у правого ребеннка нет детей
            root->value = root->right->value;
            root->right = nullptr;
            ret = root;
        } else if (root->right->left == nullptr){ // если у правого ребеннка нет левого корней
            ret = root->right;
            ret->left = root->left;
        } else { // иначе тот же алгоритм что и при удалении не корневого узла
            root->value = find_right(root->right);
            ret = root;
        }
    }
    return ret;
}

Node* remove(Node* root, int key) {
    Node* ret = root;
    if (root != nullptr) {
        if(root->value == key) {
            ret = remove_root(root);
        } else {
            remove_child(root, key);
        }
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
    {
        Node node1({nullptr, nullptr, 2});
        Node node2({&node1, nullptr, 3});
        Node node3({nullptr, &node2, 1});
        Node node4({nullptr, nullptr, 12});
        Node node5({nullptr, &node4, 11});
        Node node6({nullptr, &node5, 10});
        Node node7({&node3, &node6, 5});
        Node* newHead = remove(&node7, 5);
        assert(newHead->value == 10);
        assert(newHead->left == &node3);
        assert(newHead->right == &node5);
    }
    {
        Node node7({nullptr, nullptr, 44});
        Node node6({nullptr, &node7, 33});
        Node node5({nullptr, nullptr, 14});
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({&node5, &node6, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 21);
        assert(newHead->value == 10);
        assert(newHead->left == &node1);
        assert(newHead->right == &node6);
        assert(newHead->right->left == &node5);
    }
    {
        Node node7({nullptr, nullptr, 44});
        Node node6({nullptr, &node7, 33});
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({nullptr, &node6, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 21);
        // std::cout << newHead->right->right->value << std::endl;
        assert(newHead->value == 10);
        assert(newHead->left == &node1);
        assert(newHead->right == &node6);
        assert(newHead->right->right == &node7);
        assert(newHead->right->left == nullptr);
    }
    {
        Node node7({nullptr, nullptr, 44});
        Node node6({nullptr, &node7, 33});
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({nullptr, &node6, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 10);
        // std::cout << newHead->right->value << std::endl;
        assert(newHead->value == 21);
        assert(newHead->left == &node1);
        assert(newHead->right == &node6);
        assert(newHead->right->right == &node7);
        assert(newHead->right->left == nullptr);
    }
    {
        Node node7({nullptr, nullptr, 44});
        Node node6({nullptr, &node7, 33});
        Node node4({nullptr, nullptr, 9});
        Node node3({nullptr, nullptr, 4});
        Node node2({nullptr, &node6, 21});
        Node node1({&node3, &node4, 6});
        Node node0({&node1, &node2, 10});
        Node* newHead = remove(&node0, 44);
        // std::cout << newHead->right->value << std::endl;
        assert(newHead->value == 10);
        assert(newHead->left == &node1);
        assert(newHead->right == &node2);
        assert(newHead->right->right == &node6);
        assert(newHead->right->right->right == nullptr);
    }
    {
        Node node4({nullptr, nullptr, 27});
        Node node3({nullptr, &node4, 22});
        Node node2({&node3, nullptr, 33});
        Node node1({nullptr, nullptr, 7});
        Node node0({&node1, &node2, 14});
        Node* newHead = remove(&node0, 14);
        std::cout << newHead->value << std::endl;
        std::cout << newHead->left->value << std::endl;
        std::cout << newHead->right->value << std::endl;
        // std::cout << newHead->right->right << std::endl;
        std::cout << newHead->right->left->value << std::endl;
        // assert(newHead->value == 33);
        // assert(newHead->right->left->value == 22);
        // assert(newHead->left == nullptr);
    }
}

int main() {
  test();
}
#endif