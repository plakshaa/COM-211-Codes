#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Global variables
int list[MAX_SIZE];
int size = 0;

// Function prototypes
void insert(int element, int position);
void delete(int position);
void update(int position, int element);
int search(int element);
void traverse();

int main() {
    int choice, element, position;

    while (1) {
        printf("\nList Operations\n");
        printf("1. Insert\n2. Delete\n3. Update\n4. Search\n5. Traverse\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insert(element, position);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete(position);
                break;

            case 3:
                printf("Enter the position to update: ");
                scanf("%d", &position);
                printf("Enter the new element: ");
                scanf("%d", &element);
                update(position, element);
                break;

            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = search(element);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found in list\n");
                }
                break;

            case 5:
                traverse();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void insert(int element, int position) {
    if (position < 1 || position > size + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (size == MAX_SIZE) {
        printf("List is full!\n");
        return;
    }
    for (int i = size - 1; i >= position - 1; i--) {
        list[i + 1] = list[i];
    }
    list[position - 1] = element;
    size++;
    printf("Element inserted successfully!\n");
}

void delete(int position) {
    if (position < 1 || position > size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position - 1; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    size--;
    printf("Element deleted successfully!\n");
}

void update(int position, int element) {
    if (position < 1 || position > size) {
        printf("Invalid position!\n");
        return;
    }
    list[position - 1] = element;
    printf("Element updated successfully!\n");
}

int search(int element) {
    if (size == 0) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            return i + 1;
        }
    }
    return -1;
}

void traverse() {
    if (size == 0) {
        printf("List is empty!\n");
        return;
