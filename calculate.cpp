double calculate(double a, double b, char operation) {
    switch (operation) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return (b != 0) ? (a / b) : 0;
    default:
        return 0;
    }
}
