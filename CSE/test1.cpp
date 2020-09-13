#include "stdafx.h" 
#include "stdio.h" 
#include "string.h" 
#include "stdlib.h" 
 
int main(int argc, char* argv[]) 
{  
    FILE *fp1=NULL, *fp2=NULL;  
    fp1 = fopen("Copy.cpp","r+");  
    char ch, temp[1000];  
    int i,num;  
    printf("请输入复制次数：");  
    scanf("%d",&num);  
    for(i=0; i<num; i++)  
    {   
        rewind(fp1);   
        char file1[50]="C:\\copy0.cpp";    
        *(file1+7) += i ;   
        fp2 = fopen(file1,"w+");   
        while((ch = (fread(temp,1,sizeof(temp),fp1)))!= 0)    
            fwrite(temp,1,ch,fp2);   
        fclose(fp2);  
    }  
    fclose(fp1);  
    fp1=NULL; 
    fp2=NULL;  
    return 0; 
} 