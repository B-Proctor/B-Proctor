#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure for storing income and bill items
typedef struct {
    char name[50];
    float amount;
} FinancialItem;

// Arrays for storing income and bill items
FinancialItem incomes[MAX_ITEMS];
FinancialItem bills[MAX_ITEMS];
int incomeCount = 0;
int billCount = 0;

// Function prototypes
void loadBudgetData();
void saveBudgetData();
void displayHomePage();
void addIncome();
void addBill();
void quickActionsMenu();

int main() {
    loadBudgetData();
    displayHomePage();
    quickActionsMenu();
    return 0;
}

void loadBudgetData() {
    // Simplified: Load hardcoded data for demonstration
    strcpy(incomes[0].name, "Salary");
    incomes[0].amount = 3000;
    incomeCount++;

    strcpy(bills[0].name, "Rent");
    bills[0].amount = 1000;
    billCount++;

    strcpy(bills[1].name, "Utilities");
    bills[1].amount = 300;
    billCount++;
}

void saveBudgetData() {
    FILE* file = fopen("budget.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Type,Name,Amount\n");
    for (int i = 0; i < incomeCount; i++) {
        fprintf(file, "Income,%s,%.2f\n", incomes[i].name, incomes[i].amount);
    }
    for (int i = 0; i < billCount; i++) {
        fprintf(file, "Bill,%s,%.2f\n", bills[i].name, bills[i].amount);
    }

    fclose(file);
    printf("Data saved to budget.csv\n");
}

void displayHomePage() {
    float totalIncome = 0, totalBills = 0;

    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                    CommandLine Budget Calc                 │\n");
    printf("├────────────┬───────────────────────────────────────────────┤\n");
    printf("│  **Income**│  **Bills**                                     │\n");
    printf("│────────────┼───────────────────────────────────────────────│\n");

    for (int i = 0; i < incomeCount || i < billCount; i++) {
        if (i < incomeCount) {
            printf("│ - %s: $%.2f", incomes[i].name, incomes[i].amount);
            totalIncome += incomes[i].amount;
        }
        else {
            printf("│            ");
        }

        if (i < billCount) {
            printf("   │ - %s: $%.2f\n", bills[i].name, bills[i].amount);
            totalBills += bills[i].amount;
        }
        else {
            printf("   │\n");
        }
    }

    printf("│ **Total**: $%.2f  │ **Total**: $%.2f                        │\n", totalIncome, totalBills);
    printf("├────────────┴───────────────────────────────────────────────┤\n");
    printf("│                     **Quick Actions**                      │\n");
    printf("│  [1] Home  [2] Add Income  [3] Add Bill  [4] Save  [5] Exit│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
}

void addIncome() {
    if (incomeCount >= MAX_ITEMS) {
        printf("Maximum number of income items reached.\n");
        return;
    }

    printf("Enter income source: ");
    scanf("%s", incomes[incomeCount].name);
    printf("Enter amount: ");
    scanf("%f", &incomes[incomeCount].amount);
    incomeCount++;
    printf("Income added.\n");
}

void addBill() {
    if (billCount >= MAX_ITEMS) {
        printf("Maximum number of bill items reached.\n");
        return;
    }

    printf("Enter bill name: ");
    scanf("%s", bills[billCount].name);
    printf("Enter amount: ");
    scanf("%f", &bills[billCount].amount);
    billCount++;
    printf("Bill added.\n");
}

void quickActionsMenu() {
    int choice;
    do {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            displayHomePage();
            break;
        case 2:
            addIncome();
            break;
        case 3:
            addBill();
            break;
        case 4:
            saveBudgetData();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}
