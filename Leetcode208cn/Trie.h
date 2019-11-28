//
// Created by Wang on 2019/11/21.
//

#ifndef LEETCODE_TRIE_H
#define LEETCODE_TRIE_H

#include "config.h"

class Trie {
public:
    enum {
        PTR_LEN = 26
    };

public:
    struct node {
        bool end;
        node *ptr[PTR_LEN];

        node() : end(false) {
            for (auto &p : ptr) {
                p = nullptr;
            }
        }
    };

public:
    /** Initialize your data structure here. */
    Trie() : root(new node) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        int idx = 0;
        node *pre = root; // not null
        node *cur = pre->ptr[word[idx] - 'a'];  // maybe null
        while (true) {
            if (cur == nullptr) {
                pre->ptr[word[idx] - 'a'] = new node;
                cur = pre->ptr[word[idx] - 'a'];
            }
            ++idx;
            if (idx == word.size()) break;
            pre = cur;
            cur = cur->ptr[word[idx] - 'a'];
        }
        cur->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int idx = 0;
        node *pre = root; // not null
        node *cur = pre->ptr[word[idx] - 'a'];  // maybe null
        while (true) {
            ++idx;
            if (idx == word.size()) break;
            if (cur == nullptr) break;
            pre = cur;
            cur = pre->ptr[word[idx] - 'a'];
        }
        return idx == word.size() && cur != nullptr && cur->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int idx = 0;
        node *pre = root; // not null
        node *cur = pre->ptr[prefix[idx] - 'a'];  // maybe null
        while (true) {
            ++idx;
            if (idx == prefix.size()) break;
            if (cur == nullptr) break;
            pre = cur;
            cur = pre->ptr[prefix[idx] - 'a'];
        }
        return idx == prefix.size() && cur!= nullptr;
    }

private:
    node *root;
};

#endif //LEETCODE_TRIE_H
