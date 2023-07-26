#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // Include the header for stringstream to handle CSV data
#include <algorithm>
#include "courseInformation.h" // Include the header file with course data


// Function to load data from the .csv file and populate the courses vector
void loadCSVData(std::vector<Course>& courses, const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cout << "Error: Unable to open the file." << std::endl;
        return;
    }

    std::string line, courseNumber, courseTitle, prerequisites;
    while (std::getline(inputFile, line)) {
        std::stringstream lineStream(line);
        std::getline(lineStream, courseNumber, ',');
        std::getline(lineStream, courseTitle, ',');
        Course course(courseNumber, courseTitle);

        while (std::getline(lineStream, prerequisites, ',')) {
            if (prerequisites.empty() || prerequisites == "-1") {
                break;
            }
            course.prerequisites.push_back(prerequisites);
        }

        courses.push_back(course);
    }

    inputFile.close();
}

// Function to print an alphanumeric list of all courses
void printCourseList(const std::vector<Course>& courses) {
    if (courses.empty()) {
        std::cout << "Error: Data structure is empty. Load data first.\n";
        return;
    }

    std::cout << "Alphanumeric List of Courses (Computer Science and Math):\n";
    for (const auto& course : courses) {
        std::cout << course.courseNumber << " - " << course.courseTitle << std::endl;
    }
}

// Function to sort and print a course list in alphanumeric order
void printCourseListAlphanumeric(const std::vector<Course>& courses) {
    if (courses.empty()) {
        std::cout << "Error: Data structure is empty. Load data first.\n";
        return;
    }

    std::vector<Course> sortedCourses = courses;
    sort(sortedCourses.begin(), sortedCourses.end(), [](const Course& a, const Course& b) {
        return a.courseNumber < b.courseNumber;
    });

    std::cout << "Alphanumeric List of Courses (Computer Science and Math):\n";
    for (const auto& course : sortedCourses) {
        std::cout << course.courseNumber << " - " << course.courseTitle << std::endl;
    }
}


// Function to find a course by its courseNumber and print its information
void printCourse(const std::vector<Course>& courses, const std::string& courseNumber) {
    if (courses.empty()) {
        std::cout << "Error: Data structure is empty. Load data first.\n";
        return;
    }

    for (const auto& course : courses) {
        if (course.courseNumber == courseNumber) {
            std::cout << "Course Title: " << course.courseTitle << std::endl;
            std::cout << "Prerequisite Courses:\n";
            if (course.prerequisites.empty()) {
                std::cout << "None" << std::endl;
            } else {
                for (const auto& prerequisite : course.prerequisites) {
                    std::cout << prerequisite << std::endl;
                }
            }
            return;
        }
    }
    std::cout << "Course not found." << std::endl;
}

// Function to display the main menu and get user input
int displayMenu() {
    int choice;
    std::cout << "\nMenu:\n";
    std::cout << "1. Load Data Structure from .csv file\n";
    std::cout << "2. Print Course List\n";
    std::cout << "3. Print Course Information\n";
    std::cout << "4. Print Alphanumeric Course List\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
    std::cin >> choice;
    return choice;
}

int main() {
    std::vector<Course> courses;
    std::string csvFileName = "courseInformation.csv"; // Update this with the correct .csv file name

    // Load data from the .csv file
    loadCSVData(courses, csvFileName);

    std::string courseNumber;

    while (true) {
        int choice = displayMenu();

        switch (choice) {
          case 1:
              std::cout << "Data loaded successfully from .csv file.\n";
              break;
          case 2:
              printCourseList(courses);
              break;
          case 3:
              std::cout << "Enter the course number: ";
              std::cin >> courseNumber;
              printCourse(courses, courseNumber);
              break;
          case 4:
            if (courses.empty()) {
                std::cout << "Error: Data structure is empty. Load data first.\n";
            } else {
                printCourseListAlphanumeric(courses);
            }
            break;
          case 5:
              std::cout << "Exiting the program. Goodbye!\n";
              return 0;
          default:
              std::cout << "Invalid choice. Please try again.\n";
              break;
          }
    }

    return 0;
}
