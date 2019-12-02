//
// Created by Wang on 2019/12/3.
//

#ifndef LEETCODE_LEETCODE558CN_H
#define LEETCODE_LEETCODE558CN_H

#include "config.h"

class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Leetcode558cn {
public:
    Node *intersect(Node *quadTree1, Node *quadTree2);
};

#endif // LEETCODE_LEETCODE558CN_H
