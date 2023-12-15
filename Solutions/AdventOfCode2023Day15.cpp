#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <map>
#include <unordered_map>
#include <ranges>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>


class Solution
{
public:
  /*
   *HASH Algorithm
   * Letter = [a-z]
   * Letter in ASCII Code = N
   * N * 17 = ans
   * ans % 256 = Ans
   * sum 0..N of all letters thru algo = solution
   */

  void Split(std::string&, char, std::vector<std::string>& );
private:
};

void Solution::Split(std::string& str, char separator, std::vector<std::string> & oSplit)
{
  int startIndex = 0;
  int endIndex = 0;
  for (size_t i = 0; i < str.length(); i++)
    {
      if (str[i] == separator || i == str.length())
        {
          endIndex = i;
          std::string temp;
          temp.append(str, startIndex, endIndex - startIndex);
          oSplit.push_back(temp);
          startIndex = endIndex + 1;
        }
    }
}


int main()
{
  int curr = 0;

  std::string a = "rn=1";

  int valR = int(a[0]);
  int valN = int(a[1]);
  int valEq = int(a[2]);
  int val1 = int(a[3]);

  for (int i = 0; i < a.length(); i++)
  {
    std::cout << "|" << std::endl;
    int code = int(a[i]) + curr; std::cout << "Code: " << code << std::endl;
    int by17 = code * 17; std::cout << "By17: " << by17 << std::endl;
    int rem = by17 % 256; std::cout << "Rem: " << rem << std::endl;
    curr = rem; std::cout << "Current: " << curr << std::endl;
  }

  std::cout << "HASH -> " << curr << std::endl;

  return 0;
}
