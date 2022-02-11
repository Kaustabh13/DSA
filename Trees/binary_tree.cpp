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

//Main Function

/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {

    BinaryTreeNode* root = createNode(1);
    BinaryTreeNode* sub1 = createNode(2);
    BinaryTreeNode* sub2 = createNode(3);
    BinaryTreeNode* sub3 = createNode(4);
    BinaryTreeNode* sub4 = createNode(5);

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

    return 0;
}
