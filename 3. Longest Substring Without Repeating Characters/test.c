int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int freq[256] = {0};
    int maxlen = 0;
    int left = 0;
    for(int right = 0; right < n ; right++){
        freq[(unsigned char)s[right]]++;
        while(freq[(unsigned char)s[right]] > 1){
            freq[(unsigned char)s[left]]--;
            left++;
        }
        int len = right - left + 1;
        if(len > maxlen){
            maxlen = len;
        }
    }
    return maxlen;
}