#include <iostream>
#include <string>
#include <vector>

class Student {
public:
  std::string name;
  int id;

  Student(std::string name, int id) : name(name), id(id) {}
};

class Course {
public:
  std::string name;
  int code;

  Course(std::string name, int code) : name(name), code(code) {}
};

class Faculty {
public:
  std::string name;
  int id;

  Faculty(std::string name, int id) : name(name), id(id) {}
};

class Department {
public:
  std::string name;
  std::vector<Student> students;
  std::vector<Course> courses;
  std::vector<Faculty> faculty;

  Department(std::string name) : name(name) {}
};

class University {
public:
  std::vector<Department> departments;

  University(std::vector<Department> departments) : departments(departments) {}
};

int main() {
  // Create Students
  Student s1("John Doe", 1001);
  Student s2("Jane Doe", 1002);

  // Create Courses
  Course c1("Introduction to Computer Science", 101);
  Course c2("Data Structures and Algorithms", 201);

  // Create Faculty
  Faculty f1("Dr. Smith", 2001);
  Faculty f2("Dr. Johnson", 2002);

  // Create Department
  Department cs_department("Computer Science");
  cs_department.students.push_back(s1);
  cs_department.students.push_back(s2);
  cs_department.courses.push_back(c1);
  cs_department.courses.push_back(c2);
  cs_department.faculty.push_back(f1);
  cs_department.faculty.push_back(f2);

  // Create University
  std::vector<Department> departments = {cs_department};
  University university(departments);

  return 0;
}
