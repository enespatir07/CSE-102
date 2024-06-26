#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*d2-n2*d1;
    *d3=d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*n2;
    *d3=d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*d2;
    *d3=d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
   
   //Writing several control flows to check if numerator and/or denumerator is/are negative so that we can change them and make them suitable for the gcd algorithm.
   if(*n<0 && *d<0)
   {
    *n=*n*-1;
    *d=*d*-1;
   int gcd=1,i=1;

   while (i <=*n && i<=*d)
   {
       if(*n%i==0 && *d%i==0){
            gcd=i;
        }
        i++;
   }
   *n=*n/gcd;    
   *d=*d/gcd;
   }

   else if(*n<0)
   {
   int gcd=1,i=1;
   *n=*n*-1;

   while (i <=*n && i<=*d)
   {
       if(*n%i==0 && *d%i==0){
            gcd=i;
        }
        i++;
   }
   
   *n=*n/gcd; 
   *d=*d/gcd;
    *n=*n*-1;
   }

   else if(*d<0)
   {
    *d=*d*-1;
    int gcd=1,i=1;

   while (i <=*n && i<=*d)
   {
       if(*n%i==0 && *d%i==0){
            gcd=i;
        }
        i++;
   }
   *n=*n/gcd;    
   *d=*d/gcd;
   *d=*d*-1;
   }

   else
   {
   int gcd=1,i=1;

   while (i <=*n && i<=*d)
   {
       if(*n%i==0 && *d%i==0){
            gcd=i;
        }
        i++;
   }
   *n=*n/gcd;    
   *d=*d/gcd;
   }
 
} /* end fraction_div */

