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

NODE concatenate(NODE first1, NODE first2) {
    if (first1 == NULL) return first2;
    if (first2 == NULL) return first1;
    NODE last1 = first1;
    while (last1->next != NULL) last1 = last1->next;
    last1->next = first2;
    return first1;
}

void display(NODE first) {
    NODE temp = first;
    if (temp == NULL) { printf("Linked list is empty\n"); return; }
    while (temp != NULL) { printf("%d -> ", temp->value); temp = temp->next; }
    printf("NULL\n");
}

NODE reverse(NODE first) {
    NODE current = first, prev = NULL, next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void sort(NODE first) {
    if (first == NULL) return;
    NODE temp1, temp2;
    int tempVal;
    temp1 = first;
    while (temp1 != NULL) {
        temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->value > temp2->value) {
                tempVal = temp1->value;
                temp1->value = temp2->value;
                temp2->value = tempVal;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main() {
    NODE list1 = NULL, list2 = NULL;
    int choice, value;
    while (1) {
        printf("\nMenu:\n1. Insert at End (List 1)  2. Insert at End (List 2)\n3. Concatenate Lists\n4. Display List 1   5. Display List 2\n6. Reverse List 1   7. Reverse List 2\n8. Sort List 1   9. Sort List 2\n10. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value to insert in List 1: "); scanf("%d", &value); list1 = insert_end(value, list1); break;
            case 2: printf("Enter value to insert in List 2: "); scanf("%d", &value); list2 = insert_end(value, list2); break;
            case 3: list1 = concatenate(list1, list2); printf("Lists concatenated.\n"); break;
            case 4: printf("List 1: "); display(list1); break;
            case 5: printf("List 2: "); display(list2); break;
            case 6: list1 = reverse(list1); printf("List 1 reversed.\n"); break;
            case 7: list2 = reverse(list2); printf("List 2 reversed.\n"); break;
            case 8: sort(list1); printf("List 1 sorted.\n"); break;
            case 9: sort(list2); printf("List 2 sorted.\n"); break;
            case 10: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
