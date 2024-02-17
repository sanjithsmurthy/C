#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char id[10];
    char name[10];
    char branch[10];
    char area[10];
    struct node *ll,*rl;
}node;
node *front=NULL,*rear=NULL,*top=NULL;
node* getnode(node *temp)
{
    temp=(node*)malloc(sizeof(node));
    printf("Enter data id,name,branch,area of specialization\n");
    scanf("%s%s%s%s",temp->id,temp->name,temp->branch,temp->area);
    temp->ll=NULL;
    temp->rl=NULL;
    return(temp);
}
void stack()
{
    node *temp=NULL,*p;
    int n;
    printf("Enter number of professors\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=getnode(temp);
        if(top==NULL)
            top=temp;
        else
        {
            temp->ll=top;
            top->rl=temp;
            top=temp;
        }
    }
    printf("The professors data is:\nID\tNAME\tBRANCH\tAREA\n");
     for(p=top;p!=NULL;p=p->ll)
        printf("%s\t%s\t%s\t%s\n",p->id,p->name,p->branch,p->area);
    printf("\n");
}
void queue()
{
    int n;
    node *temp=NULL,*p;
    printf("Enter the number of professors");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=getnode(temp);
        if(front==NULL&&rear==NULL)
            front=rear=temp;
        else
        {
            rear->ll=temp;
            temp->rl=rear;
            rear=temp;
        }
    }
    printf("The professors data is:\nID\tNAME\tBRANCH\tAREA\n");
     for(p=front;p!=NULL;p=p->ll)
        printf("%s\t%s\t%s\t%s\n",p->id,p->name,p->branch,p->area);
    printf("\n");
}
int main()
{
    //add switch case to make it menu driven
    stack();
    queue();
    return 0;
}
