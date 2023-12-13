#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>





int main(){


    Tree* tree = Tree_create();
    Tree_add(tree, 10);
    Tree_add(tree, 20);
    Tree_add(tree, 9);
    Tree_add(tree, 21);
    print_tree(tree);
    Tree_remove(tree, 9);
    print_tree(tree);
    free_tree(tree);
    system("pause");

    

     
}