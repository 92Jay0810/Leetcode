bool isNum(char c){
    return (c >= '0' && c <= '9');
}
int myAtoi(char* s) {
    bool negative = false;
    if(!s) return 0;
    if(*s == ' '){
        while(*s == ' '){
            s++;
        }
    }
    if(*s == '-' || *s == '+'){
        if(*s == '-') negative = true;
        s++;
    }
    int result = 0;
    while(isNum(*s)){
        int digit = *s - '0';
        if (result > 0x7FFFFFFF / 10 ||
           (result == 0x7FFFFFFF / 10 && digit > 0x7FFFFFFF % 10)) {
            return !negative ? 0x7FFFFFFF : 0x80000000;
        }
        result = result * 10 + digit;
        s++;
    }
    return negative ? -result : result;
}