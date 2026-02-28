void reverse(char* s, int left, int right){
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
char* reverseStr(char* s, int k) {
    int n = strlen(s);
    for(int i = 0; i < n ; i = i + k * 2){
        int left = i;
        int right = i + k - 1;
        if(right >= n){
            right = n - 1;
        }
        reverse(s, left, right);
    }
    return s;
}