#include <stdio.h>
#include <stdlib.h>

char* reverse(char* s);

int main(){
	char* str;
	int n;
	printf("max size of string to enter:\n");
	scanf("%d",&n);
	printf("enter string to reverse\n");
	str=(char*)calloc(n+1,sizeof(char));
	scanf("%s",str);
	printf("the reversed string is %s\n",reverse(str));
	return 0;
}

char* reverse(char* s){
	int i,j;
	char tmp;
	j=(size(s)/2);
	for(i=0;i<j;i++){
		tmp=s[i];
		s[i]=s[size(s)-1-i];
		s[size(s)-1-i]=tmp;
	}
	
	return s;
}

int size(char* ptr){
	int count=0;
	while(ptr[count]!='\0'){
		count++;
	}
	return count;
}
