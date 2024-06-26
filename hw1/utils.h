#ifndef _UTILS_H_
#define _UTILS_H_



int validate_identity_number(char identity_number[]);
int create_customer(char identity_number[],int password);
int check_login(char identity_number[],int password);
int withdrawable_amount(float cash_amount);
int find_divisible(int x,int y,int z);
int find_nth_divisible(int n,int f_l,int z);

#endif /* _UTILS_H_ */