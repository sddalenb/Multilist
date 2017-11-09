/**
 * Driver.cpp
 * The purpose of this program is to take in a list of students and their corresponding classes
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
 *
 * @param vNode - stores imported student-class pairs in vector
 */
void fileParse(std::vector<Node *> &vNode) {
    /// everything to import and convert from external file "data.txt"
    std::ifstream inputFile("data.txt");
    std::string currentLine, string_number;
    std::stringstream ss, converter;

    /// variable to store number temporarily and vector to store all pairs which will then be attached to Node
    int number;
    std::vector<int> vTemp;

    /// check if the file is open then intake all data for length of file and put on temporary vector
    /// tell user if file doesn't exist
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
        cout << "\nUnable to open file" << endl;
    }

    /// store all student-class pairs in Node and push onto Node vector
    for(int i = 0; i < vTemp.size(); i+=2) {
        Node * node = new Node(vTemp[i], vTemp[i+1]);
        vNode.push_back(node);
    }
}

/**
 * Function to take in extra student-class pair input in console from user. Prompts for student id first, then class id.
 * Stores in node which is then returned to be manipulated as necessary.
 *
 * @return newNode - Node student-class pair is stored in
 */
Node * extraInput() {
    /// variables to intake and convert user input
    int studInt, classInt;
    std::string studStr, classStr;
    std::stringstream inputss;
    inputss.clear();
    inputss.str("");

    /// prompt for student id, convert to integer to be used in Node
    cout << "\nEnter a Student ID: ";
    cin >> studStr;
    inputss << studStr;
    inputss >> studInt;
    cout << "Student ID entered was: " << studInt << endl;
    inputss.clear();
    inputss.str("");

    /// prompt for class id, convert to integer to be used in Node
    cout << "\nEnter a Class ID: ";
    cin >> classStr;
    inputss << classStr;
    inputss >> classInt;
    cout << "Class ID entered was: " << classInt << endl;
    inputss.clear();
    inputss.str("");

    /// Node of student-class pair to be returned for manipulation
    Node * newNode = new Node(studInt, classInt);
    return newNode;
}

/**
 * Main function that runs the menus and interacts with the user. Initial menu runs to load data from file, then
 * gives user options to add additiona student-class pair, view students by class, or view classes by student. Upon
 * exiting program all data instatiated on the heap is deleted.
 *
 * @return 0 - standard return for int main()
 */
int main(void) {
    /// create a multilist object to utilize it's functions and store information
    Multilist * ml = new Multilist();

    /// variables to interpret user-input, manage loops, and store Nodes
    std::string loadStr = "", printStr = "";
    int loadMenu = 0, printMenu = 0;
    std::vector<Node *> vNode, vStud, vClass;

    std::stringstream inputss;
    inputss.clear();
    inputss.str("");

    /// main menu loop that reprompts menu until user chooses to exit
    while(loadMenu != 2 && printMenu != 4) {
        cout << "\n1. Load Data (From File)"
                "\n2. Exit the Program"
                "\nPlease enter your selection: ";
        cin >> loadStr;
        inputss << loadStr;
        inputss >> loadMenu;
        inputss.clear();
        inputss.str("");

        if(loadMenu == 1) {
            /// interpret input from file and store onto Node vector
            fileParse(vNode);

            /// take all student-class pairs and create head Node, stored on different vectors, to host row/column of
            /// multilist function, student-class pair is then inserted into the multilist. Do this for all student-class pairs
            for (int i = 0; i < vNode.size(); i++) {
                int studId = vNode[i]->getStudId(), classId = vNode[i]->getClassId();

                Node * node = vNode[i]; /// student-class pair, e.g. (1000, 1000)
                Node * studHead = new Node(studId, 0); /// head Nodes for all students, e.g. (1000, 0)
                Node * classHead = new Node(0, classId); /// head Nodes for all classes, e.g. (0, 1000)

                vStud.push_back(studHead);
                vClass.push_back(classHead);

                ml->addStudent(studHead);
                ml->addClass(classHead);
                ml->insert(node);
            }
            cout << "\nFile has been loaded" << endl;

            /// new menu to give user next set of options listed below
            while(printMenu != 4) {
                cout << "\n1. Add an additional student-class pair"
                        "\n2. Print Students by Class"
                        "\n3. Print Classes by Student"
                        "\n4. Exit Program"
                        "\nPlease enter your selection: ";
                cin >> printStr;
                inputss << printStr;
                inputss >> printMenu;
                inputss.clear();
                inputss.str("");

                if(printMenu == 1) {
                    /// create new student-class pair based on user input, put onto respective vectors
                    /// then insert new student-class pair into multilist
                    Node * n = extraInput();
                    int studInt = n->getStudId(), classInt = n->getClassId();

                    Node * s = new Node(studInt, 0);
                    Node * c = new Node(0, classInt);

                    vNode.push_back(n);
                    vStud.push_back(s);
                    vClass.push_back(c);

                    ml->addStudent(s);
                    ml->addClass(c);
                    ml->insert(n);
                } else if(printMenu == 2) {
                    /// print all students in each class for all classes
                    ml->printByClass();
                } else if(printMenu == 3) {
                    /// print all classes each student is enrolled in for all students
                    ml->printByStudent();
                } else if(printMenu == 4) {
                    cout << "\nGoodbye!" << endl;
                } else {
                    cout << "\nInvalid input" << endl;
                }
            }
        } else if(loadMenu == 2) {
            cout << "\nGoodbye!" << endl;
        } else {
            cout << "\nInvalid input" << endl;
        }
    }

    /**
     * the program is now over so we need to clean up the messy data
     * vectors allow for easy way to loop through and delete all Node pointers
     * then we finally delete the multilist once all Nodes are deleted
     */
    for(int i = 0; i < vNode.size(); i++) {
        delete vNode[i];
        delete vStud[i];
        delete vClass[i];
    }
    delete ml;

    return 0;
}
