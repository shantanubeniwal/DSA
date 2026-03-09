#include <stdio.h>

//  arg-Y return-Y
int sum(int a, int b){
    return a + b;
}

//  arg-Y return-N
void star(int n){
    for (int i = 1; i <= n;i++){
        printf("*\n");
    }
}

//  arg-N return-Y
int takeNumber(){
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    
    return n;
}

//  arg-N return-N
void singleStar(){
    printf("*");
}

int factorial(int number){
    if(number == 0 || number == 1){
        return 1;
    }else{
        return (number * factorial(number -1));
    }
}

int main(){
    //  arg-Y return-Y
    // int a, b, c;
    // a = 8;
    // b = 6;
    // c = sum(a, b);
    // printf("Sum of %d and %d is %d", a, b, c);

    //  arg-Y return-N
    // int num;
    // printf("Enter a number:");
    // scanf("%d", &num);
    // star(num);

    //  arg-N return-Y
    // int num = takeNumber();
    // printf("you enter %d.", num);

    //  arg-N return-N
    // int num = takeNumber();
    // for (int i = 0; i < num;i++){
    //     singleStar();
    //     printf("\n");
    // }

    int num = takeNumber();
    printf("Factorial of %d is %d.", num, factorial(num));
    
    return 0;
}