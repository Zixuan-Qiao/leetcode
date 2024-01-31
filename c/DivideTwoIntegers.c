int divide(int dividend, int divisor) {
    if (dividend == 0) 
        return 0;
    if (dividend == divisor) 
        return 1;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;

    bool flag = (dividend < 0 == divisor < 0);
	unsigned int a = dividend == INT_MIN ? dividend: abs(dividend);
	unsigned int b = divisor == INT_MIN ? divisor: abs(divisor);
    
    unsigned int q = 0;
    while (a >= b) {
        int p = 0;
        while (a > (b << (p + 1)))
            p++;
        q += (1 << p);
        a = a - (b << p);
    }

    if (flag)
        return q;
    else 
        return -q;
}