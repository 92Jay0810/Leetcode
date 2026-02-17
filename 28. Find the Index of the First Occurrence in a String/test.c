// KMP
void build_lsp(char* pattern, int* lsp, int m){
    //previous prefix suffix
    int len = 0;
    lsp[0] = 0;
    int i = 1;
    while(i < m){
        if(pattern[i] == pattern[len]){
            len++;
            lsp[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lsp[len - 1];
            }else{
                lsp[i] = 0;
                i++;
            }
        }
    }
}
int strStr(char* haystack, char* needle) {
    if(*needle == '\0'){
        return 0;
    }
    int n = 0;
    int m = 0;
    while(haystack[n]) n++;
    while(needle[m]) m++;
    int lsp[m];
    build_lsp(needle, lsp, m);
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(haystack[i] == needle[j]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = lsp[j - 1];
            }else{
                i++;
            }
        }
    }
    if(j == m){
        return i - j;
    }
    return -1;

}