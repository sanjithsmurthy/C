#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
}node;
node* create(node *root)
{
    node *temp;
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=(node*)malloc(sizeof(node));
        printf("Enter data\n");
        scanf("%d",&(temp->data));
        temp->llink=NULL;
        temp->rlink=NULL;
        if(root==NULL)
            root=temp;
        else
        {
            node *prev=NULL,*curr=NULL;
            curr=root;
            while(curr)
            {
                prev=curr;
                if(temp->data>curr->data)
                    curr=curr->rlink;
                else
                    curr=curr->llink;
            }
            if(temp->data>prev->data)
                prev->rlink=temp;
            else
                prev->llink=temp;
        }
    }
    return root;
}
void postorder(node *root)
{
    if(root==NULL) return;
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t",root->data);
}
void preorder(node *root)
{
    if(root==NULL) return;
        printf("%d\t",root->data);
        preorder(root->llink);
        preorder(root->rlink);
}
void inorder(node *root)
{
    if(root==NULL) return;
        inorder(root->llink);
        printf("%d\t",root->data);
        inorder(root->rlink);
}
int main()
{
    node *root=NULL;
    root=create(root);
    printf("Inorder\n");
    inorder(root);
    printf("\nPreorder\n");
    preorder(root);
    printf("\nPostorder\n");
    postorder(root);
    return 0;
}
