#include <stdio.h>
#include <stdlib.h>
//SINGLY LINKED LIST

struct node
{
    int data;
    struct node *next;
};

struct node *Insert_Beg(struct node *head)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Please enter the data you want to insert");
    scanf("%d", &newnode->data);
    if (head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
        printf("\n The node has been inserted" );
    }
    else
    {
        newnode->next=head;
        head=newnode;
        printf("\n The node has been inserted" );
    }
    return head;

}

struct node *Insert_End(struct node *head)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Please enter the data you want to insert");
    scanf("%d", &newnode->data);
    if (head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
        printf("\n The node has been inserted" );
    }
    else
    {
        struct node *temp;
        temp=head;
        while (temp->next!=NULL)
        {
            temp =temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        printf("\n The node has been inserted" );
    }
    return head;
}

struct node *Insert_Pos(struct node *head)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Please enter the data you want to insert");
    scanf("%d", &ptr->data);
    struct node *temp;
    int i, loc;
    printf("Please enter the location where you want to enter the node");
    scanf("%d", &loc);
    temp=head;
    for (i=1;i<loc-1;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    printf("\n The node has been inserted" );
    return head;
}

struct node *Delete_Beg(struct node *head)
{
    struct node *ptr;
    if (head==NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\n The node has been deleted from the begining");
    }
    return head;
}

struct node *Delete_End(struct node *head)
{
    struct node *ptr1, *ptr;
    if (head==NULL)
    {
        printf("\n The list is empty");
    }
    else if(head->next ==NULL)
    {
        ptr=head;
        head =NULL;
        free(ptr);
        printf("\n The only node of the list has been eliminated");

    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("\n The last node has been deleted");
    }
    return head;
}

struct node *Delete_Pos(struct node *head)
{
    struct node *nextnode, *temp;
    int pos, i=1;
    temp=head;
    printf("Please enter the location from where you want to delete the node\n");
    scanf("%d", &pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    return head;
}

void Display(struct node *head)
{
    if (head==NULL)
    {
        printf("The linked list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}


int main()
{
    int x=10;
    struct node *head=NULL;
    while(x!=0)
    {
        printf("\n Please enter the integer corresponding to what you would like to do\n 1. Insert node at the beginning of the linked list\n 2. Insert node at the end of the linked list\n 3. Insert node at a specific position of the linked list\n 4. Delete node at the beginning of the linked list\n 5. Delete node at the end of the linked list\n 6. Delete node from a specific position of the linked list\n 7. Display all the elements in the linked list\n 0. End the process");
        scanf("%d", &x);
        switch (x)
        {
            case 1: head=Insert_Beg(head);
                    break;
            case 2: head=Insert_End(head);
                    break;
            case 3: head=Insert_Pos(head);
                    break;
            case 4: head=Delete_Beg(head);
                    break;
            case 5: head=Delete_End(head);
                    break;
            case 6: head=Delete_Pos(head);
                    break;
            case 7: Display(head);
                    break;
            case 0: x=0;
                    break;
        }

    }
    printf("The process has been completed");
    return 0;
}
