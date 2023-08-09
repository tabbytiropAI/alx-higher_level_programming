#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

typedef struct listint_t {
    int data;
    struct listint_t *next;
} listint_t;

listint_t *insert_node(listint_t **head, int number) {
    listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
    if (!new_node) {
        return NULL; // Memory allocation failed
    }
    
    new_node->data = number;
    new_node->next = NULL;

    if (*head == NULL || number < (*head)->data) {
        new_node->next = *head;
        *head = new_node;
    } else {
        listint_t *current = *head;
        while (current->next != NULL && number >= current->next->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    return new_node;
}

int main() {
    // Create an example sorted linked list
    listint_t *head = NULL;
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);
    insert_node(&head, 40);

    // Insert a new node
    insert_node(&head, 25);

    // Print the linked list
    listint_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free the allo memory
    while (head != NULL) {
        listint_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

