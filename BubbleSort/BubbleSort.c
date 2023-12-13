
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
    Node *prev;
};

struct list
{
    Node *first;
    int length;
};


void list_bubbleSort(List *list)
{
    int i, j;
    Node *current;
    Node *temp;

    if (list->length == 0)
    {
        printf("Lista vazia!");
        return;
    }

    for (i = 0; i < list->length - 1; i++)
    {
        current = list->first;

        for (j = 0; j < list->length - 1 - i; j++)
        {
            if (current->data > current->next->data)
            {
                temp = current->next;

                if (current->prev != NULL)
                {
                    current->prev->next = temp;
                }
                else
                {
                    list->first = temp;
                }

                current->next = temp->next;

                if (temp->next != NULL)
                {
                    temp->next->prev = current;
                }

                temp->prev = current->prev;
                current->prev = temp;
                temp->next = current;
            }
            else
            {
                current = current->next;
            }
        }
    }
}