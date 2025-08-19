 typedef struct itemstore
{
   int itemno;
   char itemdesc[31];
}ITEMSTORE;

void initializeitems();
void listitems();
int Getitemname(int itemno,char *itemname);
ITEMSTORE *GetStoreItems();
int GetItemsCount();

