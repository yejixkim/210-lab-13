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

    if (numberOfStudents == 0) {
        cout << "No student records found." << endl;
        return 1;
    }

    cout << "Read " << numberOfStudents << " student records" << endl;

    //selection sort by student ID
    for (int i = 0; i < numberOfStudents - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < numberOfStudents; j++) {
            if (students[j].studentID < students[minIndex].studentID) {
                minIndex = j;
            }
        }
        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }

    //write sorted records to ouput file
    ofstream outputFile("210-lab-13-grades.txt");

    if (!outputFile) {
        cout << "Error: could not open output file." << endl;
        return 1;
    }
    
    //display summary stats

    return 0;
}