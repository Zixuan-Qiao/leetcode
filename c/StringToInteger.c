#define MAX 200

int myAtoi(char * s){

    int i = 0;
    while(s[i] == ' '){
        i++;
    }

    bool flag = false;
    if(s[i] == '-'){
        flag = true;
        i++;
    } else if(s[i] == '+'){
        i++;
    }

    while(s[i] == '0'){
        i++;
    }

    int arr[MAX];
    int len = 0;
    while(s[i] <= '9' && s[i] >= '0'){
        arr[len] = s[i] - 48;
        len++;
        i++;
    }

    long int boundary = 0x80000000;

    if(len > 10){
        if(flag == true){
            return (int) (-boundary);
        } else {
            return (int) (boundary - 1);
        }
    }

    long int sum = 0;
    long int base = 1;
    for(int i = len - 1; i >= 0; i--){
        sum += arr[i] * base;
        if(sum >= boundary){
            if(flag == true){
                return (int) (-boundary);
            } else {
                return (int) (boundary - 1);
            }
        }
        base *= 10;
    }

    if(flag == true){
        return (int) (-sum);
    } else {
        return (int) sum;
    }

}