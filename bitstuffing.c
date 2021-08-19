#include <stdio.h>
void main() {
char str[50]; 
int i,flag=0;
printf("\nEnter input string ");
gets(str);
printf("\nAfter bits stuffing\n");
printf("\nIn Sender side ");
for(i=0;i<strlen(str);i++)
{
if(flag==5) { }
if(str[i]=='1') {
flag++;
printf(" 0 ");
flag=0;
}
else
flag=0;
printf(" %c ",str[i]);
}
printf("\nAfter bits unstuffing\n");
printf("\nAt Receiver side ");
for(i=0;i<strlen(str);i++)
printf("%c ",str[i]);
}