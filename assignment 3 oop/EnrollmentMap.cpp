#include "EnrollmentMap.h"


EnrollmentMap::EnrollmentMap() : courseCount(0) 
{

}

EnrollmentMap::EnrollmentMap(const EnrollmentMap& other) : courseCount(other.courseCount) {
    for (int i = 0; i < courseCount; ++i)
    {
        courses[i] = other.courses[i];
    }
}

EnrollmentMap& EnrollmentMap::operator=(const EnrollmentMap& other) 
{
    if (this != &other) 
    {
        courseCount = other.courseCount;
        for (int i = 0; i < courseCount; ++i) 
        {
            courses[i] = other.courses[i];
        }
    }
    return *this;
}

EnrollmentMap::~EnrollmentMap() 
{

}

int EnrollmentMap::findCourse(const string& course) const
{
    for (int i = 0; i < courseCount; ++i) 
    {
        if (courses[i].courseName == course) 
        {
            return i;
        }
    }
    return -1; 
}

string* EnrollmentMap::operator[](const string& course)
{
    int index = findCourse(course);
    if (index == -1 && courseCount < MAX_COURSES)
    {
        courses[courseCount].courseName = course;
        courses[courseCount].studentCount = 0;
        return courses[courseCount++].students;
    }
    return courses[index].students;
}

EnrollmentMap& EnrollmentMap::operator+=(pair<string, string> course_student) 
{
    string course = course_student.first;
    string student = course_student.second;
    int index = findCourse(course);
    if (index == -1 && courseCount < MAX_COURSES)
    {
        index = courseCount++;
        courses[index].courseName = course;
        courses[index].studentCount = 0;
    }
    if (courses[index].studentCount < MAX_STUDENTS_PER_COURSE)
    {
        courses[index].students[courses[index].studentCount++] = student;
    }
    else 
    {
        cout << "Course " << course << " already has maximum number of students." << endl;
    }
    return *this;
}

EnrollmentMap& EnrollmentMap::operator-=(pair<string, string> course_student)
{
    string course = course_student.first;
    string student = course_student.second;
    int index = findCourse(course);
    if (index != -1)
    {
        int studentIndex = -1;
        for (int i = 0; i < courses[index].studentCount; ++i)
        {
            if (courses[index].students[i] == student)
            {
                studentIndex = i;
                break;
            }
        }
        if (studentIndex != -1) 
        {
            for (int i = studentIndex; i < courses[index].studentCount - 1; ++i) 
            {
                courses[index].students[i] = courses[index].students[i + 1];
            }
            courses[index].studentCount--;
        }
        else 
        {
            cout << "Student " << student << " not found in course " << course << "." << endl;
        }
    }
    else
    {
        cout << "Course " << course << " not found." << endl;
    }
    return *this;
}

EnrollmentMap EnrollmentMap::operator+(const EnrollmentMap& other) const 
{
    EnrollmentMap result(*this);
    for (int i = 0; i < other.courseCount; ++i)
    {
        const string& course = other.courses[i].courseName;
        for (int j = 0; j < other.courses[i].studentCount; ++j) 
        {
            result += make_pair(course, other.courses[i].students[j]);
        }
    }
    return result;
}

string EnrollmentMap::toString() const 
{
    string result;
    for (int i = 0; i < courseCount; ++i) 
    {
        result += "Course: " + courses[i].courseName + "\n";
        result += "Students:\n";
        for (int j = 0; j < courses[i].studentCount; ++j) 
        {
            result += " - " + courses[i].students[j] + "\n";
        }
    }
    return result;
}
