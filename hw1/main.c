#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void part1();
void part2();
void part3();


int main(){
    part1();
    printf("\n********End of the part 1\n");
    part2();
    printf("********End of the part 2\n");
    part3();
    printf("\n******End of the part 3");
    return 0;
}
void part1(){
    int x,y,z;
    printf("Enter the first integer: ");
    scanf("%d",&x);
    printf("Enter the second integer: ");
    scanf("%d",&y);
    printf("Enter the divisor: ");
    scanf("%d",&z);
    if(find_divisible(x,y,z)==0){
        printf("There is not any integer between %d and %d can be divided by %d",y,x,z);
    }
    else
    {
        int next;
        printf("The first integer between %d and %d by %d is %d\n",x,y,z,find_divisible(x,y,z));
        printf("How many number next: ");
        scanf("%d",&next);
        int bound=((next+1)*z)+x;
        if(bound<y)
        {
            printf("The %d. integer between %d and %d divided by %d is %d",next+1,x,y,z,find_nth_divisible(x,next,z));
        }
        else{
            printf("out of range -999");
            exit(0);
        }
    }
    
}


void part2(){
    char identity_number[100];
    int password;
    int kontrol1=0,kontrol2=0;
    
    while(1)
    {
        printf("Enter the identity number\n");
        int kontrol1=validate_identity_number(identity_number);
        printf("Enter your password\n");
        scanf("%d",&password);
        if(password>999 && password<10000){
            kontrol2=1;
        }
        if(kontrol1==1 && kontrol2==1){
            break;
        }
    }
    create_customer(identity_number,password);
    
}

void part3(){
    char identity_number[100];
    int password,kontrol=0;
    printf("login your identity number:\n");
    scanf("%s",identity_number);
    printf("login your password:\n");
    scanf("%d",&password);
    kontrol=check_login(identity_number,password);
    
    if(kontrol==1){
        float cash_amount;
        printf("login succesful\n");
        printf("Enter your withdraw amount: ");
        scanf("%f",&cash_amount);
        printf("Withdrawable amount is: %d",withdrawable_amount(cash_amount));
    }
    else{
        printf("login failed");
        exit(0);
    }

}