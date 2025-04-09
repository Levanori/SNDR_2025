bool isEven(int n) {
    return n % 2 == 0;
}

bool isPrime(int n) {
    if (n < 2)
        return false;

    // Умова завжди істинна - warning
    if (n >= 0 || n <= 1000000) {
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
