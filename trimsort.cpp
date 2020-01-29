#include <bits/stdc++.h>
#include <time.h>
#include <pthread.h>
using namespace std;

void insersort(int* arr,int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int key=arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int makepivot(int* arr,int l,int r)
{
	int pivot=arr[l];
	int s=l-1;
	int h=r+1;
	while(1){
	do{
		s++;
	}while(arr[s]<pivot);
	do
	{
		h--;
	}while(arr[h]>pivot);
	if(s>=h)
	   return h;
	swap(arr[s],arr[h]);
    }
	//return l+rand()%r-l;
}

int randompivot(int* arr,int l,int r)
{
	int p=l+rand()%r-l;
	swap(arr[p],arr[r]);
	return makepivot(arr,l,r);
}

void quicksort(int* arr,int l,int r)
{
	if(l<r)
	{
		int pivot=makepivot(arr,l,r);
		quicksort(arr,l,pivot);
		quicksort(arr,pivot+1,r);
	}
}


void merge(int* arr,int l,int m,int r)
{
	int a1=m-l+1;
	int a2=r-m;
	int lt[a1],rt[a2];
	for(int i=0;i<a1;i++)
	{
		lt[i]=arr[i+l];
	}
	for(int i=0;i<a2;i++)
	{
		rt[i]=arr[i+m+1];
	}
	int i,j,k=l;
	for(i=0,j=0;i<m-l+1 && j<r-m;k++)
	{
		if(lt[i]<=rt[j])
		{
			arr[k]=lt[i++];
		}
		else
		{
			arr[k]=rt[j++];
		}
	}
	for(int x=i;x<m-l+1;x++)
	{
		arr[k++]=lt[x];
	}
	for(int x=j;x<r-m;x++)
	{
		arr[k++]=rt[x];
	}
}


void mergesort(int* arr,int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}


main()
{
	int n=200000;
	int arr[n];
	srand(time(0));
	for(int i=0;i<n;i++)
	  arr[i]=rand()%(10000);
	clock_t t=clock();
	if(n<30)
	  insersort(arr,n);
	else
	  mergesort(arr,0,n-1);
	clock_t t1=clock();
	cout<<((float)(t1-t)/CLOCKS_PER_SEC)<<"\n";
	clock_t t2=clock();
	if(n<30)
	   insersort(arr,n);
	else{
	   printf("Quickly done:\n");
	   quicksort(arr,0,n-1);
    }
    clock_t t3=clock();
	cout<<"\n";
	cout<<((float)(t3-t2)/CLOCKS_PER_SEC);
}
//9 0 7 6 5 4 3 2 1 8 0 9 5 7 4 5 1 2 3 7 5 7 9 6 5 7 6 4 3 8 9 7 0 1 9 199 200 342 165 5
