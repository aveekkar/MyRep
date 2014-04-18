#ifndef MY_B_TREE
#define MY_B_TREE
#define true 1
#define false 2
typedef int bool;

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
}node;


typedef struct List_Node{
	node* tree_node;
	struct List_Node* next;
}list;


typedef struct Queue{
	list* head;
	list* tail;
}queue;



queue* new_queue();
void offer(node*,queue*);
node* poll(queue*);
bool empty_queue(queue*);
bool is_queue_empty(queue*);
void inorder(node*);
void preorder(node*);
void postorder(node*);
void breadth_first(node*);
void breadth_first_check(node*);
void insert(node*,int);
int depth(node*);
void delete(int,node*);
node* new_node();
node* delete_helper(int,node*,node*);
node* min_right(node*);
node* inorder_preorder(int*,int*);
node* inorder_postorder(int*,int*);
node* inorder_breadth(int*,int*);
node* inpre_helper(int*,int*,int,int,int,int);
int search(int*,int,int,int);



static char exit_command[]={'e','x','i','t','\0'};
static char insert_command[]={'i','n','s','e','r','t','\0'};
static char delete_command[]={'d','e','l','e','t','e','\0'};
static char inorder_command[]={'i','n','o','r','d','e','r','\0'};
static char preorder_command[]={'p','r','e','o','r','d','e','r','\0'};
static char postorder_command[]={'p','o','s','t','o','r','d','e','r','\0'};
static char breadth_first_command[]={'b','r','e','a','d','t','h','\0'};
static char depth_command[]={'d','e','p','t','h','\0'};
static char make_queue[]={'q','u','e','u','e','\0'};
static char offer_command[]={'o','f','f','e','r','\0'};
static char poll_command[]={'p','o','l','l','\0'};
static char empty_queue_command[]={'e','m','p','t','y','\0'};
static char pre_command[]={'p','r','e','\0'};
static char post_command[]={'p','o','s','t','\0'};
static char br_command[]={'b','r','\0'};

#endif

