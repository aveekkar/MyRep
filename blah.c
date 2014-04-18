#include<stdio.h>
#include<stdlib.h>

int main(){
	int size;
	int loop=0;
	printf("enter array size\n>");
	scanf("%d",&size);
	int arr[size = 2*size+3];
	for(;loop<size;loop++){
		arr[loop]=loop+5;
	}
	for(loop=0;loop<size;loop++){
		printf("%d ",arr[loop]);
	}
	printf("\n");
}
