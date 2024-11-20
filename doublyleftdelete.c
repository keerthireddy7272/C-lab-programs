#include <stdio.h>
#include <stdlib.h>

struct node {
int value;
struct node* next;
struct node* prev;
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
printf("%d <-> ", temp->value);
temp = temp->next;
}
printf("NULL\n");
}

NODE insert_end(NODE first, int item) {
NODE new = getnode();
new->value = item;
new->next = NULL;
new->prev = NULL;
if (first == NULL) {
    return new;
}
NODE temp = first;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = new;
new->prev = temp;
return first;
}

NODE insert_left(NODE first, int item, int key) {
NODE new = getnode();
new->value = item;
new->prev = NULL;
new->next = NULL;
if (first == NULL) {
return NULL;
}
NODE current = first;
while (current != NULL && current->value != key) {
    current = current->next;
}
if (current != NULL) {
new->prev = current->prev;
new->next = current;
if (current->prev != NULL) {
current->prev->next = new;
}
else {
first = new;
}
current->prev = new;
return first;
}
else{
printf("Value not found!\n");
return first;
}
}

NODE delete_value(NODE first, int item) {
    NODE current = first;
    if (first == NULL) {
        return NULL;
    }
    while (current != NULL && current->value != item) {
        current = current->next;
    }
    if (current != NULL) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            first = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        return first;
    } else {
        printf("Specified value not found in the linked list!\n");
        return first;
    }
}


int main() {
    NODE first = NULL;
    int choice, value, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the end ");
        printf("2. Insert left of a given key ");
        printf("3. Delete a value ");
        printf("4. Display list ");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                first = insert_end(first, value);
                break;
            case 2:
                printf("Enter value to insert and key to insert left of: ");
                scanf("%d %d", &value, &key);
                first = insert_left(first, value, key);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                first = delete_value(first, value);
                break;
            case 4:
                display(first);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
