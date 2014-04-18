#include <stdio.h>
int* foo() {
    int a[3]={1,10,100};

    return a;
}

int* goo() {
    int b[3]={2,20,200};

    return b;
}



int main() {
    int* a;
    int *b;
    a=foo();

    b=goo();

    printf("%d\n",*a);

    return 0;
}
