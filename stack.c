#include <stdlib.h>
#include <stdio.h>

int push();
int pop();
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
    puts("\n\n1 - PUSH");
    puts("2 - POP");
    puts("3 - DISPLAY");
    puts("4 - EXIT");
    printf("Enter your choice:>");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: puts("Have a nice day!"); break;

    }


}//==================================================
int push()
{
    int num;
    printf("Enter a number to PUSH into the STACK:");
    scanf("%d", &num);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    if(head == NULL)
    {
        temp->next=NULL;
        head = temp;

    }
    else if(head != NULL)
    {
        temp->next = head;
        head = temp;

    }
    printf("The number %d was successfully PUSHED into the STACK!",num);
    menu();

}//===================================================
int pop()
{
    int popped;
    struct node *desired;
    if(head == NULL)
    {
        puts("STACK is EMPTY, this operation is INVALID.");
    }
    else
    {
       desired = head->next;
       head->next = NULL;
       popped = head->data;
       free(head);
       head = desired;
       printf("\nThe number %d was successfully POPPED from the STACK!",popped);

    }
    menu();
}//=========================================================
int display()
{
    puts("\tSTACK");
    puts("=========================");
    current = head;
    while(current!= NULL)
    {
        printf("\n[\t%d\t]",current->data);
        current = current->next;
    }
    menu();
}
int main()
{
    menu();
}
