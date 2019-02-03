/*
 * main.cpp
 *
 *  Created on: Jan 26, 2019
 *      Author: tambykaghdo
 */
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

void writeToMiniFile(std::string filePrefix, int splitCounter, std::string outputLinesToFile){
	std::ofstream fileOut;
	fileOut.open (filePrefix + '_' + std::to_string(splitCounter) + ".txt");
	fileOut << outputLinesToFile;
	//outputLinesToFile = "";
	fileOut.close();
}

void processFile(std::string fileName, int splitLineNumber, std::string filePrefix){

	int splitCounter = 1;
	int counter = 0;
	std::string outputLinesToFile;
		std::ifstream file(fileName);
		if (file.is_open()) {
			std::string line;
			while (getline(file, line)) {
				if (counter < splitLineNumber-1){
					outputLinesToFile += line + '\n';
				}
				else{
					outputLinesToFile += line;
				}
				counter++;
				if (counter == splitLineNumber){
					writeToMiniFile(filePrefix, splitCounter, outputLinesToFile);
					outputLinesToFile = "";
					splitCounter++;
					counter = 0;
				}
			}

			if (!file){
				writeToMiniFile(filePrefix, splitCounter, outputLinesToFile);
				outputLinesToFile = "";
			}
			file.close();
		}
		else{
			std::cout << "ERROR OPENING FILE";
		}
}

int main(){
	std::cout << "split-file" << std::endl;

	std::string fileName = "auto-mpg.data";
	int splitLineNumber = 3;
	std::string filePrefix = "auto";

	processFile(fileName, splitLineNumber, filePrefix);



	//EXIT
	//std::string exitInput;
	//std::cin >> exitInput;

	return 0;
}

