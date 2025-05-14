#include <stdio.h>
#include <stdlib.h>

#define SIZE 11 // Mod 11

// Structure for the hash table entry with two columns
typedef struct
{
    int value1;
    int value2;
} HashEntry;

void initHashTable(HashEntry table[])
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i].value1 = -1;
        table[i].value2 = -1;
    }
}

void insert(HashEntry table[], int value)
{
    int index = value % SIZE;
    int originalIndex = index;

    while (table[index].value1 != -1 && table[index].value2 != -1)
    {
        index = (index + 1) % SIZE;
        if (index == originalIndex)
        {
            printf("Hash table is full! Cannot insert %d\n", value);
            return;
        }
    }

    if (table[index].value1 == -1)
        table[index].value1 = value;
    else
        table[index].value2 = value;

    printf("Inserted: %d at index %d\n", value, index);
}

void deleteValue(HashEntry table[], int value)
{
    int index = value % SIZE;
    int originalIndex = index;

    while (table[index].value1 != -1 || table[index].value2 != -1)
    {
        if (table[index].value1 == value)
        {
            table[index].value1 = -1;
            printf("Deleted: %d from index %d (value1)\n", value, index);
            return;
        }
        if (table[index].value2 == value)
        {
            table[index].value2 = -1;
            printf("Deleted: %d from index %d (value2)\n", value, index);
            return;
        }

        index = (index + 1) % SIZE;
        if (index == originalIndex)
        {
            break;
        }
    }
    printf("Value %d not found in the hash table!\n", value);
}

void display(HashEntry table[])
{
    printf("\nIndex | Value1 | Value2\n");
    printf("------------------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("  %2d   |  %4d  |  %4d\n", i,
               table[i].value1 == -1 ? -1 : table[i].value1,
               table[i].value2 == -1 ? -1 : table[i].value2);
    }
}

int main()
{
    HashEntry hashTable[SIZE];
    initHashTable(hashTable);

    int choice, value, count;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert multiple values\n");
        printf("2. Delete a value\n");
        printf("3. Display hash table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of values to insert: ");
            scanf("%d", &count);
            printf("Enter %d values:\n", count);
            for (int i = 0; i < count; i++)
            {
                scanf("%d", &value);
                insert(hashTable, value);
            }
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteValue(hashTable, value);
            break;

        case 3:
            display(hashTable);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
