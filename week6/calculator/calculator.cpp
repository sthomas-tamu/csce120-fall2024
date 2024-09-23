#include <iostream>
#include <sstream>

using std::cin, std::cout, std::endl, std::string;

string formatResult(double a, double b, char op, double result) {
    std::ostringstream oss;
    oss << a << " " << op << " " << b << " = " << result;
    return oss.str();
}

int main() {
    // read in expression
    cout << "Enter the expression to calculate in one line: " << endl;
    string line;
    std::getline(cin, line);

    // extract out operands and operator using an istringstream
    double firstNum = 0, secondNum = 0;
    char op = ' ';
    std::istringstream iss(line);
    iss >> firstNum;
    iss >> op;
    iss >> secondNum;
    // iss >> firstnum >> op >> secondnum; // could instead put it all on 1 line, just like we do with cin/cout

    // compute the result of the question based on the op
    double result = 0;
    switch (op) {
        case '+': 
            result = firstNum + secondNum; 
            break;
        case '-': 
            result = firstNum - secondNum; 
            break;
        case '*': 
            result = firstNum * secondNum; 
            break;
        case '/': 
            result = firstNum / secondNum; 
            break;
        default:
            cout << "Error, invalid operator '" << op << "', must be either +, -, *, or /" << endl;
            return -1;
    }

    // output result 
    cout << "result: " << result << endl;
    cout << formatResult(firstNum, secondNum, op, result) << endl;

    return 0;
}
