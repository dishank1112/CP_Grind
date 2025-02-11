#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Symbol{
    char symbol[50];
    char type[10];
    int address;
};


struct Symbol symbolTable[100];
int symbolCount = 0;
int nextAddress = 1000; 

void insertSymbol(char *symbol, char *type)
{
    // Check if the symbol already exists
    for (int i = 0; i < symbolCount; i++)
    {
        if (strcmp(symbolTable[i].symbol, symbol) == 0)
        {
            printf("Symbol '%s' already exists. Use update option.\n", symbol);
            return;
        }
    }

    // Insert the new symbol
    strcpy(symbolTable[symbolCount].symbol, symbol);
    strcpy(symbolTable[symbolCount].type, type);
    symbolTable[symbolCount].address = nextAddress;
    nextAddress += 4; // Increment address for the next symbol (assuming 4-byte size)

    symbolCount++;
    printf("Symbol '%s' inserted successfully.\n", symbol);
}

// Function to update an existing symbol in the symbol table
void updateSymbol(char *symbol, char *newType)
{
    for (int i = 0; i < symbolCount; i++)
    {
        if (strcmp(symbolTable[i].symbol, symbol) == 0)
        {
            strcpy(symbolTable[i].type, newType);
            printf("Symbol '%s' updated successfully.\n", symbol);
            return;
        }
    }
    printf("Symbol '%s' not found in the symbol table.\n", symbol);
}

// Function to delete a symbol from the symbol table
void deleteSymbol(char *symbol)
{
    for (int i = 0; i < symbolCount; i++)
    {
        if (strcmp(symbolTable[i].symbol, symbol) == 0)
        {
            // Shift the elements to delete the symbol
            for (int j = i; j < symbolCount - 1; j++)
            {
                symbolTable[j] = symbolTable[j + 1];
            }
            symbolCount--;
            printf("Symbol '%s' deleted successfully.\n", symbol);
            return;
        }
    }
    printf("Symbol '%s' not found in the symbol table.\n", symbol);
}

// Function to display the symbol table
void displaySymbolTable()
{
    if (symbolCount == 0)
    {
        printf("Symbol table is empty.\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("Symbol\tType\tAddress\n");
    printf("-----------------------------\n");
    for (int i = 0; i < symbolCount; i++)
    {
        printf("%s\t%s\t%d\n", symbolTable[i].symbol, symbolTable[i].type, symbolTable[i].address);
    }
}

int main()
{
    int choice;
    char symbol[50], type[10];

    while (1)
    {
        printf("\nSymbol Table Operations:\n");
        printf("1. Insert\n2. Update\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter symbol: ");
            scanf("%s", symbol);
            printf("Enter type: ");
            scanf("%s", type);
            insertSymbol(symbol, type);
            break;
        case 2:
            printf("Enter symbol to update: ");
            scanf("%s", symbol);
            printf("Enter new type: ");
            scanf("%s", type);
            updateSymbol(symbol, type);
            break;
        case 3:
            printf("Enter symbol to delete: ");
            scanf("%s", symbol);
            deleteSymbol(symbol);
            break;
        case 4:
            displaySymbolTable();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

