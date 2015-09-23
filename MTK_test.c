#include <stdlib.h>
#include <stdio.h>
#define DAY_OF_MONTH(n) \
 (n == 6 || n== 9 || n==11)? 30:31

int* f1(void);
int* f2(void);
int* f3(void);

int main(){
    int Cnt = 10;
    const char *pc = "Welcome";
    while(*pc){
        Cnt++;
        *pc++;
        printf("pc: %d ",pc);
        printf("*pc: %c \n",*pc);
    }
    printf("Cnt: %d \n",Cnt);
    printf("month 6: %d\n",DAY_OF_MONTH(6));
    printf("-------------------------------\n");



    unsigned long A = 0x00001111;
    unsigned long B = 0x00000202;
    unsigned long C;
    printf("~B : %x \n", ~B);
    C = A & (~B);
    printf(" A & (~B): %x \n", C);
    C = C | B;
    printf("C | B : %x \n", C);
    printf("--------------------------------\n");


    int ref[] ={8,4,0,2};
    int *ptr;
    int index;
    for(index=0,ptr=ref;index<2;index++,ptr++){
        printf("%d %d\n",ref[index],*ptr);
    }
    printf("index=%d, *ptr=%d\n",index,*ptr);
    (*ptr)++;
    printf("%d %d\n",ref[index],*ptr);
    printf("---------------------------------\n");

    //printf("f1: %d\n", f1);
    //printf("f2: %d\n", f2);
    //printf("f3: %d\n", f3);
    int fu1 = f1();
    printf("fu1: %d\n",fu1);

    int fu2 = f2();
    //printf("fu2: %d\n",fu2);

    int fu3 = f3();
    printf("fu3: %d\n",fu3);

    return 0;
}

int *f1(void){
    int x = 10;
    //printf("&x: %p",&x);
    return(&x);
}

int *f2(void){
    int *ptr, a;
    ptr = &a;
    a = 10;
    printf("*ptr: %d\n",*ptr);
    return *ptr;
}

int *f3(void){
    int *ptr ;
    ptr = (int*) malloc(sizeof(int));
    return ptr;
}
