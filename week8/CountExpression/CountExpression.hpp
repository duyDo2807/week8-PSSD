#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class CountExpressions {
 public:
  int calcExpressions(int x, int y, int val) {
    vector<int> nums = {x, x, y, y};
    vector<char> ops = {'+', '-', '*'};
    set<string> uniqueExpressions;

    // Generate all permutations of the numbers
    do {
      // Generate all combinations of the operators
      for (char op1 : ops) {
        for (char op2 : ops) {
          for (char op3 : ops) {
            // Form the expression
            string expression = to_string(nums[0]) + op1 + to_string(nums[1]) +
                                op2 + to_string(nums[2]) + op3 +
                                to_string(nums[3]);
            // Evaluate the expression
            if (evaluateExpression(nums[0], op1, nums[1], op2, nums[2], op3,
                                   nums[3]) == val) {
              uniqueExpressions.insert(expression);
            }
          }
        }
      }
    } while (next_permutation(nums.begin(), nums.end()));

    return uniqueExpressions.size();
  }

 private:
  int evaluateExpression(int a, char op1, int b, char op2, int c, char op3,
                         int d) {
    int first = applyOperator(a, op1, b);
    int second = applyOperator(first, op2, c);
    return applyOperator(second, op3, d);
  }

  int applyOperator(int left, char op, int right) {
    if (op == '+') return left + right;
    if (op == '-') return left - right;
    if (op == '*') return left * right;
    return 0;
  }
};