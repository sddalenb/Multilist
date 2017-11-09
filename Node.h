/**
 * Node.cpp
 * The purpose of this program is to take in a list of students and their corresponding classes
 * and enter them into a multilist. The Node class utilizes the concept of Nodes to act as
 * containers for student-class pairs. Similar to points on a two-dimensional graph, the student-class
 * pair have "coordinates" across a horizontal and vertical in a multilist. Each node can be connected
 * up, down, left, or right to create the relationships necessary for a multilist. This is the .h file
 * in which all functions of the Node class will be built.
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