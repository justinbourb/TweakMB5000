#include <iostream>
#include <fstream>
#include <string>
#include "source.h"
using namespace std;

string readFileFunc(string fileLocation) {
    //NOT IN USE: keeping for reference
    //this function will read data from a file
    //returns the data as a string
    streampos size;
    char* memblock;
    ifstream file(fileLocation, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
        //file.tellg() is the current get posisition (end of file set by ios::ate)
        size = file.tellg();
        memblock = new char[size];
        //file.seekg searches from 0 (beginning) to ios::beg (end of file)
        file.seekg(0, ios::beg);
        //file.read stores all information into memblock upto size (filesize)
        file.read(memblock, size);
        file.close();
        //cout original file text
        cout << memblock;

        return string(memblock);
    }
    else cout << "Unable to open file";
}

string readFile2(string fileLocation) {
    //this file opens a file at location provided
    //then it appends the file line by line to output
    //returns a contents as a string (output variable)
    string line;
    ifstream myfile(fileLocation);
    string output;
    if (myfile.is_open()) {
        //loops over file line by line
        while (getline(myfile, line)) {
            output += line + '\n';
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    return output;
}


string findAndReplaceFunc(string data, string toSearch, string replaceStr) {
    //this function will find and replace part of a string
    //returns the modified string
    string tempData = data;
    size_t pos = tempData.find(toSearch);
    //only replace is something is found
    if (pos != string::npos) {
        tempData.replace(pos, toSearch.size(), replaceStr);
    }

    return tempData;
}

void writeToFile(string fileLocation, string data) {
    ofstream myfile;
    myfile.open(fileLocation);
    myfile << data;
    myfile.close();
}

int main() {
    //set working directory
    string directory = "C:\\git_local\\";
    string fileLocation = "";
    //using the Tweak Struct from Source.h
    Tweak tweak01;
    tweak01.fileToTweak = "test.txt";
    tweak01.findText = "this";
    tweak01.replaceTextWith = "changed";

    //set file path 
    fileLocation = directory + tweak01.fileToTweak;
    
    //read file data
    string data = readFile2(fileLocation);

    //find and replace 
    data = findAndReplaceFunc(data, tweak01.findText, tweak01.replaceTextWith);
    cout << data;

    writeToFile(fileLocation, data);

    return 0;
}