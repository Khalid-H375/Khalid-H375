#include <iostream>

using namespace std;

class student 
{
  private:
  string name;
  int id;
  double gpa;

  public:
  void setName ( string n )
  {
    name = n;
  }
  void setID( int i )
  {
    id = i;
  }
  void setGPA ( double g)
  {
    gpa = g;
  }
  string getName()
  {
    return name;
  }
  int getID()
  {
    return id;
  }
  double getgpa()
  {
    return gpa;
  }

};

int main ()
{
  string n;
  int i;
  double g;

  cout << "Welcome to the SIS ! "<< endl;
  cout << "Enter student name : " << endl;
  cin >> n;
  cout << "Enter student ID : " << endl;
  cin >> i;
  cout << "Enter student GPA : " << endl;
  cin >> g;

  student student;
  student.setName(n);
  student.setID(i);
  student.setGPA(g);
  
  cout << "Student name is : " << student.getName() << endl;
  cout << "Student ID is : " << student.getID() << endl;
  
  int k = g;
  while ( k )
  {
  if ( 0 < k <= 4 )
  {
    cout << "Student GPA is : " << student.getgpa() << endl;
    break;
  }
  
  cout << "Enter between 0 and 4 : " << endl;
  cin >> g;
  k++;
  }

  return 0;
}