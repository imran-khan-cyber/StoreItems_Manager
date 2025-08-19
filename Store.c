#include<stdio.h>
#include<string.h>
#include"Store.h"

/*  GLOBAL VARIABLES DECLARED HERE  */
ITEMSTORE items[25];
int itemcount;

void initializeitems()
{
  FILE *f;
  ITEMSTORE st;
  char filename[]="./StoreItem.bin";
  f=fopen(filename,"rb");
  itemcount=0;
  while(fread(&st,sizeof(ITEMSTORE),1,f))
{
  items[itemcount].itemno=st.itemno;
  strcpy(items[itemcount].itemdesc,st.itemdesc);
  itemcount++; 
}
  fclose(f);
}

void listitems()
{
    int i;
	ITEMSTORE st;
	printf("\nList of Items...\n");
	printf("\n\nItemcode   Itemname(Desc)\n");
	printf("\n--------   --------------");
	for(i=0;i<itemcount;i++)
{
	st=items[i];
	printf("\n%-d.%20s",st.itemno,st.itemdesc);	   
}
}

int Getitemname(int itemno,char *itemname)
{
     int itemfound=0;
	 int i;
	 for(i=0;i<itemcount;i++)
{
	 if(itemno==items[i].itemno)
{
	  strcpy(itemname,items[i].itemdesc);
	  itemfound=1;
	  break; 
}
}
      return itemfound;
}

ITEMSTORE *GetStoreItems()
{
	return items;
}

int GetItemsCount()
{
	return itemcount;
}


