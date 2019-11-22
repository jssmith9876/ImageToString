#include <iostream>
#include <string>
#include <fstream>

int numDigits(int n){
    int count = 1;
    while (n >= 10){
        n /= 10;
        count += 1;
    }
    return count;
}

int main(){
    std::string fileLocation = "egg_test.png";

    system(("python3 ImageParser.py " + fileLocation).c_str());

    const int NUM_CHARS = 10;
    char newCharacters[NUM_CHARS - 1] = {  '.', '<', '~', '+', '=', '%', '&', '#', '@' };
    const double MAX_VALUE = 255.0;

    std::ifstream file;
    file.open("outputFile.txt");

    std::string line;
    while (getline(file, line)){
        if (line == "-1") {
            std::cout << std::endl;
        }
        else {
            //int numZeros = 4 - numDigits(stoi(line));
            double percentage = stoi(line) / MAX_VALUE;
            int indexValue = (percentage * 10);
            std::cout << newCharacters[indexValue] << " ";
        }

    }

    return 0;
}