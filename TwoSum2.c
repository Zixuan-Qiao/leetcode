/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quick_sort(int low, int high, int * nums, int * num_position);

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int num_position[10000];
	for(int i = 0; i < 10000; i++){
		num_position[i] = i;
	}

    quick_sort(0, numsSize - 1, nums, num_position);

    int * array = (int *)malloc(2 * sizeof(int));
    * returnSize = 2;

    int i = 0;
    int j = numsSize - 1;
    while(1){
        int sum = nums[i] + nums[j];
        if(sum == target){
            array[0] = num_position[i];
            array[1] = num_position[j];
            return array;
        } else if(sum < target){
            i++;
        } else {
            j--;
        }
    }
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