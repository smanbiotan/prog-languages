#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Patient{

  char patientID[20];
  char patientName[50];
  float consultationFee;
  float medicineFee;
  float laboratoryFee;
  float grossBill;
  float discount;
  float netBill;
  char category[30];
};

int main(){

int i, n;

printf("Enter number of patients: ");
scanf("%d", &n);
getchar();

struct Patient *patients;

patients = malloc(n * sizeof(struct Patient));

if(patients == NULL){
  printf("Memory Allocation Failed...");
  return 1;
}

for(i = 0; i < n; i++){
  
  printf("\nPatient %d\n\n", i + 1);

  printf("Patient ID: ");
  fgets(patients[i].patientID, 20, stdin);
  patients[i].patientID[strcspn(patients[i].patientID, "\n")] = '\0';

  printf("Patient Name: ");
  fgets(patients[i].patientName, 50, stdin);
  patients[i].patientName[strcspn(patients[i].patientName, "\n")] = '\0';

  printf("Consultation Fee: ");
  scanf("%f", &patients[i].consultationFee);
  getchar();

  printf("Medicine Fee: ");
  scanf("%f", &patients[i].medicineFee);
  getchar();

  printf("Laboratory Fee: ");
  scanf("%f", &patients[i].laboratoryFee);
  getchar();

  patients[i].grossBill = (patients[i].consultationFee +  patients[i].medicineFee + patients[i].laboratoryFee);

  if(patients[i].grossBill > 10000){
    patients[i].discount = patients[i].grossBill * 0.1;
  } else {
    patients[i].discount = patients[i].grossBill * 0;
  }

  patients[i].netBill = patients[i].grossBill - patients[i].discount;

  if(patients[i].netBill >= 10000){
    strcpy(patients[i].category, "High Bill");
  } else {
    strcpy(patients[i].category, "Regular Bill");
  }


}

FILE * fp;

fp = fopen("clinic.txt", "w");

if(fp == NULL){
  printf("file error...");
  free(patients);
  return 1;
}

fprintf(fp, "\nCLINIC BILLING REPORT\n\n");

for(i = 0; i < n; i++){

  fprintf(fp,"Patient ID : %s\n Patient Name : %s\n Consultation Fee : %.2f\n Medicine Fee : %.2f\n Laboratory Fee : %.2f\n Gross Bill : %.2f\n Discount : %.2f\n Net Bill : %.2f\n Category : %s\n",
    
    patients[i].patientID,
    patients[i].patientName,
    patients[i].consultationFee,
    patients[i].medicineFee,
    patients[i].laboratoryFee,
    patients[i].grossBill,
    patients[i].discount,
    patients[i].netBill,
    patients[i].category);

}

  printf("\n\n===== CLINIC BILLING REPORT =====\n\n");
  
  for(i = 0; i < n; i++){
    printf("Patient ID        : %s\n", patients[i].patientID);
    printf("Patient Name      : %s\n", patients[i].patientName);
    printf("Consultation Fee  : %.2f\n", patients[i].consultationFee);
    printf("Medicine Fee      : %.2f\n", patients[i].medicineFee);
    printf("Laboratory Fee    : %.2f\n", patients[i].laboratoryFee);
    printf("Gross Bill        : %.2f\n", patients[i].grossBill);
    printf("Discount          : %.2f\n", patients[i].discount);
    printf("Net Bill          : %.2f\n", patients[i].netBill);
    printf("Category          : %s\n\n", patients[i].category);
  }

  free(patients);
  fclose(fp);

  return 0;

}