#include <string>

using namespace std;

string triangleType(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "�� ���������";
    }
    if (a == b && b == c) {
        return "г�����������";
    }
    if (a == b || b == c || a == c) {
        return "г�����������";
    }
    return "г�����������";
}
