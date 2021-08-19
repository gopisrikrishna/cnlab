#include <stdio.h>
void main ()
{
char str [50];
int i;
printf("Enter input string");
gets(str);
printf ("After byte stuffing");
printf("\nIn Sender side \n");
printf("\nDLE STX ");
for (i=0; i< (strlen (str)-1); i++)
{
if(str[i]=='D') {
if(str[i+1]=='L') {
if (str [i+2]=='E') {
printf (" DLE DLE ");
i+=2;
continue;
}
}
}
printf(" %c DLE ",str[i]);
} // end of loop
if(i<strlen(str))
printf("%c ",str[strlen(str)-1]);
printf(" DLE ETX ");
printf("\nAfter bits unstuffing \n");
printf("\nAt Receiver side ");
for(i=0;i<strlen(str);i++)
printf("%c ",str[i]);
}