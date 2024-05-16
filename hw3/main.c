#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_VALUE 9999
#define MIN_VALUE -9999

void write_file(int number)
{
    FILE*fp=fopen("result.txt","a+");
    fprintf(fp,"%d ",number);
    fclose(fp);
}


int check (int value){
    // EN KUCUK 3 SAYIYI BULURKEN DAHA ONCE BULUNAN EN KUCUK 3 SAYIYI TEKRAR BULMAYI ENGELLEME AMACIYLA OLUSTURULDU.
	int num;
	FILE *tfp;
	tfp = fopen ("temp.txt", "r");
	while(!feof(tfp))
    {
        //DOSYADAKI DEGER GONDERILEN DEGERE ESITSE VAR ANLAMINDA 1 GONDERILIR.
        fscanf(tfp,"%d",&num);
        if(value == num){
            return 1;
        }
	}
    return 0;
    
}


int sum(int n1,int n2,int flag)
{
    switch (flag)
    {
        case 0:; // CIFT SAYI DURUMU
            int x,score=0;
            if(n1%2==0) x=2;
            else x=1;
            for (int i =n1+x; i <n2; i+=2)
            {
                score+=i;
                if(i==n2-2) printf("%d =",i);
                else if(i==n2-1) printf("%d =",i);
                else printf("%d + ",i);
            }
            printf(" %d",score);
            return score;

        case 1:; // TEK SAYI DURUMU
            int y=0,score2=0;
            if(n1%2==0)y++;
            else y+=2;
            for(int i=n1+y;i<n2;i+=2){
                score2+=i;
                if(i==n2-2) printf("%d =",i);
                else if(i==n2-1) printf("%d =",i);
                else printf("%d + ",i);
            }
            printf(" %d",score2);
            return score2;
                 
    }
}


int multi(int n1,int n2,int flag){

    switch(flag)
    {
        case 0:;//CIFT SAYI DURUMU
            int x,score=1;
            if(n1%2==0) x=2;
            else x=1;
            for (int i =n1+x; i <n2; i+=2)
            {
                score*=i;
                if(i==n2-2) printf("%d =",i);
                else if(i==n2-1) printf("%d =",i);
                else printf("%d * ",i);
            }
            printf(" %d",score);
            return score;
        case 1:;// TEK SAYI DURUMU
            int y=0,score2=1;
            if(n1%2==0)y++;
            else y+=2;
            for(int i=n1+y;i<n2;i+=2){
                score2*=i;
                if(i==n2-2) printf("%d =",i);
                else if(i==n2-1) printf("%d =",i);
                else printf("%d * ",i);
            }
            printf(" %d",score2);
            return score2;
    }
}


int isprime(int a){
    double x;
    int flag=0,k;
    x = sqrt((double)a);
    x = floor(x);
    int y=(int)x;
    for(int i=2;i<=y;i++){
        if(a%i==0){
            k=i;
            flag++;
            break;
        }
    }
    if(flag==0) return 1;
    else return k; // ASAL DEGILSE EN KUCUK TAM BOLENINI GONDERIR
}


void print_file()
{
    int n;
    FILE *fp = fopen("result.txt","r");
    if(fp==NULL){
        printf("hata");
        return; 
    }
    while(!feof(fp)){
        fscanf(fp,"%d ",&n);
        printf("%d ",n);
    }
    fclose(fp);
}


