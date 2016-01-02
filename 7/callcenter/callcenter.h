/*
employee class
director inherits from employee
manager inherits from employee
respondent inherits from employee
call center class that has a deque of employees
call center has dispatch call function

have deque of employees
1)  sort every time an employee gets added by their level
  benefits:  one vector that you can check
  drawbacks:  need to resort every time something is added and difficult to reassign to higher level
  NO
2)  keep 3 deques for employees
  benefits:  easy to assign a call and to escalate
  drawbacks:  can't iterate through each employee easily.  Actually that's not true
              no benefit of class structure
3)  keep deque of employee pointers
    also add to seperate deques for respondents, managers, and directors
  benefits:  pointers are shared between deques.  Easy to iterate and solves all our problems
  drawbacks:  need to manager memory manually unless we use a shared pointer

4)  multidimensional deque of employees organized by level
  benefits:  no need to manually manage memory, solves all our problems with iterating and
             escalating
  drawbacks:  need to make sure we're not going out of range and we have to deal with indices

new call:
 check for free respondent by iterating through the respondent deque
 if not then escalate to manager, then director

escalate:
  check for free respondent greater than the current level
*/


#include <iostream>
#include <deque>
#include <queue>

enum employeeLevel {NONE = -1, RESPONDENT = 0, MANAGER = 1, DIRECTOR = 2};

class employee;

class call
{
  public:

    call();
    call(std::string n);
    ~call();

    std::string name;
    employee * assignedEmployee = NULL;
    employeeLevel level = NONE;
};
////////////////////////////////////////////////////////////////////////////////


class employee
{
  public:

    employee();
    ~employee();

    void assignCall(call * c);
    std::string getName();
    virtual employeeLevel getLevel();
    
    bool isFree = true;

  protected:

    std::string name;
};
////////////////////////////////////////////////////////////////////////////////


class respondent : public employee
{
  public:

    respondent(std::string n);
    ~respondent();

    virtual employeeLevel getLevel();
};
////////////////////////////////////////////////////////////////////////////////


class manager : public employee
{
  public:

    manager(std::string n);
    ~manager();

    virtual employeeLevel getLevel();
};
////////////////////////////////////////////////////////////////////////////////


class director : public employee
{
  public:

    director(std::string n);
    ~director();

    virtual employeeLevel getLevel();
};
////////////////////////////////////////////////////////////////////////////////


class callCenter
{
  public:

    callCenter();
    ~callCenter();
    void dispatchCall();
    void reassignCall(call * c);
    void addEmployee(employee & e);
    void createCall(std::string name, call *& c);
    int numCalls();

  private:

    std::deque<std::deque<employee>> employees;
    std::deque<call*> calls;
};
////////////////////////////////////////////////////////////////////////////////
