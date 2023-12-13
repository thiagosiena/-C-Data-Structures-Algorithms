
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
    Node *last;
    int length;
};

List *list_create()
{
    List *new_list = (List *)malloc(sizeof(List));
    new_list->first = 0;
    new_list->last = new_list->first;
    new_list->length = 0;
    return new_list;
}

void list_add(List *list, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
      if (list->first == 0)
    {
        new_node->next = 0;
        new_node->prev = 0;
        list->first = new_node;
        list->last = new_node;
        list->length++;
        return;
    }
    new_node->next = list->first;
    new_node->prev = list->last;

  

    list->last->next = new_node;
    list->last = new_node;
    list->length++;
}

void list_display(List *list)
{
    Node *current = list->first;
    printf("[ ");
    int count = 0;
    while (count != list->length)
    {
        printf("%d ", current->data);
        current = current->next;
        count++;
    }
    printf("]\n");
}

void list_free(List *list)
{
    int count = 0;
    while (count != list->length)
    {
        Node *aux = list->first;
        list->first = list->first->next;
        free(aux);
        count++;
    }
    free(list);
}

int list_get(List *list, int index)
{
    Node *current = list->first;
    int count = 0;
    while (1)
    {
        if (count == list->length)
        {
            printf("Invalid index!\n");
            return -1;
        }

        if (count == index)
            return current->data;
        current = current->next;
        count++;
    }
}

void list_set(List *list, int index, int value)
{
    Node *current = list->first;
    int count = 0;
    while (1)
    {
        if (count == list->length)
        {
            printf("Invalid index!\n");
            return;
        }

        if (count == index)
        {
            current->data = value;
            return;
        }
        current = current->next;
        count++;
    }
}

void list_insert(List *list, int index, int value)
{
    if (index == 0)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = list->first;
        list->first->prev = new_node;
        new_node->prev = 0;
        list->first = new_node;
        list->length++;
        return;
    }

    Node *current = list->first;
    int count = 0;
    while (1)
    {

        if (count == list->length)
        {
            printf("Invalid index!\n");
            return;
        }

        if (count == index - 1)
        {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->data = value;
            new_node->next = current->next;
            new_node->prev = current;
            current->next->prev = new_node;
            current->next = new_node;
            current->prev = new_node;
            list->length++;
            return;
        }

        current = current->next;
        count++;
    }
}

int list_remove(List *list, int index)
{
    if (list->first == 0)
    {
        printf("Empty list!\n");
        return -1;
    }

    if (index == 0)
    {
        Node *aux = list->first;
        int result = aux->data;
        list->first = list->first->next;
        free(aux);
        list->length--;
        return result;
    }

    Node *current = list->first;
    int count = 0;

    while (1)
    {
        if (count == list->length)
        {
            printf("Invalid index!\n");
            return -1;
        }

    
        if (count == index - 1)
        {
            Node *aux = current->next;
            int result = aux->data;
            current->next = current->next->next;
            current->next->next->prev = current;
            free(aux);
            list->length--;
            return result;
        }
        
        current = current->next;
        count++;
    }
}

