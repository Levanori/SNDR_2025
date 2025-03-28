#include <iostream>
#include "calculate.h"
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

    return 0;
}

