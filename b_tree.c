#include<stdio.h>
#include<stdlib.h>
#include"b_tree.h"

static int* temparr;
static int* breadth_arr;
static int breadth_arr_count;
static int* in_arr;
static int in_count;
static int* pre_arr;
static int pre_count;
static int* post_arr;
static int post_count;




int main(){
	int i;
	int root_val;
	char command[20];
	int insert_val;
	int insert_val_queue;
	int delete_val;
	queue* exp_queue;
	node* exp_node;
	node* root=new_node();
	breadth_arr=(int*)malloc(2*sizeof(int));
	breadth_arr_count=0;
	in_arr=(int*)malloc(2*sizeof(int));
	in_count=0;
	pre_arr=(int*)malloc(2*sizeof(int));
	pre_count=0;
	post_arr=(int*)malloc(2*sizeof(int));
	post_count=0;
	printf("to make tree enter root \n");
	scanf("%d",&root_val);
	root->val=root_val;
	printf("enter command, \"exit\" to exit \n");
	while(true){
		printf("$");
		scanf("%s",command);
		if(strcmp(command,exit_command)==0){
			printf("\n");
			break;
		} 
		else if(strcmp(command,insert_command)==0){
			printf(">");
			scanf("%d",&insert_val);
			insert(root,insert_val);
		}
		else if(strcmp(command,inorder_command)==0){
			inorder(root);
			printf("\n");
			for(i=0;i<in_count;i++){
				printf("%d ",in_arr[i]);
			}
			printf("\n");
		}
		else if(strcmp(command,preorder_command)==0){
			preorder(root);
			printf("\n");
			for(i=0;i<pre_count;i++){
				printf("%d ",pre_arr[i]);
			}
			printf("\n");
		}
		else if(strcmp(command,postorder_command)==0){
			postorder(root);
			printf("\n");
			for(i=0;i<post_count;i++){
				printf("%d ",post_arr[i]);
			}
			printf("\n");
		}
		else if(strcmp(command,breadth_first_command)==0){
			breadth_first(root);
			//printf("count: %d\n",breadth_arr_count);
			for(i=0;i<breadth_arr_count;i++){
				printf("%d ",breadth_arr[i]);
			}
			printf("\n");
		}
		else if(strcmp(command,make_queue)==0){
			exp_queue=new_queue();
		}
		else if(strcmp(command,offer_command)==0){
			printf(">");
			scanf("%d",&insert_val_queue);
			exp_node=(node*)malloc(sizeof(node));
			exp_node->val=insert_val_queue;
			exp_node->left=NULL;
			exp_node->right=NULL;
			offer(exp_node,exp_queue);
		}
		else if(strcmp(command,poll_command)==0){
			exp_node=poll(exp_queue);
			if(exp_node!=NULL){
				printf("polled %d\n",exp_node->val);
				free(exp_node);
			}
		}
		else if(strcmp(command,empty_queue_command)==0){
			empty_queue(exp_queue)==true?printf("true\n"):printf("false\n");
		}
		else if(strcmp(command,delete_command)==0){
			printf(">");
			scanf("%d",&delete_val);
			delete(delete_val,root);
		}
		else if(strcmp(command,pre_command)==0){
			//printf("in_count=%d pre_count=%d\n",in_count,pre_count);
			node* root_traversal=inorder_preorder(in_arr,pre_arr);
			breadth_first_check(root_traversal);
		}
	}
	return 0;
	
}

queue* new_queue(){
	queue* new=(queue*)malloc(sizeof(queue));
	new->head=NULL;
	new->tail=NULL;
	return new;
}

void offer(node* tree_entry,queue* q){
	if(q->tail==NULL){
		list* new_entry=(list*)malloc(sizeof(list));
		new_entry->tree_node=tree_entry;
		new_entry->next=NULL;
		q->tail=new_entry;
		q->head=new_entry;
	}
	else{
		list* new_entry=(list*)malloc(sizeof(list));
		new_entry->tree_node=tree_entry;
		new_entry->next=NULL;
		(q->tail)->next=new_entry;
		q->tail=new_entry;
	}
	
}

node* poll(queue* q){
	if(q->head==NULL){
		printf("polling from empty queue\n");
		return NULL;
	}
	else{
		list* ret_list_node=q->head;
		node* ret=ret_list_node->tree_node;
		list* next_elem=ret_list_node->next;
		if(next_elem==NULL){
			q->head=NULL;
			q->tail=NULL;
		}
		else{
			q->head=next_elem;
		}
		free(ret_list_node);
		return ret;
	}
}

