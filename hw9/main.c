#include<stdio.h>
#include<string.h>
#define MAX_CUSTOMER_NUM 50
#define MIN_VALUE -9999
#define MAX_VALUE 9999
#define FALSE -1
#define TRUE 1




union Person{
    char name[50]; 
    int phone; 
    char address[50]; 
};


union Loan{
    float amount; 
    float interestRate; 
    int period; 
};


typedef struct{
    union Person Customer; 
    union Loan Loans[3]; 
}BankAccount;


typedef struct Period{//period struct to hold the period of loans
    int period1[3];
}Period;



Period PeriodArr[MAX_CUSTOMER_NUM];
BankAccount StructArray[MAX_CUSTOMER_NUM];
int customeridnum = 0;//Variable to hold the number of the accounts
FILE*fp;


void addCustomer(){
    int check;
    if(customeridnum==50){//Checks if the number of accounts reached the maximum
        printf("CAN'T KEEP MORE THAN 50 CUSTOMER ACCOUNT\n");
        return;
    }


    fp = fopen("customers.txt","a+");
 
    
	fflush(stdin);
    do{//Take input and check if it is correct
        printf("Customer Phone:");
        check = scanf("%d",&StructArray[customeridnum].Customer.phone);
        if(check!=1){
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        } 
    }while (check!=1);
    fprintf(fp,"Customer Phone = %d\n",StructArray[customeridnum].Customer.phone);


    printf("Customer Address:");
	fflush(stdin);
	scanf(" %[^\n]%*c",StructArray[customeridnum].Customer.address);
    fprintf(fp,"Customer Address = %s\n",StructArray[customeridnum].Customer.address);


    printf("Customer Name:");
	fflush(stdin);
	scanf(" %[^\n]%*c",StructArray[customeridnum].Customer.name);
    fprintf(fp,"Customer Name = %s\n\n",StructArray[customeridnum].Customer.name);


    StructArray[customeridnum].Loans[0].amount=0.0;
    StructArray[customeridnum].Loans[1].amount=0.0;         //Initilazing 3 loans of each account with 0 value
    StructArray[customeridnum].Loans[2].amount=0.0;


    PeriodArr[customeridnum].period1[0] = 0;
    PeriodArr[customeridnum].period1[1] = 0;                //Initilazing 3 periods of each account with 0 value
    PeriodArr[customeridnum].period1[2] = 0;


    fclose(fp);
    customeridnum++;//next customer
}


int searchforaccount(char *search){//Searches if the given names is in the struct array
    for(int i=0;i<customeridnum;i++){
        if(strcmp(search,StructArray[i].Customer.name)==0) return i;
    }    
    return FALSE;
}


float calculateLoan(float amount, int period, float interestRate){// 𝑳𝒐𝒂𝒏 𝑭𝒐𝒓𝒎𝒖𝒍𝒂= 𝑨𝒎𝒐𝒖𝒏𝒕∗( 𝟏+𝒊𝒏𝒕𝒆𝒓𝒆𝒔𝒕𝑹𝒂𝒕𝒆)^period
    float base = (1.0+interestRate);
    if(period!=0){
        if(period==1)return base*amount;
        return base*calculateLoan(amount,period-1,interestRate);
    }
    else return 1.0;
}


void newLoan(){
    if(customeridnum==0){
        printf("No Customer account found\n");
        return;
    }

    int id,period,flag=0,check1,check2,check3;
    float amount,interestRate;

    do{//CHECKS IF THE ENTRIED NAME'S ACCOUNT IS CREATED 
        char search[100];
        printf("Enter your name please :");
        fflush(stdin);
        scanf(" %[^\n]%*c",search);
        id = searchforaccount(search);
        if(id==FALSE)printf("Enter a valid name\n");
    }while(id==FALSE);


    for(int i = 0; i<3;i++){//Checks if one can take out any loan
        if(StructArray[id].Loans[i].amount!=0.0)flag++;
        if(flag==3){
            printf("You can't take out no more loan\n");
            return;
        }
    }
    
    do{//Take input and check if it is correct
        printf("amount of loan: ");
        check1 = scanf("%f",&amount);
        if(check1!=1 || amount<=0){
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        } 
    }while (check1!=1 || amount<=0);

    do{//Take input and check if it is correct
        printf("period: ");
        check2 = scanf("%d",&period);
        if(check2!=1 || period<=0){
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        } 
    }while (check2!=1 || period<=0);

    do{//Take input and check if it is correct
        printf("interest rate: ");
        check3 = scanf("%f",&interestRate);
        if(check3!=1 || interestRate<=0){
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        } 
    }while (check3!=1 || interestRate<=0);

    for(int i = 0; i<3;i++){// Taking out loan in the appropirate index
        if(StructArray[id].Loans[i].amount==0.0){
            StructArray[id].Loans[i].amount=calculateLoan(amount,period,interestRate);
            PeriodArr[id].period1[i] = period;
            break;
        }
    }    
}


