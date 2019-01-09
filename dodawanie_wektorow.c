#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int *dodawanie (int t1[SIZE], int t2[SIZE]);
int main (void){
    int t1[SIZE]={1,2,3,4,5};
    int t2[SIZE]={5,4,3,2,1};
    int *z=dodawanie(t1,t2);
    int i;
    for (i=0;i<SIZE;i++){
        printf("%d", *(z+i));
    }
    free(z);
}
int *dodawanie (int t1[SIZE], int t2[SIZE]){
    int *t3=calloc(SIZE, sizeof(int));
    int i;
    for (i=0;i<SIZE;i++){
        *(t3+i)=t2[i]+t1[i];
    }
    return t3;
}
