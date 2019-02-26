#include <iostream>
#include <fstream>
#include <cstdlib>
#include "person.cpp"
#include "person.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<string>

void readData(Person employees[],int &size);
void writeData(Person employees[],int size);

int main()
{
  int size=0;
  Person employees[20];
  readData(employees,size);
  writeData(employees,size);
  return 0;
}

void readData(Person employees[],int &size)
{
  string fname,lname;
  double workedHours,payRate;
  ifstream input;
  input.open("input.txt");

  while(input>>fname>>lname>>workedHours>>payRate)
  {
    Person p;
    p.setFirstName(fname);
    p.setLastName(lname);
    p.setHoursWorked(workedHours);
    p.setPayRate(payRate);
    employees[size]=p;
    size++;
  }
  input.close();
}

void writeData(Person employees[],int size)
{
  ofstream output;
  output<<setprecision(2)<<fixed;
  output.open("output.txt");
  for(int x=0;x<size;x++)
  {
    output<<employees[x].fullName()<<" "<<employees[x].totalPay()<<endl;
  }
  output.close();
}
