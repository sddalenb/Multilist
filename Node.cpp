/**
 * Node.cpp
 * The purpose of this program is to take in a list of students and their corresponding classes
 * and enter them into a multilist. The Node class utilizes the concept of Nodes to act as
 * containers for student-class pairs. Similar to points on a two-dimensional graph, the student-class
 * pair have "coordinates" across a horizontal and vertical in a multilist. Each node can be connected
 * up, down, left, or right to create the relationships necessary for a multilist.
 *
 * @author Seth Dalenberg (sddalenb)
 * @date 14-Oct-2017
 */

#include "Node.h"

Node::Node(){
    /// default constructor that assigns all values of Node to be null with a student id and class id to (0,0)
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
    studId = 0;
    classId = 0;
}

Node::Node(int studId, int classId) {
    /// overloaded constructor that assigns a the student id and class id to a given input
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
    this->studId = studId;
    this->classId = classId;
}

Node::~Node(){
    /// default destructor
}

/**
 * Sets the Node directly up from a Node to the passed Node. This will represent
 * the classes a student is taking.
 *
 * @param up - the Node that is to be set up from the current Node
 */
void Node::setUp(Node * up){
    this->up = up;
}

/**
 * Set the Node directly down from a Node to the passed Node. This will represent
 * the classes a student is taking.
 *
 * @param down - the Node that is to be set down from the current Node
 */
void Node::setDown(Node * down){
    this->down = down;
}

/**
 * Set the Node directly left from a Node to a passed Node. This will represent
 * the students in a given class.
 *
 * @param left - the Node that is to be set left from the current Node
 */
void Node::setLeft(Node * left){
    this->left = left;
}

/**
 * Set the Node directly right from a Node to a passed Node. This will represent
 * the students in a given class.
 *
 * @param right - the Node that is to be set right from the current Node
 */
void Node::setRight(Node * right){
    this->right = right;
}

/**
 * Get the Node that is up in the multilist from the Node calling this function,
 * i.e. the previous class the student is taking
 *
 * @return - the Node up from the current Node
 */
Node * Node::getUp() {
    return this->up;
}

/**
 * Get the Node that is down in the multilist from the Node calling this function,
 * i.e. the next class the student is taking
 *
 * @return - the Node up from the current Node
 */
Node * Node::getDown() {
    return this->down;
}

/**
 * Get the Node that is left in the multilist from the Node calling this function,
 * i.e. the previous student in the class roster
 *
 * @return - the Node up from the current Node
 */
Node * Node::getLeft(){
    return this->left;
}

/**
 * Get the Node that is right in the multilist from the Node calling this function,
 * i.e. the next student in the class roster
 *
 * @return - the Node up from the current Node
 */
Node * Node::getRight(){
    return this->right;
}

/**
 * Get the id of the student for the specified Node calling the function
 *
 * @return - the integer value of the student id
 */
int Node::getStudId(){
    return this->studId;
}

/**
 * Get the id of the class for the specified Node calling the function
 *
 * @return - the integer value of the class id
 */
int Node::getClassId() {
    return this->classId;
}