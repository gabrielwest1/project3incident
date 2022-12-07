#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Sorts.h"

// menu functions utilizing sorts
void top5_Chains_StateSide(std::string& state,int& sort,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<std::pair<int,int>>>>& list)
{
    switch(sort)
    {
        case 1: // quick sort
            break;
        case 2: // merge sort
            break;

    }
}
void top5_NonChains_StateSide(std::string& state,int& sort,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<std::pair<int,int>>>>& list)
{
    switch(sort)
    {
        case 1: // quick sort
            break;
        case 2: // merge sort
            break;

    }
}
void top10_MostFrequent_Chain_NationWide(int& sort,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<std::pair<int,int>>>>& list)
{
    switch(sort)
    {
        case 1: // quick sort
            break;
        case 2: // merge sort
            break;

    }
}
void top10_MostFrequent_NonChain_NationWide(int& sort,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<std::pair<int,int>>>>& list)
{
    switch(sort)
    {
        case 1: // quick sort
            break;
        case 2: // merge sort
            break;

    }
}
void restaurant_MostFrequent_StateSide(std::string& restaurant,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<std::pair<int,int>>>>& list)
{
    int max = 0;
    std::string sMax;
    std::unordered_map<std::string, std::vector<std::pair<int,int>>>::iterator ptr;
    for (auto iter = list.find(restaurant); iter != list.end(); iter++) {
        int i = 0;
        i++;
            for (ptr = iter->second.begin(); ptr != iter->second.end(); ptr++) {
                if (ptr->second[i].first > max ) {
                    max = ptr->second[i].first;
            }
        }
      }
        std::cout << max << std::endl;
 }

// function to read in file and update the current container
void readFile(const std::string& fileName,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<std::pair<int,int>>>>& list)
{
    std::ifstream inFile(fileName);
    std::string line;

    // place holder data but not needed
    std::string cusine,openHours,countryGEOID,countryName,uaGEOID,uaName,msaGEOID,msaName,longitude,latitude;

    // data that will be used for all functions
    std::string restaurantName,state,frequencyString,isChainString;
    int frequency,isChain;
    
    getline(inFile, line); // gets rid of header line
    while (getline(inFile, line)) {
        std::istringstream stream(line);
        getline(stream, restaurantName, ','); // ------------------------- need

        getline(stream, cusine, ','); // dont need
        getline(stream, openHours, ','); // dont need

        getline(stream, state, ','); // ------------------------- need

        getline(stream, countryGEOID, ','); // dont need
        getline(stream, countryName, ','); // dont need
        getline(stream, uaGEOID, ','); // dont need
        getline(stream, uaName, ','); // dont need
        getline(stream, msaGEOID, ','); // dont need
        getline(stream, msaName, ','); // dont need
        getline(stream, longitude, ','); // dont need
        getline(stream, latitude, ','); // dont need
        getline(stream, longitude, ','); // dont need
        getline(stream, latitude, ','); // dont need

        getline(stream, frequencyString, ','); // ------------------------- need
        frequency = std::stoi(frequencyString);
        getline(stream, isChainString, ','); // ------------------------- need
        isChain = std::stoi(isChainString);

        list.insert(std::make_pair(state,std::unordered_map<std::string,std::vector<std::pair<int,int>>>()));
        list[state].insert(std::make_pair(restaurantName,std::vector<std::pair<int,int>>()));
        list[state][restaurantName].push_back(std::make_pair(frequency,isChain));
    }
}

// simple void function for repetitive calls for the menu
void callMenu()
{
    std::cout<< "\nMenu:\n" <<
                "1. Find top 5 most frequent chain restaurant in a specific state\n" <<
                "2. Find top 5 most frequent NON-chain restaurants in a specific state\n" << 
                "3. List top 10 most frequent chain restaurants in the U.S.\n" <<
                "4. List top 10 most frequent NON-chain restaurants in the U.S.\n" <<
                "5. What state is a certain restaurant most frequent in?\n" <<
                "0. Exit\n" << std::endl;
}

void callSort()
{
    std::cout<< "\nWhich sort would you like to use?\n" <<
                "1. Quick Sort\n" <<
                "2. Merge Sort\n" << std::endl;
}

int main()
{
    std::string fileName1 = "chainness_point_2021_part1.csv";
    std::string fileName2 = "chainness_point_2021_part2.csv";
    std::string fileName3 = "chainness_point_2021_part3.csv";

    std::unordered_map<std::string,std::unordered_map<std::string,std::vector<std::pair<int,int>>>> usRestaurants;
    
    readFile(fileName1, usRestaurants);
    readFile(fileName2, usRestaurants);
    readFile(fileName3, usRestaurants);

    int choice,sort; // sort will contain 1 or 2 for quick or merge respectively

    std::cout << "Welcome to the U.S. Restaurant Frequency Project!" << std::endl;
    callMenu();

    std::cin >> choice;
    bool running = true;
    std::string state,restaurant;
    while (running){
        switch (choice)
        {
            case 0:
                running = false;
                break;
            case 1:
                std::cout << "\nWhich state would you like to select? (Using its abbreviation)\n" << std::endl;
                std::cin >> state;

                callSort();
                std::cin >> sort;

                top5_Chains_StateSide(state,sort,usRestaurants);

                callMenu();
                std::cin >> choice;
                break;
            case 2:
                std::cout << "\nWhich state would you like to select? (Using its abbreviation)\n" << std::endl;
                std::cin >> state;
                
                callSort();
                std::cin >> sort;

                top5_NonChains_StateSide(state,sort,usRestaurants);

                callMenu();
                std::cin >> choice;
                break;
            case 3:
                callSort();
                std::cin >> sort;

                top10_MostFrequent_Chain_NationWide(sort,usRestaurants);

                callMenu();
                std::cin >> choice;
                break;
            case 4:
                callSort();
                std::cin >> sort;

                top10_MostFrequent_NonChain_NationWide(sort,usRestaurants);
                
                callMenu();
                std::cin >> choice;
                break;
            case 5:
                std::cout << "\nWhich restaurant would you like to select?\n" << std::endl;
                std::cin >> restaurant;
                
                restaurant_MostFrequent_StateSide(restaurant,usRestaurants);

                callMenu();
                std::cin >> choice;
                break;
            default:
                std::cout << "\nPlease enter a valid number."<< std::endl;

                callMenu();
                std::cin >> choice;
                break;
        }
    }
    return 0;
}
