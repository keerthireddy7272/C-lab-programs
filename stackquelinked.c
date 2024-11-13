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

NODE insert_end(int item, NODE first) {
    NODE new = getnode();
    if (new == NULL) return first;
    new->value = item;
    new->next = NULL;
    if (first == NULL) return new;
    NODE current = first;
    while (current->next != NULL) current = current->next;
    current->next = new;
    return first;
}

NODE delete_end(NODE first) {
    if (first == NULL) {
        printf("Stack underflow\n");
        return NULL;
    }
    if (first->next == NULL) {
        printf("Popped value: %d\n", first->value);
        free(first);
        return NULL;
    }
    NODE current = first, prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    printf("Popped value: %d\n", current->value);
    free(current);
    prev->next = NULL;
    return first;
}

NODE delete_first(NODE first) {
    if (first == NULL) {
        printf("Queue underflow\n");
        return NULL;
    }
    NODE temp = first;
    first = first->next;
    printf("Dequeued value: %d\n", temp->value);
    free(temp);
    return first;
}

int main() {
NODE list = NULL;
int choice, item;

while (1) {
    printf("\nMenu:\n");
    printf("1. Push to Stack  ");
    printf("2. Pop from Stack  ");
    printf("3. Enqueue to Queue  ");
    printf("4. Dequeue from Queue  ");
    printf("5. Display Stack  ");
    printf("6. Display Queue  ");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &item);
                list = insert_end(item, list);
                break;

            case 2:
                if (list == NULL) {
                    printf("Stack underflow\n");
                } else {
                    list = delete_end(list);
                }
                break;

            case 3:
                printf("Enter value to enqueue: ");
                scanf("%d", &item);
                list = insert_end(item, list);
                break;

            case 4:
                list = delete_first(list);
                break;

            case 5:
                printf("Stack (from top to bottom): ");
                display(list);
                break;

            case 6:
                printf("Queue (front to rear): ");
                display(list);
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