bool empty_queue(queue* q){
	return q->head==NULL?true:false;
}



node* new_node(){
	node* new=(node*)malloc(sizeof(node));
	new->left=NULL;
	new->right=NULL;
	return new;
}

void insert(node* root,int val){
	if(val<root->val){
		if(root->left==NULL){
			node* left_child=new_node();
			left_child->val=val;
			root->left=left_child;
		}
		else{
			insert(root->left,val);
		}
	}
	else{
		if(root->right==NULL){
			node* right_child=new_node();
			right_child->val=val;
			root->right=right_child;
		}
		else{
			insert(root->right,val);
		}
	}
}

void inorder(node* root){
	if(root->left==NULL&&root->right==NULL){
		printf("%d ",root->val);
		if(in_count==0){
			in_arr[0]=root->val;
			/*printf("in if %d",breadth_arr_count);*/
			++in_count;
		}
		else{
			in_arr[in_count]=root->val;
			/*printf("in else %d",breadth_arr_count);*/
			++in_count;
			temparr=realloc(in_arr,((in_count+1)*sizeof(int)));
			if(temparr==NULL){
				printf("allocation exception\n");
				free(in_arr);
			}
			else{
				in_arr=temparr;
			}
		}
	}
	else{
		if(root->left!=NULL){
			inorder(root->left);
		}
		printf("%d ",root->val);
		if(in_count==0){
			in_arr[0]=root->val;
			/*printf("in if %d",breadth_arr_count);*/
			++in_count;
		}
		else{
			in_arr[in_count]=root->val;
			/*printf("in else %d",breadth_arr_count);*/
			++in_count;
			temparr=realloc(in_arr,((in_count+1)*sizeof(int)));
			if(temparr==NULL){
				printf("allocation exception\n");
				free(in_arr);
			}
			else{
				in_arr=temparr;
			}
		}
		if(root->right!=NULL){
			inorder(root->right);
		}
	}
}

void preorder(node* root){
	if(root->left==NULL&&root->right==NULL){
		printf("%d ",root->val);
		if(pre_count==0){
			pre_arr[0]=root->val;
			/*printf("in if %d",breadth_arr_count);*/
			++pre_count;
		}
		else{
			pre_arr[pre_count]=root->val;
			/*printf("in else %d",breadth_arr_count);*/
			++pre_count;
			temparr=realloc(pre_arr,((pre_count+1)*sizeof(int)));
			if(temparr==NULL){
				printf("allocation exception\n");
				free(pre_arr);
			}
			else{
				pre_arr=temparr;
			}
		}
		
	}
	else{
		printf("%d ",root->val);
		if(pre_count==0){
			pre_arr[0]=root->val;
			/*printf("in if %d",breadth_arr_count);*/
			++pre_count;
		}
		else{
			pre_arr[pre_count]=root->val;
			/*printf("in else %d",breadth_arr_count);*/
			++pre_count;
			temparr=realloc(pre_arr,((pre_count+1)*sizeof(int)));
			if(temparr==NULL){
				printf("allocation exception\n");
				free(pre_arr);
			}
			else{
				pre_arr=temparr;
			}
		}
		if(root->left!=NULL){
			preorder(root->left);
		}
		if(root->right!=NULL){
			preorder(root->right);
		}
	}
}

void postorder(node* root){
	if(root->left==NULL&&root->right==NULL){
		printf("%d ",root->val);
		if(post_count==0){
			post_arr[0]=root->val;
			/*printf("in if %d",breadth_arr_count);*/
			++post_count;
		}
		else{
			post_arr[post_count]=root->val;
			/*printf("in else %d",breadth_arr_count);*/
			++post_count;
			temparr=realloc(post_arr,((post_count+1)*sizeof(int)));
			if(temparr==NULL){
				printf("allocation exception\n");
				free(post_arr);
			}
			else{
				post_arr=temparr;
			}
		}
	}
	else{
		if(root->left!=NULL){
			postorder(root->left);
		}
		if(root->right!=NULL){
			postorder(root->right);
		}
		printf("%d ",root->val);
		if(post_count==0){
			post_arr[0]=root->val;
			/*printf("in if %d",breadth_arr_count);*/
			++post_count;
		}
		else{
			post_arr[post_count]=root->val;
			/*printf("in else %d",breadth_arr_count);*/
			++post_count;
			temparr=realloc(post_arr,((post_count+1)*sizeof(int)));
			if(temparr==NULL){
				printf("allocation exception\n");
				free(post_arr);
			}
			else{
				post_arr=temparr;
			}
		}
	}
}

