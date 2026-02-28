void reverse(char* s,int left,int right){
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
char* reverseWords(char* s) {
    int n = strlen(s);
    reverse(s, 0, n - 1);
    //read index
    int i = 0;
    //wirte index
    int j = 0;
    while(i < n){
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i >= n){
            break;
        }
        int word_start = j;
        while(i < n && s[i] != ' '){
            s[j++] = s[i++];
        }
        reverse(s, word_start, j - 1);
        // add space
        s[j++] = ' ';
    }
    if(j > 0){
        // remove additional space
        j--;
    }
    s[j] = '\0';
    return s;
}