#pragma once

struct AANode
{
    int value;
    int level;
    AANode* left;
    AANode* right;
    AANode* parent;

    AANode(int value) {
        level = 1;
        this->value = value;
        left = right = parent = nullptr;
    }
};

