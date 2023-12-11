/*DESCRIPTION
--- Day 8: Haunted Wasteland ---
You're still riding a camel across Desert Island when you spot a sandstorm quickly approaching.
 When you turn to warn the Elf, she disappears before your eyes! To be fair, she had just finished warning you about ghosts a few minutes ago.

One of the camel's pouches is labeled "maps" - sure enough, it's full of documents (your puzzle input) about how to navigate the desert. 
At least, you're pretty sure that's what they are; one of the documents contains a list of left/right instructions,
and the rest of the documents seem to describe some kind of network of labeled nodes.

It seems like you're meant to use the left/right instructions to navigate the network. 
Perhaps if you have the camel follow the same instructions, you can escape the haunted wasteland!

After examining the maps for a bit, two nodes stick out: AAA and ZZZ. 
You feel like AAA is where you are now, and you have to follow the left/right instructions until you reach ZZZ.

This format defines each node of the network individually. For example:

RL

AAA = (BBB, CCC)
BBB = (DDD, EEE)
CCC = (ZZZ, GGG)
DDD = (DDD, DDD)
EEE = (EEE, EEE)
GGG = (GGG, GGG)
ZZZ = (ZZZ, ZZZ)
Starting with AAA, you need to look up the next element based on the next left/right instruction in your input. 
In this example, start with AAA and go right (R) by choosing the right element of AAA, CCC. 
Then, L means to choose the left element of CCC, ZZZ. By following the left/right instructions, you reach ZZZ in 2 steps.

Of course, you might not find ZZZ right away. If you run out of left/right instructions, repeat the 
whole sequence of instructions as necessary: RL really means RLRLRLRLRLRLRLRL... and so on. 

For example, here is a situation that takes 6 steps to reach ZZZ:

LLR

AAA = (BBB, BBB)
BBB = (AAA, ZZZ)
ZZZ = (ZZZ, ZZZ)
Starting at AAA, follow the left/right instructions. How many steps are required to reach ZZZ?
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
        for (const auto& unit: iV)
            std::cout << unit << std::endl;
        std::cout << std::endl;
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

    // template <class T>
    // std::string getTypeOfItem(T& item)
    // {
    //     std::string type_name();
    //     return type_name<decltype(item)>();
    // }    
};

class Solution 
{
public:
    Solution(std::string fileName) {
        AOCUtils util;
        util.readFile(fileName, fileContainer);
    }    
    int Day8()
    {
        std::string dir = fileContainer[0];
        
        AOCUtils util;

        std::vector<std::string> directions(std::next(fileContainer.begin(), 2), fileContainer.end());
        std::sort(directions.begin(), directions.end(), 
                [](std::string& a, std::string& b){
                    return a.substr(0, 3) < b.substr(0, 3);
                });
        util.printVec<std::string>(directions);
        return 0;
    }
private:
    std::vector<std::string> fileContainer;
public:
};


int main()
{
    Solution soln("aocday8-2023.txt");
    soln.Day8();
}
