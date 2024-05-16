#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define MAX_LEN 50
#define TRUE 1
#define FALSE 0

int main(){
    int xs,seqlen,currentlen=0,digit,*h,*seq,looplen,*loop;
    printf("Please enter the sequence length: ");   
    scanf("%d",&seqlen);                            /*  INPUT */
    printf("Please enter the first element: ");             
    scanf("%d",&xs);                                /*  INPUT */
    looplen = seqlen/2;
    h = (int*)calloc(seqlen,sizeof(int));
    seq = (int*)calloc(seqlen,sizeof(int));
    loop = (int*)calloc(seqlen,sizeof(int));
    check_loop_iterative(generate_sequence,xs,seqlen,loop,&looplen);
    if(looplen<2) printf("No loop found\n\n");
    else{
        printf("Loop: {");
        for(int i =0;i<looplen;i++){                    
            if(i==looplen-1)printf("%d}\n\n",loop[i]);                  /* PRINTING THE LOOP IF FOUND*/
            else printf("%d, ",loop[i]);
        }
    }    
    hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit);
    for(int i=1;i<10;i++){
        if(i==1)printf("Histogram of the sequence: {%d, ",h[i]);        /* PRINTING THE HISTOGRAM OF THE SEQUENCE */
        else if(i==9)printf("%d}",h[i]);
        else printf("%d, ",h[i]);
    }
    return 0;
}