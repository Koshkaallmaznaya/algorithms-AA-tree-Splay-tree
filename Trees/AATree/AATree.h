#pragma once

#include "AANode.h"
#include <iostream>
#include <vector>
#include <sstream>
#include<string>
using namespace std;

class AATree
{
public:
    AATree() {
        root = nullptr;
    }

    AANode* Insert(int value) {
        root = Insert(root, value);
        return root;
    }

    AANode* Search(int value) {
        return Search(root, value);
    }

    AANode* Delete(int value) {
        return Delete(root, value);
    }

    void Show(string s, bool last) {
        Show(root, s, last);
    }

    string ShowString() { //������� ��� ������ cout, ������� ������ � ������
        return ShowString(root);
    }

private:
    AANode* root;

    void Show(AANode* node, string s, bool last) { //�������, ��������� ������ � ���� ������
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

    void WriteToArray(AANode* node, vector<int>& results) { //������� ��� ������ ������ � ������
        if (node != nullptr) {                     //������ �������� ������ �� ����� � ����� � ������
            results.push_back(node->value);
            WriteToArray(node->left, results);
            WriteToArray(node->right, results);
        }
    }

    string ShowString(AANode* node) { //������� ��� ������, ������� ������ � ������
        vector<int> results = {};
        WriteToArray(node, results);
        stringstream ss; //��� ������ � �������� ������
        for (int i = 0; i < results.size(); i++) {
            if (i == results.size() - 1) {
                ss << results[i];
            }
            else {
                ss << results[i] << " ";
            }
        }
        return ss.str();
    }

    AANode* Search(AANode* node, int value) {
        if (node == nullptr || value == node->value) {
            return node;
        }
        if (value < node->value) {
            return Search(node->left, value);
        }
        return Search(node->right, value);
    }

    AANode* Insert(AANode* node, int value) {
        if (node == nullptr) {
            AANode* node = new AANode(value);
            return node;
        }
        else if (value < node->value) {
            node->left = Insert(node->left, value);
        }  
        else if (value > node->value) {
            node->right = Insert(node->right, value);
        }          
        node = Skew(node);
        node = Split(node);
        return node;
    }

    AANode* Skew(AANode* node) { //�������, ������� ���� ����� �������������� ����� � ������� ���
        if (node == nullptr) {
            return nullptr;
        }
        else if (node->left == nullptr) {
            return node;
        }
        else if (node->left->level == node->level) {
            AANode* k = node->left;
            node->left = k->right;
            k->right = node;
            node = k;
            return node;
        }
        else {
            return node;
        }
    }

    AANode* Split(AANode* node) { //�������, ������� ���� � ������� ��� ���������������� �������������� ������ �����
        if (node == nullptr) {
            return nullptr;
        }
        else if (node->right == nullptr || node->right->right == nullptr) {
            return node;
        }
        else if (node->level == node->right->right->level) {
            AANode* k = node->right;
            node->right = k->left;
            k->left = node;
            node = k;
            node->level = node->level + 1;
            return node;
        }
        else {
            return node;
        }
    }

    AANode* Delete(AANode* node, int value) { //�������� ��������
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) { //����� ������� ��������
            node->left = Delete(node->left, value);
        }
        else if (value > node->value) {
            node->right = Delete(node->right, value);
        }
        else { //������� ������
            if (node->left == nullptr && node->right == nullptr) {
                delete(node);
                node = nullptr;
                return nullptr;
            }
            AANode* l;
            if (node->left == nullptr) {
                l = Successor(node);
                node->value = l->value;
                node->right = Delete(node->right, l->value);
            }
            else {
                l = Predecessor(node);
                node->value = l->value;
                node->left = Delete(node->left, l->value);
            }
        } //������������ � ���������� ��������� level
        node = Change_level(node);
        node = Skew(node);
        node->right = Skew(node->right);
        if (node->right != nullptr && node->right->right != nullptr) {
            node->right->right = Skew(node->right->right);
        }
        node = Split(node);
        node->right = Split(node->right);
        return node;
    }

    AANode* Predecessor(AANode* node) { //����� ����������� �������� � ����� ���������
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    AANode* Successor(AANode* node) { //����� ����������� �������� � ������ ���������
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    AANode* Change_level(AANode*& node) {  //�������, ������� ��������� �������� level � ����
        if (!node) {
            return nullptr;
        }
        int left;
        if (node->left == nullptr) {
            left = 0;
        }
        else {
            left = node->left->level;
        }
        int right;
        if (node->right == nullptr) {
            right = 0;
        }
        else {
            right = node->right->level;
        }
        int ShouldBe = Min(left, right) + 1;
        if (ShouldBe < node->level) {
            node->level = ShouldBe;
            if (node->right && ShouldBe < node->right->level) {
                node->right->level = ShouldBe;
            }
        }
        return node;
    }

    int Min(int left, int right) {
        if (left <= right) {
            return left;
        }
        return right;
    }
};