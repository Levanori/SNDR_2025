#include <string>

using namespace std;

string triangleType(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "Not a triangle";
    }
    if (a == b && b == c) {
        return "Equilateral";
    }
    if (a == b || b == c || a == c) {
        return "Isosceles";
    }
    return "Oxidousss";
}
