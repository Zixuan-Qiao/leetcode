/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
void quick_sort(int low, int high, int * nums, int * num_position);
int binary_search(int * sorted_nums, int num1, int index1, int target, int numsSize);

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   
    int num_position[10000];
	for(int i = 0; i < 10000; i++){
		num_position[i] = i;
	}

    quick_sort(0, numsSize - 1, nums, num_position);
    int * array = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){

        int returned_value = binary_search(nums, nums[i], i, target, numsSize);
        if(returned_value > -1){
            int * array = (int *)malloc(2 * sizeof(int));
            array[0] = num_position[i];
            array[1] = num_position[returned_value];
            return array;
        }
    }

    return array;
}

void quick_sort(int low, int high, int * nums, int * num_position){

    if(high <= low){
        return;
    }

    int i = low;
    int j = high;
    int base = nums[low];

    while(j > i){
        if(nums[j] < base){
            while(i < j){
                if(nums[i] > base){
                    int t = nums[i];
                    nums[i] = nums[j];
                    nums[j] = t;
					t = num_position[i];
					num_position[i] = num_position[j];
					num_position[j] = t;
                    break;
                }
                i++;
            }
        }
        if(i == j){
            break;
        }
        j--;
    }

    nums[low] = nums[j];
    nums[j] = base; 
	int t = num_position[low];
	num_position[low] = num_position[j];
	num_position[j] = t;

    quick_sort(low, j - 1, nums, num_position);
    quick_sort(j + 1, high, nums, num_position);    
}

int binary_search(int * sorted_nums, int num1, int index1, int target, int numsSize){

    int num2 = target - num1;

    int left = index1 + 1;
    int right = numsSize;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(num2 < sorted_nums[mid]){
            right = mid;
        } else if(num2 > sorted_nums[mid]){
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}
