double calculate(double a, double b, char operation) {
    switch (operation) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        // ������� �� ���� ��� �������� - ������ error (�����������)
        return a / b;
    default:
        return 0;
    }
}
