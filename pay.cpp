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
#include<vector>

void readData(vector<Person> &a);
void writeData(vector<Person> &a);

int main()
{
  // fstream h;
  // h.open("input.txt");
  vector<Person> a;
  //int size=0;
  //Person employees[20];
  readData(a);
  writeData(a);
  return 0;
}

void readData(vector<Person> &a)
{
  string fname,lname;
  double workedHours=0;
  double payRate = 0;
  ifstream input;
  input.open("input.txt");
  while(input>>fname>>lname>>workedHours>>payRate)
  {
    // Person p;
    // p.setFirstName(fname);
    // p.setLastName(lname);
    // p.setHoursWorked(workedHours);
    // p.setPayRate(payRate);
    // employees[size]=p;
    // size++;
    a.emplace_back(Person(fname,lname,workedHours,payRate));
  }
  input.close();
}

void writeData(vector<Person> &a)
{
  ofstream output;
  output<<setprecision(2)<<fixed;
  output.open("output.txt");
  for(int x=0;x<a.size();x++)
  {
    //cout << a.at(x).fullName() << a.at(x).totalPay() << endl;
    output<<a.at(x).fullName()<<" "<<a.at(x).totalPay()<<endl;
  }
  output.close();
}
