# Multilist
A Simple Multilist

This project is designed to give a basic look at how multilists work.
It uses the concept of student-class enrollment by connecting student-class pairs in the multilist.
Each unique student is given a header node in the multilist that it is connected from to allow all classes the student is enrolled in to be connected to it. 
Unique classes are given a header node in the multilist and connects the students enrolled in each classes. 

This program utilizes vectors for easy memory management and also imports data from an external file.
**Important Note: external data should have each student-class pair listed in seperate lines with the student-class pair being comma separated, e.g.
0,0
1,1
2,2