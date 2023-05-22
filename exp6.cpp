// A set of strings are saved in a data structure. Represent the string in form of non-linear data structurein such a way that searching takes minimal time.


#include <iostream>
#include <unordered_map>

// Trie Node
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

// Trie class
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        // Delete the trie nodes recursively
        deleteTrie(root);
    }
    
    void insert(const std::string& word) {
        TrieNode* curr = root;
        
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            
            curr = curr->children[c];
        }
        
        curr->isEndOfWord = true;
    }
    
    bool search(const std::string& word) {
        TrieNode* curr = root;
        
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                return false;  // Prefix not found
            }
            
            curr = curr->children[c];
        }
        
        return curr != nullptr && curr->isEndOfWord;  // Full word found
    }
    
private:
    TrieNode* root;
    
    void deleteTrie(TrieNode* node) {
        if (node == nullptr) {
            return;
        }
        
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        
        delete node;
    }
};

int main() {
    Trie trie;
    
    // Inserting strings into the trie
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");
    trie.insert("grape");
    
    // Searching for strings in the trie
    std::cout << std::boolalpha;
    std::cout << trie.search("apple") << std::endl;   // Output: true
    std::cout << trie.search("banana") << std::endl;  // Output: true
    std::cout << trie.search("kiwi") << std::endl;    // Output: false
    
    return 0;
}
