#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node {
    int data;
    Node* next;
};

struct queue {
    int length;
    int size;
    Node* first;
    Node* last;
};

Queue* queue_create(int size) {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->first = 0;
    new_queue->last = 0;
    new_queue->size = size;
    new_queue->length = 0;
    return new_queue;
}

void queue_free(Queue* queue) {
    while(queue->first != 0) {
        Node* aux = queue->first;
        queue->first = queue->first->next;
        free(aux);
    }
    free(queue);
}

void queue_enqueue(Queue* queue, int value){
    if(queue_is_full(queue)) {
        printf("Queue is full!\n");
        return;
    }
   
    queue->length++;
   
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = 0;
   
    if(queue->first == 0) {
        queue->first = new_node;
        queue->last = new_node;
        return;
    }
   
    queue->last->next = new_node;
    queue->last = new_node;
}

int queue_dequeue(Queue* queue){
    if(queue_is_empty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }
   
    queue->length--;
   
    int result = queue->first->data;
   
    if(queue->first == queue->last){
        free(queue->first);
        queue->first = 0;
        queue->last = 0;
    } else {
        Node* aux = queue->first;
        queue->first = queue->first->next;
        free(aux);
    }
   
    return result;
}

int queue_first(Queue* queue){
     if(queue_is_empty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->first->data;
}

int queue_last(Queue* queue){
     if(queue_is_empty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->last->data;
}


int queue_is_empty(Queue* queue) {
    return queue->length == 0;
}

int queue_is_full(Queue* queue){
    return queue->length == queue->size;
}