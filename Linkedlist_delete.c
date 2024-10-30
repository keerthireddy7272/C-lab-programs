#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node* NODE;

NODE getnode() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return ptr;
}

void display(NODE first) {
    NODE temp = first;
    if (temp == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

NODE insert_beg(NODE first, int value) {
    NODE new_node = getnode();
    new_node->value = value;
    new_node->next = first;
    return new_node;
}

NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }
    NODE temp = first;
    first = first->next;
    free(temp);
    return first;
}

NODE delete_end(NODE first) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }
    if (first->next == NULL) {
        free(first);
        return NULL;
    }

    NODE current = first;
    NODE prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);
    prev->next = NULL;
    return first;
}

NODE delete_value(NODE first, int value) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }

    if (first->value == value) {
        return delete_front(first);
    }

    NODE current = first;
    NODE prev = NULL;

    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found in the list\n");
        return first;
    }

    prev->next = current->next;
    free(current);
    return first;
}

int main() {
    NODE first = NULL;
    int choice, value;

    while (1) {
        printf("Choices:\n");
        printf("1. Insert at beginning 2. Delete from beginning 3. Delete from end 4. Delete by value");
        printf("5. Display the linked list 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                first = insert_beg(first, value);
                break;
            case 2:
                first = delete_front(first);
                break;
            case 3:
                first = delete_end(first);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                first = delete_value(first, value);
                break;
            case 5:
                display(first);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
