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

using namespace std;

enum employeeLevel {NONE = -1, RESPONDENT = 0, MANAGER = 1, DIRECTOR = 2};

class employee;

class call
{
  public:

    call() {};
    call(string n) : name(n) {};
    ~call() {};

    string name;

    employee * assignedEmployee = NULL;
    employeeLevel level = NONE;
};
////////////////////////////////////////////////////////////////////////////////


class employee
{
  public:

    employee() {};
    ~employee() {};

    void assignCall(call * c)
    {
      isFree = false;
      c->assignedEmployee = this;
    }

    string getName() {return name;};
    virtual employeeLevel getLevel() {return NONE;};
    
    bool isFree = true;

  protected:

    string name;
};
////////////////////////////////////////////////////////////////////////////////


class respondent : public employee
{
  public:

    respondent(string n) {name = n;};
    ~respondent() {};

    virtual employeeLevel getLevel() {return RESPONDENT;};
};
////////////////////////////////////////////////////////////////////////////////


class manager : public employee
{
  public:

    manager(string n) {name = n;};
    ~manager() {};

    virtual employeeLevel getLevel() {return MANAGER;};
};
////////////////////////////////////////////////////////////////////////////////


class director : public employee
{
  public:

    director(string n) {name = n;};
    ~director() {};

    virtual employeeLevel getLevel() {return DIRECTOR;};
};
////////////////////////////////////////////////////////////////////////////////


class callCenter
{
  public:

    callCenter() 
    {
      employees.resize(3);
    };

    ~callCenter() {};

    void dispatchCall()
    {
      call * currentCall = calls[0];
      calls.pop_front();

      bool foundEmployee = false;

      if (currentCall->level == DIRECTOR)
      {
        cout << "Already at max level\n" << endl;
        return;
      }

      //if currentLevel is -1, it's new so assign to 0 which is dispatch
      //if current level is set to something else, this assigns it to the next level
      for (int l = currentCall->level+1; l < employees.size(); l++)
      {
        for (int e = 0; e < employees[l].size(); e++)
        {
          if (employees[l][e].isFree)
          {
            foundEmployee = true;
            currentCall->level = (employeeLevel)l;
            employees[l][e].assignCall(currentCall);
            break;
          }
        }
        if (foundEmployee) break;
      }

      if (!foundEmployee)
      {
        cout << "Could not find a free employee for call " << currentCall->name << endl;
      }
      else
      {
        cout << "Call " << currentCall->name << " is assigned to " << currentCall->assignedEmployee->getName() << " of level " << currentCall->level << endl;
      }
    }

    void reassignCall(call * c)
    {
      if (c == NULL) return;

      if (c->assignedEmployee == NULL)
      {
        cout << "Assigned is NULL\n" << endl;
      }
      c->assignedEmployee->isFree = true;
      c->assignedEmployee = NULL;
      calls.push_front(c);
      dispatchCall();
    }

    void addEmployee(employee & e)
    {
      if (e.getLevel() == NONE)
      {
        printf("Unassigned Employee!\n");
        return;
      }

      employees[e.getLevel()].push_back(e);
    }

    void createCall(string name, call *& c)
    {
      c = new call(name);
      calls.push_back(c);
    }

    int numCalls()
    {
      return calls.size();
    }

  private:

    deque<deque<employee>> employees;
    deque<call*> calls;
};
////////////////////////////////////////////////////////////////////////////////


int main()
{
  respondent r1("Joe");
  respondent r2("Joel");
  respondent r3("Joseph");
  respondent r4("Geoff");
  respondent r5("James");
  respondent r6("Jamal");
  manager m1("Adam");
  manager m2("Adrian");
  manager m3("Finn");
  manager m4("Balor");
  director d1("Xavier");
  director d2("Pat");
  director d3("George");

  callCenter myCallCenter;
  myCallCenter.addEmployee(r1);
  myCallCenter.addEmployee(r2);
  myCallCenter.addEmployee(r3);
  myCallCenter.addEmployee(r4);
  myCallCenter.addEmployee(r5);
  myCallCenter.addEmployee(r6);
  myCallCenter.addEmployee(m1);
  myCallCenter.addEmployee(m2);
  myCallCenter.addEmployee(m3);
  myCallCenter.addEmployee(m4);
  myCallCenter.addEmployee(d1);
  myCallCenter.addEmployee(d2);
  myCallCenter.addEmployee(d3);

  call *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8, *c9, *c10;

  myCallCenter.createCall("Bob", c1);
  myCallCenter.createCall("Sam", c2);
  myCallCenter.createCall("Adrian", c3);
  myCallCenter.createCall("Alexander", c4);
  myCallCenter.createCall("Wade", c5);
  myCallCenter.createCall("Jimmy", c6);
  myCallCenter.createCall("Jackson", c7);
  myCallCenter.createCall("Patrick", c8);
  myCallCenter.createCall("Timmy", c9);
  myCallCenter.createCall("Ulysses", c10);

  cout << "Number of calls " << myCallCenter.numCalls() << endl;
  while (myCallCenter.numCalls() > 0)
  {
    myCallCenter.dispatchCall();
  }

  myCallCenter.reassignCall(c1); 
  myCallCenter.reassignCall(c4);

  return 0;
}
