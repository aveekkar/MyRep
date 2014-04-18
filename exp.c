#include<stdio.h>
#include<stdlib.h>


long power(long base,long pow);

int main(){
	long base;
	long pow;
	printf("enter base\n>");
	scanf("%ld",&base);
	//printf("you entered %ld",base);
	printf("enter pow\n>");
	scanf("%ld",&pow);
	//printf("you entered %ld",base);
	printf("%ld\n",power(base,pow));
	return 0;
}

long power(long base,long pow){
	long to_ret;
	if(pow==1){
		return base;
	}
	else if(pow==0){
		return 1;
	}
	else{
		if(pow%2==0){
			to_ret=power(base,pow/2);
			return to_ret*to_ret;
		}
		else{
			to_ret=power(base,(pow-1)/2);
			return base*to_ret*to_ret;
		}
	}
}
