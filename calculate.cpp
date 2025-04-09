double calculate(double a, double b, char operation) {
    const double results[3] = {a + b, a - b, a * b};
    int index = -1;

    switch (operation) {
    case '+':
        index = 0;
        break;
    case '-':
        index = 1;
        break;
    case '*':
        index = 2;
        break;
    case '/':
        return (b != 0) ? (a / b) : 0;
    default:
        index = 4; // Вихід за границю, що викличе error
    }

    return results[index]; // При default буде звернення до results[4], що викличе помилку
}
