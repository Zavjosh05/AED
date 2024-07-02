typedef struct node
{
    struct node *before;
    struct node *next;
    char element;
}*Node, Size_node;

int createNode(Node*);
int freeNode(Node*);
int initializeNode(Node);
int printInfoNode(Node);
int printDataNode(Node);
int insertInfoNode(Node);
int randomNodeGenerator(Node*,int);
void mensajeNodo(int);