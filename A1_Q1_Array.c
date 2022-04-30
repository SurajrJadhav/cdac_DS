///changed from local pc

#include<stdio.h>
#include<stdlib.h>

typedef struct arr_info{
    int *arr;
    int size;
    int first_empty_index;//first empty index
}array_t;


enum{
    SIZE_FAULT=-1,UNSUCCESSFUL,SUCCESSFUL
};

int insert_element(array_t *arr_info_ptr,int val,int index);
int delete_element(array_t *arr_info_ptr,int index);
int search_element(array_t *arr_info_ptr,int val);
void reverse_array(array_t *arr_info_ptr);
int avgofarray(int *arr,int size);
int minofarray(int *arr,int size);
int maxofarray(int *arr,int size);
int find_duplicates(int *arr,int size);
void display(int *arr,int size);

int main(){
    int size,choice,val,index;
    printf("Enter Array size : ");
    scanf("%d",&size);

    //creatting array
    int *arr=(int*)malloc(sizeof(int)*size);

    //init array
    for(int i=0;i<size;i++){
        // scanf("%d",arr+i);
        arr[i]=i+1;
    }

    //Fill Array Info
    array_t array_info={arr,size,size};
   while (1)
   {
    
    printf("Enter choice\n");
    printf("Enter 0 : Dsiplay Array\n");
    printf("Enter 1 : Insert Element\n");
    printf("Enter 2 : Delete Element\n");
    printf("Enter 3 : Search Element\n");
    printf("Enter 4 : Average of Array Element\n");
    printf("Enter 5 : Min of Array\n");
    printf("Enter 6 : Max of Array\n");
    printf("Enter 7 : Reverse Array\n");
    printf("Enter 8 : Find duplicate elements in array\n");

    scanf("%d",&choice);

    switch (choice)
    {
        case 0:
                display(arr,size);
                break;
        case 1:
            printf("Enter value to Insert : ");
            scanf("%d",&val);
            printf("Enter the index : ");
            scanf("%d",&index);
            if(insert_element(&array_info,val,index)==SUCCESSFUL)
                printf("Insertion Successful\n");
            break;
        case 2:
            printf("Enter the index to delete : ");
            scanf("%d",&index);
            if(delete_element(&array_info,index)==SUCCESSFUL)
                printf("Succefully deleted !!\n");
            break;
        case 3:
            printf("Enter value to be search\n");
            scanf("%d",&val);
            printf("value found at index : %d\n",search_element(&array_info,val));
            break;
        case 4:
            avgofarray(arr,size);
            break;
        case 5:
            minofarray(arr,size);
            break;
        case 6:
            maxofarray(arr,size);
            break;
        case 7:
            reverse_array(&array_info);
            break;
        case 8:
            //limitations-only work for two digit element
            printf("Duplicates found = %d\n",find_duplicates(arr,size));
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid input\n");
            break;    
    }
   }

}
int insert_element(array_t *arr_info_ptr,int val,int index){
    if (index > arr_info_ptr->size || index < 0)
    {
        return SIZE_FAULT;
    }
    else if(arr_info_ptr->first_empty_index >= arr_info_ptr->size){
        return UNSUCCESSFUL;
    }
    else if(index < arr_info_ptr->first_empty_index ){
        //shifting elements
        for (int  i = arr_info_ptr->first_empty_index;i> index ;i--){
            arr_info_ptr->arr[i]=arr_info_ptr->arr[i-1];    
        }
        //writing value
        arr_info_ptr->arr[index]=val;
        arr_info_ptr->first_empty_index++;
        return SUCCESSFUL;
        
    }
    else if(index > arr_info_ptr->first_empty_index){
        //writing value
        arr_info_ptr->arr[arr_info_ptr->first_empty_index]=val;
        arr_info_ptr->first_empty_index++;
        return SUCCESSFUL;
        
    }
    

}
int delete_element(array_t *arr_info_ptr,int index){
    if (index > arr_info_ptr->size || index < 0)
    {
        return SIZE_FAULT;;
    }
    else if(index > arr_info_ptr->first_empty_index){
        return UNSUCCESSFUL;
    }
    else if(index < arr_info_ptr->first_empty_index){
        int i;
        //shifting elements
        for (i = index; i < arr_info_ptr->first_empty_index; i++)
        {
            arr_info_ptr->arr[i]=arr_info_ptr->arr[i+1];
        }
        arr_info_ptr->first_empty_index--;
        arr_info_ptr->arr[i-1]=-1;
        return SUCCESSFUL;
        
    }
}
void reverse_array(array_t *arr_info_ptr){
    int size=arr_info_ptr->size;
    for(int i=0;i<size/2;i++){
        int temp=arr_info_ptr->arr[i];
        arr_info_ptr->arr[i]= arr_info_ptr->arr[size-1-i];
        arr_info_ptr->arr[size-1-i]=temp;
    }

}

int search_element(array_t *arr_info_ptr,int val){
   //return index number
   for(int i=0;i<arr_info_ptr->size;i++)
   {
       if(val==arr_info_ptr->arr[i])
            return i;
   }
   return -1;
    
}
int sumofarray(int *a,int size)
{	int result=0;
	for(int i=0;i<size;i++){
		result+=a[i];
	}
	printf("sum of elements of array is = %d\n",result);
	return result;
}
int avgofarray(int *a,int size){
	int sum,result;
	sum=sumofarray(a,size);
	result=sum/size;
	printf("average of array is = %d\n",result);
	return result;
}
int minofarray(int *a,int size){
	int min=a[0];
	for(int i=0;i<(size);i++){
		min=min<a[i]?min:a[i];
	}
	printf("min of array element is = %d\n",min);
	return min;
}
int maxofarray(int *a,int size){
	int max;
	for(int i=0;i<(size);i++){
		max=max>a[i]?max:a[i];
	}
	printf("max of array element is %d\n",max);
	return max;
}
int find_duplicates(int *arr,int size){
    int count=0;
    //temp array of 0-9 to check repeatation
    int temp_arr[100]={0};
    //storing repeated values
    for (int i = 0; i < size; i++)
    {
        int temp=arr[i];
        temp_arr[temp]++;
    }
    //finding non-repeated digits
    for (int i = 0; i < 100; i++)
    {
        if(temp_arr[i]>1)
            count++;
    }
    return count;
    
}
void display(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

