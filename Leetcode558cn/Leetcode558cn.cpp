//
// Created by Wang on 2019/12/3.
//

#include "Leetcode558cn.h"

Node *Leetcode558cn::intersect(Node *quadTree1, Node *quadTree2) {
    if (quadTree1->isLeaf) {
        if (quadTree1->val) {
            return quadTree1;
        } else {
            return quadTree2;
        }
    }
    if (quadTree2->isLeaf) {
        if (quadTree2->val) {
            return quadTree2;
        } else {
            return quadTree1;
        }
    }
    Node *topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
    Node *topRight = intersect(quadTree1->topRight, quadTree2->topRight);
    Node *bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    Node *bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val &&
        topRight->val && bottomLeft->val && bottomRight->val) {
        return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
    }
    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
}
