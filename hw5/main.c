#include <stdio.h>
#include <math.h>
#define PI 3.14


enum shapes{triangle=1,quadrilateral,circle,pyramid,cylinder};
enum calculators{area=1,perimeter,volume};

int select_shape()
{
    // MENU
    printf("Welcome to the geometric calculator!\n\n");
    printf("Select a shape to calculate:\n");
    printf("-----------\n");
    printf("%d. Triangle\n",triangle);
    printf("%d. quadrilateral\n",quadrilateral);
    printf("%d. circle\n",circle);
    printf("%d. pyramid\n",pyramid);
    printf("%d. cylinder\n",cylinder);  
    printf("%d. Exit\n",0);
    printf("-----------\n");
    printf("Input : ");
    int choice;
    int choice1,score;
    // CHECKING IF USER INPUT IS VALID
    do
    {
        choice1 = scanf("%d",&choice);
        score =choice1;
        if(score!=1 || choice<0 || choice>5)
        {
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        } 
    }while (score!=1 || choice<0 || choice>5);
    return choice;
}

int select_calc()
{
    // MENU
    printf("\nSelect calculator:\n");
    printf("-----------\n");
    printf("%d. Area\n",area);
    printf("%d. Perimeter\n",perimeter);
    printf("%d. Volume\n",volume);
    printf("%d. Exit\n",0);
    printf("-----------\n");
    printf("Input: ");
    int choice;
    int choice1,score;
    // CHECKING IF USER INPUT IS VALID
    do
    {
        choice1 = scanf("%d",&choice);
        score =choice1;
        if(score!=1 || choice<0 || choice>3)
        {
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
        } 
    }while (score!=1 || choice<0 || choice>3);
    return choice;
}

int calc_triangle(int y)
{
    float a,b,c,s;
    int a1,b1,c1,score;
    switch (y)
    {
    case area:
        printf("Please enter three sides of Triangle :\n");
        // CHECKING IF USER INPUT IS VALID
        do
        {
            a1 = scanf("%f",&a);
            b1 = scanf("%f",&b);
            c1 = scanf("%f",&c);
            score=a1+b1+c1;
            if(score!=3 || a<=0 || b<=0 || c<=0 ||(a+b)<c || (b+c)<a || (c+a)<b)
            {
                printf("ERROR! Please try a valid entry.\n");
                int c;
                do {
                    c = getchar();
                } while (c != '\n' && c != EOF);            
            }            
        } while (score!=3 || a<=0 || b<=0 || c<=0 ||(a+b)<c || (b+c)<a || (c+a)<b);
        s = (a+b+c)/2;
        printf("Area of triangle : %.2f\n\n",sqrt(s*(s-a)*(s-b)*(s-c)));
        break;
    case perimeter:
        printf("Please enter three sides of Triangle :\n");
        // CHECKING IF USER INPUT IS VALID
        do
        {
            a1 = scanf("%f",&a);
            b1 = scanf("%f",&b);
            c1 = scanf("%f",&c);
            score=a1+b1+c1;
            if(score!=3 || a<=0 || b<=0 || c<=0 ||(a+b)<c || (b+c)<a || (c+a)<b)
            {
                printf("ERROR! Please try a valid entry.\n");
                int c;
                do {
                    c = getchar();
                } while (c != '\n' && c != EOF);            
            }            
        } while (score!=3 || a<=0 || b<=0 || c<=0 ||(a+b)<c || (b+c)<a || (c+a)<b);
        printf("Perimeter of triangle : %.1f\n\n",a+b+c);
        break;
    }
    return 0;
}

int calc_quadrilateral(int y)
{
    float a,b,c,d,s;
    int a1,b1,c1,d1,score;
    switch (y)
    {
    case area:
        
        printf("Please enter four sides of Quadrilateral\n");
        // CHECKING IF USER INPUT IS VALID
        do
        {
        a1 = scanf("%f",&a);
        b1 = scanf("%f",&b);
        c1 = scanf("%f",&c);
        d1 = scanf("%f",&d);
        score=a1+b1+c1+d1;
        if(score!=4  || a<=0 || b<=0 || c<=0 || d<=0)
        {
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);            
        }            
        } while (score!=4 || a<=0 || b<=0 || c<=0 || d<=0);
        s = (a+b+c+d)/2;
        printf("Area of quadrilateral : %.2f\n\n",sqrt((s-a)*(s-b)*(s-c)*(s-d)));    
        break;
    case perimeter:
        printf("Please enter four sides of Quadrilateral\n");
        // CHECKING IF USER INPUT IS VALID
        do
        {
        a1 = scanf("%f",&a);
        b1 = scanf("%f",&b);
        c1 = scanf("%f",&c);
        d1 = scanf("%f",&d);
        score=a1+b1+c1+d1;
        if(score!=4 || a<=0 || b<=0 || c<=0 || d<=0)
        {
            printf("ERROR! Please try a valid entry.\n");
            int c;
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);            
        }            
        } while (score!=4 || a<=0 || b<=0 || c<=0 || d<=0);
        printf("Perimeter of quadrilateral : %.2f\n\n",a+b+c+d);
        break;
    }

    return 0;    
}

