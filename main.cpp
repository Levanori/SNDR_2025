#include <iostream>
#include "calculate.h"
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    double a, b, c;
    char operation;

    cout << "������ ��� �����: ";
    cin >> a >> b;

    cout << "������ �� (+, -, *, /): ";
    cin >> operation;

    cout << "���������: " << calculate(a,b,operation) << endl;

    return 0;
}

