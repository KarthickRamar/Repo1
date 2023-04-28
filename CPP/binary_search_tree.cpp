//In BST the first element that is inserted is always the root node.
//For ordered insertion it does not work good as the tree is right balanced

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* ============INSERITON USING RECURSION-============================
// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node in the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}
=====================================================================
*/

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }
    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == NULL) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (val < current->data) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == NULL) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }
    void inorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Preorder traversal of binary search tree (root-left-right)
    void preorderTraversal(Node* node) {
        if (node != NULL) {
            cout << root->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Postorder traversal of binary search tree (left-right-root)
    void postorderTraversal(Node* node) {
        if (node != NULL) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);
    bst.insert(6);
    bst.inorderTraversal(bst.root); // Output: 1 3 5 6 7 9
    bst.preorderTraversal(bst.root);
    bst.postorderTraversal(bst.root);
    return 0;
}
