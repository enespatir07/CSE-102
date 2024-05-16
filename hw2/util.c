#include <stdio.h>
#include <math.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}
/* Provide your implementations for all the requested functions here */
char dt1a(double pl, double pw, double sl, double sw){

    if(pl<2.45) return 's';

    else if(pw<1.65 && pl<4.95) return 'v';
    
    return 'g';
}

char dt1b(double pl, double pw, double sl, double sw){
    if(pl<2.55) return 's';

    else if(pl<4.85 && pw<1.69) return 'v';
    
    return 'g';
}

double dt2a(double x1,double x2, double x3,int x4,int x5){
    if (x1<31.5){
        if(x2>-2.5) return 5.0;

        else if(x1>=x2-0.1 && x1<=x2+0.1) return 2.1;

        return -1.1;
    }
    else{
        if(x3>=-1.0 && x3<=2.0) return 1.4;
        
        else if(x4==1 && x5==1) return -2.23; 

        return 11.0;
    }
}


double dt2b(double x1,double x2, double x3,int x4,int x5){
    if (x1<22 && x1>12){
        if(x3>(5/3)) return -2;   

        else if(x3>=x1-0.1 && x3<=x1+0.1) return 1.01;
        
        return -8;
    }
    else{
        if(x4==1 && x5==1) return -1;

        else if(x2>=-1 && x2<=2) return -1/7.0;
        
        return sqrt(2)/3.0;
    }
}


char *dt3a(double ort,double temp,int odev,int kalan_gun,int weather_num,int day_num){

    if(odev==1){
        if(kalan_gun<5) return "study";
        else if(temp<30 && temp>10) return "do outdoor sport";
        else if(weather_num==1 || weather_num==2 || weather_num==4 ) return "do indoor sport";
        else if(weather_num==3 || weather_num==5 && ort>3) return "play video games";
    }
    else{

        if(ort<2.5) return "study";
        else if(day_num<6) return "study";
        else if(temp>10 && temp<30) return "do outdoor sport";
        else if(weather_num==1 || weather_num==2 || weather_num==4 ) return "do indoor sport";
        else if(weather_num==3 || weather_num==5 && ort>3) return "play video games";
    }

}
char *dt3b(double ort,double temp,int odev,int kalan_gun,int weather_num,int day_num){
    if(odev==1){
        if(kalan_gun<4) return "study";
        else if(temp<31 && temp>15) return "do outdoor sport";
        else if(weather_num==1 || weather_num==2 || weather_num==4 && temp<10) return "do indoor sport";
        else if(weather_num==3 || weather_num==5 && ort>3) return "play video games";
    }
    else{

        if(ort<2.4) return "study";
        else if(day_num<5) return "study";
        else if(temp>15 && temp<31) return "do outdoor sport";
        else if(weather_num==1 || weather_num==2 || weather_num==4 && temp<10) return "do indoor sport";
        else if(weather_num==3 || weather_num==5 && ort>3) return "play video games";
    }

}


