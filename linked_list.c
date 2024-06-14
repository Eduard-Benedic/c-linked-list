/**
 * Linked list library
 * @file linked_list.c
 * @author Eben
 * @date Thursday, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

/**
 * @param node -> node in linked list
 * @param int -> value to replace the current val with
 * @return nothing, creates side effects
*/
void replace_matches(Node* node, int find_value, int replace_value) {
    if (node != NULL) {
        if (node->value == find_value)  {
            node->value = replace_value;
        }
        replace_matches(node->next, find_value, replace_value);
    }
}

int count_matches(Node *node, int find_value)
{
    if (node == NULL) return 0;
    else if(node->value == find_value)
        return 1 + count_matches(node->next, find_value);
    else return count_matches(node->next, find_value);
}

int recursive_length(Node *node) {
    if (node == NULL) return 0;
    else return 1 + recursive_length(node->next);
}

bool is_member(Node *node, int find_value)
{
    if (node == NULL) return false;
    else if (node->value == find_value) return true;
    else return is_member(node->next, find_value);
}

int length(Node *head) {
    Node *current;
    current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

Node *delete_at_tail(Node *head) {
    if (head == NULL) return NULL;
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else {
        Node *current = head;
        Node *prev = NULL;
        while (current->next != NULL) {
            prev = current;     
            current = current->next;
        }
        prev->next = NULL;
        free(current);
        return head;
    }
}

Node *delete_at_head(Node *head) {
    if (head == NULL) return NULL;
    else
    {
        Node *to_return = head->next;
        free(head);
        return to_return;
    }
}

Node *insert_at_tail(Node *head, int new_value) {
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;
    if (head == NULL) return new_node;
    else
    {
        Node *current = head;
        while (current->next != NULL) current = current->next;
        current->next = new_node;
        return head;
    }
}

Node *insert_at_head(Node *head, int new_value) {
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;

    if (head == NULL) return new_node;
    else {
        new_node->next = head;
        return new_node;
    }
}

void print_list(Node *head) {
    Node *current;
    current = head;
    int i = 0;
    while (current != NULL) {
        printf("Node %d: %d\n", i, current->value);
        i++;
        current = current->next;
    }
}