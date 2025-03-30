#include <iostream>
#include "calculate.h"
#include "triangle.h"
#include "number_utils.h"
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    double a, b, c;
    char operation;
    cout << "¬вед≥ть два числа: ";
    cin >> a >> b;

    cout << "¬вед≥ть д≥ю (+, -, *, /): ";
    cin >> operation;

    cout << "–езультат: " << calculate(a,b,operation) << endl;

    double d, e, g;
    cout << "¬вед≥ть три сторони трикутника: ";
    cin >> d >> e >> g;

    cout << "“ип трикутника: " << triangleType(d, e, g) << endl;

    int num;
    cout << "¬вед≥ть число: ";
    cin >> num;

    cout << "„исло " << (isEven(num) ? "парне" : "непарне") << endl;
    cout << "„исло " << (isPrime(num) ? "просте" : "складене") << endl;

    return 0;
}

