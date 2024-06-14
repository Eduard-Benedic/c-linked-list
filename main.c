#include <stdio.h>
#include "linked_list.h"

int main()
{
    Node *list1_head = NULL;

    list1_head = insert_at_head(list1_head, 7);
    list1_head = insert_at_head(list1_head, 3);
    list1_head = insert_at_tail(list1_head, 100);
    list1_head = insert_at_head(list1_head, 323);
    
    printf("%d\n", is_member(list1_head, 7));

    printf("Linked list length: %d\n", length(list1_head));
}
