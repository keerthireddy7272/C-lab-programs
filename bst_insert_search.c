#include<stdio.h>
#include <stdlib.h>

struct BST {
int data;
struct BST *left;
struct BST *right;
};

typedef struct BST node;

node* create() {
node *temp;
printf("Enter data: ");
temp = (node*)malloc(sizeof(node));
scanf("%d", &temp->data);
temp->left = temp->right = NULL;
return temp;
}

node* insert(node *root, node *temp) {
if (root == NULL) {return temp;}
if (temp->data < root->data) {
if (root->left != NULL)
{root->left = insert(root->left, temp);
}
else {root->left = temp;
}
}
else if (temp->data > root->data) {
if(root->right != NULL)
{root->right = insert(root->right, temp);
}
else {root->right = temp;
}
}
return root;
}

void preorder(node *root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}

void inorder(node *root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

void postorder(node *root) {
if(root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}

int main() {
    node *root = NULL;
    node *temp;
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node ");
        printf("2. Preorder Traverse ");
        printf("3. Inorder Traverse ");
        printf("4. Postorder Traverse ");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                temp = create();
                root = insert(root, temp);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
