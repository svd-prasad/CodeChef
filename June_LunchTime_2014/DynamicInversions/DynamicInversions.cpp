#include <iostream>
#include <cstdlib>
using namespace std;
unsigned long int _mergeSort(unsigned long int *arr,unsigned long int temp[],unsigned long int left,unsigned long int right);
unsigned long int merge(unsigned long int arr[],unsigned long int temp[],unsigned long int left,unsigned long int mid,unsigned long int right);
void swap(unsigned long int a[],unsigned long int indexI, unsigned long int indexJ)
{
	unsigned long int temp = a[indexI];
	a[indexI] = a[indexJ];
	a[indexJ] = temp;
}
unsigned long int mergeSort(unsigned long int *arr,unsigned long int array_size)
{
    unsigned long int *temp = (unsigned long int *)malloc(sizeof(unsigned long int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
unsigned long int _mergeSort(unsigned long int *arr,unsigned long int temp[],unsigned long int left,unsigned long int right)
{
  unsigned long int mid, inv_count = 0;
  if (right > left)
  {
     mid = (right + left)/2;
     inv_count  = _mergeSort(arr, temp, left, mid);
     inv_count += _mergeSort(arr, temp, mid+1, right);
     inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
unsigned long int merge(unsigned long int arr[],unsigned long int temp[],unsigned long int left,unsigned long int mid,unsigned long int right)
{
  unsigned long int i, j, k;
  unsigned long int inv_count = 0;
  i = left; 
  j = mid; 
  k = left; 
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  return inv_count;
}
int main()
{
	unsigned long int *a, n, q, i, indexI, indexJ, inversions;
	cin >> n ;
	cin>> q;
	a = (unsigned long int *)malloc(n*sizeof(unsigned long int));
	for(i = 0; i < n; i++)
		cin >> a[i];
	for(i = 0 ; i < q; i++)
	{
		cin>>indexI>>indexJ;
		swap(a, indexI, indexJ);
		inversions = mergeSort(a, n);
		cout<<inversions%2<<endl;
	}
	free(a);
	return 0;
}