//o(N^3)

#include <stdio.h>
int main()
{
    int a[]={0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5};
    int i=0,j=12,k=0;
    int max=-999;
    int sum=0;

    for(i=0;i<13;i++)
    {
        for(j=12;j>=i;j--)
        {
            sum=0;
            for(k=i;k<=j;k++)
            {
                sum=a[k]+sum;
            }
            if(sum>max)
                max=sum;
        }
    }
    printf("%d\n",max);
    return 0;
}
