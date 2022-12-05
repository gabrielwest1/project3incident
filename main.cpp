#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

void readFile(const std::string& fileName, std::string& restaurantName, std::string& cusine, std::string& openHours, std::string& state, std::string& countryGEOID, std::string& countryName, std::string& uaGEOID, std::string& uaName, std::string& msaGEOID, std::string& msaName, std::string& longitude, std::string& latitude, std::string& frequencyString, std::string& isChainString) {
    std::ifstream inFile(fileName);
    std::string line;

    int frequency;
    int isChain;
    //std::vector<std::string> restaurants;

    while (getline(inFile, line)) {
        std::istringstream stream(line);
        getline(stream, restaurantName, ',');
        getline(stream, cusine, ',');
        getline(stream, openHours, ',');
        getline(stream, state, ',');
        getline(stream, countryGEOID, ',');
        getline(stream, countryName, ',');
        getline(stream, uaGEOID, ',');
        getline(stream, uaName, ',');
        getline(stream, msaGEOID, ',');
        getline(stream, msaName, ',');
        getline(stream, longitude, ',');
        getline(stream, latitude, ',');
        getline(stream, frequencyString, ',');
        //frequency = stoi(frequencyString);
        getline(stream, isChainString, ',');
        //isChain = stoi(isChainString);

    }
}

int main() {
    std::string fileName = "chainness_point_2021_part1.csv";
    std::string fileName2 = "chainness_point_2021_part2.csv";
    std::string fileName3 = "chainness_point_2021_part3.csv";
    std::string restaurantName;
    std::string cusine;
    std::string openHours;
    std::string state;
    std::string countryGEOID; //int
    std::string countryName;
    std::string uaGEOID; //int
    std::string uaName;
    std::string msaGEOID; //int
    std::string msaName;
    std::string longitude; //double
    std::string latitude; //double
    std::string frequencyString; //int
    std::string isChainString; //int

    /*std::cout << "Enter first dataset file name: " << std::endl;
    std::cin >> fileName;
    std::cout << "Enter second dataset file name: " << std::endl;
    std::cin >> fileName2;
    std::cout << "Enter third dataset file name: " << std::endl;
    std::cin >> fileName3;*/

    readFile(fileName, restaurantName, cusine, openHours, state, countryGEOID, countryName, uaGEOID, uaName, msaGEOID, msaName, longitude, latitude, frequencyString, isChainString);

    int choice;

    std::cout << "Welcome to the U.S. Restaurant Frequency Project!" << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Find top 5 most frequent NON-chain restaurants in a specific state" << std::endl;
    std::cout << "2. Find top 5 most frequent chain restaurant in a specific state" << std::endl;
    std::cout << "3. List top 10 most frequent chain restaurants in the U.S." << std::endl;
    std::cout << "4. List top 10 most frequent NON-chain restaurants in the U.S." << std::endl;
    std::cout << "5. What state is a certain restaurant most frequent in?" << std::endl;

    std::cin >> choice;
    if (choice == 1) {
        std::string state;
        std::cout << "Which state would you like to select? " << std::endl;
        std::cin >> state;
    }
    else if (choice == 2) {
        std::string state;
        std::cout << "Which state would you like to select? " << std::endl;
        std::cin >> state;
    }
    else if (choice == 3) {

    }
    else if (choice == 4) {

    }
    else if (choice == 5) {
        std::string restaurant;
        std::cout << "Which restaurant would you like to select? " << std::endl;
        std::cin >> restaurant;
    }


    return 0;
}
