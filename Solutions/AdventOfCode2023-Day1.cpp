/*
Problem Statement

As they're making the final adjustments, they discover that their calibration document (your puzzle input) 
has been amended by a very young Elf who was apparently just excited to show off her art skills. 
Consequently, the Elves are having trouble reading the values on the document.


The newly-improved calibration document consists of lines of text;
each line originally contained a specific calibration value that the Elves now need to recover. 
On each line, the calibration value can be found by combining the first digit and the last digit (in that order) 
to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

In this example, the calibration values of these four lines are 12, 38, 15, and 77. 
Adding these together produces 142.

Consider your entire calibration document. 
What is the sum of all of the calibration values?

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <string_view>
#include <functional>

typedef std::unordered_map<int, std::string> uMapSTI;

int sumCalibrationValuesNumber()
{
    std::ifstream inputFile("AdventOfCode2023Day1.txt");

    int sum = 0;
    for (std::string line; getline(inputFile, line); )
    {
        std::vector<int> numbers;
        for (int i = 0; i < line.length(); i++)
        {            
            if (!std::isalpha(line[i]))
            {
                numbers.push_back(int(line[i])-48);
            }
        }

        int num1 = numbers[0];
        int num2 = numbers[numbers.size() - 1];
        sum += num1 * 10 + num2;        
    }
    return sum;
}

int sumCalibrationValuesWord() {
    std::ifstream inputFile("aocd1_test.txt");

    std::unordered_map<int, std::string> m1 = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10,"ten"}
    };

    std::unordered_map<std::string, int> m2 = {
        {"one",   1},
        {"two",   2},
        {"three", 3},
        {"four",  4},
        {"five",  5},
        {"six",   6},
        {"seven", 7},
        {"eight", 8},
        {"nine",  9},
        {"ten",   10}
    };

    std::vector<std::string> wordList = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    std::vector<std::string> numsFound{};
    std::vector<std::string> numsFoundPerLine{};
    int sum = 0;

    for (std::string line; getline(inputFile, line); )
    {                            
        for (const std::string word: wordList)
        {
            auto foundIt = std::ranges::search(
                    line.begin(), line.end(),
                    word.begin(), word.end()                    
                );

            if (!(foundIt.empty()))
            {
                numsFound.push_back(word);            
                numsFoundPerLine.push_back(word);            
            }

            for (const auto& w: numsFoundPerLine)
            {
                
            }

            
        }
        int num1 = m2[numsFound[0]] * 10;
        int num2 = m2[numsFound[numsFound.size() - 1]];
        sum += (num1 + num2);
        numsFoundPerLine.clear();
    }   
    return sum;
}


int main(int argc, char** argv)
{
    int sum1 = sumCalibrationValuesNumber();
    std::cout << "Sum Day 1.1: " << sum1 << std::endl;
    int sum2 = sumCalibrationValuesWord();
    std::cout << "Sum Day 1.2: " << sum2 << std::endl;
    return 0;
}


/**
 * @brief // find the first number
            for (int k = 0; i < v.size(); i++)
            {
                std::string::size_type n = line.find(m2[v[k]]);
                if (n != std::string::npos)
                {
                    int substrlen = v[k].length();
                    num1 = m2[line.substr(n, substrlen)];
                    continue;
                }                    
            }

            std::string revLine(line);
            std::reverse(revLine.begin(), revLine.end());

            for (int p = 0; i < v.size(); i++)
            {
                std::string::size_type n = revLine.find(m2[v[p]]);
                if (n != std::string::npos)
                {
                    int substrlen = v[p].length();
                    num2 = m2[revLine.substr(substrlen, n)];
                    continue;   
                }                    
            }
            sum += num1 *10 + num2;
 * 
 */
