#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int data;
    struct node *next;
}node;
node* create(node *first,int a[],int n)
{
    int i;
    node *temp,*last;
    first=(node*)malloc(sizeof(node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        temp=(node*)malloc(sizeof(node));
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
    return(first);
}
void display(node *first)
{
    node *p;
    for(p=first;p;p=p->next)
        printf("%d\t",p->data);
    printf("\n");
}
node* concat(node *p,node *s)
{
    int i;
    node *n;
    for(n=p;n->next!=NULL;n=n->next)
        i++;
    n->next=s;
    return(p);
}
int main()
{
    node *root=NULL,*first1=NULL,*first2=NULL;
    int A[]={3,5,6,7};
    int b[]={1,2,3};
    int c[]={4,5,6,7,8};
    root=create(root,A,4);
    printf("The ll is\n");
    display(root);
    first1=create(first1,b,3);
    first2=create(first2,c,5);
    concat(first1,first2);
    printf("The concatenated ll is\n");
    display(first1);
    return 0;
}
