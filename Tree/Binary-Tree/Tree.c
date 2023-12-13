#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node
{
    int data;
    Node *right;
    Node *left;
};

typedef struct tree Tree;
struct tree
{
    Node *root;
};

Tree *Tree_create(void){
    Tree *new_tree = (Tree *)malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;

}

Node *Node_create(int data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->data = data;
    return new_node;

}

void Tree_add_root(Tree *Tree, Node *node){
    if (Tree->root == NULL){
        Tree->root = node;
    }

}

Node *insert_right(Node *node, int data){
    if (node != NULL){
        node->right = Node_create(data);
        return node->right;
    }
    return NULL;

}

Node *insert_left(Node *node, int data){
    if (node != NULL){
        node->left = Node_create(data);
        return node->left;
    }
    return NULL;

}

void Print_beforeorder(Node *root){
    if (root){
        printf("%d ", root->data);
        Print_beforeorder(root->left);
        Print_beforeorder(root->right);
    }

}

void Show_beforeorder(Tree *tree){

    Print_beforeorder(tree->root);

}

void Print_inorder(Node *root){
    if (root){
        Print_inorder(root->left);
        printf("%d ", root->data);
        Print_inorder(root->right);
    }

}

void Show_inorder(Tree *tree){
    Print_inorder(tree->root);

}

void Print_afterorder(Node *root){
    if (root){
        Print_afterorder(root->left);
        Print_afterorder(root->right);
        printf("%d ", root->data);
    }

}

void Show_afterorder(Tree *tree){
    Print_afterorder(tree->root);

}


void Tree_free_helper(Node* node){
    if(node != NULL){
        Tree_free_helper(node->left);
        Tree_free_helper(node->right);
        free(node);
    }
}


void Tree_free(Tree *tree){
    Tree_free_helper(tree->root);
    free(tree->root);
    free(tree);
}