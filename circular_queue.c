#include<stdio.h>
#include<stdlib.h>

#define SIZE 10;

static char exit_command[]={'e','x','i','t','\0'};
static char empty_command[]={'e','m','p','t','y','\0'};
static char insert_command[]={'i','n','s','e','r','t','\0'};
static char delete_command[]={'d','e','l','e','t','e','\0'};
static int full=-1;
typedef int bool;
#define true 1
#define false 0


typedef struct{
	int front;
	int rear;
	int size;
	int buffer_array[];
}circular_queue;

bool is_empty(circular_queue* queue);
void insert(circular_queue* q,int val);
int delete(circular_queue* q);

int main(){
	char command[10];
	int retrieved;
	int val;
	printf("enter queue size\n>");
	int size;
	scanf("%d",&size);
	circular_queue* queue=(circular_queue *)malloc((sizeof(circular_queue) + size*sizeof(int)));
	queue->front=0;
	queue->rear=size-1;
	queue->size=size;
	full=0;
	printf("circular queue initialized\n");
	while(true){
		printf("$");
		scanf("%s",command);
		if(strcmp(command,exit_command)==0){
			printf("Thank You!!\n");
			return 0;
		}
		else if(strcmp(command,empty_command)==0){
			is_empty(queue)==true?printf("true\n"):printf("false\n");
		}
		else if(strcmp(command,insert_command)==0){
			printf(">");
			scanf("%d",&val);
			insert(queue,val);
			printf("size: %d\n",full);
		}
		else if(strcmp(command,delete_command)==0){
			retrieved=delete(queue);
			printf("popped: %d\n",retrieved);
			printf("size: %d\n",full);
		}
		else{
			printf("invalid command\n");
		}
	}
	free(queue);
	return 0;
}

bool is_empty(circular_queue* queue){
	if(full<=0){
		return true;
	}
	else{
		return false;
	}
}

void insert(circular_queue* q,int val){
	if(full!=q->size){
		q->rear =(q->rear+1)%q->size;
		q->buffer_array[q->rear]=val;
		++full;
	}
	else{
		printf("queue is full\n");
	}
}

int delete(circular_queue* q){
	int to_return;
	if(is_empty(q)){
		printf("queue is empty!!\n");
		return -1234;
	}
	else{
		to_return=q->buffer_array[q->front];
		q->front += 1;
		--full;
		if(q->front>q->size-1){
			q->front=0;
		}
		return to_return;
	}
}
