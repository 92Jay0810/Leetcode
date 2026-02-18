char* multiply(char* num1, char* num2) {
    if(num1 == NULL || num2 == NULL){
        return NULL;
    }
    int n1 = strlen(num1);
    int n2 = strlen(num2);
    int size = n1 + n2;
    int* temp_result = (int*)calloc(size,sizeof(int));
    for(int i = n1 - 1 ; i >= 0 ; i--){
        for(int j = n2 -1 ; j >= 0 ; j--){
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + temp_result[i + j + 1];
            temp_result[i + j + 1] = sum % 10;
            temp_result[i + j] += sum / 10;
        }
    }
    // transform to string
    char* result = (char*)malloc((size + 1) * sizeof(char));
    // read for temp_result
    int k = 0;
    // write on result
    int l = 0;
    while(k < size && temp_result[k] == 0){
        k++;    
    }
    if(k == size){
        free(temp_result);
        strcpy(result,"0");
        return result;
    }
    while(k < size){
        result[l++] = temp_result[k++] + '0';
    }
    result[l] = '\0';
    free(temp_result);
    return result;
}