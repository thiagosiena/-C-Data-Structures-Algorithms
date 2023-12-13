#include "bstree.h"
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

Tree *Tree_create(void)
{

    Tree *new_tree = (Tree *)malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}

Node *Node_create(int data)
{

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->data = data;
    return new_node;
}

void Tree_add_wrapper(Node *root, int data)
{

    if (data > root->data)
    {

        if (root->right != NULL)
        {

            Tree_add_wrapper(root->right, data);
        }
        else
        {

            root->right = Node_create(data);
        }
    }
    if (data < root->data)
    {

        if (root->left != NULL)
        {

            Tree_add_wrapper(root->left, data);
        }
        else
        {

            root->left = Node_create(data);
        }
    }
    else
    {
        // não faz nada se o valor já estiver alocado em um node!
    }
}

void Tree_add(Tree *tree, int data)
{
    if (tree->root != NULL)
    {
        Tree_add_wrapper(tree->root, data);
    }
    else
    {
        tree->root = Node_create(data);
    }
}

Node *Tree_remove_wrapper_helper(Node *node)
{
    if (node->left == NULL)
    {
        Node *aux = node;
        free(node);
        return aux;
    }
    Tree_remove_wrapper_helper(node->left);
}

Node *Tree_remove_wrapper(Node *root, int data)
{

    if (root != NULL)
    {

        if (root->data > data)
        {
            root->left = Tree_remove_wrapper(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = Tree_remove_wrapper(root->right, data);
        }
        else if (root->data == data)
        {

            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                root = NULL;
            }
            else
            {
                if (root->left != NULL)
                {
                    Node *aux1 = root;
                    root = root->left;
                    free(aux1);
                }
                else
                {
                    Node *aux2 = root;
                    root = root->right;
                    free(aux2);
                }
            }
        }
    }
   return root;
}

void Tree_remove(Tree *tree, int data)
{
    if (tree->root != NULL)
    {
        Tree_remove_wrapper(tree->root, data);
    }
    else
    {
        printf("arvore vazia \n");
    }
}

void print_tree_wrapper(Node *node)
{
    if (node != NULL)
    {
        printf("%d", node->data);

        if (node->left != NULL)
        {
            printf("L(");
            print_tree_wrapper(node->left);
            printf(")");
        }

        if (node->right != NULL)
        {
            printf("R(");
            print_tree_wrapper(node->right);
            printf(")");
        }
    }
}

void print_tree(Tree *tree)
{
    if (tree != NULL)
    {
        printf("(");
        print_tree_wrapper(tree->root);
        printf(")\n");
    }
    else
    {
        printf("()\n");
    }
}

void free_tree_wrapper(Node *node)
{
    if (node != NULL)
    {
        free_tree_wrapper(node->left);
        free_tree_wrapper(node->right);
        free(node);
    }
}

void free_tree(Tree *tree)
{
    if (tree != NULL)
    {
        free_tree_wrapper(tree->root);
        free(tree);
        tree->root = NULL;
        tree = NULL;
    }
}