#include<stdio.h>
#include<stdlib.h>
int main(void){
char path[5]="PATH";
int i=setenv(path,"/home/girish/progs:/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin:/usr/X11R6/bin:/root/bin",1);
if(i==-1)
printf("Error kano escape maadu");
else
if(i==0)
printf("Success maga!!!");

getchar();
}

