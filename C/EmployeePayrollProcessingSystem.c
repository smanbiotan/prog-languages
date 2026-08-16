#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee {

  char employeeID[20];
  char employeeName[50];
  float hoursWorked;
  float hoursRate;
  float grossPay;
  float Tax;
  float NetPay;
  
};

int main()
{

  int n, i;
  struct Employee *employees;

  printf("Enter number of employees: ");
  scanf("%d", &n);
  getchar();

  employees = malloc(n * sizeof(struct Employee));

  if (employees == NULL)
  {
    printf("Memory Allocation Failed...");
    return 1;
  }

  for (i = 0; i < n; i++)
  {

    printf("\nEmployee %d\n\n", i + 1);

    printf("Employee ID: ");
    fgets(employees[i].employeeID, 20, stdin);
    employees[i].employeeID[strcspn(employees[i].employeeID, "\n")] = '\0';

    printf("Employee Name: ");
    fgets(employees[i].employeeName, 50, stdin);
    employees[i].employeeName[strcspn(employees[i].employeeName, "\n")] = '\0';

    printf("Hours Worked: ");
    scanf("%f", &employees[i].hoursWorked);
    getchar();

    printf("Hourly Rate: ");
    scanf("%f", &employees[i].hoursRate);
    getchar();

    employees[i].grossPay = employees[i].hoursWorked * employees[i].hoursRate;

    if (employees[i].grossPay < 5000)
    {
      employees[i].Tax = employees[i].grossPay * 0.05;
    }
    else
    {
      employees[i].Tax = employees[i].grossPay * 0.1;
    }

    employees[i].NetPay = employees[i].grossPay - employees[i].Tax;
  }

  FILE *fp;

  fp = fopen("payroll.txt", "w");

  if (fp == NULL)
  {
    printf("file not found...");
    free(employees);
    return 1;
  }

  fprintf(fp, "PAYROLL REPORT\n\n");

  for (i = 0; i < n; i++)
  {

    fprintf(fp, " Employee ID: %s\n Employee Name: %s\n Hours Worked: %.2f\n Hours Rate: %.2f\n Gross Pay: %.2f\n Tax: %.2f\n Net Pay: %.2f\n",

            employees[i].employeeID,
            employees[i].employeeName,
            employees[i].hoursWorked,
            employees[i].hoursRate,
            employees[i].grossPay,
            employees[i].Tax,
            employees[i].NetPay);
  }

  printf("\n===== PAYROLL REPORT =====\n\n");

  for (i = 0; i < n; i++)
  {

    printf("Employee ID     : %s\n", employees[i].employeeID);
    printf("Employee Name   : %s\n", employees[i].employeeName);
    printf("Hours Worked    : %.2f\n", employees[i].hoursWorked);
    printf("Hourly Rate     : %.2f\n", employees[i].hoursRate);
    printf("Gross Pay       : %.2f\n", employees[i].grossPay);
    printf("Tax             : %.2f\n", employees[i].Tax);
    printf("Net Pay         : %.2f\n\n", employees[i].NetPay);
  }

  free(employees);
  fclose(fp);

  return 0;
}