void sort_file()
{
    int min1=MAX_VALUE,min2=MAX_VALUE,min3=MAX_VALUE,score=0,num;
    FILE*fp =fopen("result.txt","r");
    // DOSYADAKI ELEMAN SAYISININ BIR DEGISKENDE TUTULMASI
    while (!feof(fp))
    {
        fscanf(fp,"%d",&num);
        score++;
    }
    fclose(fp);
    fp=fopen("result.txt","r");   
    // EN KUCUK 3 SAYININ BULUNMASI 
    while(!feof(fp))
    {
        fscanf(fp,"%d",&num);
        if(num<min1)
        {
            min3=min2;
            min2=min1;
            min1=num;
        }
        if(num<min2 && num>min1)
        {
            min3=min2;
            min2=num;
        }
        if(num>min2 && num<min3)min3=num;
    }
    fclose(fp);
    FILE*tfp=fopen("temp.txt","w");
    fprintf(tfp,"%d %d %d ",min1,min2,min3);
    fclose(tfp);
    // HER SONRAKI EN KUCUK 3 SAYININ BULUNMASI
    for(int i=0;i<(score/3);i++)
    {
        min1=MAX_VALUE,min2=MAX_VALUE,min3=MAX_VALUE;
        fp=fopen("result.txt","r");    
        while(!feof(fp))
        {
            fscanf(fp,"%d",&num);
            if(check(num)==0)
            {
                if(num<min1)
                {
                    min3=min2;
                    min2=min1;
                    min1=num;
                }
                if(num<min2 && num>min1)
                {
                    min3=min2;
                    min2=num;
                }
                if(num>min2 && num<min3)min3=num;
            }

        }
        fclose(fp);
        tfp=fopen("temp.txt","a");
        // SABIT DEGER(MAX_VALUE || MIN_VALUE) OLMADIGINDAN EMIN OLARAK BASTIRMAK
        if(min1!=MAX_VALUE)fprintf(tfp,"%d ", min1);
        if(min2!=MAX_VALUE)fprintf(tfp,"%d ", min2);
        if(min3!=MAX_VALUE)fprintf(tfp,"%d ", min3);
        fclose(tfp);        
    }
    tfp=fopen("temp.txt","r");       
    int n;
    while(!feof(tfp))
    {
        fscanf(tfp,"%d ",&n);
        if(n!=MAX_VALUE)printf("%d ",n);
    }
    fclose(tfp);
    remove("result.txt");
    rename("temp.txt","result.txt");
}


int main()
{
    // MENU 
    int menu_secimi;
    // HATALI GİRDİ VERILDIGI SURECE TEKRAR SORACAK.
    do
    {
        printf("Select operation\n");
        printf("1. Calculate sum/multiplication between two numbers\n");
        printf("2. Calculate prime numbers\n");
        printf("3. Show numbers in sequence in file\n");
        printf("4. Sort numbers in sequence in file\n");
        scanf("%d",&menu_secimi);
        if(menu_secimi>4 || menu_secimi<1) printf("Invalid input, try again.\n\n");
    } while (menu_secimi>4 || menu_secimi<1);
    
                       
    // PART 1
    if(menu_secimi==1)
    {
        int n1,n2,flag,operation;
        // HATALI GİRDİ VERILDIGI SURECE TEKRAR SORACAK.
        do
        {
            printf("Please enter '0' for sum, '1' for multiplication.\n");
            scanf("%d",&operation);
            printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
            scanf("%d",&flag);
            if(flag<0 || flag>1 || operation<0 || operation>1)printf("Invalid input,please try again.\n");
        } while (flag<0 || flag>1 || operation<0 || operation>1);
        do
        {
            printf("Please enter two different integer numbers:\n");
            printf("Number 1: ");
            scanf("%d",&n1);
            printf("Number 2: ");
            scanf("%d",&n2);
            if(n1<0 || n2<0 || n1>n2) printf("Invalid input,please try again.\n");             
        } while (n1<0 || n2<0 || n1>n2);
        switch(operation)
        {
            case 0:
                //SONUCUN EKRANA BASTIRILMASI VE RESULT.TXT ADLI DOSYAYA YAZDIRILMASI
                printf("Result\n");
                write_file(sum(n1,n2,flag));
                printf("\nThe result is written to the result.txt file.");
                break;

            case 1:
                //SONUCUN EKRANA BASTIRILMASI VE RESULT.TXT ADLI DOSYAYA YAZDIRILMASI
                printf("Result\n");
                write_file(multi(n1,n2,flag));
                printf("\nThe result is written to the result.txt file.");
                break;
        }
    }

    // PART 2
    else if(menu_secimi==2)
    {
        int a;
        // HATALI GİRDİ VERILDIGI SURECE TEKRAR SORACAK.
        do
        {
            printf("Please enter an integer: ");
            scanf("%d",&a);
            if(a<3)printf("Invalid input, try again.\n");            
        } while (a<3);
        
        for (int i = 2; i <a; i++)
        {
           // GIRILEN SAYIYA KADAR OLAN SAYILARI ASAL ISE DIREKT EKRANA BASTIRMA DEGIL ISE 1 HARIC EN KUCUK TAM BOLENINI EKRANA BASTIRMA
           if(isprime(i)==1)printf("%d is a prime number.\n",i);
           else printf("%d is not a prime number, it is divisble by %d.\n",i,isprime(i));
        }    
    }

    // PART 3.1
    else if(menu_secimi==3)
    {
        printf("Result: \n");
        print_file();

    }

    // PART 3.2
    else if(menu_secimi==4)
    {
        printf("Sorting is complete.\n");
        printf("Result:\n");
        sort_file();
        
        
    }    



    return 0;
}


