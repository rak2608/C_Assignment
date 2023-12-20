#include <stdio.h>
#include <stdlib.h>
#define RENTAL 250 
#define RATE 4 
#define SUBSIDY 150 

struct Consumer {
    char name[50];
    int units;
    float bill;
    float subsidy;
};

void show()
{
    struct Consumer consumer;
    char *ptr = consumer.name;
    printf("\n\n******  ELECTRICITY BILL APP  ******\n\n");
    printf("Enter consumer name: ");
    scanf("%[^\n]", consumer.name); 
    printf("Enter units consumed: ");
    scanf("%d", &consumer.units);

    if (consumer.units < 0)
    {
        printf("\n\nError: Units consumed cannot be negative. Please try again.\n");
        exit(0);
    }
    consumer.bill = RENTAL + RATE * consumer.units;

    if (consumer.units < 100)
    {
        consumer.subsidy = SUBSIDY;
        consumer.bill = consumer.bill - consumer.subsidy; 
    }
    else
    {
        consumer.subsidy = 0;
    }
    printf("\n\n **** BILL GENERATED ****");
    printf("\n---------------------------------");
    printf("\nConsumer Name:      ");
    for(int i=0;consumer.name[i]!='\0';++i){
        printf("%c",*(ptr+i));
    }
    printf("\nUnits consumed:     %d\n", consumer.units);
    printf("Subsidy (if any):   Rs. %.2f\n", consumer.subsidy);
    printf("Total Bill Amount:  Rs. %.2f\n", consumer.bill);
    printf("---------------------------------");
}
