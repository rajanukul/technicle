#include <iostream>
#include <vector>

bool binarySearch(const std::vector<int>& list, int target) {
    int left = 0;
    int right = list.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (list[mid] == target) {
            return true; 
        }
        else if (list[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return false;  
}
void checkRollNumbers(const std::vector<int>& rollNames, const std::vector<int>& courseNames, const std::vector<int>& CGPAs) {
    int rollNo;
    std::cout << "Enter roll number to search: ";
    std::cin >> rollNo;
    
    if (binarySearch(courseNames, rollNo) && binarySearch(CGPAs, rollNo)) {
        std::cout << "Roll No: " << rollNo << std::endl;
    }
    else {
        std::cout << "Roll number not found." << std::endl;
    }
}

int main() {
    std::vector<int> rollNames;
    std::vector<int> courseNames;
    std::vector<int> CGPAs;
    
    int rollNo;
    int courseNo;
    int CGPA;
    int n;
    
    std::cout << "Enter the number of students: ";
    std::cin >> n;
    
    std::cout << "Enter roll numbers and names of students:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> rollNo;
        rollNames.push_back(rollNo);
    }
    
    std::cout << "Enter roll numbers and course names for students:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> rollNo >> courseNo;
        courseNames.push_back(rollNo);
    }
    
    std::cout << "Enter roll numbers and CGPA of students:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> rollNo >> CGPA;
        CGPAs.push_back(rollNo);
    }
    
    checkRollNumbers(rollNames, courseNames, CGPAs);
    
    return 0;
}
