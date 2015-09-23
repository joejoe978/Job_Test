#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HELLO_MESSAGE 123

#if !defined( HELLO_MESSAGE )
   # error "You have forgotten to define the header file name."
#endif

#define SECONDS_PER_YEAR 60 * 60 * 24 * 365
#define MIN(A,B)  A <= B ? A : B

//typedef void (*FP)();

void func1(void){ printf("f1\n");}
void func2(void){ printf("f2\n");}
void func3(void){ printf("f3\n");}
void func4(void){ printf("f4\n");}
void func5(void){ printf("f5\n");}
void my(int n);
void test();
void test2();
void test3();
void test4();
void testswap();
void test5();
void test6();

int main(){
    my(1);
    printf("-----------------------\n");
    test();
    //test2();
    printf("-----------------------\n");
    test3();
    printf("-----------------------\n");
    test4();
    printf("-----------------------\n");
    testswap();
    printf("-----------------------\n");
    test5();
    printf("-----------------------\n");
    test6();

    return 0;
}

void my(int n){
    void (*fun[])() = {func1,func2,func3,func4,func5};
    fun[n-1]();
    //FP fp[] = {func1,func2,func3,func4,func5};
    //(*fp[n-1])();
}

void test(){
    int a = 10;
    const int *i = &a;
    printf("i: %d\n",*i);
    i++;
    printf("i: %d\n",*i);

    int *const b = &a;
    printf("b: %d\n",*b);
    (*b)++;
    printf("b: %d\n",*b);
}

void test2(){
    char *apt = "I am Joe.";
    while(*apt != '.'){
        printf("%c ",*apt);
        apt++;
    }
}

void test3(){
    int a[5] = {100, 2, 3, 4, 5};
    int *p = (int*)(&a);
    int *q = &a+1;
    printf(" *a+1: %d\n",*a+1);
    printf(" *(a+1): %d\n",*(a+1));
    printf(" (*a)+1: %d\n",(*a)+1);
    printf(" *p: %d\n",*p);
    printf(" *q: %d\n",*q);
    printf(" (*p-1): %d\n",(*p-1));
}

void test4(){
    int a=1, b=52, least;
    int *p = malloc(sizeof(int));
    *p = 30;

    printf("SECOND_PER_YEAR : %d \n",SECONDS_PER_YEAR);
    printf("%d \n",MIN(a,b));

    printf("p: %d\n", *p);
    printf("p address: %d\n", &p);

    least = MIN(*p++, b);
    printf("least = %d \n",least);
}

void testswap(){
    int a = 22;
    int b = 11;
    printf("a: %d, b: %d \n",a,b);
    swap(&a,&b);
    printf("a: %d, b: %d \n",a,b);
}

void swap(int *ptra,int *ptrb){
    int temp;
    //printf("ptra: %d\n",ptra);
    //printf("*ptra: %d\n",*ptra);
    //temp = *ptra;
    //*ptra = *ptrb;
    //*ptrb = temp;
    *ptra = *ptra - *ptrb;
    *ptrb = *ptrb + *ptra;
    *ptra = *ptrb - *ptra;
}

void test5(){
    int n = 5,i;
    int b = ((n!=0) && !(n & (n-1)));
    printf("n: ",n);
    for(i=16;i;i>>=1)
        printf(i&n? "1":"0");
    printf(" \n");
    printf("%d is a power of 2? A: %d\n",n,b);
}

void test6(){
    int i;
    int *a[10];
    int (*b)[10] ;
    int c[10] = {1,2,3,4,5,6,7,8,9,10};

    for(i=0;i<10;i++)
        a[i] = &c[i];

    printf("a[0]: %d\n",a[0]);
    printf("*a[0]: %d\n",*a[0]);
    printf("&a[0]: %d\n",&a[0]);
    printf("a[5]: %d\n",a[5]);
    printf("*a[5]: %d\n",*a[5]);
    printf("&a[5]: %d\n",&a[5]);

    b=&c;

    printf("b: %d\n",b);
    printf("(*b)[0]: %d\n",(*b)[0]);
    printf("(*b)[5]: %d\n",(*b)[5]);
    printf("(*b)[9]: %d\n",(*b)[9]);
}
