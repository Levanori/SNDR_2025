#include <iostream>
#include "calculate.h"
#include "triangle.h"
#include "number_utils.h"
#include <locale> // Просто інформування, що cppcheck не бачить файли бібліотек

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    double a, b;
    char operation;
    cout << "Введіть два числа: ";
    cin >> a >> b;

    cout << "Введіть дію (+, -, *, /): ";
    cin >> operation;

    cout << "Результат: " << calculate(a,b,operation) << endl;

    double d, e, g;
    cout << "Введіть три сторони трикутника: ";
    cin >> d >> e >> g;

    cout << "Тип трикутника: " << triangleType(d, e, g) << endl;

    int num;
    cout << "Введіть число: ";
    cin >> num;

    cout << "Число " << (isEven(num) ? "парне" : "непарне") << endl;
    cout << "Число " << (isPrime(num) ? "просте" : "складене") << endl;

    return 0;
}

