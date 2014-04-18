#include<stdio.h>
#include<stdlib.h>

int main(){
	//int *p;
	int a=10;
	int* p=&a;
	char* s=(char*)malloc(sizeof(char));
	printf("%d at memory %u\n",*p,p);
	printf("%d at memory %u\n",a,&a);
	scanf("%[^\n]s",s);
	printf("%s\n",s);
	printf("%d\n",strlen(s));
	
}
