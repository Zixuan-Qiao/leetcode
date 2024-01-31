#define SIZE 300

bool is_similar(char * str1, char * str2);
int numSimilarGroups(char ** strs, int strsSize);
void parents_update(int index1, int index2, int * parents, int array_size);
int find_parent(int index, int *parents);

int numSimilarGroups(char ** strs, int strsSize){

    int parents[SIZE];

    for(int i = 0; i < strsSize; i++){
        parents[i] = -1;
    }

    for(int i = 0; i < strsSize; i++){
        for(int j = i + 1; j < strsSize; j++){

            if(is_similar(strs[i], strs[j])){
                parents_update(i, j, parents, strsSize); 
            }
        }
    }

    int parents_counter = 0;
    for(int i = 0; i < strsSize; i++){
        if(parents[i] == -1){
            parents_counter++;
        }
    }

    return parents_counter;

}

bool is_similar(char * str1, char * str2){

    int difference_counter = 0;
    int length = strlen(str1);
    for(int i = 0; i < length; i++){
        if(str1[i] != str2[i]){
            difference_counter++;
        }
    }

    if(difference_counter == 0 || difference_counter == 2){
        return true;
    } else {
        return false;
    }
}

int find_parent(int index, int *parents){
	
	while(true){
		if(parents[index] < 0){
			return index;
		} else {
			index = parents[index];
		}
	}

	return 0;
}

void parents_update(int index1, int index2, int * parents, int array_size){
	
	int p1 = find_parent(index1, parents);
	int p2 = find_parent(index2, parents);

	if(p1 != p2){
		parents[p2] = p1;
	}
}
