void merge(int *array, int *temp, int left, int mid, int right){
    //left array = array from left to mid-1
    //right array = array from mid to right
    
    left_end = mid-1;
    temp_ctr = left;
    num_elements = (right-left)+1;
    
    while(left <= left_end && mid <= right){ //mid does not stay true to its name as loop iterates; mid gets shifted as right array elements get processed;
        if(array[left] <= array[mid]){
            temp[temp_ctr] = array[left]; 
            left++;
        }
        else{
            temp[temp_ctr] = array[mid];
            mid++;
        }
        temp_ctr++;
    }
    while(left <= left_end){ //if theres stuff left in 'left' array
        temp[temp_ctr] = array[left];
        left++;
        temp_ctr++;
    }
    while(mid <= right){ //if theres stuff left in 'right' array
        temp[temp_ctr] = array[mid];
        mid++;
        temp_ctr++;
    }
    //temp is now a sorted array of the elements from the subarrays passed int
    //push the changes to the official array since the relative indexes are the same
    //Note: in the early executions of this function: the array will be a frankenstein array with some parts sorted and some parts not...
    int i;
    for(i = 1; i <= count; i++){ //for every element (left array + right array)
        array[right] = temp[right];
        right--;
    }
}

void sort(int *array, int *temp, int left, int right){
    if(right > left){ //Do this only if array is NOT one element-> if array of 1 block (right == left) leave out of function and begin the merging process on the way back up
        int mid = (right-left)/2;
        sort(array, temp, left, mid-1);  
        sort(array, temp, mid, right);
        merge(array, temp, left, mid, right);
    }
}
