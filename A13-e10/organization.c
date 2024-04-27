#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
struct file{ 
char fileName[15][20]; 
char dirName[10]; 
int fno; 
}; 
struct file dir; 
int i,n; 
void InsertFile(){ 
printf("Enter the File name "); 
scanf("%s",dir.fileName[dir.fno]); 
dir.fno++; 
} 
void DisplayFiles(){ 
printf("Directorytfiles | "); 
printf("--->"); 
printf("%s",dir.dirName); 
for(i=0;i<dir.fno;i++){ 
printf("---->%s",dir.fileName[i]); 
} 
printf("\n"); 
} 
void DeleteFile(){ 
char name[20]; 
printf("Enter the file to be deleted : "); 
scanf("%s",name); 
for(i=0;i<dir.fno;i++){ 
if(strcmp(dir.fileName[i],name)==0){ 
printf("%s is deleted \n",dir.fileName[i]); 
strcpy(dir.fileName[i],dir.fileName[dir.fno-1]); 
dir.fno--; 
} 
} 
} 
void SearchFile(){ 
char name[20]; 
int found=-1; 
printf("Enter the file to be searched :"); 
scanf("%s",name); 
for(i=0;i<dir.fno;i++){ 
if(strcmp(dir.fileName[i],name)==0){ 
printf("The File is found at position %d \n",i+1); 
found=1; 
break; 
} 
}
if(found==-1) 
printf("the file is not found \n"); 
} 
int main(){ 
int op; 
dir.fno=0; 
printf("Enter the directory name : "); 
scanf("%s",dir.dirName); 
while(1){ 
printf("choose the option 1:Insert a file\t2:Display Files\t3:Delete File\t4:Search
Filen\t5:Exit>>"); 
scanf("%d",&op); 
switch(op){ 
case 1:InsertFile(); 
break; 
case 2:DisplayFiles(); 
break; 
case 3:DeleteFile(); 
break; 
case 4:SearchFile(); 
break; 
case 5:exit(0);
} 
} 
return 0; 
}
