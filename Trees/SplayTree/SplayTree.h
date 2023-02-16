#pragma once

#include "SplayNode.h"
#include <iostream>
#include <vector>
#include <sstream>
#include<string>
using namespace std;

class SplayTree
{
public:
    SplayTree() {
        root = nullptr;
    }

    void Insert(int value) {
        Node* node = InsertNode(value);
        Splay(node);
    }

    void Search(int value) {
        Node* result = Search(root, value);
        if (result) {
            Splay(result);
        }
    }

    void Delete(int value) {
        DeleteNode(root, value);
    }

    void Show(string s, bool last) {
        Show(root, s, last);
    }

    string ShowString() {
        return ShowString(root);
    }
    
//private:
    
    Node* root;

    void Show(Node* node, string s, bool last) { //�������, ��������� ������ � ���� ������
        if (node != nullptr) {
            cout << s;
            if (last) {
                cout << "R-";
                s += "  ";
            }
            else {
                cout << "L-";
                s += node->right != nullptr ? "| " : "  ";
            }
            cout << node->value << endl;
            Show(node->left, s, false);
            Show(node->right, s, true);
        }
    }

    void WriteToArray(Node* node, vector<int>& results) { //������� ��� ������ ������ � ������
        if (node != nullptr) {                   //������ �������� ������ �� ����� � ����� � ������
            results.push_back(node->value);
            WriteToArray(node->left, results);
            WriteToArray(node->right, results);
        }
    }

    string ShowString(Node* node) { //������� ��� ������, ������� ������ � ������
        vector<int> results = {};
        WriteToArray(node, results);
        stringstream s; //��� ������ � �������� ������
        for (int i = 0; i < results.size(); i++) {
            if (i == results.size() - 1) {
                s << results[i];
            }
            else {
                s << results[i] << " ";
            }
        }
        return s.str();
    }

    void Splay(Node* node) { //�������� �������� ������ ��� �������� �������� � �����
        while (node->parent) {
            if (!node->parent->parent) {
                if (node == node->parent->left) {
                    // �������� zig
                    RightRotate(node->parent);
                }
                else {
                    // �������� zag
                    LeftRotate(node->parent);
                }
            }
            else if (node == node->parent->left && node->parent == node->parent->parent->left) {
                // �������� zig-zig
                RightRotate(node->parent->parent);
                RightRotate(node->parent);
            }
            else if (node == node->parent->right && node->parent == node->parent->parent->right) {
                // �������� zag-zag
                LeftRotate(node->parent->parent);
                LeftRotate(node->parent);
            }
            else if (node == node->parent->right && node->parent == node->parent->parent->left) {
                // �������� zag-zig
                LeftRotate(node->parent);
                RightRotate(node->parent);
            }
            else {
                // �������� zig-zag
                RightRotate(node->parent);
                LeftRotate(node->parent);
            }
        }
    }

    Node* Search(Node* node, int value) { //����� ��� � ������� ������
        if (node == nullptr || value == node->value) {
            return node;
        }
        if (value < node->value) {
            return Search(node->left, value);
        }
        return Search(node->right, value);
    }

//        y        -->            x
//      /    \   RightRotate    /   \
//     x      c              a       y
//   /    \     LeftRotate        /    \
// a       b       <--           b       c

    Node* RightRotate(Node* node) {
        Node* current = node->left;
        node->left = current->right;
        if (current->right != nullptr) {
            current->right->parent = node;
        }
        current->parent = node->parent;
        if (node->parent == nullptr) {
            root = current;
        }
        else if (node == node->parent->right) {
            node->parent->right = current;
        }
        else {
            node->parent->left = current;
        }
        current->right = node;
        node->parent = current;
        return node;
    }

    Node* LeftRotate(Node* node) {
        Node* current = node->right;
        node->right = current->left;
        if (current->left != nullptr) {
            current->left->parent = node;
        }
        current->parent = node->parent;
        if (node->parent == nullptr) {
            root = current;
        }
        else if (node == node->parent->left) {
            node->parent->left = current;
        }
        else {
            node->parent->right = current;
        }
        current->left = node;
        node->parent = current;
        return node;
    }

    Node* InsertNode(int value) { //�������, ��� � ������� ������
        Node* node = new Node(value);
        if (root == nullptr) {
            root = node;
            return root;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (node->value < current->value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        node->parent = parent;
        if (node->value < parent->value) {
            parent->left = node;
        }
        else if (node->value > parent->value) {
            parent->right = node;
        }
        else {
            delete node;
            return parent;
        }
        return node;
    }

    Node* DeleteNode(Node* node, int value) {
        Node* x = nullptr;
        while (node != nullptr) { //����� ��������
            if (node->value == value) {
                x = node;
            }
            if (node->value <= value) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
        if (x == nullptr) {
            return root;
        }
        Node* tree1 = nullptr;
        Node* tree2 = nullptr;
        Split(x, tree1, tree2); //���������� ������ �� ��� ��������� tree1 � tree2
        if (tree1->left) {
            tree1->left->parent = nullptr;
        }
        root = Join(tree1->left, tree2); //���������� �������� 
        delete tree1;
        return root;
    }

    Node* Join(Node* tree1, Node* tree2) { //���������� ��������, ������������ ��� ��������
        if (!tree1) {
            return tree2;
        }
        if (!tree2) {
            return tree1;
        }
        Node* x = Max(tree1);
        Splay(x);
        x->right = tree2;
        tree2->parent = x;
        return x;
    }

    Node* Split(Node* x, Node* & tree1, Node* & tree2) { //���������� ������ �� ��� ��������� s � t, ������������ ��� ��������
        Splay(x);
        if (x->right) {
            tree2 = x->right;
            tree2->parent = nullptr;
        }
        else {
            tree2 = nullptr;
        }
        tree1 = x;
        tree1->right = nullptr;
        x = nullptr;
        return root;
    }

    Node* Max(Node* node) { //����� ������������� ����� � ������
        if (node == nullptr) {
            return nullptr;
        }
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
};