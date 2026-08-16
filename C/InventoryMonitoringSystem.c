#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {

  char itemCode[20];
  char itemName[50];
  int quantity;
  float price;
  float totalValue;
  char status[20];
};

void inputCompute(struct Item *items, int n);
void displaySave(struct Item *items, int n);

int main() {

  struct Item *items;

  int n, i;

  printf("Enter number of items: ");
  scanf("%d", &n);
  getchar();

  items = malloc(n * sizeof(struct Item));

  if(items == NULL){
    printf("Memory Allocation Failed...");
    return 1;
  }

  inputCompute(items, n);
  displaySave(items, n);

  free(items);

  return 0;
}

void inputCompute(struct Item *items, int n){
  int i;

  for(i = 0; i < n; i++){

    printf("\nItem %d\n\n", i + 1);

    printf("Item Code: ");
    fgets(items[i].itemCode, 20, stdin);
    items[i].itemCode[strcspn(items[i].itemCode, "\n")] = '\n';

    printf("Item Name: ");
    fgets(items[i].itemName, 50, stdin);
    items[i].itemName[strcspn(items[i].itemName, "\n")] = '\n';

    printf("Quantity: ");
    scanf("%d", &items[i].quantity);
    getchar();

    printf("Price: ");
    scanf("%f", &items[i].price);
    getchar();

    items[i].totalValue = (items[i].quantity * items[i].price);

    if(items[i].quantity >= 10){

        strcpy(items[i].status, "Sufficient");
    } else {

        strcpy(items[i].status, "Restock");
    }

  }

}

void displaySave(struct Item *items, int n){
  int i;

  FILE * fp;

  fp = fopen("inventory.txt", "w");

  printf("===== INVENTORY REPORT =====\n\n");

  for(i = 0; i < n; i++){

    printf("Item Code     : %s\n", items[i].itemCode);
    printf("Item Name     : %s\n", items[i].itemName);
    printf("Quantity      : %d\n", items[i].quantity);
    printf("Price         : %.2f\n", items[i].price);
    printf("Total Value   : %2.f\n", items[i].totalValue);
    printf("Status        : %s\n\n", items[i].status);
  }

  fprintf(fp, "INVENTORY REPORT\n\n");

  for(i = 0; i < n; i++){

    fprintf(fp, "Item Code     : %s\n", items[i].itemCode);
    fprintf(fp, "Item Name     : %s\n", items[i].itemName);
    fprintf(fp, "Quantity      : %d\n", items[i].quantity);
    fprintf(fp, "Price         : %.2f\n", items[i].price);
    fprintf(fp, "Total Value   : %2.f\n", items[i].totalValue);
    fprintf(fp, "Status        : %s\n\n", items[i].status);
  }

  free(fp);

}
