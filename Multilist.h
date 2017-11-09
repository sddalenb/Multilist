/**
 * Multilist.h
 * The purpose of this program is to take in a list of students and their corresponding classes
 * and enter them into a multilist. The multilist class utilizes a head node at (0,0) to connect all students
 * and classes from. Head nodes for students give a start point to check if students exist or not as head
 * nodes for classes give a start point to check if classes exist. This is the .h file in which all functions
 * of the Multilist class will be built.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#ifndef MULTILIST_H
#define MULTILIST_H

#include "Node.h"

class Multilist{
private:
    Node * headNode = nullptr;
public:
    Multilist(); ///default constructor
    ~Multilist(); ///default destructor

    void addStudent(Node *);
    void addClass(Node *);
    void insert(Node *);

    void printByStudent();
    void printByClass();
};


#endif