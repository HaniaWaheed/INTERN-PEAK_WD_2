#include <iostream>
#include <string>

using namespace std;

const int MAX_COURSES = 100;          
const int MAX_STUDENTS_PER_COURSE = 6;

class EnrollmentMap 
{
private:
    struct Course
    {
        string courseName;
        string students[MAX_STUDENTS_PER_COURSE];
        int studentCount;
    };

    Course courses[MAX_COURSES];
    int courseCount;

    int findCourse(const string& course) const;

public:
    EnrollmentMap();                         
    EnrollmentMap(const EnrollmentMap& other); 
    EnrollmentMap& operator=(const EnrollmentMap& other); 
    ~EnrollmentMap();                        

    string* operator[](const string& course); 
    EnrollmentMap& operator+=(pair<string, string> course_student); 
    EnrollmentMap& operator-=(pair<string, string> course_student); 
    EnrollmentMap operator+(const EnrollmentMap& other) const; 

    string toString() const;         
};
