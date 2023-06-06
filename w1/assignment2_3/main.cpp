#include <iostream>
#include <vector>
#include <string>

struct StudentStruct
    {
        std::string name {};
        int age {};
        int grade {};
    };



//set students from user

void get_students_from_user(std::vector<StudentStruct> &students_vect)
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

//get average grade

//get highest grade


int main()
{
    std::vector<StudentStruct> students_vect;

    get_students_from_user(students_vect);

    std::cout << "Oma testitulostus:" << std::endl;
    for(auto student : students_vect)
    {
        std::cout << student.name << " "<< student.age << " " << student.grade << std::endl;

    }

    return 0;
}