#include<stdio.h>
#include<string.h>
int failure[10];
int pmatch(char *string,char *pat)
{
int i=0;
int j=0;
int lens=strlen(string);
int lenp=strlen(pat);
while(i<lens && j<lenp)
{
if(string[i]==pat[j])
{
 i++;
 j++;
}
else if(j==0)
 i++;
else
 j=failure[j-1]+1;
}
return((j==lenp)?(i-lenp):-1);
}
void fail(char* pat)
{
int n,i,j;
n=strlen(pat);
failure[0]=-1;
for(j=1;j<n;j++)
{
i=failure[j-1];
while((pat[j]!=pat[i+1])&&(i>=0))
i=failure[i];
if(pat[j]==pat[i+1])
failure[j]=i+1;
else
failure[j]=-1;
}
}
int main()
{
char string[10],pat[10];
int flag;
printf("enter the string");
scanf("%s",string);
printf("enter the pattern to be searched");
scanf("%s",pat);
fail(pat);
flag=pmatch(string,pat);
if(flag==-1)
printf("pat is not found");
else
printf("string is found at %d location",flag+1);
return 0;
}