#include <stdio.h>
#include <stdlib.h>

// Schematic of a ROW of a hash table (i.e., Each variable is a column (called "variable" acc. to the Stats -- got from IITM-ODP))
struct Node
{
    int key, age;
    int marker;
}*hashTable=NULL;
// Global variable with the default Initializations..
int total_elements=0, hashIndex=-1, table_size=0;

void insertInHash(int age, int key)
{
    int hashindex = key % table_size;
    if(table_size == total_elements)
    {
        printf("Can't perform Insertion, as HASH TABLE is full..!!");
        return;
    }
    while(hashTable[hashIndex].marker == 1)
    {
        printf("Collision Occured at %d: ", hashIndex);
        hashIndex = (hashIndex+1)%table_size;
        printf("New index at %d\n", hashIndex);
    }
    // Place the element in that respective slot..
    hashTable[hashIndex].key = key;
    hashTable[hashIndex].age = age;
    hashTable[hashIndex].marker = 1;

    total_elements++;
    return;
}

void display()
{
    if (total_elements == 0){
        printf("No data in the table to display..!! Try again after inserting some data..!!");
        return;
    }
    // Control here means, some data is in the list.. so print the table which buckets has data...
    printf("KEY \t Age\n_________________\n");
    for(int i=0; i<table_size; i++)
    {
        if(hashTable[i].marker != 1)        // Is the bucket filled..?? If not go to the next bucket..
            continue;
        printf("%3d \t %2d\n", hashTable[i].key, hashTable[i].age);
    }
}

int main()
{
    int key, age, choice;
    printf("Enter the table size: ");
    scanf("%d", &table_size);
    hashTable = (struct Node*) calloc(1,table_size * ( sizeof(struct Node)));

    // Take the choice...
    while(1)
    {
        printf("Choose an option to perform:\n1. Insert\n2. Display\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Insert operation\n");
                    printf("Enter your age: ");
                    scanf("%d", &age);
                    printf("Enter key: ");
                    scanf("%d", &key);
                    insertInHash(age, key);
                    break;
            case 2:
                    printf("Display operation\n");
                    display();
                    break;
            case 3: 
                    printf("Exit\n");
                    exit(EXIT_SUCCESS);
                    //break;                  // There will be no need with these.. right...????
            default:
                    printf("Please select a valid option..");
                    break;
        }
    }
}