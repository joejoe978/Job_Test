#include <stdlib.h>
#include <stdio.h>

void reverse1();
void reverse2();

int main(){

    //reverse1();
    reverse2();

    return 0;
}

void reverse1(){
    char str[100], temp;
    int i, j = 0;
    printf("\nEnter the string :");
    gets(str);

    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        printf("%c\n",str[i]);
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    printf("\nReverse string is :%s", str);
}

void reverse2(){
    int length,i,size=100;
    char str[size];
    printf("Enter the string :");
    gets(str);

    length = strlen(str);

    for(i=0;i<length/2;i++){
        str[length]=str[i];
        str[i]=str[length-i-1];
        str[length-i-1]=str[length];
    }

    str[length]='\0';
    printf("\nReverse string is :%s", str);
}
