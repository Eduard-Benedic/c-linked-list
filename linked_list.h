#include <stdbool.h>

/**
 * Typedef for a node in the linked list
*/
typedef struct node {
    int value; /**<the value of the node  */
    struct node *next /**<the next node in the chain */;
} Node;

void print_list(Node *head);

Node *insert_at_head(Node *head, int new_value);

Node *insert_at_tail(Node *head, int new_value);

Node *delete_at_head(Node *head);

Node *delete_at_tail(Node *head);

int length(Node *head);

int recursive_length(Node *node);

bool is_member(Node *node, int find_value);

void replace_matches(Node* node, int find_value, int replace_value);
