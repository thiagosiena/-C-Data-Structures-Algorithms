#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node {
    int data;
    Node* next;
};

struct stack {
    int size;
    int length;
    Node* first;
    Node* last;
};

Stack* stack_create(int size){
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->first = 0;
    new_stack->last = 0;
    new_stack->size = size;
    new_stack->length = 0;
}

void stack_free(Stack* stack){
       while(stack->first != 0) {
        Node* aux = stack->first;
        stack->first = stack->first->next;
        free(aux);
    }
    free(stack);
}

void stack_push(Stack* stack, int value){
    if(stack_is_full(stack)) {
        printf("Stack is full!\n");
        return;
    }
   
    stack->length++;
   
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = 0;
   
    if(stack->first == 0){
        stack->first = new_node;
        stack->last = new_node;
        return;
    }
   
    stack->last->next = new_node;
    stack->last = new_node;
}

int stack_pop(Stack* stack){
    if(stack_is_empty(stack)){
        printf("Stack is empty!");
        return;
    }
   
    if(stack->first->next == 0){
        int result = stack->first->data;
        free(stack->first);
        stack->first = 0;
        stack->last = 0;
        stack->length = 0;
    }
   
    int result = stack->last->data;
    Node* current = stack->first;
    while(current->next != stack->last){
        current = current->next;
    }
   
    free(current->next);
    current->next = 0;
    stack->last = current;
    stack->length--;
    return result;
}

int stack_peek(Stack* stack, int index){
    if(index >= stack->length){
        printf("invalid index!");
        return -1;
    }

    Node* current = stack->first;
    int count = 0;

    while(current != 0){
        if(count == index){
            return current->data;
        }
        count++;
        current = current->next;
    }

}


int stack_top(Stack* stack){
    if(stack_is_empty(stack)){
        printf("stack is empty!\n");
        return -1;
    }
    return stack->last->data;
}

int stack_is_empty(Stack* stack){
    return stack->length == 0;
}

int stack_is_full(Stack* stack){
    return stack->length == stack->size;
}