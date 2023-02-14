#pragma once

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node *parent;

    Node(int value) {
        this->value = value;
        left = right = parent = nullptr;
    }
};

