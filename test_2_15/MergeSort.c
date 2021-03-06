#include <malloc.h>
#include <string.h>
void MergeData(int* array,int left,int mid,int right,int* temp)
{
  int index = left;
  int begin1 = left;
  int end1 = mid;
  int begin2 = mid;
  int end2 = right;
  while(begin1<end1 && begin2<end2)
  {
    if(array[begin1]<=array[begin2])
    {
      temp[index++] = array[begin1++];
    }
    else 
    {
      temp[index++] = array[begin2++];
    }
  }
    while(begin1<end1)
    {
      temp[index++] = array[begin1++];
    }
    while(begin2<end2)
    {
      temp[index++] = array[begin2++];
    }     
}

void _MergeSort(int* array,int left,int right,int* temp)
{
  if(right-left > 1)
  {
    int mid = left+(right-left)/2;
    _MergeSort(array,left,mid,temp);
    _MergeSort(array,mid,right,temp);
    MergeData(array,left,mid,right,temp);
    memcpy(array+left,temp+left,sizeof(int)*(right-left));
  }
}

void MergeSort(int* array,int size)
{
  int* temp = (int*)malloc(sizeof(int)*size);
  if(NULL == temp)
  {
    return;
  }

  _MergeSort(array,0,size,temp);
}
