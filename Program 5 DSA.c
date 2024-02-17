#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
}node;
node *f1=NULL,*f2=NULL,*r1=NULL,*r2=NULL;
    //there are 2 ways to traverse a LL 1: for loop, 2: while loop
    /*//while loop
        p=temp;
        while(p!=NULL)
        {
            //print anything here or count using counter or search using if and key
            p=p->link;
        }
        //for loop
        for(p=temp;p!=NULL;p=p->link)
        //anything to do during traversal here
    */
    /*Function recieves pointer called top to denote the top of stack
Step 1: it asks for the number of nodes and stores it in n
it runs a for loop for i=0 to n to create n nodes
Step 2: it creates a node using the temp pointer by using malloc function
        it accepts data to that node
        it initializes the link of that node to NULL
Step 3: it checks if the top pointer is NULL which tells if it's a first node or not
        if top is NULL then it assigns top to temp node created
Step 4: else if the top is not NULL then there are nodes that already exist
        in that case the temp->link is assigned to top : which stores the address of
        previous node in next node, i.e. it establishes link between new node and the
        immediate node below it
        then since there exists a new node above the top pointer, the new node is made
        to be top by assigning top to temp node
Step 5: the n iterations of for loop creates the stack of n integer data
        since the linked list creation is completed we return the top pointer.*/
node* getnode(node *temp)
{
        temp=(node*)malloc(sizeof(node));
        printf("Enter data\n");
        scanf("%d",&(temp->data));
        temp->link=NULL;
        return temp;
}
node* create_stack(node *top)
{
    int i,n;
    node *temp,*p;//to create node each time
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=getnode(temp);
        if(top==NULL)
            top=temp;
        else
        {
            temp->link=top;
            top=temp;
        }
    }
    return top;
}
void display(node *temp)
{
    node *p;
    for(p=temp;p!=NULL;p=p->link)
        printf("%d\t",p->data);
    printf("\n");
}
void linear_search(node *temp)
{
    int key;//for liner search
    int f=0;//flag initialized to 0
    int i=0;//counter
    node *p;//pointer to traverse ll
    //take key input
    printf("enter key\n");
    scanf("%d",&key);
    for(p=temp;p!=NULL;p=p->link)
    {
        i++;
        if(p->data==key)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        printf("element %d is found at %d\n",key,i);
    else
        printf("Search Unsuccessful\n");
}
void create1()
{
    node *temp;
    int n,i;
    printf("Enter the number of nodes for queue 1\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=getnode(temp);
        if(f1==NULL&&r1==NULL)
            f1=r1=temp;
        else
        {
            r1->link=temp;
            r1=temp;
        }

    }
}

void create2()
{
    node *temp;
    int n,i;
    printf("Enter the number of nodes for queue 2\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=getnode(temp);
        if(f2==NULL&&r2==NULL)
            f2=r2=temp;
        else
        {
            r2->link=temp;
            r2=temp;
        }
    }
}
void concat()
{
    node *p;
    int count;
    for(p=f1;p->link!=NULL;p=p->link)
        count++;
    p->link=f2;
    display(f1);
}
int main()
{
    node *stack=NULL;
    stack=create_stack(stack);
    display(stack);
    linear_search(stack);
    create1();
    create2();
    concat();
    return 0;
}
