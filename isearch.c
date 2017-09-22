index Isearch(int array[],int left,int right,int x)
{
	if(array[right]<=x) return FAIL;
	if(array[left]>x) return left;
	int middle;
	while(left<right) {
		printf("123\n");
		middle = left+(right-left)*(x-array[left])/(array[right]-array[left]);
		if(array[middle]>x) {
			right = middle;
		} else if(array[middle]<x) {
			left = middle+1;
		} else {
			while(array[++middle]==x);
			return middle;
		}
	}
	return right;
}
