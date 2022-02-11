#include <iostream>
using namespace std;

class BinaryTreeNode {

public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

//Create Tree

/**
 * @brief Create a Node object
 * 
 * @param data -> The node data
 * @return BinaryTreeNode* 
 */

BinaryTreeNode* createNode(int data) {
    BinaryTreeNode* node = new BinaryTreeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Traversals

/**
 * @brief This function is used to traverse the tree in pre order
 * 
 * @param root -> The root of the node
 */

void preorder(BinaryTreeNode* root) { 

    // Root -> Left -> Right

    if(root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

/**
 * @brief This function is used to traversethe root in the post order
 * 
 * @param root -> The root of the node
 */

void postOrder(BinaryTreeNode* root) {
    //Left -> Right -> Root

    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

/**
 * @brief This function is used to traverse the tree in InOrder
 * 
 * @param root -> The root of the node
 */

void inOrder(BinaryTreeNode* root) {

    //Left -> Root -> Right

    //      1
    //    /   \
    //   2     5
    //  / \
    // 3   4

    if(root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    //3 2 4 1 5

}

//Searching

/**
 * @brief This function is used to search the value in the binary search tree iteratively
 * 
 * @param root -> The root of the tree
 * @param key -> The matching position or the key
 * @return -> A boolean which tells whether the search value is present in the tree or not
 */

bool isSearchedValuePresentIterative(BinaryTreeNode* root, int key) {

    while(root != NULL) {

        if(root->data == key) {
            return true;
        } else if(key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return false;
}

/**
 * @brief This function is used to search the binary tree recursively
 * 
 * @param root -> The root of the node
 * @param key -> The key to be matched in the tree
 * @return A boolean which tells whether the key is present in the search tree or not
 */

bool isSearchedValuePresentRec(BinaryTreeNode* root, int key) {
    
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    } else if(key < root->data) {
        return isSearchedValuePresentRec(root->left, key);
    } else {
       return isSearchedValuePresentRec(root->right, key);
    }

    return false;
}

// Check for BST

/**
 * @brief This function is used to check if the given binary tree is a binary search tree or not
 * 
 * @param root -> The root of the tree
 * @return A boolean which tells whether the tree is a BST or not 
 */

bool isBinarySearchTree(BinaryTreeNode* root) {

    //      8
    //    /   \
    //   5     9
    //  / \
    // 3   6

    static BinaryTreeNode* prev = NULL;

    if(root == NULL) {
        return true;
    }

    if(!isBinarySearchTree(root->left)) {
        return false;
    }

    if(prev != NULL && prev->data >= root->data) {
        return false;
    }

    prev = root;
    return isBinarySearchTree(root->right);
}

//Main Function

/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {

    BinaryTreeNode* root = createNode(8);
    BinaryTreeNode* sub1 = createNode(5);
    BinaryTreeNode* sub2 = createNode(3);
    BinaryTreeNode* sub3 = createNode(6);
    BinaryTreeNode* sub4 = createNode(9);

    //      1
    //    /   \
    //   2     5
    //  / \
    // 3   4

    root->left = sub1;
    root->right = sub4;

    sub1->left = sub2;
    sub1->right = sub3;   

    cout << "PreOrder ->" << endl;
    preorder(root);
    cout << endl;
    cout << "PostOrder ->" << endl;
    postOrder(root);
    cout << endl;
    cout << "InOrder ->" << endl;
    inOrder(root); 
    cout << endl;
    cout << "Is BST ->" << endl;
    cout << isBinarySearchTree(root) << endl;
    cout << "Is Searched Recursive ->" << endl;
    cout << isSearchedValuePresentRec(root, 13) << endl;
     cout << "Is Searched Iterative ->" << endl;
    cout << isSearchedValuePresentIterative(root, 13) << endl;
    return 0;
}
