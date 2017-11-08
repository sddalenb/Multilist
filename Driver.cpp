/**
 * Driver.cpp
 * The purpose of this program is to take in a list of students and their orresponding classes
 * and enter them into a multilist. The menu in the main allows for the user to load the students
 * from a data file or exit, a subsequent submenu allows for the user to add their own data, or
 * view the classes by student and student by classes.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Multilist.h"

using std::cout;
using std::cin;
using std::endl;

/**
 * parses a given data file to determine the student numbers and class numbers to be
 * used in the multilist
 * @param vStud
 * @param vClass
 */
void fileParse(std::vector<int> &vStud, std::vector<int> &vClass) {
    std::ifstream inputFile("data.txt");
    std::string currentLine, string_number;
    std::stringstream ss, converter;
    int number;
    std::vector<int> vTemp;
    if(inputFile.is_open()) {
        while(std::getline(inputFile, currentLine)) {
            ss.clear();
            ss.str("");
            ss.str(currentLine);
            while(std::getline(ss, string_number, ',')) {
                converter.clear();
                converter.str("");
                converter << string_number;
                converter >> number;
                vTemp.push_back(number);
            }
        }
    } else {
        cout << "Unable to open file" << endl;
    }
    for(int i = 0; i < vTemp.size(); i+=2) {
        vStud.push_back(vTemp[i]);
    }
    for(int j = 1; j < vTemp.size(); j+=2) {
        vClass.push_back(vTemp[j]);
    }
}

/**
 * Main function that runs the menus and interacts with the user
 * @return
 */
int main(void) {
    Multilist * ml = new Multilist();

    bool keepGoing = true, keepGoing2 = true;
    std::string loadStr = "", printStr = "";
    int loadMenu = 0, printMenu = 0;

    std::stringstream inputss;
    inputss.clear();
    inputss.str("");

    while(keepGoing) {
        cout << "\n1. Load Data (From File)\n"
             "2. Exit the Program\n"
             "Please enter your selection: ";
        cin >> loadStr;
        inputss << loadStr;
        inputss >> loadMenu;
        inputss.clear();
        inputss.str("");

        if(loadMenu == 1) {
            std::vector<int> vStud, vClass;
            fileParse(vStud, vClass);
            int studSize = vStud.size(), classSize = vClass.size();

            for (int i = 0; i < studSize; i++) {
                int studId = vStud[i], classId = vClass[i];
                ml->addStudent(studId);
                ml->addClass(classId);
                ml->insert(studId, classId);
            }
            cout << "File has been loaded" << endl;
            while(keepGoing2) {
                cout << "\n1. Add an additional student-class pair\n"
                     "2. Print Students by Class\n"
                     "3. Print Classes by Student\n"
                     "4. Exit Program\n"
                        "Please enter your selection: ";
                cin >> printStr;
                inputss << printStr;
                inputss >> printMenu;
                inputss.clear();
                inputss.str("");
                if(printMenu == 1) {
                    int studInt, classInt;
                    std::string studStr, classStr;

                    cout << "\nEnter a Student ID: ";
                    cin >> studStr;
                    inputss << studStr;
                    inputss >> studInt;
                    inputss.clear();
                    inputss.str("");

                    cout << "\nEnter a Class ID: ";
                    cin >> classStr;
                    inputss << classStr;
                    inputss >> classInt;
                    inputss.clear();
                    inputss.str("");

                    ml->addStudent(studInt);
                    ml->addClass(classInt);
                    ml->insert(studInt, classInt);
                } else if(printMenu == 2) {
                    ml->printByClass();
                } else if(printMenu == 3) {
                    ml->printByStudent();
                } else if(printMenu == 4) {
                    keepGoing = false;
                    keepGoing2 = false;
                } else {
                    cout << "Invalid input" << endl;
                }
            }
        } else if (loadMenu == 2) {
            cout << "Goodbye" << endl;
            keepGoing = false;
        } else {
            cout << "Invalid input" << endl;
        }
    }

    delete ml;

    return 0;
}