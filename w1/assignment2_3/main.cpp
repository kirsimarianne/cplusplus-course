#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct StudentStruct
{
    std::string name {};
    int age {};
    int grade {};
};

void set_students(std::vector<StudentStruct> &students_vect)
{
    StudentStruct student;
    std::cout << "Count of students: " << std::endl;
    int count {};
    std::cin >> count;
    for(int i = 0; i < count; i++){
        std::cout << "Name of student: " << std::endl;
        std::cin >> student.name;
        std::cout << "Age of student: " << std::endl;
        std::cin >> student.age;
        std::cout << "Grade of student: " << std::endl;
        std::cin >> student.grade;
        students_vect.push_back(student);
    }
}

void print_average(std::vector<StudentStruct> &students_vect)
{
    double sum {0};
    for(StudentStruct student : students_vect)
    {
        sum = sum + student.grade;
    }
    double average {sum/students_vect.size()};
    std::cout << "Average is: " << round(average*100.0)/100.0 << std::endl;
}

void get_highest(std::vector<StudentStruct> &students_vect)
{
    int top_grade {0};
    std::string top_student {};
    for(StudentStruct student : students_vect)
    {
        if(student.grade > top_grade)
        {
            top_student = student.name;
        }
    }
    std::cout << "The student with the highest grade is: "  << top_student << std::endl;
}


int main()
{
    std::vector<StudentStruct> students_vect;

    set_students(students_vect);
    print_average(students_vect);
    get_highest(students_vect);

    return 0;
}