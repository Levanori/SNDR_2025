#include <string>

using namespace std;

string triangleType(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "Не трикутник";
    }
    if (a == b && b == c) {
        return "Рівносторонній";
    }
    if (a == b || b == c || a == c) {
        return "Рівнобедрений";
    }
    return "Різносторонній";
}
