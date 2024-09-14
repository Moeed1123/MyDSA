//Singly_Linked_List_Basic_Operations

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    displayList(head);  // Output: 10 -> 20 -> 30 -> NULL

    insertAtBeginning(&head, 5);
    displayList(head);  // Output: 5 -> 10 -> 20 -> 30 -> NULL

    deleteNode(&head, 20);
    displayList(head);  // Output: 5 -> 10 -> 30 -> NULL

    return 0;
}
