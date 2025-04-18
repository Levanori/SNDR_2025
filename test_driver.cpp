#include <iostream>
#include <cassert>
#include <cmath>
#include "calculate.h"
#include "number_utils.h"
#include "triangle.h"

using namespace std;

void run_tests_triangle_gemini() {
    int passed_count = 0;
    int failed_count = 0;

    auto run_test = [&](const char* test_name, double a, double b, double c, const std::string& expected) {
        std::cout << "Running test: " << test_name << std::endl;
        std::cout << "Arguments: " << a << ", " << b << ", " << c << std::endl;
        std::string actual = triangleType(a, b, c);
        std::cout << "Expected:  " << expected << std::endl;
        std::cout << "Actual:    " << actual << std::endl;
        if (actual == expected) {
            std::cout << " - PASSED" << std::endl;
            passed_count++;
        } else {
            std::cout << " - FAILED" << std::endl;
            failed_count++;
        }
        std::cout << "========" << std::endl;
    };

    // Tests for "Not a triangle"
    run_test("Not a triangle - sum less than", 1, 2, 5, "Not a triangle");
    run_test("Not a triangle - sum equal to", 1, 2, 3, "Not a triangle");
    run_test("Not a triangle - negative side", -1, 2, 3, "Not a triangle");
    run_test("Not a triangle - zero side", 0, 2, 3, "Not a triangle");

    // Tests for "Equilateral"
    run_test("Equilateral - positive", 3, 3, 3, "Equilateral");
    run_test("Equilateral - small", 0.1, 0.1, 0.1, "Equilateral");

    // Tests for "Isosceles"
    run_test("Isosceles - a == b", 4, 4, 5, "Isosceles");
    run_test("Isosceles - b == c", 5, 4, 4, "Isosceles");
    run_test("Isosceles - a == c", 4, 5, 4, "Isosceles");
    run_test("Isosceles - with small numbers", 0.5, 0.5, 0.7, "Isosceles");

    // Tests for "Oxidous"
    run_test("Scalene - positive", 3, 4, 5, "Oxidous");
    run_test("Scalene - non-integer", 3.1, 4.2, 5.3, "Oxidous");

    std::cout << "\n--- Test Summary ---" << std::endl;
    std::cout << "Total tests: " << passed_count + failed_count << std::endl;
    std::cout << "Passed:      " << passed_count << std::endl;
    std::cout << "Failed:      " << failed_count << std::endl;

    if (failed_count == 0) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

void run_isEven_tests_gemini() {
    std::cout << "--- Running isEven tests ---" << std::endl;

    auto run_test = [&](const char* test_name, int input, bool expected) {
        std::cout << "Test: " << test_name << ", Input: " << input << ", Expected: " << expected;
        bool actual = isEven(input);
        if (actual == expected) {
            std::cout << " - PASSED" << std::endl;
        } else {
            std::cout << " - FAILED (Actual: " << actual << ")" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    };

    run_test("Positive even", 4, true);
    run_test("Positive odd", 7, false);
    run_test("Negative even", -2, true);
    run_test("Negative odd", -5, false);
    run_test("Zero", 0, true);
}

void run_isPrime_tests_gemini() {
    std::cout << "\n--- Running isPrime tests ---" << std::endl;

    auto run_test = [&](const char* test_name, int input, bool expected) {
        std::cout << "Test: " << test_name << ", Input: " << input << ", Expected: " << expected;
        bool actual = isPrime(input);
        if (actual == expected) {
            std::cout << " - PASSED" << std::endl;
        } else {
            std::cout << " - FAILED (Actual: " << actual << ")" << std::endl;
        }
        std::cout << "------------------------------" << std::endl;
    };

    run_test("Less than 2", 1, false);
    run_test("Two", 2, true);
    run_test("Small prime", 3, true);
    run_test("Small non-prime", 4, false);
    run_test("Larger prime", 17, true);
    run_test("Larger non-prime", 25, false);
    run_test("Negative number", -7, false);
}

void run_calculate_tests_gemini() {
    std::cout << "--- Running calculate tests ---" << std::endl;

    auto run_test = [&](const char* test_name, double a, double b, char op, double expected) {
        std::cout << "Test: " << test_name << ", Input: " << a << " " << op << " " << b << ", Expected: " << expected;
        double actual = calculate(a, b, op);
        if (std::abs(actual - expected) < 1e-9) { // Double comparison with margin of error
            std::cout << " - PASSED" << std::endl;
        } else {
            std::cout << " - FAILED (Actual: " << actual << ")" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    };

    // Tests for addition
    run_test("Addition positive", 2.5, 3.7, '+', 6.2);
    run_test("Addition negative", -1.0, 5.0, '+', 4.0);
    run_test("Addition zero", 10.0, 0.0, '+', 10.0);

    // Subtraction tests
    run_test("Subtraction positive", 7.0, 3.0, '-', 4.0);
    run_test("Subtraction negative", -2.0, -5.0, '-', 3.0);
    run_test("Subtraction zero", 5.0, 0.0, '-', 5.0);

    // Multiplication tests
    run_test("Multiplication positive", 2.0, 4.5, '*', 9.0);
    run_test("Multiplication negative", -3.0, 2.0, '*', -6.0);
    run_test("Multiplication by zero", 8.0, 0.0, '*', 0.0);

    // Division tests
    run_test("Division positive", 10.0, 2.0, '/', 5.0);
    run_test("Division negative", -6.0, 3.0, '/', -2.0);
    run_test("Division by one", 7.5, 1.0, '/', 7.5);
    run_test("Division zero by non-zero", 0.0, 5.0, '/', 0.0);
    run_test("Division by zero", 5.0, 0.0, '/', 0.0); // According to your implementation

    // Test for invalid operation
    run_test("Invalid operation", 5.0, 3.0, '%', 0.0); // According to your implementation
}

void testTriangleType_chatgpt() {
    cout << "=== Testing triangleType ===" << endl;

    struct TestCase {
        double a, b, c;
        string expected;
    };

    TestCase tests[] = {
        {3, 3, 3, "Equilateral"},
        {5, 5, 8, "Isosceles"},
        {7, 6, 5, "Oxidous"},
        {1, 2, 3, "Not a triangle"},
        {10, 1, 1, "Not a triangle"},
        {4, 4, 7.99, "Isosceles"}
    };

    for (const auto& test : tests) {
        string result = triangleType(test.a, test.b, test.c);
        cout << "triangleType(" << test.a << ", " << test.b << ", " << test.c << ") = " << result
             << " | Expected: " << test.expected
             << " | " << (result == test.expected ? "PASSED" : "FAILED") << endl;
    }

    cout << endl;
}

void testIsEven_chatgpt() {
    cout << "=== Testing isEven ===" << endl;

    int testValues[] = {2, 3, 0, -4, -7};
    bool expected[] = {true, false, true, true, false};

    for (int i = 0; i < 5; ++i) {
        bool result = isEven(testValues[i]);
        cout << "isEven(" << testValues[i] << ") = " << result
             << " | Expected: " << expected[i]
             << " | " << (result == expected[i] ? "PASSED" : "FAILED") << endl;
    }

    cout << endl;
}

void testIsPrime_chatgpt() {
    cout << "=== Testing isPrime ===" << endl;

    int testValues[] = {2, 3, 4, 17, 0, 1, -3};
    bool expected[] = {true, true, false, true, false, false, false};

    for (int i = 0; i < 7; ++i) {
        bool result = isPrime(testValues[i]);
        cout << "isPrime(" << testValues[i] << ") = " << result
             << " | Expected: " << expected[i]
             << " | " << (result == expected[i] ? "PASSED" : "FAILED") << endl;
    }

    cout << endl;
}

void testCalculate_chatgpt() {
    cout << "=== Testing calculate ===" << endl;

    struct TestCase {
        double a, b;
        char op;
        double expected;
    };

    TestCase tests[] = {
        {10, 5, '+', 15},
        {10, 5, '-', 5},
        {10, 5, '*', 50},
        {10, 5, '/', 2},
        {10, 0, '/', 0},   // division by zero check
        {5, 3, '?', 0}     // unknown operator
    };

    for (const auto& test : tests) {
        double result = calculate(test.a, test.b, test.op);
        cout << "calculate(" << test.a << ", " << test.b << ", '" << test.op << "') = " << result
             << " | Expected: " << test.expected
             << " | " << ((abs(result - test.expected) < 1e-6) ? "PASSED" : "FAILED") << endl;
    }

    cout << endl;
}

int main() {
    assert(2 + 2 == 5);
    run_tests_triangle_gemini();
    run_isEven_tests_gemini();
    run_isPrime_tests_gemini();
    run_calculate_tests_gemini();
    testIsEven_chatgpt();
    testIsPrime_chatgpt();
    testTriangleType_chatgpt();
    testCalculate_chatgpt();
    return 0;
}
