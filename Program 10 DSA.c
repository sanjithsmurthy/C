#include <stdio.h>
#include <stdlib.h>
#define max 10
int hash(int key)
{
    return key%max;
}
void insert(int H[],int key)
{
    int i,hv;
    hv=hash(key);
    for(i=0;H[(hv+i)%max]!=0;i++)
    {}
    H[(hv+i)%max]=key;
}
int main()
{
    int n,i,key,H[max]={0};
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Enter %d values\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&key);
        insert(H,key);
    }
    printf("Hash Map is\nIndex\tValue\n");
    for(i=0;i<max;i++)
        printf("%d\t%d\n",i,H[i]);
    return 0;
}
