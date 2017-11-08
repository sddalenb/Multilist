/**
 * Multilist.cpp
 * The purpose of this program is to take in a list of students and their orresponding classes
 * and enter them into a multilist. The menu in the main allows for the user to load the students
 * from a data file or exit, a subsequent submenu allows for the user to add their own data, or
 * view the classes by student and student by classes.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#include "Multilist.h"

using namespace std;

Multilist::Multilist(){
    //default constructor
    headNode = new Node(0,0);
}

Multilist::~Multilist(){
    //default destructor
    Node * p = headNode;
    while(headNode->getRight() != NULL) {
        while (headNode->getDown() != NULL)
            headNode = headNode->getDown();
        headNode = headNode->getRight();
        delete p;
        p = headNode;
    }
}

/**
 * The purpose of this function is to add a haeder node for unique students.
 * If the student already exists it doesn't do anything. If the new student falls
 * between two students, it places it between those two students.
 * @param studId
 */
void Multilist::addStudent(int studId) {
    Node * newNode = new Node(studId, 0);
    Node * current = headNode;
    bool keepGoing = true;

    while(keepGoing) {
        if(current->getStudId() == newNode->getStudId()) {
            //cout << "Student already exists" << endl;
            keepGoing = false;
        } else if(current->getStudId() < newNode->getStudId()) {
            if(current->getRight() == NULL) {
                current->setRight(newNode);
                newNode->setLeft(current);
                keepGoing = false;
            } else {
                current = current->getRight();
            }
        } else if(current->getStudId() > newNode->getStudId()) {
            Node * temp = current->getLeft();
            temp->setRight(newNode);
            newNode->setRight(current);
            current->setLeft(newNode);
            newNode->setLeft(temp);
            keepGoing = false;
        } else {
            cout << "something went wrong: addStudent" << endl;
            keepGoing = false;
        }
    }
}

/**
 * The purpose of this function is to add a haeder node for unique classes.
 * If the class already exists it doesn't do anything. If the new class falls
 * between two classes, it places it between those two classes.
 * @param classId
 */
void Multilist::addClass(int classId) {
    Node * newNode = new Node(0, classId);
    Node * current = headNode;
    bool keepGoing = true;

    while(keepGoing) {
        if(current->getClassId() == newNode->getClassId()) {
            //cout << "Class already exists" << endl;
            keepGoing = false;
        } else if(current->getClassId() < newNode->getClassId()) {
            if(current->getDown() == NULL) {
                current->setDown(newNode);
                newNode->setUp(current);
                keepGoing = false;
            } else {
                current = current->getDown();
            }
        } else if(current->getClassId() > newNode->getClassId()) {
            Node * temp = current->getUp();
            temp->setDown(newNode);
            newNode->setDown(current);
            current->setUp(newNode);
            newNode->setUp(temp);
            keepGoing = false;
        } else {
            cout << "something went wrong: addClass" << endl;
            keepGoing = false;
        }
    }
}

/**
 * the purpose of this function is to insert a student into the multilist. It connects students and classes
 * to the previous node in the list so as to save space in memory only adding nodes when they've been created.
 * Students and classes are linked horizontally and vertically with eachother, should a pair have already been entered
 * the user is notified and nothing happens.
 *
 * @param studId
 * @param classId
 */
void Multilist::insert(int studId, int classId) {

    Node * current = headNode;
    Node * newNode = new Node(studId, classId);
    bool keepGoing = true;
    while(keepGoing) {
        if(current->getStudId() == newNode->getStudId()) {
            if(current->getClassId() == newNode->getClassId()){
                cout << "Student-Class union already exists" << endl;
                keepGoing = false;
            } else if(current->getClassId() < newNode->getClassId()) {
                if(current->getDown() == NULL) {
                    current->setDown(newNode);
                    newNode->setUp(current);
                    keepGoing = false;
                } else {
                    current = current->getDown();
                }
            } else if(current->getClassId() > newNode->getClassId()) {
                Node * temp = current->getUp();
                temp->setDown(newNode);
                newNode->setDown(current);
                current->setUp(newNode);
                newNode->setUp(temp);
                keepGoing = false;
            } else {
                cout << "Something went wrong: insert" << endl;
                keepGoing = false;
            }
        } else if(current == NULL) {
            cout << "Something went wrong: insert" << endl;
            keepGoing = false;
        } else {
            current = current->getRight();
        }
    }

    current = headNode;
    keepGoing = true;
    while(keepGoing) {
        if(current->getClassId() == newNode->getClassId()) {
            if(current->getStudId() == newNode->getStudId()){
                //cout << "Student-Class union already exists" << endl;
                keepGoing = false;
            } else if(current->getStudId() < newNode->getStudId()) {
                if(current->getRight() == NULL) {
                    current->setRight(newNode);
                    newNode->setLeft(current);
                    keepGoing = false;
                } else {
                    current = current->getRight();
                }
            } else if(current->getStudId() > newNode->getStudId()) {
                Node * temp = current->getLeft();
                temp->setRight(newNode);
                newNode->setRight(current);
                current->setLeft(newNode);
                newNode->setLeft(temp);
                keepGoing = false;
            } else {
                cout << "Something went wrong: insert" << endl;
                keepGoing = false;
            }
        } else if(current == NULL) {
            cout << "Something went wrong: insert" << endl;
            keepGoing = false;
        } else {
            current = current->getDown();
        }
    }
}

/**
 * The purpose of this function is to print out a list of classes and the students enrolled in them.
 * It only displays students and classes in the multilist.
 */
void Multilist::printByClass() {
    cout << endl << endl;
    Node * currentClass = headNode->getDown();
    while(currentClass != NULL) {
        cout << "Class " << currentClass->getClassId() << " has students: ";
        Node * currentStud = currentClass->getRight();
        while(currentStud != NULL) {
            cout << currentStud->getStudId() << " ";
            currentStud = currentStud->getRight();
        }
        currentClass = currentClass->getDown();
        cout << endl << endl;
    }
}

/**
 * The purpose of this function is to print out a list of students and the classes in which they are enrolled.
 * it only displays students and classes in the multilist.
 */
void Multilist::printByStudent() {
    cout << endl << endl;
    Node * currentStud = headNode->getRight();
    while(currentStud != NULL) {
        cout << "Student " << currentStud->getStudId() << " has classes: ";
        Node * currentClass = currentStud->getDown();
        while(currentClass != NULL) {
            cout << currentClass->getClassId() << " ";
            currentClass = currentClass->getDown();
        }
        currentStud = currentStud->getRight();
        cout << endl << endl;
    }
}
