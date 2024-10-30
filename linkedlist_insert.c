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

NODE insert_beg(int item, NODE first) {
NODE new = getnode();
if (new == NULL) return first;
new->value = item;
new->next = first;
return new;
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

NODE insert_pos(NODE first, int item, int pos) {
if (pos < 1) {
    printf("Invalid position\n");
    return first;
}
NODE new = getnode();
new->value = item;
if (pos == 1) {
    new->next = first;
    return new;
}
NODE current = first;
NODE prev = NULL;
int count = 1;
while (count < pos && current != NULL) {
    prev = current;
    current = current->next;
    count++;
}
if (count == pos) {
    new->next = current;
    prev->next = new;
}else{
    printf("Invalid position\n");
    free(new);
}
return first;
}

NODE insert_end(int item, NODE first) {
NODE new = getnode();
if (new == NULL) return first;
new->value = item;
new->next = NULL;
if (first == NULL) {
    return new;
    }
NODE current = first;
while (current->next != NULL) {
    current = current->next;
}
current->next = new;
return first;
}

int main(){
NODE first = NULL;
int item, choice;
while(1){
    printf("Choices:\n1. Insert at beginning 2. Insert at any position 3. Insert at end 4. Display the linked list please 5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &item);
            first = insert_beg(item, first);
            break;
        case 2:
            printf("Enter the value to insert and position: ");
            scanf("%d %d", &item, &choice);
            first = insert_pos(first, item, choice);
            break;
        case 3:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &item);
            first = insert_end(item, first);
            break;
        case 4:
            display(first);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
