#include "EnrollmentMap.h"

int main()
{
    EnrollmentMap enrollments1, enrollments2, mergedEnrollments;

    enrollments1 += make_pair("Math 101", "Alice Smith");
    enrollments1 += make_pair("History 201", "Bob Johnson");
    enrollments2 += make_pair("Physics 101", "Charlie Brown");

    enrollments1 += make_pair("Math 101", "David Jones");
    enrollments1 += make_pair("Math 101", "Eva Green");
    enrollments2 += make_pair("Physics 101", "Frank White");
    enrollments2 += make_pair("Physics 101", "Grace Black");
    enrollments2 += make_pair("Physics 101", "Hank Blue");
    enrollments2 += make_pair("Physics 101", "Ivy Red");

    enrollments2 += make_pair("Chemistry 101", "Jack Gold");
    enrollments2 += make_pair("Chemistry 101", "Karen Silver");
    enrollments2 += make_pair("Chemistry 101", "Leo Bronze");
    enrollments2 += make_pair("Chemistry 101", "Mia Copper");

    mergedEnrollments = enrollments1 + enrollments2;
    cout << "Merged Enrollments: " << endl << mergedEnrollments.toString() << endl;

    enrollments1 -= make_pair("Math 101", "David Jones");
    cout << "Updated Enrollments: " << endl << enrollments1.toString() << endl;

    return 0;
}
