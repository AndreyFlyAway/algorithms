/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
struct TrieNode
{
    TrieNode(char val_): val(val_) {}
    char val = '0';
    bool terminal = false;
    std::unordered_map<char, TrieNode*> childes; 

};

class Trie {
public:
    Trie() {
        root = new TrieNode('0');
    } 

    TrieNode* findStart(char c) {
        TrieNode* cur_node = root;
        for(const auto& it: cur_node->childes) {
            if(it.first == c) {
                return it.second;
            }
        }
        return nullptr;
    }

    void insert(string word) {
        TrieNode* cur_node = root; 
        // for(int i = 0 ; i < word.length() ; ++i) {
        for(char c: word) {
            if(cur_node->childes.count(c) == 0) {
                cur_node->childes[c] = new TrieNode(c);
            }
            cur_node = cur_node->childes[c];
        }
        cur_node->terminal = true;
    }
    
    bool search(string word) {
        TrieNode* cur_node = root; 
        for(char c: word) {
            if(cur_node->childes.count(c) == 0) {
                return false;
            }
            cur_node = cur_node->childes[c];
        }
        return true && cur_node->terminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur_node = root;
        for(char c: prefix) {
            if(cur_node->childes.count(c) == 0) {
                return false;
            }
            cur_node = cur_node->childes[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

