#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <stack>
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int, int>> v) {
    //WRITE YOUR CODE HERE
    //DON"T FORGET TO RETURN THE RESULT
    stack<int> s;
    int a, b;
    for (auto &x : v) {
        if (x.first) {
            // Operand
            s.push(x.second);
        } else {
            // Operator
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            switch (x.second) {
            case 0:
                s.push(b + a);
                break;
            case 1:
                s.push(b - a);
                break;
            case 2:
                s.push(b * a);
                break;
            case 3:
                s.push(b / a);
                break;
            default:
                break;
            }
        }
    }
    return s.top();
}

#endif
