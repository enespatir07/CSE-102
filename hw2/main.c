#include <stdio.h>
#include <stdlib.h>
#include "util.h"


void main() {

    /* Ask for the problem selection (1,2,3) .....  */
   
    printf("Which problem(0,1,2,3) do you want to be solved: ");
    char choice = getchar();
    printf("Put a whitespace character after each input.\n\n");


    if(choice == '0')
    {   
        int t,w;
        double p,h;
        int s;
        printf("Please enter the values of temperature pressure humidity sunny or not day of the week\n");
        scanf("%d %lf %lf %d %d",&t,&p,&h,&s,&w);
        if(dt0(t,p,h,s,w)==1) printf("You should turn on your AC");
        else printf("You should turn off your AC");
    }
    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    else if(choice == '1') 
    {
       double pl,pw,sl,sw;
       char x[100];
       printf("Please enter the PL PW SL SW: ");
       scanf("%lf %lf %lf %lf",&pl,&pw,&sl,&sw);
       x[0]=dt1a(pl,pw,sl,sw);
       x[1]=dt1b(pl,pw,sl,sw);
    /* Compare performances and print results */
       if(x[0]==x[1]){
           if(x[0]=='s') printf("Setosa");
           else if(x[0]=='v') printf("Versicolor");
           else if(x[0]=='g') printf("Verginica");
       }
       else{
           if(x[0]=='s' && x[1]=='v') printf("For dt1a setosa , For dt1b versicolor");
           else if(x[0]=='s' && x[1]=='g') printf("For dt1a setosa , For dt1b verginica");
           else if(x[0]=='v' && x[1]=='s') printf("For dt1a versicolor , For dt1b setosa");
           else if(x[0]=='v' && x[1]=='g') printf("For dt1a versicolor , For dt1b verginica");
           else if(x[0]=='g' && x[1]=='s') printf("For dt1a verginica , For dt1b setosa");
           else if(x[0]=='g' && x[1]=='v') printf("For dt1a verginica , For dt1b versicolor");
       }
    }
    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    else if(choice == '2')
    {
        double x1,x2,x3;
        int x4,x5; // binary nums
        printf("Please enter the x1 x2 x3 x4 x5(x4 and x5 must be either 0 or 1): ");
        scanf("%lf %lf %lf %d %d",&x1,&x2,&x3,&x4,&x5);
         /* Compare performances and print results */
        if(dt2a(x1,x2,x3,x4,x5)==dt2b(x1,x2,x3,x4,x5)){
            printf("%lf",dt2a(x1,x2,x3,x4,x5));
        }
        else if(dt2a(x1,x2,x3,x4,x5)-dt2b(x1,x2,x3,x4,x5)==CLOSE_ENOUGH || dt2b(x1,x2,x3,x4,x5)-dt2a(x1,x2,x3,x4,x5)==CLOSE_ENOUGH ){
            printf("%lf",(dt2a(x1,x2,x3,x4,x5)+dt2b(x1,x2,x3,x4,x5))/2);
        }
        else{
            printf("For dt2a it is %.2lf\n",dt2a(x1,x2,x3,x4,x5));
            printf("For dt2b it is %.2lf\n",dt2b(x1,x2,x3,x4,x5));
        }
    }
    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    else if(choice == '3')
    {  
        // a decision tree for determining the type of the bacteria by reading enviromental conditions from the user

        double ort,temp;
        int odev;
        int kalan_gun;
        int weather_num;
        int day_num;

        printf("Choose a number for both the given weather type(1-5) and day(1-7) that is appropriate for you.\n");
        printf("For weather types: sunny, cloudy, windy, rainy, snow\n");
        printf("For days: monday, tuesday, wednesday, thursday, friday, satuday, sunday\n\n");
        printf("Please enter the values of gpa, temperature, if you have homework(1 or 0), days left for homework, weather and day number:\n");
        
        scanf("%lf %lf %d %d %d %d",&ort,&temp,&odev,&kalan_gun,&weather_num,&day_num);
 
        /* Compare performances and prin    t results */

        if(dt3a(ort,temp,odev,kalan_gun,weather_num,day_num)==dt3b(ort,temp,odev,kalan_gun,weather_num,day_num))
        {printf("You should %s",dt3a(ort,temp,odev,kalan_gun,weather_num,day_num));}

        else{
            printf("For dt3a you should %s\n",dt3a(ort,temp,odev,kalan_gun,weather_num,day_num));
            printf("For dt3b you should %s\n",dt3b(ort,temp,odev,kalan_gun,weather_num,day_num));
        }

    }

}