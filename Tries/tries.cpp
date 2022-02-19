#include <iostream>
using namespace std;

//Structure for the node

struct Node
{
    Node* links[26];
    bool flag; //Set false as default

    //Functions

    /**
     * @brief This function is used to check whether the Trie contains this key or not
     * 
     * @param ch -> The character of the word
     * @return -> It returns a boolean which tells whether the character is present in the trie or not
     */

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    /**
     * @brief This function is used to insert the new Node to the existing key
     * 
     * @param ch -> The character for which the new Node is inserted
     * @param node -> The new node for the trie
     */

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    /**
     * @brief This function is used to find the node as per the given character
     * 
     * @param ch -> The character
     * @return Node* -> The matching node for the character
     */

    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    /**
     * @brief Set the End object
     * 
     * @return set flag as true
     */

    void setEnd() {
        flag = true;
    }

    /**
     * @brief Get the End object
     * 
     * @return The flag value
     */

    bool getEnd() {
        return flag;
    }
};

//Class For Trie

class Tries {

private:
    Node* root;

public:

    //Constructor

    Tries() {
        root = new Node(); // Set the root
    }

    //Base Functions

    //Insert

    /**
     * @brief This function is used to insert the word as a Trie
     * 
     * @param s -> The word
     */

    void insert(string s) {

        Node* node = root;

        for(int i = 0; i < s.length(); i++) {

            if(!node->containsKey(s[i])) {
                //Insert
                node->put(s[i], new Node());
            }
            
            //Moves to the reference trie
            node = node->get(s[i]);
        }

        node->setEnd();
    }

    /**
     * @brief This function is used to check whether the word is present in Trie or not
     * 
     * @param s -> The word for matching
     * @return A boolean which tells whether the word is present in the trie or not
     */

    bool doesWordMatch(string s) {

        Node* node = root;

        for(int i = 0; i < s.length(); i++) {

            if(!node->containsKey(s[i])) {
                return false;
            }

            node = node->get(s[i]);
        }

        return node->getEnd();
    }

    /**
     * @brief This function is used to check whether the Trie contains the passed prefix or not
     * 
     * @param s -> The prefix string
     * @return A boolean which tells whether the prefix is present in the trie or not
     */

    bool containsPrefix(string s) {

        Node* node = root;

        for(int i = 0; i < s.length(); i++) {

            if(!node->containsKey(s[i])) {
                return false;
            }

            node = node->get(s[i]);
        }

        return true;
    }

};

 //Main Function

int main() {

    Tries* trie = new Tries();
    trie->insert("word");
    cout << trie->doesWordMatch("word") << endl;
    cout << trie->containsPrefix("wo");
    return 0;
}
