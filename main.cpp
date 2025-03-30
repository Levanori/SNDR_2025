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
    cout << "������ ��� �����: ";
    cin >> a >> b;

    cout << "������ �� (+, -, *, /): ";
    cin >> operation;

    cout << "���������: " << calculate(a,b,operation) << endl;

    double d, e, g;
    cout << "������ ��� ������� ����������: ";
    cin >> d >> e >> g;

    cout << "��� ����������: " << triangleType(d, e, g) << endl;

    int num;
    cout << "������ �����: ";
    cin >> num;

    cout << "����� " << (isEven(num) ? "�����" : "�������") << endl;
    cout << "����� " << (isPrime(num) ? "������" : "��������") << endl;

    return 0;
}

