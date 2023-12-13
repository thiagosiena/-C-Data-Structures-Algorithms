#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    //     20
    //    /  \ 
    //  10    30
    //       /  \ 
    //     25    40

    Node *node1 = Node_create(20);

    Node *node2 = insert_left(node1, 10);

    Node *node3 = insert_right(node1, 30);

    Node *node4 = insert_left(node3, 25);

    Node *node5 = insert_right(node3, 40);

    Tree *tree = Tree_create();

    Tree_add_root(tree, node1);

    int op;

    while (op != 4)
    {

        printf("--------MENU-----------\n 1 = print before order\n 2 = print in order\n 3 = print after order\n 4 = exit\n");
        printf("Choose one option: ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
        case 1:
            printf("\n\n");
            printf("[");
            Show_beforeorder(tree);
            printf("]");
            printf("\n\n");
            break;
        case 2:
            printf("\n\n");
            printf("[");
            Show_inorder(tree);
            printf("]");
            printf("\n\n");
            break;
        case 3:
            printf("\n\n");
            printf("[");
            Show_afterorder(tree);
            printf("]");
            printf("\n\n");
            break;
        case 4:
            break;

        default:
            printf("\n\n");
            printf("invalid Number");
            printf("\n\n");
        }
    }
    Tree_free(tree);
    system("pause");
}
