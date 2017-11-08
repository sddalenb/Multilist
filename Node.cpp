/**
 * Node.cpp
 * The purpose of this program is to take in a list of students and their orresponding classes
 * and enter them into a multilist. The menu in the main allows for the user to load the students
 * from a data file or exit, a subsequent submenu allows for the user to add their own data, or
 * view the classes by student and student by classes.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#include "Node.h"

Node::Node(){
    //default constructor
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    studId = 0;
    classId = 0;
}

Node::Node(int studId, int classId) {
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    this->studId = studId;
    this->classId = classId;
}

Node::~Node(){
    //default destructor
}

void Node::setUp(Node * up){
    this->up = up;
}

void Node::setDown(Node * down){
    this->down = down;
}

void Node::setLeft(Node * left){
    this->left = left;
}

void Node::setRight(Node * right){
    this->right = right;
}

Node * Node::getUp() {
    return this->up;
}

Node * Node::getDown() {
    return this->down;
}

Node * Node::getLeft(){
    return this->left;
}

Node * Node::getRight(){
    return this->right;
}

int Node::getStudId(){
    return this->studId;
}

int Node::getClassId() {
    return this->classId;
}