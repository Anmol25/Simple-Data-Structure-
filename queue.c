#include <stdlib.h>
#include <stdio.h>

int enqueue();
int dequeue();
int display();
int menu();

struct node
{
    int data;
    struct node *next;
}*head = NULL, *current = NULL, *temp = NULL;
//==============================================
int menu()
{
    int choice;
    puts("\n\n1 - ENQUEUE");
    puts("2 - DEQUEUE");
    puts("3 - DISPLAY");
    puts("4 - EXIT");
    printf("Enter your choice:>");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: enqueue(); break;
        case 2: dequeue(); break;
        case 3: display(); break;
        case 4: puts("Have a nice day!"); break;

    }


}//==================================================
int enqueue()
{
    int num;
    puts("Enter a number to place into the QUEUE:");
    scanf("%d", &num);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    if(head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else if(head != NULL)
    {
        current = head;
        while(current->next != NULL) current = current->next;
        current->next = temp;
        temp->next = NULL;
    }
    menu();
}//==================================================
int dequeue()
{
    if(head == NULL)
    {
        printf("The QUEUE is EMPTY, this operation is not valid!");
    }
    else
    {
    struct node *desired, *unwanted;
    desired = head->next;
    unwanted = head;
    unwanted->next = NULL;
    printf("The number %d has been dequeued from the list.",unwanted->data);
    free(unwanted);
    head = desired;
    }
    menu();
}//===================================================
int display()
{
    current = head;
    printf("QUEUE:\t");
    while(current!= NULL)
    {
        printf("[%d]~",current->data);
        current = current->next;

    }
    printf("[STOP]");
    menu();
}
int main()
{
    menu();
}
