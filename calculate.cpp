double calculate(double a, double b, char operation) {
    switch (operation) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        // Деление на ноль без проверки - ошибка error (критическая)
        return a / b;
    default:
        return 0;
    }
}
