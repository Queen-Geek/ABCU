#ifndef COURSE_DATA_H
#define COURSE_DATA_H

#include <string>
#include <vector>

class Course {

public:
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites;

    Course(const std::string& num, const std::string& title, const std::vector<std::string>& prereqs = {})
        : courseNumber(num), courseTitle(title), prerequisites(prereqs) {}
};

const std::vector<Course> courses = {
    Course("MATH201", "Discrete Mathematics"),
    Course("CSCI300", "Introduction to Algorithms", {"CSCI200", "MATH201"}),
    Course("CSCI350", "Operating Systems", {"CSCI300"}),
    Course("CSCI101", "Introduction to Programming in C++", {"CSCI100"}),
    Course("CSCI100", "Introduction to Computer Science"),
    Course("CSCI301", "Advanced Programming in C++", {"CSCI101"}),
    Course("CSCI400", "Large Software Development", {"CSCI301", "CSCI350"}),
    Course("CSCI200", "Data Structures", {"CSCI101"})
};

#endif // COURSE_DATA_H