#include <stdio.h>
#include <cstdint>
#include <string>
// #include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Employee
{ 
  public:

    string extension;
    string givenname;
    string surname;
};


//-1 if left is first
//1 is right is first
//0 if equal
int compareAlphabetical(const string & left, const string & right)
{
  int minSize = 0;
  if (left.size() > right.size())
    minSize = right.size();
  else
    minSize = left.size();

  for (int i = 0; i < minSize; i++)
  {
    if (left[i] < right[i])
      return -1;
    else if (right[i] < left[i])
      return 1;
    else if (left[i] == right[i])
      continue;
  }

  if (left.size() == right.size())
    return 0;
  else if (left.size() < right.size())
    return -1;
  else
    return 1;
}


bool compareEmployees(const Employee left, const Employee right)
{
  int lastNameComparison = compareAlphabetical(left.surname, right.surname);
  if (lastNameComparison == 0)
  {
    int firstNameComparison = compareAlphabetical(left.givenname, right.givenname);
    return (firstNameComparison == -1);
  }
  return (lastNameComparison == -1);
}

int main()
{
  vector<Employee> evect;
  Employee employee;

  employee.givenname = "Joe";
  employee.surname = "Lyga";
  employee.extension = "4292";
  evect.push_back(employee);

  employee.givenname = "Bob";
  employee.surname = "Lyga";
  employee.extension = "1251";
  evect.push_back(employee);

  employee.givenname = "Bobby";
  employee.surname = "Lygan"; 
  employee.extension = "1255";
  evect.push_back(employee);

  employee.givenname = "Rando";
  employee.surname = "Ortona"; 
  employee.extension = "1256";
  evect.push_back(employee);

  employee.givenname = "John";
  employee.surname = "Cemna"; 
  employee.extension = "1656";
  evect.push_back(employee);

  printf("before...\n");
  for (auto empl : evect)
  {
    printf("%s %s %s\n", empl.extension.c_str(), empl.surname.c_str(), empl.givenname.c_str());
  }
  printf("______________________________________\n");

  // qsort(evect, 5, sizeof(Employee), compareEmployees); //well that was worth a shot...
  std::sort(evect.begin(), evect.end(), compareEmployees);

  printf("after...\n");
  for (auto empl : evect)
  {
    printf("%s %s %s\n", empl.extension.c_str(), empl.surname.c_str(), empl.givenname.c_str());
  }

  return 0;
}
