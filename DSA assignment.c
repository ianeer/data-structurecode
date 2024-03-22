//Stephen Omondi Charles-SCT221-0277/2022
//Kungu ian SCT221-0734/2022
//Jeff mark owour SCT221-0440/2022

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
       
    }
    return root;
}


// Function to calculate the height of the BST
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

// Function to print the level and height of a node
void printLevelAndHeight(struct Node* root, int data) {
    int level = 0;
    int height = 0;
    struct Node* current = root;
    while (current != NULL) {
        if (data == current->data) {
            printf("Level: %d\n", level);
            printf("Height: %d\n", height);
            break;
        } else if (data < current->data) {
            current = current->left;
            level++;
            height++;
        } else {
            current = current->right;
            level++;
            height++;
        }
    }
    if (current == NULL) {
        printf("Node not found.\n");
    }
}



int main() {
    int arr[] = {30, 20, 40, 10, 25, 35, 45, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = NULL;
     int i;
    // Creating the BST
    for(i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Deleting a node
    root = deleteNode(root, 20);

    // Printing the height of the BST
    int bstHeight = height(root);
    printf("Height of the BST: %d\n", bstHeight);

    // Printing the level and height of a node
    int nodeData = 40;
    printLevelAndHeight(root, nodeData);

    return 0;
}
