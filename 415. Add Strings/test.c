int my_strlen(const char* str){
    int count = 0;
    while(*str){
        str++;
        count++;
    }
    return count;
}
char *addStrings(const char *num1, const char *num2){
    int n1 = my_strlen(num1);
    int n2 = my_strlen(num2);
    int i = n1 - 1 ;
    int j = n2 - 1 ;
    // +2 for carry and \0
    // Note the Precedence +2 must after the tuple operator
    int maxlen = ((n1 > n2) ? n1 : n2) + 2;
    // reuslt 一定要是malloc 因為後面會回傳 若用靜態宣告 會被call stack 清理掉
    char* result = (char*)malloc((maxlen) * sizeof(char));
    int k = 0;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry){
        int sum = carry;
        if(i >= 0){
            sum += num1[i--] - '0';
        }
        if(j >= 0){
            sum += num2[j--] - '0';
        }
        result[k++] = sum % 10 + '0';
        carry = sum / 10; 
    }
    result[k] = '\0';
    for(int i = 0 ; i < k/2 ; i++){
        char temp = result[i];
        result[i] = result[k - 1  - i];
        result[k - 1 - i] = temp;
    }
    return result;
}