#include "utils.h"
#include<stdio.h>
#include<stdlib.h>

int find_divisible(int x,int y,int z){

    if(x>y || y==x || (y-x)<=z){
        return 0;//false
    }
    else{
    for (int i =x+1; i <y; i++)
    {
        if(i%z==0){
            return i;
        }   
    }
    
    }
    
};

int find_nth_divisible(int n,int f_l,int z){
    int score=1;
    n=n+1;
    while(1){
        if(n%z==0){
            score++;
        }
        if(score==f_l+2){
            break;
        }
        n++;
    }
    return n;
};

int validate_identity_number(char identity_number[]){
    int length=100;
    int s=0;
    int ct=1;
    // kullanıcıdan 11 haneli stringi almak
    scanf("%s",identity_number);
    int i=0;
    while (identity_number[i]!='\0')
    {
        s++;
        i++;
    }
    
    
    //printf("ct( // kullanicidan 11 haneli stringi almak): %d\n",ct);
    // hane sayısı kontrolü
    if(s!=11){
        ct=0;
        //printf("ct(// hane sayisi kontrolü): %d\n",ct);
        return ct;//false
    }
    

    // her hanedeki karakterin sayi olduğunun kontrolü
    int flag=0;
    for(int i=0;i<11;i++){
        if(identity_number[i]<48 || identity_number[i]>57)
        {
            flag++;
            break;
        }
    }
    if(flag!=0){
        ct=0;
        //printf("ct(// her hanedeki karakterin sayi olduğunun kontrolü): %d\n",ct);
        return ct;//false
    }
    


    // ilk hane 0 olmadığı durumda true false dönüşü için değişkeni 1 arttırmak
    if(identity_number[0]=='0'){
        ct=0;
        //printf("ct( ilk hane 0 olmadigi durumda true false dönüşü için değişkeni 1 arttirmak): %d\n",ct);
        return ct; //false
    }
    

    
    // 2 4 6 8 . hanelerdeki sayiların toplamı
    int sc=0;
    for (int i =1; i <8; i+=2)
    {
        sc+=identity_number[i]-48;
    }
    
    // 1 3 5 7 9 . hanelerdeki sayıların toplamı

    int st=0;

    for (int i =0;i<9; i+=2)
    {
        st+=identity_number[i]-48;
    }
    
     
    // farkların 10a göre modunun
    st=st*7;
    if((st-sc)%10!=identity_number[9]-48){
        ct = 0;
        //printf("ct(// farklarin 10a göre modunun): %d\n",ct);
        return (ct);//false
    }
    

    int ilk10hane=0;

    for (int i = 0; i <=9; i++)
    {
        ilk10hane+=identity_number[i]-48;
    }
    
   // printf("ilk10hane : %d\n",ilk10hane);
    //printf("identity_number[10] : %d\n",identity_number[10]);

    if(( ilk10hane%10) != identity_number[10]-48){
        ct=0;
      //  printf("ct(ilk 10 hane): %d\n",ct);
        return ct;
    }
    
    return ct;
    
    
    
};

int create_customer(char identity_number[],int password){
    
    identity_number[11]=',';
    FILE *dosya;

    dosya=fopen("customeraccount.txt","w");

    fprintf(dosya,"%s%d",identity_number,password);
    
    
 

    fclose(dosya);

    return 1;//
    
};

int check_login(char identity_number[],int password){
    char eski_identity_number[100];
    int eski_password;
    FILE *dosya;
    dosya=fopen("customeraccount.txt","r");

    fscanf(dosya,"%s%d",eski_identity_number,&eski_password);

    int i=0;
    int flag=0;
    for (int i = 0; i < 11; i++)
    {
        if(identity_number[i]!=eski_identity_number[i]){
            flag++;
            break;
        }
    }
    if(flag==0){
        return 1;//true
    }
    
    return 0;
    



    fclose(dosya);

    
};

int withdrawable_amount(float cash_amount){
    int new_cash_amount;
    new_cash_amount=(int)cash_amount;

    int mod_on;
    mod_on=new_cash_amount%10;

    if(mod_on==0){
        return new_cash_amount;
    }
    else{
        return new_cash_amount-mod_on;
    }
};
