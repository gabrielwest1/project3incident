#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include "Sorts.h"

// menu functions utilizing sorts
void top5_Chains_StateSide(std::string& state,std::map<std::string,std::map<std::string,std::vector<std::pair<int,int>>>>& list)
{

}
void top5_NonChains_StateSide(std::string& state,std::map<std::string,std::map<std::string,std::vector<std::pair<int,int>>>>& list)
{

}
void top10_MostFrequent_Chain_NationWide(std::map<std::string,std::map<std::string,std::vector<std::pair<int,int>>>>& list)
{

}
void top10_MostFrequent_NonChain_NationWide(std::map<std::string,std::map<std::string,std::vector<std::pair<int,int>>>>& list)
{

}
void restaurant_MostFrequent_StateSide(std::string& state,std::map<std::string,std::map<std::string,std::vector<std::pair<int,int>>>>& list)
{

}

// function to read in file and update the current container
void readFile(const std::string& fileName,std::map<std::string,std::map<std::string,std::vector<std::pair<int,int>>>>& list)
{
    std::ifstream inFile(fileName);
    std::string line;

    // place holder data but not needed
    std::string cusine,openHours,countryGEOID,countryName,uaGEOID,uaName,msaGEOID,msaName,longitude,latitude;

    // data that will be used for all functions
    std::string restaurantName,state,frequencyString,isChainString;
    int frequency,isChain;

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

        getline(stream, frequencyString, ','); // ------------------------- need
        frequency = stoi(frequencyString);
        getline(stream, isChainString, ','); // ------------------------- need
        isChain = stoi(isChainString);

        list.insert(std::make_pair(state,std::map<std::string,std::vector<std::pair<int,int>>>()));
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

int main()
{
    std::string fileName1 = "chainness_point_2021_part1.csv";
    std::string fileName2 = "chainness_point_2021_part2.csv";
    std::string fileName3 = "chainness_point_2021_part3.csv";

    std::map<std::string,std::map<std::string,std::vector<std::pair<int,int>>>> usRestaurants;
    
    //readFile(fileName, usRestaurants);
    //readFile(fileName2, usRestaurants);
    //readFile(fileName3, usRestaurants);

    int choice;

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
                std::cout << "\nWhich state would you like to select?\n" << std::endl;
                std::cin >> state;
                
                top5_Chains_StateSide(state,usRestaurants);

                callMenu();
                std::cin >> choice;
                break;
            case 2:
                std::cout << "\nWhich state would you like to select?\n" << std::endl;
                std::cin >> state;
                
                top5_NonChains_StateSide(state,usRestaurants);

                callMenu();
                std::cin >> choice;
                break;
            case 3:
                top10_MostFrequent_Chain_NationWide(usRestaurants);

                callMenu();
                std::cin >> choice;
                break;
            case 4:
                top10_MostFrequent_NonChain_NationWide(usRestaurants);
                
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
