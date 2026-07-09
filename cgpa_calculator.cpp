#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n;
    float totalCredits = 0, totalGradePoints = 0;
    float cgpa;

    cout << "========== CGPA Calculator ==========\n";
    cout << "Enter the number of courses: ";
    cin >> n;

    vector<string> courseName(n);
    vector<float> grade(n), credit(n);

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Course Name: ";
        cin >> courseName[i];

        cout << "Enter Grade Point (0 - 10): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    float gpa = totalGradePoints / totalCredits;

    cout << "\nEnter Overall CGPA (or enter the same GPA if only one semester): ";
    cin >> cgpa;

    cout << "\n========== Result ==========\n";
    cout << left << setw(15) << "Course"
         << setw(12) << "Grade"
         << setw(12) << "Credits" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << courseName[i]
             << setw(12) << grade[i]
             << setw(12) << credit[i] << endl;
    }

    cout << "\nTotal Credits      : " << totalCredits;
    cout << "\nSemester GPA       : " << fixed << setprecision(2) << gpa;
    cout << "\nOverall CGPA       : " << fixed << setprecision(2) << cgpa;

    return 0;
}