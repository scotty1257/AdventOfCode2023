#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <iterator>
#include <ranges>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <cmath>

void matchRegex(const std::string& text, const std::regex& pattern, std::vector<int> & oVec)
{
    std::sregex_iterator it(text.begin(), text.end(), pattern);
    std::sregex_iterator it_end;
    
    for(; it != it_end; ++it)
    {
        const std::smatch& match = *it;
        oVec.push_back(std::stoi(match.str()));
    }
    
}
template <class T>
void printVec(const std::vector<T>& iV)
{
    for (const auto& unit: iV)
        std::cout << unit << "_";
    std::cout << std::endl;
}


int NumberOfWaysToWin()
{
    std::ifstream file;
    file.open("AdventOfCode2023Day6.txt");

    if(!(file.is_open())) return 0;
          
    std::string strTime;
    std::string strDistance;
    //while (file >> strTime >> strDistance) {}
    std::getline(file, strTime);
    std::getline(file, strDistance);
    
    std::vector<int> times;
    std::vector<int> distances;            

    matchRegex(strTime, std::regex("[0-9]+"), times);
    matchRegex(strDistance, std::regex("[0-9]+"), distances);                  
    printVec(times);
    printVec(distances);

    std::vector<std::vector<int>> maxDistance;

    for (int count = 0; count < 4; count++)
    {
        std::vector<int> numTimesWon;
        for (int i = 0; i < times[count]; i++)
        {
            // 7 seconds
            // Hold for 3
            // Go 7 - 4 * 


            uint64_t holdButtonTime = i;

            uint64_t distanceGone = (times[count] - holdButtonTime) * holdButtonTime;


            if (distanceGone > distances[count])
                numTimesWon.push_back(1);
        }
        maxDistance.push_back(numTimesWon);
    }

    int total = 1;
    for (int i = 0; i < maxDistance.size(); i++)
    {
        total *= maxDistance[i].size();
    }

    return total;
}
int NumberOfWaysToWinPart2()
{
    uint64_t time = 38947970;
    uint64_t distance = 241154910741091;

    int count = 0;
    for (int i = 0; i < time; i++)
    {
        uint64_t speed = i;

        uint64_t distanceGone = (time * i) - (i*i);

        if (distanceGone > distance)
            count += 1;
    }

    return count;
}

int main()
{
    uint64_t a = NumberOfWaysToWin();
    std::cout << "Part 1: " << a;
    uint64_t b = NumberOfWaysToWinPart2();
    std::cout << "Part 2: " << b;
    return 0;
}
