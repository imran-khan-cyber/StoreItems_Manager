#include<stdio.h>
#include<stdlib.h>
#include"Store.h"
#include"Stock.h"
void menu();

int main()
{
   initializeitems();
   menu();
}

void menu()
{
   int choice;
   while(1)
{
   system("cls");
   printf("\n\n       RR  TEXTILES");
   printf("\n\n   STOCK MANAGEMENT\n\n");
   printf("\n1. Receipt Entry");
   printf("\n2. Issue Entry");
   printf("\n3. Stock List");
   printf("\n4. Stock Transaction List");
   printf("\n5. View Store Items");
   printf("\n6. Exit");
   printf("\n\nEnter your choice (1-6) : ");
   scanf("%d",&choice);
	
   switch(choice)
{
   case 1:
	  RecieptOrIssue('R');
     break;
   case 2:
	  RecieptOrIssue('I');
     break;
   case 3:
	  Stocklist();
     break;
   case 4:
	  Transactionlist();
	 break;
   case 5:
	  listitems();
     break;
   case 6:
	  return;
	 break;
   default:
      printf("\nInvalid options!  Try again(1-6)...");
	 break;
}
    printf("\nPress any key to proceed...");
	getch();
}
}


