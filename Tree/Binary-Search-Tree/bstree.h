



typedef struct node Node;
typedef struct tree Tree;


Tree *Tree_create(void);
void Tree_add(Tree* tree, int data);
void Tree_remove(Tree* tree, int data);
void print_tree(Tree *tree);
void free_tree(Tree *tree);