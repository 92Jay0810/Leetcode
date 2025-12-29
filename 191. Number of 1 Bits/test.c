int hammingWeight(int n) {
    uint32_t num = (uint32_t)n;   // C-style cast
    int count = 0;

    for (int i = 0; i < 32; i++) {
        // 1u 很重要  1u 是 unsigned int
        // 若把 1 看是 signed int 左移到第 31 bit → undefined behavior
        if ((1u << i) & num) {
            count++;
        }
    }
    return count;
}