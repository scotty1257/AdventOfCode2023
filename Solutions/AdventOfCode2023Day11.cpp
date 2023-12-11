/*
--- Day 11: Cosmic Expansion ---
You continue following signs for "Hot Springs" and eventually come across an observatory. 
The Elf within turns out to be a researcher studying cosmic expansion using the giant telescope here.

He doesn't know anything about the missing machine parts; he's only visiting for this research project. 
However, he confirms that the hot springs are the next-closest area likely to have people; 
he'll even take you straight there once he's done with today's observation analysis.

Maybe you can help him with the analysis to speed things up?

The researcher has collected a bunch of data and compiled the data into a single giant image (your puzzle input). 
The image includes empty space (.) and galaxies (#). For example:

...#......
.......#..
#.........
..........
......#...
.#........
.........#
..........
.......#..
#...#.....
The researcher is trying to figure out the sum of the lengths of the shortest path between every pair of galaxies. 
However, there's a catch: the universe expanded in the time it took the light from those galaxies to reach the observatory.

Due to something involving gravitational effects, only some space expands. 
In fact, the result is that any rows or columns that contain no galaxies should all actually be twice as big.

In the above example, three columns and two rows contain no galaxies:

   v  v  v
 ...#......
 .......#..
 #.........
>..........<
 ......#...
 .#........
 .........#
>..........<
 .......#..
 #...#.....
   ^  ^  ^
These rows and columns need to be twice as big; the result of cosmic expansion therefore looks like this:

....#........
.........#...
#............
.............
.............
........#....
.#...........
............#
.............
.............
.........#...
#....#.......
Equipped with this expanded universe, the shortest path between every pair of galaxies can be found. 
It can help to assign every galaxy a unique number:

....1........
.........2...
3............
.............
.............
........4....
.5...........
............6
.............
.............
.........7...
8....9.......
In these 9 galaxies, there are 36 pairs. Only count each pair once; order within the pair doesn't matter. 
For each pair, find any shortest path between the two galaxies using only steps that 
move up, down, left, or right exactly one . or # at a time. 
(The shortest path between two galaxies is allowed to pass through another galaxy.)

For example, here is one of the shortest paths between galaxies 5 and 9:

....1........
.........2...
3............
.............
.............
........4....
.5...........
.##.........6
..##.........
...##........
....##...7...
8....9.......
This path has length 9 because it takes a minimum of nine steps to get 
from galaxy 5 to galaxy 9 (the eight locations marked # plus the step onto galaxy 9 itself). 

Here are some other example shortest path lengths:

Between galaxy 1 and galaxy 7: 15
Between galaxy 3 and galaxy 6: 17
Between galaxy 8 and galaxy 9: 5
In this example, after expanding the universe, the sum of the shortest path between all 36 pairs of galaxies is 374.

Expand the universe, then find the length of the shortest path between every pair of galaxies. 

What is the sum of these lengths?

*/
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
#include <unordered_map>
#include <xhash>

static const bool DEBUG_PRINTER = true;


struct AOCUtils 
{
    template <class T>
    void matchRegex(const std::string& text, const std::regex& pattern, std::vector<T> & oVec, bool toNum)
    {
        std::sregex_iterator it(text.begin(), text.end(), pattern);
        std::sregex_iterator it_end;
        
        for(; it != it_end; ++it)
        {
            const std::smatch& match = *it;
            if (toNum == true)
                oVec.push_back(std::stoi(match.str()));
            else 
                oVec.push_back(match.str());
        }
        
    }

    template <class T>
    void printVec(const std::vector<T>& iV)
    {
        if (DEBUG_PRINTER)
        {
            for (const auto& unit: iV)
                std::cout << unit << std::endl;
            std::cout << std::endl;
        }
    }

    template <typename T>
    void readFile(std::string& fileName, std::vector<T>& outputVector)
    {
        std::ifstream file;
        file.open(fileName);

        if (file.is_open())
        {   
            std::vector<T> out;
            std::string line;
            while (std::getline(file, line))
            {
                out.push_back(line);
            }
            outputVector = out;
        }
        file.close();
    } 
};

class Solution 
{
public:
    Solution(std::string fileName) {
        utils = AOCUtils();        
        utils.readFile(fileName, fileContainer);
    }    
    int Day11()
    {
        const char galaxy = '#';
        int width = fileContainer[0].size();
        int height = fileContainer.size();

        std::vector<int> rowsWithoutGalaxies{};

        for (int i = 0; i < fileContainer.size(); i++)
        {
            std::string row = fileContainer[i];

            if (row.contains(galaxy))
            {
                continue;
            } 
            else 
            {
                rowsWithoutGalaxies.push_back(i);
            }
        }


        utils.printVec(rowsWithoutGalaxies);
        
        return 0;
    }
private:
    AOCUtils utils;
    std::vector<std::string> fileContainer;
public:
};


int main()
{
    Solution soln("AdventOfCode2023Day11.txt");
    soln.Day11();
}
