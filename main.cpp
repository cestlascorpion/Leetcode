#include "Leetcode208cn/Trie.h"
#include <config.h>

void test() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple");   // 返回 true
    cout << trie.search("app");     // 返回 false
    cout << trie.startsWith("app"); // 返回 true
    trie.insert("app");
    cout << trie.search("app");     // 返回 true
}

int main() {
    test();
    return 0;
}
