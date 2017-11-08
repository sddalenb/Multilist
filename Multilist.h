/**
 * Multilist.h
 * The purpose of this program is to take in a list of students and their orresponding classes
 * and enter them into a multilist. The menu in the main allows for the user to load the students
 * from a data file or exit, a subsequent submenu allows for the user to add their own data, or
 * view the classes by student and student by classes.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#ifndef MULTILIST_H
#define MULTILIST_H

#include "Node.h"

class Multilist{
private:
    Node * headNode = NULL;
public:
    Multilist(); ///default constructor
    ~Multilist(); ///default destructor

    void addStudent(int);
    void addClass(int);
    void insert(int, int);

    void printByStudent();
    void printByClass();
};


#endif