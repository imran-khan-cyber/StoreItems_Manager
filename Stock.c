#include<stdio.h>
#include<string.h>
#include"Stock.h"
#include"Store.h"

/*  DECLARED THIS FILE AS GLOBAL  */
char Stkfile[]="./StockTxn.bin";

void RecieptOrIssue(char Txn)
{
   STOCKTXN item;
   char Itemname[31];
   int itemfound;
   int itemno;
   float qty;
   char opt;
   printf("\nEnter the Item No : ");
   scanf("%d",&itemno);
   fflush(stdin);
   itemfound=Getitemname(itemno,Itemname);
   if(itemfound==0)
{
   printf("\nInvalid Item Code!");
   return;
}
   printf("\nItem Name : %-s",Itemname);
   printf("\nIs this Item  Name correct ? (Y/N) : ");
   scanf("%c",&opt);
   if(opt>='a'&&opt<='x'||opt>='A'&&opt<='X'||opt=='z'||opt=='Z')
   return;
   printf("\nEnter Item Quantity : ");
   scanf("%f",&qty);
   fflush(stdin);
   Transaction(itemno,Txn,qty);
}

void Transaction(int itemcode, char Txn, float qty)
{
	STOCKTXN trans;
	FILE *f;
	trans.Itemno = itemcode;
	trans.Txn = Txn;
	trans.Qty = qty;
	f = fopen(Stkfile, "ab");
	fwrite(&trans, sizeof(STOCKTXN), 1, f);
	fclose(f);
}

void Transactionlist()
{
   char itemname[31];
   int Itemno,itemfound;
   printf("\nEnter the Item No : ");
   scanf("%d",&Itemno);
   fflush(stdin);
   itemfound = Getitemname(Itemno,itemname);
   if(itemfound == 0){
   printf("\nInvalid Item Number!");
   return; 
}
   printf("\nItem Name : %-s\n",itemname);
   transactiondetails(Itemno);  
}

void transactiondetails(int itemcode)
{
    float ReciTot,IssTot,Reci,Iss;
	STOCKTXN trans;
	FILE *f;
    printf("\n%5sTransaction Details...\n\n"," ");
	ReciTot=IssTot=0;	
    f=fopen(Stkfile, "rb");
	while(fread(&trans, sizeof(STOCKTXN), 1, f))
{
	if(trans.Itemno == itemcode)
{
	Reci = 0;
	Iss = 0;
    if(trans.Txn == 'R')
	Reci = trans.Qty;
	else
	Iss = trans.Qty;
	ReciTot += Reci;
	IssTot += Iss;
	printf("\n%-10s ", trans.Txn=='R' ? "Receipt" : "Issue");
	if(Reci != 0)
	printf("%10.3f",Reci);
	else
	printf("%10s %10.3f", "",Iss);
}
}
    if(ReciTot > 0 || IssTot > 0)
{
	printf("\n%10s ---------- ----------", "");
	printf("\n%-10s %10.3f %10.3f", "Total: ", ReciTot,IssTot);
	if((ReciTot - IssTot) != 0)
{
	if(ReciTot > IssTot)
	printf("\n%-15s %10.3f", "Balance Stock: ", ReciTot - IssTot);
	else
	printf("\n%-15s %10s %10.3f", "Balance Stock: ", "", IssTot - ReciTot);	  
}
}
    else
	printf("\n\nNo transactions found.");
	fclose(f);
}

float BAL_Stock(int itemcode)
{
	STOCKTXN trans;
	float stock = 0;
	FILE *f = fopen(Stkfile, "rb");
	while(fread(&trans, sizeof(STOCKTXN), 1, f))
{
	if(trans.Itemno == itemcode)
{
	stock += (trans.Txn == 'R')? trans.Qty : -trans.Qty;
}
}
	fclose(f);
	return stock;
}


void Stocklist()
{
	int i;
	ITEMSTORE *items = GetStoreItems();	   
	int itemcount = GetItemsCount();
	ITEMSTORE item;	  
	float balancestk;
	printf(" \nItemcode   Itemname(Desc)   Stock(containing)\n");
	printf("\n---------   --------------   ------------------");
	for(i=0; i<itemcount; i++)
{
	item = items[i];			
	balancestk = BAL_Stock(item.itemno);
	if(balancestk != 0)
	printf("\n%-3d. %20s    %14.3f", item.itemno, item.itemdesc, balancestk);
} 
	
}


