typedef struct{
   int itemno;
   char itemdesc[31];
} ITEMSTORE;
#include<stdio.h>
int main(){
     int n,i;
   printf("\nPlease enter how much data items should be written in a file : ");
   scanf("%d",&n);
   ITEMSTORE st[n];
    FILE *f;
	char  bfilename[]="./StoreItem.bin";
   f=fopen(bfilename,"ab");
   for(i=0;i<n;i++){
   printf("\nEnter Item no %d : ",i+1);
   scanf("%d",&st[i].itemno);
   fflush(stdin);
   printf("\nEnter Item Name : ");
   gets(st[i].itemdesc);
   
  } 
   fwrite(st,sizeof(ITEMSTORE),n,f);
   
   fclose(f);
}

