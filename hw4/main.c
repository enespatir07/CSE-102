#include <stdio.h>
void red () {
  printf("\033[1;31m");
}
void reset () {
  printf("\033[0m");
}
int main()
 {
 	int choice;
	do
	{
	printf("Select an operation...\n");
	printf("0. -> Enter the coefficients.\n");
	printf("1. -> Draw the graph.\n");
	printf("2. -> Print the graph into a .txt file.\n");
	printf("3. -> Exit.\n\n");
	printf("Choice: ");
	scanf("%d",&choice);
	printf("\n\n");
	
	if(choice==0)
	{
		FILE*fp=fopen("coefficients.txt","w");
		int a,b,c;	
		printf("Please enter the coefficient for the following equation: x = a*(y*y) + b*y + c\n");
		do
		{
			printf("a: ");
			scanf("%d",&a);
			printf("b: ");
			scanf("%d",&b);
			printf("c: ");
			scanf("%d",&c);
			if(a>2 || a<0)printf("enter valid numbers!\n");
		} while (a>2 || a<0);
		fprintf(fp,"%d\n%d\n%d\n",a,b,c);
		if(fp!=NULL)printf("\ncoefficients.txt file has been created.\n");
		fclose(fp);
	}
	
	if(choice==1)
	{
		int a,b,c,y,x; 
		FILE*fp=fopen("coefficients.txt","r");
		fscanf(fp,"%d %d %d",&a,&b,&c);
		fclose(fp);

		printf("Coefficients has been read from the coefficient.txt file.\n");
		printf("Printing the graph of x = %d(y*y) + %d*y +%d\n",a,b,c);
		
		for(y=16;y>=-15;y--)
		{
			for(x=-56;x<=56;x++)
			{
				
				if(x==a*y*y + b*y+c && y<16){
					red();
					printf("#");
					reset();
				}
				else if(y==0 && x==-56)printf("<");
				else if(y==0 && x==56)printf(">");
				else if(x==0 && y<=15 && y>=-15)printf("|");
				else if(y==0 &&x>=-55 && x<=55)printf("-");
				else if(x==0 && y==16)printf("^");
				else if(y==-1 && (x+1)%10==0 && x<=-10 && x>=-51)printf("\b\b%d",x+1);
				else if(y==-1 && (x+1)%10==0 && x>=9 && x<=50)printf("\b%d",x+1);
				else if(y==-1 && x==-1)printf("%d",0);
				else if(x==-1 && y%5==0 && y<=15 && y>=10)printf("\b%d",y);
				else if(x==-1 && y%5==0 && y>=-15 && y<=-10)printf("\b\b%d",y);
				else if(x==-1 && y==5)printf("%d",5);
				else if(x==-1 && y==-5)printf("%d",5);
				else printf(" ");
			}
			printf("\n");
		}
		
	}


	if(choice==2)
	{
		int a,b,c,x,y;
		FILE *fp=fopen("coefficients.txt","r");
		fscanf(fp,"%d %d %d",&a,&b,&c);
		fclose(fp);
		FILE *graphfp=fopen("graph.txt","w");
		

		for(y=15;y>=-15;y--)
		{
			for(x=-55;x<=55;x++)
			{
				if(x==a*y*y + b*y+c)fprintf(graphfp,"#");
				else if(y==0 && x==-55)fprintf(graphfp,"<");
				else if(y==0 && x==55)fprintf(graphfp,">");
				else if(y==0 &&x>-55 && x<55)fprintf(graphfp,"-");
				else if(x==0 && y==15)fprintf(graphfp,"^");
				else if(x==0 && y==-15)fprintf(graphfp,"v");
				else if(x==0 && y<15 && y>-15)fprintf(graphfp,"|");
				else fprintf(graphfp," ");
			}
			fprintf(graphfp,"\n");
		}

		fclose(graphfp);
	}
	if(choice==3)break;	
	}while(choice!=3);
	return 0;
}
