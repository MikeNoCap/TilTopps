// C++ program to print all permutations using
// Heap's algorithm
#include <algorithm>
#include <cmath>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct Answer
{
  double number;
  string operands;
};

void operations(vector<int> nums, string answers[])
{
  int numCount = nums.size();

  double n1;
  double n2;
  double n3;
  double n4;
  double n5;

  n1 = nums[0];
  if (numCount > 1)
  {
    n2 = nums[1];
  }
  if (numCount > 2)
  {
    n3 = nums[2];
  }
  if (numCount > 3)
  {
    n4 = nums[3];
  }
  if (numCount > 4)
  {
    n5 = nums[4];
  }

  vector<Answer> operations5num = {
      {n1 + n2 + n3 + n4 + n5, "n1+n2+n3+n4+n5"},
      {n1 + n2 + n3 + n4 - n5, "n1+n2+n3+n4-n5"},
      {n1 + n2 + n3 + n4 * n5, "n1+n2+n3+n4*n5"},
      {n1 + n2 + n3 + pow(n4, n5), "n1+n2+n3+n4^n5"},
      {n1 + n2 + n3 + n4 / n5, "n1+n2+n3+n4/n5"},
      {n1 + n2 + n3 - n4 + n5, "n1+n2+n3-n4+n5"},
      {n1 + n2 + n3 - n4 - n5, "n1+n2+n3-n4-n5"},
      {n1 + n2 + n3 - n4 * n5, "n1+n2+n3-n4*n5"},
      {n1 + n2 + n3 - pow(n4, n5), "n1+n2+n3-n4^n5"},
      {n1 + n2 + n3 - n4 / n5, "n1+n2+n3-n4/n5"},
      {n1 + n2 + n3 * n4 + n5, "n1+n2+n3*n4+n5"},
      {n1 + n2 + n3 * n4 - n5, "n1+n2+n3*n4-n5"},
      {n1 + n2 + n3 * n4 * n5, "n1+n2+n3*n4*n5"},
      {n1 + n2 + n3 * pow(n4, n5), "n1+n2+n3*n4^n5"},
      {n1 + n2 + n3 * n4 / n5, "n1+n2+n3*n4/n5"},
      {n1 + n2 + pow(n3, n4) + n5, "n1+n2+n3^n4+n5"},
      {n1 + n2 + pow(n3, n4) - n5, "n1+n2+n3^n4-n5"},
      {n1 + n2 + pow(n3, n4) * n5, "n1+n2+n3^n4*n5"},
      {n1 + n2 + pow(n3, pow(n4, n5)), "n1+n2+n3^n4^n5"},
      {n1 + n2 + pow(n3, n4) / n5, "n1+n2+n3^n4/n5"},
      {n1 + n2 + n3 / n4 + n5, "n1+n2+n3/n4+n5"},
      {n1 + n2 + n3 / n4 - n5, "n1+n2+n3/n4-n5"},
      {n1 + n2 + n3 / n4 * n5, "n1+n2+n3/n4*n5"},
      {n1 + n2 + n3 / pow(n4, n5), "n1+n2+n3/n4^n5"},
      {n1 + n2 + n3 / n4 / n5, "n1+n2+n3/n4/n5"},
      {n1 - n2 - n3 - n4 + n5, "n1-n2-n3-n4+n5"},
      {n1 - n2 - n3 - n4 - n5, "n1-n2-n3-n4-n5"},
      {n1 - n2 - n3 - n4 * n5, "n1-n2-n3-n4*n5"},
      {n1 - n2 - n3 - pow(n4, n5), "n1-n2-n3-n4^n5"},
      {n1 - n2 - n3 - n4 / n5, "n1-n2-n3-n4/n5"},
      {n1 - n2 - n3 + n4 + n5, "n1-n2-n3+n4+n5"},
      {n1 - n2 - n3 + n4 - n5, "n1-n2-n3+n4-n5"},
      {n1 - n2 - n3 + n4 * n5, "n1-n2-n3+n4*n5"},
      {n1 - n2 - n3 + pow(n4, n5), "n1-n2-n3+n4^n5"},
      {n1 - n2 - n3 + n4 / n5, "n1-n2-n3+n4/n5"},
      {n1 - n2 - n3 * n4 + n5, "n1-n2-n3*n4+n5"},
      {n1 - n2 - n3 * n4 - n5, "n1-n2-n3*n4-n5"},
      {n1 - n2 - n3 * n4 * n5, "n1-n2-n3*n4*n5"},
      {n1 - n2 - n3 * pow(n4, n5), "n1-n2-n3*n4^n5"},
      {n1 - n2 - n3 * n4 / n5, "n1-n2-n3*n4/n5"},
      {n1 - n2 - pow(n3, n4) + n5, "n1-n2-n3^n4+n5"},
      {n1 - n2 - pow(n3, n4) - n5, "n1-n2-n3^n4-n5"},
      {n1 - n2 - pow(n3, n4) * n5, "n1-n2-n3^n4*n5"},
      {n1 - n2 - pow(n3, pow(n4, n5)), "n1-n2-n3^n4^n5"},
      {n1 - n2 - pow(n3, n4) / n5, "n1-n2-n3^n4/n5"},
      {n1 - n2 - n3 / n4 + n5, "n1-n2-n3/n4+n5"},
      {n1 - n2 - n3 / n4 - n5, "n1-n2-n3/n4-n5"},
      {n1 - n2 - n3 / n4 * n5, "n1-n2-n3/n4*n5"},
      {n1 - n2 - n3 / pow(n4, n5), "n1-n2-n3/n4^n5"},
      {n1 - n2 - n3 / n4 / n5, "n1-n2-n3/n4/n5"},
      {n1 * n2 * n3 * n4 + n5, "n1*n2*n3*n4+n5"},
      {n1 * n2 * n3 * n4 - n5, "n1*n2*n3*n4-n5"},
      {n1 * n2 * n3 * n4 * n5, "n1*n2*n3*n4*n5"},
      {n1 * n2 * n3 * pow(n4, n5), "n1*n2*n3*n4^n5"},
      {n1 * n2 * n3 * n4 / n5, "n1*n2*n3*n4/n5"},
      {n1 * n2 * n3 + n4 + n5, "n1*n2*n3+n4+n5"},
      {n1 * n2 * n3 + n4 - n5, "n1*n2*n3+n4-n5"},
      {n1 * n2 * n3 + n4 * n5, "n1*n2*n3+n4*n5"},
      {n1 * n2 * n3 + pow(n4, n5), "n1*n2*n3+n4^n5"},
      {n1 * n2 * n3 + n4 / n5, "n1*n2*n3+n4/n5"},
      {n1 * n2 * n3 - n4 + n5, "n1*n2*n3-n4+n5"},
      {n1 * n2 * n3 - n4 - n5, "n1*n2*n3-n4-n5"},
      {n1 * n2 * n3 - n4 * n5, "n1*n2*n3-n4*n5"},
      {n1 * n2 * n3 - pow(n4, n5), "n1*n2*n3-n4^n5"},
      {n1 * n2 * n3 - n4 / n5, "n1*n2*n3-n4/n5"},
      {n1 * n2 * pow(n3, n4) + n5, "n1*n2*n3^n4+n5"},
      {n1 * n2 * pow(n3, n4) - n5, "n1*n2*n3^n4-n5"},
      {n1 * n2 * pow(n3, n4) * n5, "n1*n2*n3^n4*n5"},
      {n1 * n2 * pow(n3, pow(n4, n5)), "n1*n2*n3^n4^n5"},
      {n1 * n2 * pow(n3, n4) / n5, "n1*n2*n3^n4/n5"},
      {n1 * n2 * n3 / n4 + n5, "n1*n2*n3/n4+n5"},
      {n1 * n2 * n3 / n4 - n5, "n1*n2*n3/n4-n5"},
      {n1 * n2 * n3 / n4 * n5, "n1*n2*n3/n4*n5"},
      {n1 * n2 * n3 / pow(n4, n5), "n1*n2*n3/n4^n5"},
      {n1 * n2 * n3 / n4 / n5, "n1*n2*n3/n4/n5"},
      {pow(n1, pow(n2, pow(n3, n4))) + n5,
       "n1^n2^n3^n4+n5"},
      {pow(n1, pow(n2, pow(n3, n4))) - n5,
       "n1^n2^n3^n4-n5"},
      {pow(n1, pow(n2, pow(n3, n4))) * n5,
       "n1^n2^n3^n4*n5"},
      {pow(n1, pow(n2, pow(n3, pow(n4, n5)))),
       "n1^n2^n3^n4^n5"},
      {pow(n1, pow(n2, pow(n3, n4))) / n5,
       "n1^n2^n3^n4/n5"},
      {pow(n1, pow(n2, n3)) + n4 + n5, "n1^n2^n3+n4+n5"},
      {pow(n1, pow(n2, n3)) + n4 - n5, "n1^n2^n3+n4-n5"},
      {pow(n1, pow(n2, n3)) + n4 * n5, "n1^n2^n3+n4*n5"},
      {pow(n1, pow(n2, n3)) + pow(n4, n5),
       "n1^n2^n3+n4^n5"},
      {pow(n1, pow(n2, n3)) + n4 / n5, "n1^n2^n3+n4/n5"},
      {pow(n1, pow(n2, n3)) - n4 + n5, "n1^n2^n3-n4+n5"},
      {pow(n1, pow(n2, n3)) - n4 - n5, "n1^n2^n3-n4-n5"},
      {pow(n1, pow(n2, n3)) - n4 * n5, "n1^n2^n3-n4*n5"},
      {pow(n1, pow(n2, n3)) - pow(n4, n5),
       "n1^n2^n3-n4^n5"},
      {pow(n1, pow(n2, n3)) - n4 / n5, "n1^n2^n3-n4/n5"},
      {pow(n1, pow(n2, n3)) * n4 + n5, "n1^n2^n3*n4+n5"},
      {pow(n1, pow(n2, n3)) * n4 - n5, "n1^n2^n3*n4-n5"},
      {pow(n1, pow(n2, n3)) * n4 * n5, "n1^n2^n3*n4*n5"},
      {pow(n1, pow(n2, n3)) * pow(n4, n5),
       "n1^n2^n3*n4^n5"},
      {pow(n1, pow(n2, n3)) * n4 / n5, "n1^n2^n3*n4/n5"},
      {pow(n1, pow(n2, n3)) / n4 + n5, "n1^n2^n3/n4+n5"},
      {pow(n1, pow(n2, n3)) / n4 - n5, "n1^n2^n3/n4-n5"},
      {pow(n1, pow(n2, n3)) / n4 * n5, "n1^n2^n3/n4*n5"},
      {pow(n1, pow(n2, n3)) / pow(n4, n5),
       "n1^n2^n3/n4^n5"},
      {pow(n1, pow(n2, n3)) / n4 / n5, "n1^n2^n3/n4/n5"},
      {n1 + n2 - n3 * n4 + n5, "n1+n2-n3*n4+n5"},
      {n1 + n2 - n3 * n4 - n5, "n1+n2-n3*n4-n5"},
      {n1 + n2 - n3 * n4 * n5, "n1+n2-n3*n4*n5"},
      {n1 + n2 - n3 * pow(n4, n5), "n1+n2-n3*n4^n5"},
      {n1 + n2 - n3 * n4 / n5, "n1+n2-n3*n4/n5"},
      {n1 + n2 - pow(n3, n4) + n5, "n1+n2-n3^n4+n5"},
      {n1 + n2 - pow(n3, n4) - n5, "n1+n2-n3^n4-n5"},
      {n1 + n2 - pow(n3, n4) * n5, "n1+n2-n3^n4*n5"},
      {n1 + n2 - pow(n3, pow(n4, n5)), "n1+n2-n3^n4^n5"},
      {n1 + n2 - pow(n3, n4) / n5, "n1+n2-n3^n4/n5"},
      {n1 + n2 - n3 / n4 + n5, "n1+n2-n3/n4+n5"},
      {n1 + n2 - n3 / n4 - n5, "n1+n2-n3/n4-n5"},
      {n1 + n2 - n3 / n4 * n5, "n1+n2-n3/n4*n5"},
      {n1 + n2 - n3 / pow(n4, n5), "n1+n2-n3/n4^n5"},
      {n1 + n2 - n3 / n4 / n5, "n1+n2-n3/n4/n5"},
      {n1 + n2 * n3 + n4 + n5, "n1+n2*n3+n4+n5"},
      {n1 + n2 * n3 + n4 - n5, "n1+n2*n3+n4-n5"},
      {n1 + n2 * n3 + n4 * n5, "n1+n2*n3+n4*n5"},
      {n1 + n2 * n3 + pow(n4, n5), "n1+n2*n3+n4^n5"},
      {n1 + n2 * n3 + n4 / n5, "n1+n2*n3+n4/n5"},
      {n1 + n2 * n3 - n4 + n5, "n1+n2*n3-n4+n5"},
      {n1 + n2 * n3 - n4 - n5, "n1+n2*n3-n4-n5"},
      {n1 + n2 * n3 - n4 * n5, "n1+n2*n3-n4*n5"},
      {n1 + n2 * n3 - pow(n4, n5), "n1+n2*n3-n4^n5"},
      {n1 + n2 * n3 - n4 / n5, "n1+n2*n3-n4/n5"},
      {n1 + n2 * n3 * n4 + n5, "n1+n2*n3*n4+n5"},
      {n1 + n2 * n3 * n4 - n5, "n1+n2*n3*n4-n5"},
      {n1 + n2 * n3 * n4 * n5, "n1+n2*n3*n4*n5"},
      {n1 + n2 * n3 * pow(n4, n5), "n1+n2*n3*n4^n5"},
      {n1 + n2 * n3 * n4 / n5, "n1+n2*n3*n4/n5"},
      {n1 + n2 * pow(n3, n4) + n5, "n1+n2*n3^n4+n5"},
      {n1 + n2 * pow(n3, n4) - n5, "n1+n2*n3^n4-n5"},
      {n1 + n2 * pow(n3, n4) * n5, "n1+n2*n3^n4*n5"},
      {n1 + n2 * pow(n3, pow(n4, n5)), "n1+n2*n3^n4^n5"},
      {n1 + n2 * pow(n3, n4) / n5, "n1+n2*n3^n4/n5"},
      {n1 + n2 * n3 / n4 + n5, "n1+n2*n3/n4+n5"},
      {n1 + n2 * n3 / n4 - n5, "n1+n2*n3/n4-n5"},
      {n1 + n2 * n3 / n4 * n5, "n1+n2*n3/n4*n5"},
      {n1 + n2 * n3 / pow(n4, n5), "n1+n2*n3/n4^n5"},
      {n1 + n2 * n3 / n4 / n5, "n1+n2*n3/n4/n5"},
      {n1 + pow(n2, n3) + n4 + n5, "n1+n2^n3+n4+n5"},
      {n1 + pow(n2, n3) + n4 - n5, "n1+n2^n3+n4-n5"},
      {n1 + pow(n2, n3) + n4 * n5, "n1+n2^n3+n4*n5"},
      {n1 + pow(n2, n3) + pow(n4, n5), "n1+n2^n3+n4^n5"},
      {n1 + pow(n2, n3) + n4 / n5, "n1+n2^n3+n4/n5"},
      {n1 + pow(n2, n3) - n4 + n5, "n1+n2^n3-n4+n5"},
      {n1 + pow(n2, n3) - n4 - n5, "n1+n2^n3-n4-n5"},
      {n1 + pow(n2, n3) - n4 * n5, "n1+n2^n3-n4*n5"},
      {n1 + pow(n2, n3) - pow(n4, n5), "n1+n2^n3-n4^n5"},
      {n1 + pow(n2, n3) - n4 / n5, "n1+n2^n3-n4/n5"},
      {n1 + pow(n2, n3) * n4 + n5, "n1+n2^n3*n4+n5"},
      {n1 + pow(n2, n3) * n4 - n5, "n1+n2^n3*n4-n5"},
      {n1 + pow(n2, n3) * n4 * n5, "n1+n2^n3*n4*n5"},
      {n1 + pow(n2, n3) * pow(n4, n5), "n1+n2^n3*n4^n5"},
      {n1 + pow(n2, n3) * n4 / n5, "n1+n2^n3*n4/n5"},
      {n1 + pow(n2, pow(n3, n4)) + n5, "n1+n2^n3^n4+n5"},
      {n1 + pow(n2, pow(n3, n4)) - n5, "n1+n2^n3^n4-n5"},
      {n1 + pow(n2, pow(n3, n4)) * n5, "n1+n2^n3^n4*n5"},
      {n1 + pow(n2, pow(n3, pow(n4, n5))),
       "n1+n2^n3^n4^n5"},
      {n1 + pow(n2, pow(n3, n4)) / n5, "n1+n2^n3^n4/n5"},
      {n1 + pow(n2, n3) / n4 + n5, "n1+n2^n3/n4+n5"},
      {n1 + pow(n2, n3) / n4 - n5, "n1+n2^n3/n4-n5"},
      {n1 + pow(n2, n3) / n4 * n5, "n1+n2^n3/n4*n5"},
      {n1 + pow(n2, n3) / pow(n4, n5), "n1+n2^n3/n4^n5"},
      {n1 + pow(n2, n3) / n4 / n5, "n1+n2^n3/n4/n5"},
      {n1 + n2 / n3 / n4 + n5, "n1+n2/n3/n4+n5"},
      {n1 + n2 / n3 / n4 - n5, "n1+n2/n3/n4-n5"},
      {n1 + n2 / n3 / n4 * n5, "n1+n2/n3/n4*n5"},
      {n1 + n2 / n3 / pow(n4, n5), "n1+n2/n3/n4^n5"},
      {n1 + n2 / n3 / n4 / n5, "n1+n2/n3/n4/n5"},
      {n1 + n2 / n3 + n4 + n5, "n1+n2/n3+n4+n5"},
      {n1 + n2 / n3 + n4 - n5, "n1+n2/n3+n4-n5"},
      {n1 + n2 / n3 + n4 * n5, "n1+n2/n3+n4*n5"},
      {n1 + n2 / n3 + pow(n4, n5), "n1+n2/n3+n4^n5"},
      {n1 + n2 / n3 + n4 / n5, "n1+n2/n3+n4/n5"},
      {n1 + n2 / n3 - n4 + n5, "n1+n2/n3-n4+n5"},
      {n1 + n2 / n3 - n4 - n5, "n1+n2/n3-n4-n5"},
      {n1 + n2 / n3 - n4 * n5, "n1+n2/n3-n4*n5"},
      {n1 + n2 / n3 - pow(n4, n5), "n1+n2/n3-n4^n5"},
      {n1 + n2 / n3 - n4 / n5, "n1+n2/n3-n4/n5"},
      {n1 + n2 / n3 * n4 + n5, "n1+n2/n3*n4+n5"},
      {n1 + n2 / n3 * n4 - n5, "n1+n2/n3*n4-n5"},
      {n1 + n2 / n3 * n4 * n5, "n1+n2/n3*n4*n5"},
      {n1 + n2 / n3 * pow(n4, n5), "n1+n2/n3*n4^n5"},
      {n1 + n2 / n3 * n4 / n5, "n1+n2/n3*n4/n5"},
      {n1 + n2 / pow(n3, n4) + n5, "n1+n2/n3^n4+n5"},
      {n1 + n2 / pow(n3, n4) - n5, "n1+n2/n3^n4-n5"},
      {n1 + n2 / pow(n3, n4) * n5, "n1+n2/n3^n4*n5"},
      {n1 + n2 / pow(n3, pow(n4, n5)), "n1+n2/n3^n4^n5"},
      {n1 + n2 / pow(n3, n4) / n5, "n1+n2/n3^n4/n5"},
      {n1 - n2 * n3 + n4 + n5, "n1-n2*n3+n4+n5"},
      {n1 - n2 * n3 + n4 - n5, "n1-n2*n3+n4-n5"},
      {n1 - n2 * n3 + n4 * n5, "n1-n2*n3+n4*n5"},
      {n1 - n2 * n3 + pow(n4, n5), "n1-n2*n3+n4^n5"},
      {n1 - n2 * n3 + n4 / n5, "n1-n2*n3+n4/n5"},
      {n1 - n2 * n3 - n4 + n5, "n1-n2*n3-n4+n5"},
      {n1 - n2 * n3 - n4 - n5, "n1-n2*n3-n4-n5"},
      {n1 - n2 * n3 - n4 * n5, "n1-n2*n3-n4*n5"},
      {n1 - n2 * n3 - pow(n4, n5), "n1-n2*n3-n4^n5"},
      {n1 - n2 * n3 - n4 / n5, "n1-n2*n3-n4/n5"},
      {n1 - n2 * n3 * n4 + n5, "n1-n2*n3*n4+n5"},
      {n1 - n2 * n3 * n4 - n5, "n1-n2*n3*n4-n5"},
      {n1 - n2 * n3 * n4 * n5, "n1-n2*n3*n4*n5"},
      {n1 - n2 * n3 * pow(n4, n5), "n1-n2*n3*n4^n5"},
      {n1 - n2 * n3 * n4 / n5, "n1-n2*n3*n4/n5"},
      {n1 - n2 * pow(n3, n4) + n5, "n1-n2*n3^n4+n5"},
      {n1 - n2 * pow(n3, n4) - n5, "n1-n2*n3^n4-n5"},
      {n1 - n2 * pow(n3, n4) * n5, "n1-n2*n3^n4*n5"},
      {n1 - n2 * pow(n3, pow(n4, n5)), "n1-n2*n3^n4^n5"},
      {n1 - n2 * pow(n3, n4) / n5, "n1-n2*n3^n4/n5"},
      {n1 - n2 * n3 / n4 + n5, "n1-n2*n3/n4+n5"},
      {n1 - n2 * n3 / n4 - n5, "n1-n2*n3/n4-n5"},
      {n1 - n2 * n3 / n4 * n5, "n1-n2*n3/n4*n5"},
      {n1 - n2 * n3 / pow(n4, n5), "n1-n2*n3/n4^n5"},
      {n1 - n2 * n3 / n4 / n5, "n1-n2*n3/n4/n5"},
      {n1 - pow(n2, n3) + n4 + n5, "n1-n2^n3+n4+n5"},
      {n1 - pow(n2, n3) + n4 - n5, "n1-n2^n3+n4-n5"},
      {n1 - pow(n2, n3) + n4 * n5, "n1-n2^n3+n4*n5"},
      {n1 - pow(n2, n3) + pow(n4, n5), "n1-n2^n3+n4^n5"},
      {n1 - pow(n2, n3) + n4 / n5, "n1-n2^n3+n4/n5"},
      {n1 - pow(n2, n3) - n4 + n5, "n1-n2^n3-n4+n5"},
      {n1 - pow(n2, n3) - n4 - n5, "n1-n2^n3-n4-n5"},
      {n1 - pow(n2, n3) - n4 * n5, "n1-n2^n3-n4*n5"},
      {n1 - pow(n2, n3) - pow(n4, n5), "n1-n2^n3-n4^n5"},
      {n1 - pow(n2, n3) - n4 / n5, "n1-n2^n3-n4/n5"},
      {n1 - pow(n2, n3) * n4 + n5, "n1-n2^n3*n4+n5"},
      {n1 - pow(n2, n3) * n4 - n5, "n1-n2^n3*n4-n5"},
      {n1 - pow(n2, n3) * n4 * n5, "n1-n2^n3*n4*n5"},
      {n1 - pow(n2, n3) * pow(n4, n5), "n1-n2^n3*n4^n5"},
      {n1 - pow(n2, n3) * n4 / n5, "n1-n2^n3*n4/n5"},
      {n1 - pow(n2, pow(n3, n4)) + n5, "n1-n2^n3^n4+n5"},
      {n1 - pow(n2, pow(n3, n4)) - n5, "n1-n2^n3^n4-n5"},
      {n1 - pow(n2, pow(n3, n4)) * n5, "n1-n2^n3^n4*n5"},
      {n1 - pow(n2, pow(n3, pow(n4, n5))),
       "n1-n2^n3^n4^n5"},
      {n1 - pow(n2, pow(n3, n4)) / n5, "n1-n2^n3^n4/n5"},
      {n1 - n2 / n3 + n4 + n5, "n1-n2/n3+n4+n5"},
      {n1 - n2 / n3 + n4 - n5, "n1-n2/n3+n4-n5"},
      {n1 - n2 / n3 + n4 * n5, "n1-n2/n3+n4*n5"},
      {n1 - n2 / n3 + pow(n4, n5), "n1-n2/n3+n4^n5"},
      {n1 - n2 / n3 + n4 / n5, "n1-n2/n3+n4/n5"},
      {n1 - n2 / n3 - n4 + n5, "n1-n2/n3-n4+n5"},
      {n1 - n2 / n3 - n4 - n5, "n1-n2/n3-n4-n5"},
      {n1 - n2 / n3 - n4 * n5, "n1-n2/n3-n4*n5"},
      {n1 - n2 / n3 - pow(n4, n5), "n1-n2/n3-n4^n5"},
      {n1 - n2 / n3 - n4 / n5, "n1-n2/n3-n4/n5"},
      {n1 - n2 / n3 * n4 + n5, "n1-n2/n3*n4+n5"},
      {n1 - n2 / n3 * n4 - n5, "n1-n2/n3*n4-n5"},
      {n1 - n2 / n3 * n4 * n5, "n1-n2/n3*n4*n5"},
      {n1 - n2 / n3 * pow(n4, n5), "n1-n2/n3*n4^n5"},
      {n1 - n2 / n3 * n4 / n5, "n1-n2/n3*n4/n5"},
      {n1 - n2 / pow(n3, n4) + n5, "n1-n2/n3^n4+n5"},
      {n1 - n2 / pow(n3, n4) - n5, "n1-n2/n3^n4-n5"},
      {n1 - n2 / pow(n3, n4) * n5, "n1-n2/n3^n4*n5"},
      {n1 - n2 / pow(n3, pow(n4, n5)), "n1-n2/n3^n4^n5"},
      {n1 - n2 / pow(n3, n4) / n5, "n1-n2/n3^n4/n5"},
      {n1 - n2 / n3 / n4 + n5, "n1-n2/n3/n4+n5"},
      {n1 - n2 / n3 / n4 - n5, "n1-n2/n3/n4-n5"},
      {n1 - n2 / n3 / n4 * n5, "n1-n2/n3/n4*n5"},
      {n1 - n2 / n3 / pow(n4, n5), "n1-n2/n3/n4^n5"},
      {n1 - n2 / n3 / n4 / n5, "n1-n2/n3/n4/n5"},
      {n1 * n2 + n3 + n4 + n5, "n1*n2+n3+n4+n5"},
      {n1 * n2 + n3 + n4 - n5, "n1*n2+n3+n4-n5"},
      {n1 * n2 + n3 + n4 * n5, "n1*n2+n3+n4*n5"},
      {n1 * n2 + n3 + pow(n4, n5), "n1*n2+n3+n4^n5"},
      {n1 * n2 + n3 + n4 / n5, "n1*n2+n3+n4/n5"},
      {n1 * n2 + n3 - n4 + n5, "n1*n2+n3-n4+n5"},
      {n1 * n2 + n3 - n4 - n5, "n1*n2+n3-n4-n5"},
      {n1 * n2 + n3 - n4 * n5, "n1*n2+n3-n4*n5"},
      {n1 * n2 + n3 - pow(n4, n5), "n1*n2+n3-n4^n5"},
      {n1 * n2 + n3 - n4 / n5, "n1*n2+n3-n4/n5"},
      {n1 * n2 + n3 * n4 + n5, "n1*n2+n3*n4+n5"},
      {n1 * n2 + n3 * n4 - n5, "n1*n2+n3*n4-n5"},
      {n1 * n2 + n3 * n4 * n5, "n1*n2+n3*n4*n5"},
      {n1 * n2 + n3 * pow(n4, n5), "n1*n2+n3*n4^n5"},
      {n1 * n2 + n3 * n4 / n5, "n1*n2+n3*n4/n5"},
      {n1 * n2 + pow(n3, n4) + n5, "n1*n2+n3^n4+n5"},
      {n1 * n2 + pow(n3, n4) - n5, "n1*n2+n3^n4-n5"},
      {n1 * n2 + pow(n3, n4) * n5, "n1*n2+n3^n4*n5"},
      {n1 * n2 + pow(n3, pow(n4, n5)), "n1*n2+n3^n4^n5"},
      {n1 * n2 + pow(n3, n4) / n5, "n1*n2+n3^n4/n5"},
      {n1 * n2 + n3 / n4 + n5, "n1*n2+n3/n4+n5"},
      {n1 * n2 + n3 / n4 - n5, "n1*n2+n3/n4-n5"},
      {n1 * n2 + n3 / n4 * n5, "n1*n2+n3/n4*n5"},
      {n1 * n2 + n3 / pow(n4, n5), "n1*n2+n3/n4^n5"},
      {n1 * n2 + n3 / n4 / n5, "n1*n2+n3/n4/n5"},
      {n1 * n2 - n3 + n4 + n5, "n1*n2-n3+n4+n5"},
      {n1 * n2 - n3 + n4 - n5, "n1*n2-n3+n4-n5"},
      {n1 * n2 - n3 + n4 * n5, "n1*n2-n3+n4*n5"},
      {n1 * n2 - n3 + pow(n4, n5), "n1*n2-n3+n4^n5"},
      {n1 * n2 - n3 + n4 / n5, "n1*n2-n3+n4/n5"},
      {n1 * n2 - n3 - n4 + n5, "n1*n2-n3-n4+n5"},
      {n1 * n2 - n3 - n4 - n5, "n1*n2-n3-n4-n5"},
      {n1 * n2 - n3 - n4 * n5, "n1*n2-n3-n4*n5"},
      {n1 * n2 - n3 - pow(n4, n5), "n1*n2-n3-n4^n5"},
      {n1 * n2 - n3 - n4 / n5, "n1*n2-n3-n4/n5"},
      {n1 * n2 - n3 * n4 + n5, "n1*n2-n3*n4+n5"},
      {n1 * n2 - n3 * n4 - n5, "n1*n2-n3*n4-n5"},
      {n1 * n2 - n3 * n4 * n5, "n1*n2-n3*n4*n5"},
      {n1 * n2 - n3 * pow(n4, n5), "n1*n2-n3*n4^n5"},
      {n1 * n2 - n3 * n4 / n5, "n1*n2-n3*n4/n5"},
      {n1 * n2 - pow(n3, n4) + n5, "n1*n2-n3^n4+n5"},
      {n1 * n2 - pow(n3, n4) - n5, "n1*n2-n3^n4-n5"},
      {n1 * n2 - pow(n3, n4) * n5, "n1*n2-n3^n4*n5"},
      {n1 * n2 - pow(n3, pow(n4, n5)), "n1*n2-n3^n4^n5"},
      {n1 * n2 - pow(n3, n4) / n5, "n1*n2-n3^n4/n5"},
      {n1 * n2 - n3 / n4 + n5, "n1*n2-n3/n4+n5"},
      {n1 * n2 - n3 / n4 - n5, "n1*n2-n3/n4-n5"},
      {n1 * n2 - n3 / n4 * n5, "n1*n2-n3/n4*n5"},
      {n1 * n2 - n3 / pow(n4, n5), "n1*n2-n3/n4^n5"},
      {n1 * n2 - n3 / n4 / n5, "n1*n2-n3/n4/n5"},
      {n1 * pow(n2, n3) + n4 + n5, "n1*n2^n3+n4+n5"},
      {n1 * pow(n2, n3) + n4 - n5, "n1*n2^n3+n4-n5"},
      {n1 * pow(n2, n3) + n4 * n5, "n1*n2^n3+n4*n5"},
      {n1 * pow(n2, n3) + pow(n4, n5), "n1*n2^n3+n4^n5"},
      {n1 * pow(n2, n3) + n4 / n5, "n1*n2^n3+n4/n5"},
      {n1 * pow(n2, n3) - n4 + n5, "n1*n2^n3-n4+n5"},
      {n1 * pow(n2, n3) - n4 - n5, "n1*n2^n3-n4-n5"},
      {n1 * pow(n2, n3) - n4 * n5, "n1*n2^n3-n4*n5"},
      {n1 * pow(n2, n3) - pow(n4, n5), "n1*n2^n3-n4^n5"},
      {n1 * pow(n2, n3) - n4 / n5, "n1*n2^n3-n4/n5"},
      {n1 * pow(n2, n3) * n4 + n5, "n1*n2^n3*n4+n5"},
      {n1 * pow(n2, n3) * n4 - n5, "n1*n2^n3*n4-n5"},
      {n1 * pow(n2, n3) * n4 * n5, "n1*n2^n3*n4*n5"},
      {n1 * pow(n2, n3) * pow(n4, n5), "n1*n2^n3*n4^n5"},
      {n1 * pow(n2, n3) * n4 / n5, "n1*n2^n3*n4/n5"},
      {n1 * pow(n2, pow(n3, n4)) + n5, "n1*n2^n3^n4+n5"},
      {n1 * pow(n2, pow(n3, n4)) - n5, "n1*n2^n3^n4-n5"},
      {n1 * pow(n2, pow(n3, n4)) * n5, "n1*n2^n3^n4*n5"},
      {n1 * pow(n2, pow(n3, pow(n4, n5))),
       "n1*n2^n3^n4^n5"},
      {n1 * pow(n2, pow(n3, n4)) / n5, "n1*n2^n3^n4/n5"},
      {n1 * pow(n2, n3) / n4 + n5, "n1*n2^n3/n4+n5"},
      {n1 * pow(n2, n3) / n4 - n5, "n1*n2^n3/n4-n5"},
      {n1 * pow(n2, n3) / n4 * n5, "n1*n2^n3/n4*n5"},
      {n1 * pow(n2, n3) / pow(n4, n5), "n1*n2^n3/n4^n5"},
      {n1 * pow(n2, n3) / n4 / n5, "n1*n2^n3/n4/n5"},
      {n1 * n2 / n3 + n4 + n5, "n1*n2/n3+n4+n5"},
      {n1 * n2 / n3 + n4 - n5, "n1*n2/n3+n4-n5"},
      {n1 * n2 / n3 + n4 * n5, "n1*n2/n3+n4*n5"},
      {n1 * n2 / n3 + pow(n4, n5), "n1*n2/n3+n4^n5"},
      {n1 * n2 / n3 + n4 / n5, "n1*n2/n3+n4/n5"},
      {n1 * n2 / n3 - n4 + n5, "n1*n2/n3-n4+n5"},
      {n1 * n2 / n3 - n4 - n5, "n1*n2/n3-n4-n5"},
      {n1 * n2 / n3 - n4 * n5, "n1*n2/n3-n4*n5"},
      {n1 * n2 / n3 - pow(n4, n5), "n1*n2/n3-n4^n5"},
      {n1 * n2 / n3 - n4 / n5, "n1*n2/n3-n4/n5"},
      {n1 * n2 / n3 * n4 + n5, "n1*n2/n3*n4+n5"},
      {n1 * n2 / n3 * n4 - n5, "n1*n2/n3*n4-n5"},
      {n1 * n2 / n3 * n4 * n5, "n1*n2/n3*n4*n5"},
      {n1 * n2 / n3 * pow(n4, n5), "n1*n2/n3*n4^n5"},
      {n1 * n2 / n3 * n4 / n5, "n1*n2/n3*n4/n5"},
      {n1 * n2 / pow(n3, n4) + n5, "n1*n2/n3^n4+n5"},
      {n1 * n2 / pow(n3, n4) - n5, "n1*n2/n3^n4-n5"},
      {n1 * n2 / pow(n3, n4) * n5, "n1*n2/n3^n4*n5"},
      {n1 * n2 / pow(n3, pow(n4, n5)), "n1*n2/n3^n4^n5"},
      {n1 * n2 / pow(n3, n4) / n5, "n1*n2/n3^n4/n5"},
      {n1 * n2 / n3 / n4 + n5, "n1*n2/n3/n4+n5"},
      {n1 * n2 / n3 / n4 - n5, "n1*n2/n3/n4-n5"},
      {n1 * n2 / n3 / n4 * n5, "n1*n2/n3/n4*n5"},
      {n1 * n2 / n3 / pow(n4, n5), "n1*n2/n3/n4^n5"},
      {n1 * n2 / n3 / n4 / n5, "n1*n2/n3/n4/n5"},
      {pow(n1, n2) + n3 + n4 + n5, "n1^n2+n3+n4+n5"},
      {pow(n1, n2) + n3 + n4 - n5, "n1^n2+n3+n4-n5"},
      {pow(n1, n2) + n3 + n4 * n5, "n1^n2+n3+n4*n5"},
      {pow(n1, n2) + n3 + pow(n4, n5), "n1^n2+n3+n4^n5"},
      {pow(n1, n2) + n3 + n4 / n5, "n1^n2+n3+n4/n5"},
      {pow(n1, n2) + n3 - n4 + n5, "n1^n2+n3-n4+n5"},
      {pow(n1, n2) + n3 - n4 - n5, "n1^n2+n3-n4-n5"},
      {pow(n1, n2) + n3 - n4 * n5, "n1^n2+n3-n4*n5"},
      {pow(n1, n2) + n3 - pow(n4, n5), "n1^n2+n3-n4^n5"},
      {pow(n1, n2) + n3 - n4 / n5, "n1^n2+n3-n4/n5"},
      {pow(n1, n2) + n3 * n4 + n5, "n1^n2+n3*n4+n5"},
      {pow(n1, n2) + n3 * n4 - n5, "n1^n2+n3*n4-n5"},
      {pow(n1, n2) + n3 * n4 * n5, "n1^n2+n3*n4*n5"},
      {pow(n1, n2) + n3 * pow(n4, n5), "n1^n2+n3*n4^n5"},
      {pow(n1, n2) + n3 * n4 / n5, "n1^n2+n3*n4/n5"},
      {pow(n1, n2) + pow(n3, n4) + n5, "n1^n2+n3^n4+n5"},
      {pow(n1, n2) + pow(n3, n4) - n5, "n1^n2+n3^n4-n5"},
      {pow(n1, n2) + pow(n3, n4) * n5, "n1^n2+n3^n4*n5"},
      {pow(n1, n2) + pow(n3, pow(n4, n5)),
       "n1^n2+n3^n4^n5"},
      {pow(n1, n2) + pow(n3, n4) / n5, "n1^n2+n3^n4/n5"},
      {pow(n1, n2) + n3 / n4 + n5, "n1^n2+n3/n4+n5"},
      {pow(n1, n2) + n3 / n4 - n5, "n1^n2+n3/n4-n5"},
      {pow(n1, n2) + n3 / n4 * n5, "n1^n2+n3/n4*n5"},
      {pow(n1, n2) + n3 / pow(n4, n5), "n1^n2+n3/n4^n5"},
      {pow(n1, n2) + n3 / n4 / n5, "n1^n2+n3/n4/n5"},
      {pow(n1, n2) - n3 + n4 + n5, "n1^n2-n3+n4+n5"},
      {pow(n1, n2) - n3 + n4 - n5, "n1^n2-n3+n4-n5"},
      {pow(n1, n2) - n3 + n4 * n5, "n1^n2-n3+n4*n5"},
      {pow(n1, n2) - n3 + pow(n4, n5), "n1^n2-n3+n4^n5"},
      {pow(n1, n2) - n3 + n4 / n5, "n1^n2-n3+n4/n5"},
      {pow(n1, n2) - n3 - n4 + n5, "n1^n2-n3-n4+n5"},
      {pow(n1, n2) - n3 - n4 - n5, "n1^n2-n3-n4-n5"},
      {pow(n1, n2) - n3 - n4 * n5, "n1^n2-n3-n4*n5"},
      {pow(n1, n2) - n3 - pow(n4, n5), "n1^n2-n3-n4^n5"},
      {pow(n1, n2) - n3 - n4 / n5, "n1^n2-n3-n4/n5"},
      {pow(n1, n2) - n3 * n4 + n5, "n1^n2-n3*n4+n5"},
      {pow(n1, n2) - n3 * n4 - n5, "n1^n2-n3*n4-n5"},
      {pow(n1, n2) - n3 * n4 * n5, "n1^n2-n3*n4*n5"},
      {pow(n1, n2) - n3 * pow(n4, n5), "n1^n2-n3*n4^n5"},
      {pow(n1, n2) - n3 * n4 / n5, "n1^n2-n3*n4/n5"},
      {pow(n1, n2) - pow(n3, n4) + n5, "n1^n2-n3^n4+n5"},
      {pow(n1, n2) - pow(n3, n4) - n5, "n1^n2-n3^n4-n5"},
      {pow(n1, n2) - pow(n3, n4) * n5, "n1^n2-n3^n4*n5"},
      {pow(n1, n2) - pow(n3, pow(n4, n5)),
       "n1^n2-n3^n4^n5"},
      {pow(n1, n2) - pow(n3, n4) / n5, "n1^n2-n3^n4/n5"},
      {pow(n1, n2) - n3 / n4 + n5, "n1^n2-n3/n4+n5"},
      {pow(n1, n2) - n3 / n4 - n5, "n1^n2-n3/n4-n5"},
      {pow(n1, n2) - n3 / n4 * n5, "n1^n2-n3/n4*n5"},
      {pow(n1, n2) - n3 / pow(n4, n5), "n1^n2-n3/n4^n5"},
      {pow(n1, n2) - n3 / n4 / n5, "n1^n2-n3/n4/n5"},
      {pow(n1, n2) * n3 + n4 + n5, "n1^n2*n3+n4+n5"},
      {pow(n1, n2) * n3 + n4 - n5, "n1^n2*n3+n4-n5"},
      {pow(n1, n2) * n3 + n4 * n5, "n1^n2*n3+n4*n5"},
      {pow(n1, n2) * n3 + pow(n4, n5), "n1^n2*n3+n4^n5"},
      {pow(n1, n2) * n3 + n4 / n5, "n1^n2*n3+n4/n5"},
      {pow(n1, n2) * n3 - n4 + n5, "n1^n2*n3-n4+n5"},
      {pow(n1, n2) * n3 - n4 - n5, "n1^n2*n3-n4-n5"},
      {pow(n1, n2) * n3 - n4 * n5, "n1^n2*n3-n4*n5"},
      {pow(n1, n2) * n3 - pow(n4, n5), "n1^n2*n3-n4^n5"},
      {pow(n1, n2) * n3 - n4 / n5, "n1^n2*n3-n4/n5"},
      {pow(n1, n2) * n3 * n4 + n5, "n1^n2*n3*n4+n5"},
      {pow(n1, n2) * n3 * n4 - n5, "n1^n2*n3*n4-n5"},
      {pow(n1, n2) * n3 * n4 * n5, "n1^n2*n3*n4*n5"},
      {pow(n1, n2) * n3 * pow(n4, n5), "n1^n2*n3*n4^n5"},
      {pow(n1, n2) * n3 * n4 / n5, "n1^n2*n3*n4/n5"},
      {pow(n1, n2) * pow(n3, n4) + n5, "n1^n2*n3^n4+n5"},
      {pow(n1, n2) * pow(n3, n4) - n5, "n1^n2*n3^n4-n5"},
      {pow(n1, n2) * pow(n3, n4) * n5, "n1^n2*n3^n4*n5"},
      {pow(n1, n2) * pow(n3, pow(n4, n5)),
       "n1^n2*n3^n4^n5"},
      {pow(n1, n2) * pow(n3, n4) / n5, "n1^n2*n3^n4/n5"},
      {pow(n1, n2) * n3 / n4 + n5, "n1^n2*n3/n4+n5"},
      {pow(n1, n2) * n3 / n4 - n5, "n1^n2*n3/n4-n5"},
      {pow(n1, n2) * n3 / n4 * n5, "n1^n2*n3/n4*n5"},
      {pow(n1, n2) * n3 / pow(n4, n5), "n1^n2*n3/n4^n5"},
      {pow(n1, n2) * n3 / n4 / n5, "n1^n2*n3/n4/n5"},
      {pow(n1, n2) / n3 + n4 + n5, "n1^n2/n3+n4+n5"},
      {pow(n1, n2) / n3 + n4 - n5, "n1^n2/n3+n4-n5"},
      {pow(n1, n2) / n3 + n4 * n5, "n1^n2/n3+n4*n5"},
      {pow(n1, n2) / n3 + pow(n4, n5), "n1^n2/n3+n4^n5"},
      {pow(n1, n2) / n3 + n4 / n5, "n1^n2/n3+n4/n5"},
      {pow(n1, n2) / n3 - n4 + n5, "n1^n2/n3-n4+n5"},
      {pow(n1, n2) / n3 - n4 - n5, "n1^n2/n3-n4-n5"},
      {pow(n1, n2) / n3 - n4 * n5, "n1^n2/n3-n4*n5"},
      {pow(n1, n2) / n3 - pow(n4, n5), "n1^n2/n3-n4^n5"},
      {pow(n1, n2) / n3 - n4 / n5, "n1^n2/n3-n4/n5"},
      {pow(n1, n2) / n3 * n4 + n5, "n1^n2/n3*n4+n5"},
      {pow(n1, n2) / n3 * n4 - n5, "n1^n2/n3*n4-n5"},
      {pow(n1, n2) / n3 * n4 * n5, "n1^n2/n3*n4*n5"},
      {pow(n1, n2) / n3 * pow(n4, n5), "n1^n2/n3*n4^n5"},
      {pow(n1, n2) / n3 * n4 / n5, "n1^n2/n3*n4/n5"},
      {pow(n1, n2) / pow(n3, n4) + n5, "n1^n2/n3^n4+n5"},
      {pow(n1, n2) / pow(n3, n4) - n5, "n1^n2/n3^n4-n5"},
      {pow(n1, n2) / pow(n3, n4) * n5, "n1^n2/n3^n4*n5"},
      {pow(n1, n2) / pow(n3, pow(n4, n5)),
       "n1^n2/n3^n4^n5"},
      {pow(n1, n2) / pow(n3, n4) / n5, "n1^n2/n3^n4/n5"},
      {pow(n1, n2) / n3 / n4 + n5, "n1^n2/n3/n4+n5"},
      {pow(n1, n2) / n3 / n4 - n5, "n1^n2/n3/n4-n5"},
      {pow(n1, n2) / n3 / n4 * n5, "n1^n2/n3/n4*n5"},
      {pow(n1, n2) / n3 / pow(n4, n5), "n1^n2/n3/n4^n5"},
      {pow(n1, n2) / n3 / n4 / n5, "n1^n2/n3/n4/n5"},
      {n1 / n2 + n3 + n4 + n5, "n1/n2+n3+n4+n5"},
      {n1 / n2 + n3 + n4 - n5, "n1/n2+n3+n4-n5"},
      {n1 / n2 + n3 + n4 * n5, "n1/n2+n3+n4*n5"},
      {n1 / n2 + n3 + pow(n4, n5), "n1/n2+n3+n4^n5"},
      {n1 / n2 + n3 + n4 / n5, "n1/n2+n3+n4/n5"},
      {n1 / n2 + n3 - n4 + n5, "n1/n2+n3-n4+n5"},
      {n1 / n2 + n3 - n4 - n5, "n1/n2+n3-n4-n5"},
      {n1 / n2 + n3 - n4 * n5, "n1/n2+n3-n4*n5"},
      {n1 / n2 + n3 - pow(n4, n5), "n1/n2+n3-n4^n5"},
      {n1 / n2 + n3 - n4 / n5, "n1/n2+n3-n4/n5"},
      {n1 / n2 + n3 * n4 + n5, "n1/n2+n3*n4+n5"},
      {n1 / n2 + n3 * n4 - n5, "n1/n2+n3*n4-n5"},
      {n1 / n2 + n3 * n4 * n5, "n1/n2+n3*n4*n5"},
      {n1 / n2 + n3 * pow(n4, n5), "n1/n2+n3*n4^n5"},
      {n1 / n2 + n3 * n4 / n5, "n1/n2+n3*n4/n5"},
      {n1 / n2 + pow(n3, n4) + n5, "n1/n2+n3^n4+n5"},
      {n1 / n2 + pow(n3, n4) - n5, "n1/n2+n3^n4-n5"},
      {n1 / n2 + pow(n3, n4) * n5, "n1/n2+n3^n4*n5"},
      {n1 / n2 + pow(n3, pow(n4, n5)), "n1/n2+n3^n4^n5"},
      {n1 / n2 + pow(n3, n4) / n5, "n1/n2+n3^n4/n5"},
      {n1 / n2 + n3 / n4 + n5, "n1/n2+n3/n4+n5"},
      {n1 / n2 + n3 / n4 - n5, "n1/n2+n3/n4-n5"},
      {n1 / n2 + n3 / n4 * n5, "n1/n2+n3/n4*n5"},
      {n1 / n2 + n3 / pow(n4, n5), "n1/n2+n3/n4^n5"},
      {n1 / n2 + n3 / n4 / n5, "n1/n2+n3/n4/n5"},
      {n1 / n2 - n3 + n4 + n5, "n1/n2-n3+n4+n5"},
      {n1 / n2 - n3 + n4 - n5, "n1/n2-n3+n4-n5"},
      {n1 / n2 - n3 + n4 * n5, "n1/n2-n3+n4*n5"},
      {n1 / n2 - n3 + pow(n4, n5), "n1/n2-n3+n4^n5"},
      {n1 / n2 - n3 + n4 / n5, "n1/n2-n3+n4/n5"},
      {n1 / n2 - n3 - n4 + n5, "n1/n2-n3-n4+n5"},
      {n1 / n2 - n3 - n4 - n5, "n1/n2-n3-n4-n5"},
      {n1 / n2 - n3 - n4 * n5, "n1/n2-n3-n4*n5"},
      {n1 / n2 - n3 - pow(n4, n5), "n1/n2-n3-n4^n5"},
      {n1 / n2 - n3 - n4 / n5, "n1/n2-n3-n4/n5"},
      {n1 / n2 - n3 * n4 + n5, "n1/n2-n3*n4+n5"},
      {n1 / n2 - n3 * n4 - n5, "n1/n2-n3*n4-n5"},
      {n1 / n2 - n3 * n4 * n5, "n1/n2-n3*n4*n5"},
      {n1 / n2 - n3 * pow(n4, n5), "n1/n2-n3*n4^n5"},
      {n1 / n2 - n3 * n4 / n5, "n1/n2-n3*n4/n5"},
      {n1 / n2 - pow(n3, n4) + n5, "n1/n2-n3^n4+n5"},
      {n1 / n2 - pow(n3, n4) - n5, "n1/n2-n3^n4-n5"},
      {n1 / n2 - pow(n3, n4) * n5, "n1/n2-n3^n4*n5"},
      {n1 / n2 - pow(n3, pow(n4, n5)), "n1/n2-n3^n4^n5"},
      {n1 / n2 - pow(n3, n4) / n5, "n1/n2-n3^n4/n5"},
      {n1 / n2 - n3 / n4 + n5, "n1/n2-n3/n4+n5"},
      {n1 / n2 - n3 / n4 - n5, "n1/n2-n3/n4-n5"},
      {n1 / n2 - n3 / n4 * n5, "n1/n2-n3/n4*n5"},
      {n1 / n2 - n3 / pow(n4, n5), "n1/n2-n3/n4^n5"},
      {n1 / n2 - n3 / n4 / n5, "n1/n2-n3/n4/n5"},
      {n1 / n2 * n3 + n4 + n5, "n1/n2*n3+n4+n5"},
      {n1 / n2 * n3 + n4 - n5, "n1/n2*n3+n4-n5"},
      {n1 / n2 * n3 + n4 * n5, "n1/n2*n3+n4*n5"},
      {n1 / n2 * n3 + pow(n4, n5), "n1/n2*n3+n4^n5"},
      {n1 / n2 * n3 + n4 / n5, "n1/n2*n3+n4/n5"},
      {n1 / n2 * n3 - n4 + n5, "n1/n2*n3-n4+n5"},
      {n1 / n2 * n3 - n4 - n5, "n1/n2*n3-n4-n5"},
      {n1 / n2 * n3 - n4 * n5, "n1/n2*n3-n4*n5"},
      {n1 / n2 * n3 - pow(n4, n5), "n1/n2*n3-n4^n5"},
      {n1 / n2 * n3 - n4 / n5, "n1/n2*n3-n4/n5"},
      {n1 / n2 * n3 * n4 + n5, "n1/n2*n3*n4+n5"},
      {n1 / n2 * n3 * n4 - n5, "n1/n2*n3*n4-n5"},
      {n1 / n2 * n3 * n4 * n5, "n1/n2*n3*n4*n5"},
      {n1 / n2 * n3 * pow(n4, n5), "n1/n2*n3*n4^n5"},
      {n1 / n2 * n3 * n4 / n5, "n1/n2*n3*n4/n5"},
      {n1 / n2 * pow(n3, n4) + n5, "n1/n2*n3^n4+n5"},
      {n1 / n2 * pow(n3, n4) - n5, "n1/n2*n3^n4-n5"},
      {n1 / n2 * pow(n3, n4) * n5, "n1/n2*n3^n4*n5"},
      {n1 / n2 * pow(n3, pow(n4, n5)), "n1/n2*n3^n4^n5"},
      {n1 / n2 * pow(n3, n4) / n5, "n1/n2*n3^n4/n5"},
      {n1 / n2 * n3 / n4 + n5, "n1/n2*n3/n4+n5"},
      {n1 / n2 * n3 / n4 - n5, "n1/n2*n3/n4-n5"},
      {n1 / n2 * n3 / n4 * n5, "n1/n2*n3/n4*n5"},
      {n1 / n2 * n3 / pow(n4, n5), "n1/n2*n3/n4^n5"},
      {n1 / n2 * n3 / n4 / n5, "n1/n2*n3/n4/n5"},
      {n1 / pow(n2, n3) + n4 + n5, "n1/n2^n3+n4+n5"},
      {n1 / pow(n2, n3) + n4 - n5, "n1/n2^n3+n4-n5"},
      {n1 / pow(n2, n3) + n4 * n5, "n1/n2^n3+n4*n5"},
      {n1 / pow(n2, n3) + pow(n4, n5), "n1/n2^n3+n4^n5"},
      {n1 / pow(n2, n3) + n4 / n5, "n1/n2^n3+n4/n5"},
      {n1 / pow(n2, n3) - n4 + n5, "n1/n2^n3-n4+n5"},
      {n1 / pow(n2, n3) - n4 - n5, "n1/n2^n3-n4-n5"},
      {n1 / pow(n2, n3) - n4 * n5, "n1/n2^n3-n4*n5"},
      {n1 / pow(n2, n3) - pow(n4, n5), "n1/n2^n3-n4^n5"},
      {n1 / pow(n2, n3) - n4 / n5, "n1/n2^n3-n4/n5"},
      {n1 / pow(n2, n3) * n4 + n5, "n1/n2^n3*n4+n5"},
      {n1 / pow(n2, n3) * n4 - n5, "n1/n2^n3*n4-n5"},
      {n1 / pow(n2, n3) * n4 * n5, "n1/n2^n3*n4*n5"},
      {n1 / pow(n2, n3) * pow(n4, n5), "n1/n2^n3*n4^n5"},
      {n1 / pow(n2, n3) * n4 / n5, "n1/n2^n3*n4/n5"},
      {n1 / pow(n2, pow(n3, n4)) + n5, "n1/n2^n3^n4+n5"},
      {n1 / pow(n2, pow(n3, n4)) - n5, "n1/n2^n3^n4-n5"},
      {n1 / pow(n2, pow(n3, n4)) * n5, "n1/n2^n3^n4*n5"},
      {n1 / pow(n2, pow(n3, pow(n4, n5))),
       "n1/n2^n3^n4^n5"},
      {n1 / pow(n2, pow(n3, n4)) / n5, "n1/n2^n3^n4/n5"},
      {n1 / pow(n2, n3) / n4 + n5, "n1/n2^n3/n4+n5"},
      {n1 / pow(n2, n3) / n4 - n5, "n1/n2^n3/n4-n5"},
      {n1 / pow(n2, n3) / n4 * n5, "n1/n2^n3/n4*n5"},
      {n1 / pow(n2, n3) / pow(n4, n5), "n1/n2^n3/n4^n5"},

      {(pow(n1, n2) + n3) * n4 - n5, "(n1^n2+n3)*n4-n5"},
      {(n1 * n2 + n3) * (n4 + n5), "(n1*n2+n3)*(n4+n5)"},
      {(n1+n2)*(n3+n4)*n5, "(n1+n2)*(n3+n4)*n5"}
      


  };

  vector<Answer> operations4num = {
      {n1 + n2 + n3 + n4, "n1+n2+n3+n4"},
      {n1 + n2 + n3 - n4, "n1+n2+n3-n4"},
      {n1 + n2 + n3 * n4, "n1+n2+n3*n4"},
      {n1 + n2 + pow(n3, n4), "n1+n2+n3^n4"},
      {n1 + n2 + n3 / n4, "n1+n2+n3/n4"},
      {n1 - n2 - n3 - n4, "n1-n2-n3-n4"},
      {n1 - n2 - n3 + n4, "n1-n2-n3+n4"},
      {n1 - n2 - n3 * n4, "n1-n2-n3*n4"},
      {n1 - n2 - pow(n3, n4), "n1-n2-n3^n4"},
      {n1 - n2 - n3 / n4, "n1-n2-n3/n4"},
      {n1 * n2 * n3 * n4, "n1*n2*n3*n4"},
      {n1 * n2 * n3 + n4, "n1*n2*n3+n4"},
      {n1 * n2 * n3 - n4, "n1*n2*n3-n4"},
      {n1 * n2 * pow(n3, n4), "n1*n2*n3^n4"},
      {n1 * n2 * n3 / n4, "n1*n2*n3/n4"},
      {pow(n1, pow(n2, pow(n3, n4))), "n1^n2^n3^n4"},
      {pow(n1, pow(n2, n3)) + n4, "n1^n2^n3+n4"},
      {pow(n1, pow(n2, n3)) - n4, "n1^n2^n3-n4"},
      {pow(n1, pow(n2, n3)) * n4, "n1^n2^n3*n4"},
      {pow(n1, pow(n2, n3)) / n4, "n1^n2^n3/n4"},
      {n1 + n2 - n3 * n4, "n1+n2-n3*n4"},
      {n1 + n2 - pow(n3, n4), "n1+n2-n3^n4"},
      {n1 + n2 - n3 / n4, "n1+n2-n3/n4"},
      {n1 + n2 * n3 + n4, "n1+n2*n3+n4"},
      {n1 + n2 * n3 - n4, "n1+n2*n3-n4"},
      {n1 + n2 * n3 * n4, "n1+n2*n3*n4"},
      {n1 + n2 * pow(n3, n4), "n1+n2*n3^n4"},
      {n1 + n2 * n3 / n4, "n1+n2*n3/n4"},
      {n1 + pow(n2, n3) + n4, "n1+n2^n3+n4"},
      {n1 + pow(n2, n3) - n4, "n1+n2^n3-n4"},
      {n1 + pow(n2, n3) * n4, "n1+n2^n3*n4"},
      {n1 + pow(n2, pow(n3, n4)), "n1+n2^n3^n4"},
      {n1 + pow(n2, n3) / n4, "n1+n2^n3/n4"},
      {n1 + n2 / n3 / n4, "n1+n2/n3/n4"},
      {n1 + n2 / n3 + n4, "n1+n2/n3+n4"},
      {n1 + n2 / n3 - n4, "n1+n2/n3-n4"},
      {n1 + n2 / n3 * n4, "n1+n2/n3*n4"},
      {n1 + n2 / pow(n3, n4), "n1+n2/n3^n4"},
      {n1 - n2 * n3 + n4, "n1-n2*n3+n4"},
      {n1 - n2 * n3 - n4, "n1-n2*n3-n4"},
      {n1 - n2 * n3 * n4, "n1-n2*n3*n4"},
      {n1 - n2 * pow(n3, n4), "n1-n2*n3^n4"},
      {n1 - n2 * n3 / n4, "n1-n2*n3/n4"},
      {n1 - pow(n2, n3) + n4, "n1-n2^n3+n4"},
      {n1 - pow(n2, n3) - n4, "n1-n2^n3-n4"},
      {n1 - pow(n2, n3) * n4, "n1-n2^n3*n4"},
      {n1 - pow(n2, pow(n3, n4)), "n1-n2^n3^n4"},
      {n1 - n2 * n3 / n4, "n1-n2*n3/n4"},
      {n1 - n2 / n3 + n4, "n1-n2/n3+n4"},
      {n1 - n2 / n3 - n4, "n1-n2/n3-n4"},
      {n1 - n2 / n3 * n4, "n1-n2/n3*n4"},
      {n1 - n2 / pow(n3, n4), "n1-n2/n3^n4"},
      {n1 - n2 / n3 / n4, "n1-n2/n3/n4"},
      {n1 * n2 + n3 + n4, "n1*n2+n3+n4"},
      {n1 * n2 + n3 - n4, "n1*n2+n3-n4"},
      {n1 * n2 + n3 * n4, "n1*n2+n3*n4"},
      {n1 * n2 + pow(n3, n4), "n1*n2+n3^n4"},
      {n1 * n2 + n3 / n4, "n1*n2+n3/n4"},
      {n1 * n2 - n3 + n4, "n1*n2-n3+n4"},
      {n1 * n2 - n3 - n4, "n1*n2-n3-n4"},
      {n1 * n2 - n3 * n4, "n1*n2-n3*n4"},
      {n1 * n2 - pow(n3, n4), "n1*n2-n3^n4"},
      {n1 * n2 - n3 / n4, "n1*n2-n3/n4"},
      {n1 * pow(n2, n3) + n4, "n1*n2^n3+n4"},
      {n1 * pow(n2, n3) - n4, "n1*n2^n3-n4"},
      {n1 * pow(n2, n3) * n4, "n1*n2^n3*n4"},
      {n1 * pow(n2, pow(n3, n4)), "n1*n2^n3^n4"},
      {n1 * pow(n2, n3) / n4, "n1*n2^n3/n4"},
      {n1 * n2 / n3 + n4, "n1*n2/n3+n4"},
      {n1 * n2 / n3 - n4, "n1*n2/n3-n4"},
      {n1 * n2 / n3 * n4, "n1*n2/n3*n4"},
      {n1 * n2 / pow(n3, n4), "n1*n2/n3^n4"},
      {n1 * n2 / n3 / n4, "n1*n2/n3/n4"},
      {pow(n1, n2) + n3 + n4, "n1^n2+n3+n4"},
      {pow(n1, n2) + n3 - n4, "n1^n2+n3-n4"},
      {pow(n1, n2) + n3 * n4, "n1^n2+n3*n4"},
      {pow(n1, n2) + pow(n3, n4), "n1^n2+n3^n4"},
      {pow(n1, n2) + n3 / n4, "n1^n2+n3/n4"},
      {pow(n1, n2) - n3 + n4, "n1^n2-n3+n4"},
      {pow(n1, n2) - n3 - n4, "n1^n2-n3-n4"},
      {pow(n1, n2) - n3 * n4, "n1^n2-n3*n4"},
      {pow(n1, n2) - pow(n3, n4), "n1^n2-n3^n4"},
      {pow(n1, n2) - n3 / n4, "n1^n2-n3/n4"},
      {pow(n1, n2) * n3 + n4, "n1^n2*n3+n4"},
      {pow(n1, n2) * n3 - n4, "n1^n2*n3-n4"},
      {pow(n1, n2) * n3 * n4, "n1^n2*n3*n4"},
      {pow(n1, n2) * pow(n3, n4), "n1^n2*n3^n4"},
      {pow(n1, n2) * n3 / n4, "n1^n2*n3/n4"},
      {pow(n1, n2) / n3 + n4, "n1^n2/n3+n4"},
      {pow(n1, n2) / n3 - n4, "n1^n2/n3-n4"},
      {pow(n1, n2) / n3 * n4, "n1^n2/n3*n4"},
      {pow(n1, n2) / pow(n3, n4), "n1^n2/n3^n4"},
      {pow(n1, n2) / n3 / n4, "n1^n2/n3/n4"},
      {n1 / n2 + n3 + n4, "n1/n2+n3+n4"},
      {n1 / n2 + n3 - n4, "n1/n2+n3-n4"},
      {n1 / n2 + n3 * n4, "n1/n2+n3*n4"},
      {n1 / n2 + pow(n3, n4), "n1/n2+n3^n4"},
      {n1 / n2 + n3 / n4, "n1/n2+n3/n4"},
      {n1 / n2 - n3 + n4, "n1/n2-n3+n4"},
      {n1 / n2 - n3 - n4, "n1/n2-n3-n4"},
      {n1 / n2 - n3 * n4, "n1/n2-n3*n4"},
      {n1 / n2 - pow(n3, n4), "n1/n2-n3^n4"},
      {n1 / n2 - n3 / n4, "n1/n2-n3/n4"},
      {n1 / n2 * n3 + n4, "n1/n2*n3+n4"},
      {n1 / n2 * n3 - n4, "n1/n2*n3-n4"},
      {n1 / n2 * n3 * n4, "n1/n2*n3*n4"},
      {n1 / n2 * pow(n3, n4), "n1/n2*n3^n4"},
      {n1 / n2 * n3 / n4, "n1/n2*n3/n4"},
      {n1 / pow(n2, n3) + n4, "n1/n2^n3+n4"},
      {n1 / pow(n2, n3) - n4, "n1/n2^n3-n4"},
      {n1 / pow(n2, n3) * n4, "n1/n2^n3*n4"},
      {n1 / pow(n2, pow(n3, n4)), "n1/n2^n3^n4"},
      {n1 / pow(n2, n3) / n4, "n1/n2^n3/n4"}};

  vector<Answer> operations3num = {
      {n1 + n2 + n3, "n1+n2+n3"},
      {n1 - n2 - n3, "n1-n2-n3"},
      {n1 * n2 * n3, "n1*n2*n3"},
      {pow(pow(n1, n2), n3), "n1^n2^n3"},
      {n1 / n2 / n3, "n1/n2/n3"},

      {n1 + n2 - n3, "n1+n2-n3"},
      {n1 + n2 * n3, "n1+n2*n3"},
      {n1 + pow(n2, n3), "n1+n2^n3"},
      {n1 + n2 / n3, "n1+n2/n3"},

      {n1 - n2 * n3, "n1-n2*n3"},
      {n1 - pow(n2, n3), "n1-n2^n3"},
      {n1 - n2 / n3, "n1-n2/n3"},

      {n1 * n2 + n3, "n1*n2+n3"},
      {n1 * n2 - n3, "n1*n2-n3"},
      {n1 * pow(n2, n3), "n1*n2^n3"},
      {n1 * n2 / n3, "n1*n2/n3"},

      {pow(n1, n2) + n3, "n1^n2+n3"},
      {pow(n1, n2) - n3, "n1^n2-n3"},
      {pow(n1, n2) * n3, "n1^n2*n3"},
      {pow(n1, n2) / n3, "n1^n2/n3"},

      {n1 / n2 + n3, "n1/n2+n3"},
      {n1 / n2 - n3, "n1/n2-n3"},
      {n1 / n2 * n3, "n1/n2*n3"},
      {pow(n1 / n2, n3), "n1/n2^n3"}};

  vector<Answer> operations2num = {{n1 + n2, "n1+n2"},
                                   {n1 - n2, "n1-n2"},
                                   {n1 * n2, "n1*n2"},
                                   {pow(n1, n2), "n1^n2"},
                                   {n1 / n2, "n1/n2"}};

  vector<Answer> operations1num = {{n1, "n1"}};

  vector<Answer> possibleAnswers;
  if (numCount == 1)
  {
    possibleAnswers = operations1num;
  }
  else if (numCount == 2)
  {
    possibleAnswers = operations2num;
  }
  else if (numCount == 3)
  {
    possibleAnswers = operations3num;
  }
  else if (numCount == 4)
  {
    possibleAnswers = operations4num;
  }
  else if (numCount == 5)
  {
    possibleAnswers = operations5num;
  }

  for (Answer operation : possibleAnswers)
  {
    if (operation.number < 1 || operation.number > 100 ||
        !(round(operation.number) == operation.number))
    {
      continue;
    }

    int intN1 = round(n1);
    int intN2 = round(n2);
    int intN3 = round(n3);
    int intN4 = round(n4);
    int intN5 = round(n5);

    string answer = operation.operands;
    answer.replace(answer.find("n1"), sizeof("n1") - 1, to_string(intN1));
    if (numCount > 1)
    {
      answer.replace(answer.find("n2"), sizeof("n2") - 1, to_string(intN2));
    }
    if (numCount > 2)
    {
      answer.replace(answer.find("n3"), sizeof("n3") - 1, to_string(intN3));
    }
    if (numCount > 3)
    {
      answer.replace(answer.find("n4"), sizeof("n4") - 1, to_string(intN4));
    }
    if (numCount > 4)
    {
      answer.replace(answer.find("n5"), sizeof("n5") - 1, to_string(intN5));
    }

    int answerIndex = round(operation.number) - 1;

    if (answers[answerIndex] == "")
    {
      answers[answerIndex] = answer;
    }
    if (answers[answerIndex].length() > answer.length())
    {
      answers[answerIndex] = answer;
    }
  }
}

// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n, vector<vector<int>> &permList)
{

  // if size becomes 1 then prints the obtained
  // permutation
  if (size == 1)
  {
    permList.push_back({a[0], a[1], a[2], a[3], a[4]});
    return;
  }

  for (int i = 0; i < size; i++)
  {
    heapPermutation(a, size - 1, n, permList);

    // if size is odd, swap 0th i.e (first) and
    // (size-1)th i.e (last) element
    if (size % 2 == 1)
      swap(a[0], a[size - 1]);

    // If size is even, swap ith and
    // (size-1)th i.e (last) element
    else
      swap(a[i], a[size - 1]);
  }
}

// Driver code
int main(int argc, char *argv[])
{
  if (argc < 5 || argc > 6)
  {
    return 1;
  }

  long x = strtol(argv[1], NULL, 10);
  int n1 = x;
  x = strtol(argv[2], NULL, 10);
  int n2 = x;
  x = strtol(argv[3], NULL, 10);
  int n3 = x;
  x = strtol(argv[4], NULL, 10);
  int n4 = x;
  x = strtol(argv[5], NULL, 10);
  int n5 = x;

  int ukeTall[5] = {n1, n2, n3, n4, n5};
  vector<int> vectorUkeTall = {ukeTall[0], ukeTall[1], ukeTall[2], ukeTall[3],
                               ukeTall[4]};
  string svar[100];

  vector<vector<int>> perm5;
  int n = sizeof ukeTall / sizeof ukeTall[0];
  heapPermutation(ukeTall, n, n, perm5);

  vector<vector<int>> perm4 = perm5;
  for (int i = 0; i < perm4.size(); i++)
  {
    perm4[i].pop_back();
  }
  perm4.erase(unique(perm4.begin(), perm4.end()), perm4.end());

  vector<vector<int>> perm3 = perm4;
  for (int i = 0; i < perm3.size(); i++)
  {
    perm3[i].pop_back();
  }
  perm3.erase(unique(perm3.begin(), perm3.end()), perm3.end());

  vector<vector<int>> perm2 = perm3;
  for (int i = 0; i < perm2.size(); i++)
  {
    perm2[i].pop_back();
  }
  perm2.erase(unique(perm2.begin(), perm2.end()), perm2.end());

  for (vector<int> numbers5 : perm5)
  {
    operations(numbers5, svar);
  }
  for (vector<int> numbers4 : perm4)
  {
    operations(numbers4, svar);
  }
  for (vector<int> numbers3 : perm3)
  {
    operations(numbers3, svar);
  }
  for (vector<int> numbers2 : perm2)
  {
    operations(numbers2, svar);
  }
  for (int numbers1 : vectorUkeTall)
  {
    vector<int> numbers1Vector = {numbers1};
    operations(numbers1Vector, svar);
  }

  for (int i = 0; i < 100; i++)
  {
    cout << svar[i] << "\n";
  }
  return 0;
}