void breadth_first(node* root){
	queue* q=new_queue();
	offer(root,q);
	while(empty_queue(q)==false){
		node* current=poll(q);
		printf("%d ",current->val);
		if(breadth_arr_count==0){
			breadth_arr[0]=current->val;
			/*printf("in if %d",breadth_arr_count);*/
			++breadth_arr_count;
		}
		else{
			breadth_arr[breadth_arr_count]=current->val;
			/*printf("in else %d",breadth_arr_count);*/
			++breadth_arr_count;
			temparr=realloc(breadth_arr,((breadth_arr_count+1)*sizeof(int)));
			if(temparr==NULL){
				printf("allocation exception\n");
				free(breadth_arr);
			}
			else{
				breadth_arr=temparr;
			}
		}
		if(current->left!=NULL){
			offer(current->left,q);
		}
		if(current->right!=NULL){
			offer(current->right,q);
		}
		
	}
	printf("\n");
}

void breadth_first_check(node* root){
	queue* q=new_queue();
	offer(root,q);
	while(empty_queue(q)==false){
		node* current=poll(q);
		printf("%d ",current->val);
		if(current->left!=NULL){
			offer(current->left,q);
		}
		if(current->right!=NULL){
			offer(current->right,q);
		}
		
	}
	printf("\n");
}

void delete(int search,node* root){
	node* del=NULL;
	if(root==NULL){
		return;
	}
	else if(root->val==search){
		node* aux=new_node();
		aux->val=root->val+1;
		aux->right=NULL;
		aux->left=root;
		del=delete_helper(search,NULL,aux);
		root=aux->left;
		free(aux);
	}
	else{
		del=delete_helper(search,NULL,root);
	}
	if(del!=NULL){
		free(del);
	}
}

node* delete_helper(int search,node* parent,node* current){
	if(search==current->val){
		if(current->left==NULL&&current->right==NULL){
			parent->left==current?(parent->left=NULL):(parent->right=NULL);
			return current;
		}
		else if(current->left!=NULL&&current->right==NULL){
			parent->left==current?(parent->left=current->left):(parent->right=current->left);
			return current;
		}
		else if(current->left==NULL&&current->right!=NULL){
			parent->left==current?(parent->left=current->right):(parent->right=current->right);
			return current;
		}
		else{
			node* min=min_right(current->right);
			current->val=min->val;
			return delete_helper(min->val,current,current->right);
		}
	}
	else{
		if(search<current->val){
			if(current->left!=NULL){
				return delete_helper(search,current,current->left);
			}
			else{
				return NULL;
			}
		}
		else{
			if(current->right!=NULL){
				return delete_helper(search,current,current->right);
			}
			else{
				return NULL;
			}
		}
	}
}


node* min_right(node* subtree){
	if(subtree->left==NULL){
		return subtree;
	}
	else{
		return min_right(subtree->left);
	}
}


node* inorder_preorder(int* in,int* pre){
	node* root=inpre_helper(in,pre,0,in_count-1,0,pre_count-1);
	//printf("in in_pre %d \n",root->val);
	return root;
}

node* inpre_helper(int* in,int* pre, int in_start,int in_end,int pre_start,int pre_end){
	if(in_start==in_end){
		node* root=new_node();
		root->val=in[in_start];
		root->left=NULL;
		root->right=NULL;
		//printf("created leaf node %d \n",in[in_start]);
		return root;
	}
	else{
		int root_index=search(in,pre[pre_start],in_start,in_end);
		//printf("index search %d ",root_index);
		node* root=new_node();
		root->val=in[root_index];
		//printf("creating root %d \n",in[root_index]);
		++pre_start;
		if(root_index!=in_start){
			root->left=inpre_helper(in,pre,in_start,root_index-1,pre_start,pre_start+((root_index-in_start)-1));
		}
		else{
			root->left=NULL;
		}
		if(root_index!=in_end){
			root->right=inpre_helper(in,pre,root_index+1,in_end,pre_end-((in_end-root_index)-1),pre_end);
		}
		else{
			root->right=NULL;
		}
		
		return root;
	}
	
}

int search(int* arr,int search,int start,int end){
	int i=start;
	//printf("in search start=%d end=%d\n",start,end);
	for(i;i<=end;i++){
		//printf("considering %d in search\n",*(arr+i));
		if((*(arr+i))==search){
			return i;
		}
	}
	
	return -1;
}














