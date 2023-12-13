

typedef struct tree Tree;
typedef struct node Node;

Tree *Tree_create(void);

Node *Node_create(int data);

Node *insert_right(Node *node, int data);

Node *insert_left(Node *node, int data);

void Tree_add_root(Tree *Tree, Node *node);

void Tree_free(Tree *tree);

void Show_beforeorder(Tree *tree);

void Show_inorder(Tree *tree);

void Show_afterorder(Tree *tree);

