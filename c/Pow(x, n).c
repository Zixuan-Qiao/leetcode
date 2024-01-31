double pow_div(double x, long n) {
    if(n < 0) {
        x = 1 / x;
        n = -n;
    }

    if(n == 0)
        return 1.0;

    if(n % 2 == 0)
        return pow_div(x * x, n / 2);
    else
        return x * pow_div(x * x, (n - 1) / 2);
}

double myPow(double x, int n) {
    if(x == 0.0 || n == 1 || x == 1.0)
        return x;

    return pow_div(x, (long)n);
}