void listCustomers(){
    if(customeridnum==0){printf("No Customer account found\n");return;}
    float sum;
    for(int i = 0;i<customeridnum;i++){//PRINTING ID, NAME AND LOANS OF EVERY CUSTOMER ACCOUNT
        printf("Customer ID = %d\n",i+1);
        printf("Customer Name = %s\n",StructArray[i].Customer.name);
        if(StructArray[i].Loans[0].amount==0)printf("NO LOANS\n\n");
        else if(StructArray[i].Loans[1].amount==0)printf("LOANS = %.2f\n\n",StructArray[i].Loans[0].amount);
        else if(StructArray[i].Loans[2].amount==0)printf("LOANS = [%.2f + %.2f] => %.2f\n\n",StructArray[i].Loans[0].amount,StructArray[i].Loans[1].amount,StructArray[i].Loans[0].amount+StructArray[i].Loans[1].amount);
        else printf("LOANS = [%.2f + %.2f + %.2f] => %.2f\n\n",StructArray[i].Loans[0].amount,StructArray[i].Loans[1].amount,StructArray[i].Loans[2].amount,StructArray[i].Loans[0].amount+StructArray[i].Loans[1].amount+StructArray[i].Loans[2].amount);
    }
}


void getReport(){
    if(customeridnum==0){printf("No Customer account found\n");return;}
    int choice,i,check;
    float total;
    char ch;
    printf("\nChoose option 1 (Customer list) or 2 (Loan detail): ");
    do{//Take input and check if it is correct
        check = scanf("%d",&choice);
        if(check!=1|| choice<1 || choice>2){
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        } 
    }while (check!=1 || choice<1 || choice>2);

    switch(choice)
    {
        case 1:
            fp = fopen("customers.txt","r"); 
            while(!feof(fp)){  //READ FROM FILE
                ch = fgetc(fp);
                printf("%c",ch);
            }
            fclose(fp);
            break;

        case 2:;
            int credit,x,id,control=FALSE;

            do{//CHECKS IF THE ENTRIED NAME'S ACCOUNT IS CREATED 
                char search[100];
                printf("Enter the name of the customer account for month installment: ");
                fflush(stdin);
                scanf(" %[^\n]%*c",search);
                id = searchforaccount(search);
                if(id==FALSE)printf("Enter a valid name\n");
            }while(id==FALSE);
            
            do{//CHECKS IF ENTRIED MONTH INSTALLMENT IS PRESENT
                printf("Which month installment would you like to see(1,2 or 3): ");
                do{//Take input and check if it is correct
                    x = scanf("%d",&credit);
                    if(x!=1|| credit<1 || credit>3){
                        printf("ERROR! Please try a valid entry.\n");
                        int c;
                        do {
                            c = getchar();
                        } while (c != '\n' && c != EOF);
                    } 
                }while (x!=1 || credit<1 || credit>3);
                if(StructArray[id].Loans[credit-1].amount!=0)control=TRUE;
                else printf("Month installment %d is not present. Please enter a valid number\n",credit);
            }while(control==FALSE);

            fp = fopen("loans.txt","w");// WRITING TO FILE THE MONTH INSTALLMENT DETAILS
            fprintf(fp,"Customer ID = %d\n",id+1);
            fprintf(fp,"Customer Name = %s\n",StructArray[id].Customer.name);
            fprintf(fp,"Total Credit Value = %.2f\n",StructArray[id].Loans[credit-1].amount);
            for(int i=1;i<=PeriodArr[id].period1[credit-1];i++){
                fprintf(fp,"%d. Month Installment = %.4f\n",i,StructArray[id].Loans[credit-1].amount/PeriodArr[id].period1[credit-1]);
            }
            fprintf(fp,"\n");

            fclose(fp);
            fp = fopen("loans.txt","r");
            printf("\n");   
            while(!feof(fp)){//READ FROM FILE AND PRINT ON THE SCREEN
                ch = fgetc(fp);
                printf("%c",ch);
            }
            fclose(fp);          
                                     
            break;
    }

}


int main(){
    fp = fopen("customers.txt","w");
    fclose(fp);
    int choice,check;
    do{ //MENU
        printf("=====================================\n");
        printf("Welcome to the Bank Management System\n");
        printf("=====================================\n");
        printf("    1. List All Customers\n");
        printf("    2. Add New Customers\n");
        printf("    3. New Loan Application\n");
        printf("    4. Report Menu\n");
        printf("    5. Exit System\n");
        do{//Take input and check if it is correct
            check = scanf("%d",&choice);
            if(check!=1 || choice<1 || choice>5){
                printf("ERROR! Please try a valid entry.\n");
                int c;
                do {
                    c = getchar();
                } while (c != '\n' && c != EOF);
            } 
        }while (check!=1|| choice<1 || choice>5);

        switch(choice)
        {
            case 1:
                listCustomers();
                break;

            case 2:
                addCustomer();
                break;

            case 3:
                newLoan();
                break;

            case 4:
                getReport();
                break;
        }
    }while(choice!=5);

    return 0;
}