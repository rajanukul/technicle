//Three lists are maintained with the integer rollnos of student, one list contains the rollno and name and
// second list contains roll no and course name third list contains roll no and cgpa. find a common way to check common roll nos in three lists

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> rollnoSet;
    unordered_set<int> commonRollnos;

    int rollnoNameSize, rollnoCourseSize, rollnoCgpaSize;

    cout << "Enter the number of roll numbers and names: ";
    cin >> rollnoNameSize;

    int* rollnoNameList = new int[rollnoNameSize];
    cout << "Enter the roll numbers and names: ";
    for (int i = 0; i < rollnoNameSize; i++) {
        cin >> rollnoNameList[i];
    }

    cout << "Enter the number of roll numbers and course names: ";
    cin >> rollnoCourseSize;

    int* rollnoCourseList = new int[rollnoCourseSize];
    cout << "Enter the roll numbers and course names: ";
    for (int i = 0; i < rollnoCourseSize; i++) {
        cin >> rollnoCourseList[i];
    }

    cout << "Enter the number of roll numbers and CGPA: ";
    cin >> rollnoCgpaSize;

    int* rollnoCgpaList = new int[rollnoCgpaSize];
    cout << "Enter the roll numbers and CGPA: ";
    for (int i = 0; i < rollnoCgpaSize; i++) {
        cin >> rollnoCgpaList[i];
    }

    // Add roll numbers from List 1 to the set
    for (int i = 0; i < rollnoNameSize; i++) {
        rollnoSet.insert(rollnoNameList[i]);
    }

    // Check for common roll numbers in List 2 and List 3
    for (int i = 0; i < rollnoCourseSize; i++) {
        if (rollnoSet.count(rollnoCourseList[i]) > 0) {
            commonRollnos.insert(rollnoCourseList[i]);
        }
    }

    rollnoSet.clear();

    // Add roll numbers from List 2 to the set
    for (int i = 0; i < rollnoCourseSize; i++) {
        rollnoSet.insert(rollnoCourseList[i]);
    }

    // Check for common roll numbers in List 3
    for (int i = 0; i < rollnoCgpaSize; i++) {
        if (rollnoSet.count(rollnoCgpaList[i]) > 0) {
            commonRollnos.insert(rollnoCgpaList[i]);
        }
    }

    cout << "Common Roll Numbers: ";
    for (int rollno : commonRollnos) {
        cout << rollno << " ";
    }
    cout << endl;

    delete[] rollnoNameList;
    delete[] rollnoCourseList;
    delete[] rollnoCgpaList;

    return 0;
}
