 typedef struct stocktxn
{
  int Itemno;
  float Qty;
  char Txn;
}STOCKTXN;

void RecieptOrIssue(char Txn);
void Transaction(int itemcode, char Txn, float qty);
void Transactionlist();
void transactiondetails(int itemcode);
void Stocklist();
float BAL_Stock(int itemcode);

