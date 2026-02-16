void itoa(int x, char* str){
    if(x == 0){
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    int count = 0;
    while(x > 0){
        str[count] = x % 10 + '0';
        x = x / 10;
        count++;
    }
    str[count] = '\0';
    int left = 0;
    int right = count - 1;
    while(left < right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}
//記得string的結尾是\0
bool isPalindrome(int x) {
    if(x < 0) return false;
    int left = 0;
    char s[12];
    itoa(x,s);
    int right =strlen(s)  - 1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
//記得負數的情況
//char 陣列傳入function 會自動decay成pointer 不用取址
//也有不用itoa的方法
