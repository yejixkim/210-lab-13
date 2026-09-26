// COMSC 210 | Lab 13 | Yeji Kim

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//make student struct
struct Student {
    int studentID;
    double score;
};

const int MAX_STUDENTS = 1000;

int main () {
    Student students[MAX_STUDENTS];
    int numberOfStudents = 0;
    
    // open input file
    ifstream inputFile("210-lab-13-grades.txt");

    if (!inputFile) {
        cout << "Error: could not open file." << endl;
        return 1;
    }

    // read all student records from input file
    while (numberOfStudents < MAX_STUDENTS && 
        inputFile >> students[numberOfStudents].studentID 
        >> students[numberOfStudents].score) {
            numberOfStudents++;
        }

    inputFile.close();

    return 0;
}