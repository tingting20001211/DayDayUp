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

