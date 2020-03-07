//O(N^2)
int funsum(int a[],int N)
{
	int maxsum=0,thissum=0;
	int i,j;
	for (i=0;i<N;i++)
	{
		thissum = 0;
		for(j=i;j<N;j++)
		{
			thissum = thissum+a[j];
			if(thissum>maxsum)
				maxsum=thissum;
		}
	}
	return maxsum;
}


//O(NlogN)  -->  分而治之
int fun()
	pass



//在线处理    O(N)
int MaxSubseqSum4( int A[], int N )
{   int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for( i = 0; i < N; i++ ) {
          ThisSum += A[i]; /* 向右累加 */
          if( ThisSum > MaxSum )
                  MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
          else if( ThisSum < 0 ) /* 如果当前子列和为负 */
		  ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之 */
    }
    return MaxSum;
}
