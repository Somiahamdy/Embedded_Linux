#include <stdio.h>

int binarysearch(int *a,int size,int key){
	int low=0 , high=size-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(a[mid]==key){
		}else if(a[mid]<key){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
     return -1;
}

int main(){
    int arr[]={3,7,9,10,15,20};
    int s=sizeof(arr)/sizeof(arr[0]);
    int result=binarysearch(arr,s,7);
    if(result==-1){
	    printf("not found");
    }else{
	printf("index is: %d \n",arr[result]);
    }

  return 0;
}
