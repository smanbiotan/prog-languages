#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product
{
  char productCode[20];
  char productName[50];
  char category[30];
  int quantity;
  float unitPrice;
  char supplierName[50];
};

void inputRecords(struct Product *records, int n);
void displayAll(struct Product *records, int n);
void searchRecord(struct Product *records, int n);
void displaySummary(struct Product *records, int n);
const char *stockStatus(int qty);
void printDivider(void);
void printHeader(void);
void displayMenu(void);d

int main(void)
{
  int n;
  int choice;
  struct Product *records = NULL;
  printHeader();
  printf(" Enter number of product records to encode: ");
  scanf("%d", &n);
  getchar();
  if (n <= 0)
  {
    printf(" [ERROR] Invalid number of records. Exiting.\n\n");
    return 1;
  }
  records = (struct Product *)malloc(n * sizeof(struct Product));

  if (records == NULL)
  {
    printf(" [ERROR] Memory allocation failed. Exiting.\n\n");
    return 1;
  }
  inputRecords(records, n);
  do
  {
    displayMenu();
    printf(" Enter choice: ");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
      displayAll(records, n);
      break;
    case 2:
      searchRecord(records, n);
      break;
    case 3:
      displaySummary(records, n);
      break;
    case 4:
      printf("\n");
      printDivider();
      printf(" Freeing memory and exiting. Goodbye!\n");
      printDivider();
      printf("\n");
      break;
    default:
      printf("\n [!] Invalid choice. Please try again.\n\n");
    }
  } while (choice != 4);

  free(records);
  records = NULL;
  return 0;
}

void inputRecords(struct Product *records, int n)
{
  int i;
  printf("\n");
  printDivider();
  printf(" ENCODING %d PRODUCT RECORD(S)\n", n);
  printDivider();
  for (i = 0; i < n; i++)
  {
    printf("\n --- Record #%d ---\n", i + 1);
    printf(" Product Code : ");
    scanf("%s", (records + i)->productCode);
    getchar();
    printf(" Product Name : ");
    fgets((records + i)->productName, 50, stdin);
    (records + i)->productName[strcspn((records + i)->productName, "\n")] = '\0';
    printf(" Category : ");
    fgets((records + i)->category, 30, stdin);
    (records + i)->category[strcspn((records + i)->category, "\n")] = '\0';
    printf(" Quantity : ");
    scanf("%d", &(records + i)->quantity);
    printf(" Unit Price : ");
    scanf("%f", &(records + i)->unitPrice);
    getchar();
    printf(" Supplier Name : ");
    fgets((records + i)->supplierName, 50, stdin);
    (records + i)->supplierName[strcspn((records + i)->supplierName, "\n")] = '\0';
  }
  printf("\n [CHECK] All records encoded successfully.\n");
}

void displayAll(struct Product *records, int n)
{
  int i;
  printf("\n");
  printDivider();

  printf(" ALL PRODUCT RECORDS\n");
  printDivider();
  for (i = 0; i < n; i++)
  {
    printf("\n [Record #%d]\n", i + 1);
    printf(" Product Code : %s\n", (records + i)->productCode);
    printf(" Product Name : %s\n", (records + i)->productName);
    printf(" Category : %s\n", (records + i)->category);
    printf(" Quantity : %d\n", (records + i)->quantity);
    printf(" Unit Price : PHP %.2f\n", (records + i)->unitPrice);
    printf(" Supplier Name : %s\n", (records + i)->supplierName);
    printf(" Stock Status : %s\n", stockStatus((records + i)->quantity));
  }
  printDivider();
  printf("\n");
}

void searchRecord(struct Product *records, int n)
{
  int i;
  int found = 0;
  char key[20];
  printf("\n");
  printDivider();
  printf(" SEARCH PRODUCT RECORD\n");
  printDivider();
  printf(" Enter Product Code to search: ");
  scanf("%s", key);
  getchar();
  for (i = 0; i < n; i++)
  {
    if (strcmp((records + i)->productCode, key) == 0)
    {
      found = 1;
      printf("\n [CHECK] Record Found!\n");
      printDivider();
      printf(" Product Code : %s\n", (records + i)->productCode);
      printf(" Product Name : %s\n", (records + i)->productName);
      printf(" Category : %s\n", (records + i)->category);
      printf(" Quantity : %d\n", (records + i)->quantity);
      printf(" Unit Price : PHP %.2f\n", (records + i)->unitPrice);
      printf(" Supplier Name : %s\n", (records + i)->supplierName);
      printf(" Stock Status : %s\n", stockStatus((records + i)->quantity));

      printDivider();
      break;
    }
  }
  if (!found)
  {
    printf("\n [!] No record found with Product Code: %s\n", key);
    printDivider();
  }
  printf("\n");
}

void displaySummary(struct Product *records, int n)
{
  int i;
  int totalQty = 0;
  float highestPrice = (records + 0)->unitPrice;
  char expensiveName[50];
  strcpy(expensiveName, (records + 0)->productName);
  for (i = 0; i < n; i++)
  {
    totalQty += (records + i)->quantity;
    if ((records + i)->unitPrice > highestPrice)
    {
      highestPrice = (records + i)->unitPrice;
      strcpy(expensiveName, (records + i)->productName);
    }
  }
  printf("\n");
  printDivider();
  printf(" PRODUCT SUMMARY\n");
  printDivider();
  printf(" Total Quantity of All Products : %d\n", totalQty);
  printf(" Highest Unit Price : PHP %.2f\n", highestPrice);
  printf(" Most Expensive Product : %s\n", expensiveName);
  printDivider();
  printf("\n");
}

const char *stockStatus(int qty)
{

  if (qty >= 1 && qty <= 5)
    return "Low Stock";
  else if (qty >= 6 && qty <= 20)
    return "Sufficient Stock";
  else if (qty > 20)
    return "High Stock";
  else
    return "Invalid Quantity";
}

void displayMenu(void)
{
  printf("\n");
  printDivider();
  printf(" PRODUCT RECORD MANAGER MENU\n");
  printDivider();
  printf(" [1] Display All Records\n");
  printf(" [2] Search a Record by Product Code\n");
  printf(" [3] Display Summary\n");
  printf(" [4] Exit\n");
  printDivider();
}

void printHeader(void)
{
  printf("\n");
  printDivider();
  printf(" Multi-Record Manager: Product Record\n");
  printDivider();
  printf("\n");
}

void printDivider(void)
{
  printf(" <============================================>\n");
}