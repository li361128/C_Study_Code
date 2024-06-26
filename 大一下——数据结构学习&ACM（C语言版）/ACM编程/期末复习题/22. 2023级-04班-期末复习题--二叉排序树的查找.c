#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) {  // If the tree is empty, create a new node
        return createNode(data);
    }
    if (data < root->data) {  // If the data is less, insert in the left subtree
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {  // If the data is more, insert in the right subtree
        root->right = insertNode(root->right, data);
    }
    return root;  // Return the unchanged root pointer
}

// Function to search for a node in the BST
int searchNode(Node* root, int key) {
    if (root == NULL) {
        return 0;  // Return 0 if the node is not found
    }
    if (root->data == key) {
        return 1;  // Return 1 if the node is found
    }
    if (key < root->data) {
        return searchNode(root->left, key);  // Search in the left subtree
    } else {
        return searchNode(root->right, key);  // Search in the right subtree
    }
}

// Main function
int main() {
    int n, i, key;
    Node *root = NULL;

    printf("输入二叉树的结点个数:\n");
    scanf("%d", &n);  // Input the number of nodes

    printf("输入各个结点:\n");
    for (i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);  // Input the node values
        root = insertNode(root, value);  // Insert each value into the BST
    }

    printf("输入查找结点:\n");
    scanf("%d", &key);  // Input the key to be searched

    if (searchNode(root, key)) {
        printf("查找成功\n");
    } else {
        printf("查找失败\n");
    }

    return 0;
}

