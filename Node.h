/**
 * Node.h
 * The purpose of this program is to take in a list of students and their orresponding classes
 * and enter them into a multilist. The menu in the main allows for the user to load the students
 * from a data file or exit, a subsequent submenu allows for the user to add their own data, or
 * view the classes by student and student by classes.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

class Node{
private:
    int studId;
    int classId;

    Node * up;
    Node * down;
    Node * left;
    Node * right;
public:
    Node();
    Node(int, int);
    ~Node();

    void setUp(Node *);
    void setDown(Node * );
    void setLeft(Node * );
    void setRight(Node * );

    Node * getUp();
    Node * getDown();
    Node * getLeft();
    Node * getRight();
    int getStudId();
    int getClassId();

};
#endif