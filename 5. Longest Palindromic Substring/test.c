void expand(char* s, int left, int right,int* start, int* maxlen){
    while(left>=0 && s[right] && s[left] == s[right]){
        left--;
        right++;
    }
    // 結束時有多走一圈
    // (right - 1) - (left + 1) + 1 = right - left + 1
    int len = right - left - 1;
    if(len > *maxlen){
        *maxlen = len;
        // left 結束時有多走一圈，因此加1 到正確位置
        *start = left + 1;
    }
}
char* longestPalindrome(char* s) {
    int n = strlen(s);
    if(n < 2){
        return s;
    }
    int start = 0;
    int maxlen = 1;
    for(int i = 0 ; i < n ; i++){
        expand(s, i, i, &start, &maxlen);
        expand(s, i, i + 1, &start, &maxlen);
    }
    // 原字串切一刀
    s[start + maxlen] = '\0';
    return s + start;
}