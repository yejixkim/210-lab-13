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

    for (int i = 0; i < numberOfStudents; i++) {
        outputFile << students[i].studentID << " " << students[i].score << endl;
    }

    outputFile.close();

    cout << "Sorted results written to 210-lab-13-grades.txt" << endl;
    
    //display summary stats

    //find min and max scores
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < numberOfStudents; i++) {
        if (students[i].score < students[minIndex].score) {
            minIndex = i;
        }

        if (students[i].score > students[maxIndex].score) {
            maxIndex = i;
        }
    }

    //find mean
    double total = 0;

    for (int i = 0; i < numberOfStudents; i++) {
        total += students[i].score;
    }

    double mean = total / numberOfStudents;

    //find median
    //make a copy of the array to sort by score so the first array stays sorted by ID
    Student scoreSorted[MAX_STUDENTS];

    //selection sort by score
    for (int i = 0; i < numberOfStudents; i++) {
        int minIndex = i;

        for (int j = i + 1; j < numberOfStudents; j++) {
            if (scoreSorted[j].score < scoreSorted[minIndex].score) {
                minIndex = j;
            }
        }
         
        Student temp = scoreSorted[i];
        scoreSorted[i] = scoreSorted[minIndex];
        scoreSorted[minIndex] = temp;
    }

    double median;
    int medianID;

    if (numberOfStudents % 2 ==1) {
        int middle = numberOfStudents / 2;

        median = scoreSorted[middle].score;
        medianID = scoreSorted[middle].studentID;
    }
    else {
        int middle1 = numberOfStudents / 2 - 1;
        int middle2 = numberOfStudents / 2;
        
        median = (scoreSorted[middle1].score + scoreSorted[middle2].score) / 2;
        medianID = -1;
    }



    return 0;
}