int calc_circle(int y)
{
    float r;
    int r1,score;
    switch(y)
    {
        case area:
            printf("Please enter the radius of the circle:\n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                r1 = scanf("%f",&r);
                score =r1;
                if(score!=1 || r<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=1 || r<=0);
            printf("Area of circle : %.2f\n\n",PI*r*r);
            break;
        case perimeter:
            printf("Please enter the radius of the circle:\n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                r1 = scanf("%f",&r);
                score =r1;
                if(score!=1 || r<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=1 || r<=0);
            printf("Perimeter of circle : %.2f\n\n",2*PI*r);
    }
    return 0;
}

int calc_pyramid(int y)
{
    float a,h,l;
    int a1,h1,l1,score; 
    switch(y)
    {
        case area:
            printf("Please enter the base side and slant height of the pyramid :\n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                a1 = scanf("%f",&a);
                l1 = scanf("%f",&l);
                score =a1+l1;
                if(score!=2 || a<=0 || l<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=2 || a<=0 || l<=0);
            printf("Base surface area of the pyramid : %.2f\n",a*a);
            printf("Lateral surface area of the pyramid : %.2f\n",2*a*l);
            printf("Surface area of the pyramid : %.2f\n",a*a + 2*a*l);
            break;
        
        case perimeter:
            printf("Please enter the base side of the pyramid :\n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                a1 = scanf("%f",&a);
                score =a1;
                if(score!=1 || a<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=1 || a<=0);
            printf("Base surface perimeter of the pyramid : %.2f\n\n",4*a);
            break;

        case volume:
            printf("Please enter the base side and height of the pyramid :\n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                a1 = scanf("%f",&a);
                h1 = scanf("%f",&h);
                score =a1+h1;
                if(score!=2 || a<=0 || h<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=2 || a<=0 || h<=0);
            printf("Volume of the pyramid : %.2f\n\n",(a*a*h)/3);
            break;
    }
    return 0;
}

int calc_cylinder(int y)
{
    float r,h;
    int r1,h1,score;
    switch(y)
    {
        case area:
            printf("Please enter the radius and height of the cylinder : \n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                r1 = scanf("%f",&r);
                h1 = scanf("%f",&h);
                score =r1+h1;
                if(score!=2 || r<=0 || h<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=2 || r<=0 || h<=0);
            printf("Base surface area of the cylinder : %.2f\n",PI*r*r);
            printf("Lateral surface area of the cylinder : %.2f\n",2*PI*r*h);
            printf("Surface area of the cylinder : %.2f\n",2*PI*r*(r+h));
            break;
        
        case perimeter:
            printf("Please enter the radius and height of the cylinder : \n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                r1 = scanf("%f",&r);
                h1 = scanf("%f",&h);
                score =r1+h1;
                if(score!=2 || r<=0 || h<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=2 || r<=0 || h<=0);
            printf("Base surface perimeter of the cylinder : %.2f\n\n",2*PI*r);
            break;

        case volume:
            printf("Please enter the radius and height of the cylinder : \n");
            // CHECKING IF USER INPUT IS VALID
            do
            {
                r1 = scanf("%f",&r);
                h1 = scanf("%f",&h);
                score =r1+h1;
                if(score!=2 || r<=0 || h<=0)
                {
                    printf("ERROR! Please try a valid entry.\n");
                    int c;
                    do {
                        c = getchar();
                    } while (c != '\n' && c != EOF);
                }     
            }while (score!=2 || r<=0 || h<=0);
            printf("Volume of the cylinder : %.2f\n\n",PI*r*r*h);
            break;
    }

    return 0;
}

int calculate(int (*select_shape)(),int (*select_calc)())
{
    // LOOP CONTINUES TILL THE USER INPUT EQUALS 0
    while(1)
    { 
        int x = select_shape();
        if(x==0)return 0;
        int y = select_calc();
        if(y==0)return 0;
        switch (x)
        {
            case triangle:
                if(y==volume)printf("ERROR ! You cannot calculate the volume of a triangle. Please try again.\n\n");
                else calc_triangle(y);
                break;
            case quadrilateral:
                if(y==volume)printf("ERROR ! You cannot calculate the volume of a quadrilateral. Please try again.\n\n");
                else calc_quadrilateral(y);
                break;
            case circle:
                if(y==volume)printf("ERROR ! You cannot calculate the volume of a circle. Please try again.\n\n");
                else calc_circle(y);
                break;
            case pyramid:
                calc_pyramid(y);
                break;
            case cylinder:
                calc_cylinder(y);
        }
    }
    return 0;   
}   

void main()
{
    calculate(select_shape,select_calc);
}