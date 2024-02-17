#include <stdio.h>
#include <stdlib.h>
int a[]={1,2,3,4,5,6,7,8,9,10},length=10,i,index=0,x=0,choice;
void display()
{
    printf("\nArray elements are :\n");
    for(i=0;i<length;i++)
        printf("%d ",a[i]);
}
void delete()
{
    display();
    printf("\nEnter the index of element to be deleted: \t");
    scanf("%d",&index);
    if(index>length-1 || index<0)
        printf("Incorrect index provided, please provide within range of %d to %d\n",0,length-1);
    else
    {
        x=a[index];
        for(i=index+1;i<length;i++)
            a[i-1]=a[i];
        length--;
        display();
        printf("\nElement deleted from index %d is %d",index,x);
    }
}

int main()
{
    while(1)
    {
        delete();
        printf("Do you want to continue ?\nPress 1 for yes and 2 for no\n");
        scanf("%d",&choice);
        if(choice==1)
            continue;
        else
            break;
    }
    return 0;
}
