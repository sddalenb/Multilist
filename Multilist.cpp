/**
 * Multilist.cpp
 * The purpose of this program is to take in a list of students and their corresponding classes
 * and enter them into a multilist. The multilist class utilizes a head node at (0,0) to connect all students
 * and classes from. Head nodes for students give a start point to check if students exist or not as head
 * nodes for classes give a start point to check if classes exist.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#include "Multilist.h"

using std::cout;
using std::endl;

Multilist::Multilist(){
    /// default constructor, instatiated headNode for start of multilist
    headNode = new Node(0,0);
}

Multilist::~Multilist(){
    /// default destructor, clean up headNode upon destruction
    delete headNode;
}

/**
 * The purpose of this function is to add a header node for unique students.
 * If the student already exists it doesn't do anything. If the new student falls
 * between two students, it places it between those two students. If the new student
 * falls at the end of list, i.e. is the student with the largest ID, it is
 * added to the end of the list of header nodes.
 *
 * @param newNode - node to act as current student that needs to be added
 */
void Multilist::addStudent(Node * newNode) {
    Node * current = headNode;
    bool keepGoing = true;

    while(keepGoing) {
        if(current->getStudId() == newNode->getStudId()) {
            keepGoing = false;
        } else if(current->getStudId() < newNode->getStudId()) {
            if(current->getRight() == nullptr) {
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
 * The purpose of this function is to add a header node for unique classes.
 * If the class already exists it doesn't do anything. If the new class falls
 * between two classes, it places it between those two classes. If the new class
 * falls at the end of list, i.e. is the class with the largest ID, it is
 * added to the end of the list of header nodes.
 *
 * @param newNode - node to act as current class that needs to be added
 */
void Multilist::addClass(Node * newNode) {
    Node * current = headNode;
    bool keepGoing = true;

    while(keepGoing) {
        if(current->getClassId() == newNode->getClassId()) {
            keepGoing = false;
        } else if(current->getClassId() < newNode->getClassId()) {
            if(current->getDown() == nullptr) {
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
 * The purpose of this function is to insert a student-class pair into the multilist. It connects students and classes
 * to the previous node in the list so as to save space in memory only adding nodes when they've been created.
 * Students and classes are linked horizontally and vertically with each-other, should a pair have already been entered
 * the user is notified and nothing happens.
 *
 * @param newNode - the node that is to be added into the multilist containing a student-class pair
 */
void Multilist::insert(Node * newNode) {

    Node * current = headNode;
    bool keepGoing = true;
    while(keepGoing) {
        if(current->getStudId() == newNode->getStudId()) {
            if(current->getClassId() == newNode->getClassId()){
                cout << "Student-Class union already exists" << endl;
                keepGoing = false;
            } else if(current->getClassId() < newNode->getClassId()) {
                if(current->getDown() == nullptr) {
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
        } else if(current == nullptr) {
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
                keepGoing = false;
            } else if(current->getStudId() < newNode->getStudId()) {
                if(current->getRight() == nullptr) {
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
        } else if(current == nullptr) {
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
    while(currentClass != nullptr) {
        cout << "Class " << currentClass->getClassId() << " has students: ";
        Node * currentStud = currentClass->getRight();
        while(currentStud != nullptr) {
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
    while(currentStud != nullptr) {
        cout << "Student " << currentStud->getStudId() << " has classes: ";
        Node * currentClass = currentStud->getDown();
        while(currentClass != nullptr) {
            cout << currentClass->getClassId() << " ";
            currentClass = currentClass->getDown();
        }
        currentStud = currentStud->getRight();
        cout << endl << endl;
    }
}