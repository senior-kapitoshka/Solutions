#include <iostream>
#include <regex>
#include <fmt/format.h>
#include <fstream>
#include <algorithm>
#include <iterator>

class Person {
  // variables
  int ag;
  std::string nam;
  char gend;
  std::string info;
  std::string lin;
public:
	Person(const std::string& line)
  : lin(line)
  {
    std::regex r("([\\w]*);([m|w]{1});([\\d]*)");
    std::smatch m;
    std::regex_search(line,m,r);
    nam=m[1];
    gend=m[2].str().front();
    ag=std::stoi(m[3]);
  }	
	std::string print() const {return lin;} // "name;gender;age;"
	std::string writeString() const {return fmt::format("{};{}",nam,ag);} // "name;age"
	char gender() const {return gend;}
	std::string name() const {return nam;}
	friend std::ostream& operator<<(std::ostream& os, const Person& p) {
    os<<p.print();
    return os;
  }
	int age() {return ag;}
};

class Worker {
public:
	// reads line by line from file (from "path")
	// transform line to person
	// return vector with persons
	static std::vector<Person> readItems(const std::string &path){
    std::ifstream in;
    in.open(path);
    std::vector<Person> vp;
    for(std::string s;std::getline(in,s);){
      vp.emplace_back(s);
    }
    in.close();
    return vp;
  }

	// writes persons into filePath
	// every person is stored like ("name;gender;age;")
	static void writeAllItems([[maybe_unused]]const std::vector<Person> &v, [[maybe_unused]]const std::string &filePath){
    std::ofstream on;
    on.open(filePath);
    std::copy(v.begin(),v.end(),std::ostream_iterator<Person>(on,"\n"));
    on.close();
  }
  
	 // This function is used to show value information from persons in a vector
	 // show info about person by using print()
   // show one person per one line
	 static void showItems([[maybe_unused]]const std::vector<Person> &v){
     std::copy(v.begin(),v.end(),std::ostream_iterator<Person>(std::cout,"\n"));
   }

 	 // writes persons splitted by gender either to file on "pathMen" or to file on "pathWomen"
	// per line only name and gender are stored ("name;age;")
	static void writeSplitedItems([[maybe_unused]]const std::vector<Person> &v, [[maybe_unused]]const std::string &pathMen, [[maybe_unused]]const std::string &pathWomen){
    std::ofstream mon(pathMen);
    std::ofstream won(pathWomen);
    std::for_each(v.begin(),v.end(),[&mon,&won](auto& p){
      p.gender()=='m'?mon<<p.writeString()<<"\n":won<<p.writeString()<<"\n";
    });
    mon.close();
    won.close();
  }

};

/////////////////////////

#include <iostream>
#include <fstream>

class Person {
  std::string name_;
  char gender_;
  int age_;
public:
	Person(const std::string& l) {
    size_t p1 = l.find(';');size_t p2 = l.find(';', p1 + 1);
    if (p1 != std::string::npos && p2 != std::string::npos) {
      name_ = l.substr(0, p1);
      gender_ = l[p1 + 1];
      age_ = std::stoi(l.substr(p2 + 1));
    } else { name_ = "";gender_ = 'X';age_ = 0; }
  }
	std::string print() const {return name_ + ';' + gender_ + ';' + std::to_string(age_) + ';';} // "name;gender;age;"
	std::string writeString() const {return name_ + ';' + std::to_string(age_);} // "name;age"
	char gender() const {return gender_;}
	std::string name() const {return name_;}
	friend std::ostream& operator<<(std::ostream& os, const Person& p) {os << p.print();return os;}
	int age() {return age_;}
};


class Worker {
public:
	// reads line by line from file (from "path")
	// transform line to person
	// return vector with persons
	static std::vector<Person> readItems(const std::string &path){
    std::vector<Person> people;
    std::ifstream f(path);
    
    if (f.is_open()) {
      std::string l;
      while (std::getline(f, l)){
        Person p = Person(l);
        people.push_back(p);
      } f.close();
    } else { std::cerr << "Error: Unable to open file" << path << std::endl; }
    
    
    return people;
  }

	// writes persons into filePath
	// every person is stored like ("name;gender;age;")
	static void writeAllItems(const std::vector<Person> &v, const std::string &filePath) {
    std::ofstream out(filePath);
    
    if (out.is_open()) {
      for (const Person& p : v) {
        out << p.print() << "\n";
      }out.close();
    } else {
      std::cerr << "Unable to open file " << filePath << std::endl;
    }
  }
  
	 // This function is used to show value information from persons in a vector
	 // show info about person by using print()
   // show one person per one line
	 static void showItems(const std::vector<Person> &v) {
     for (const Person& p : v) {
       std::cout << p.print() << "\n";
     }
   }

 	 // writes persons splitted by gender either to file on "pathMen" or to file on "pathWomen"
	// per line only name and gender are stored ("name;age;")
	static void writeSplitedItems(const std::vector<Person> &v, const std::string &pathMen, const std::string &pathWomen) {
    std::ofstream outM(pathMen);
    std::ofstream outW(pathWomen);
    
    if (outM.is_open() && outW.is_open()) {
      for (const Person& p : v) {
        if (p.gender() == 'm') {
          outM << p.writeString() << '\n';
        } else if (p.gender() == 'w'){
          outW << p.writeString() << '\n';
        }
      }outM.close();outW.close();
    } else {
      std::cerr << "Error unable to open files";
    }
  }
};

///////////////////////


#include <iostream>

class Person {
private:
  std::string m_name;
  char m_gender;
  int m_age;
public:
	Person(const std::string& line) { m_name = line.substr(0, line.find(";")); m_gender = line[line.find(";") + 1]; m_age = stoi(line.substr(line.find(";") + 3)); }	
	std::string print() const { return m_name + ";" + m_gender + ";" + std::to_string(m_age) + ";"; }
	std::string writeString() const { return m_name + ";" + std::to_string(m_age); }
	char gender() const { return m_gender; }
	std::string name() const { return m_name; }
	friend std::ostream& operator<<(std::ostream& os, const Person& p) { os << p.print(); return os; }
	int age() { return m_age; }
};

class Worker {
public:
	// reads line by line from file (from "path")
	// transform line to person
	// return vector with persons
	static std::vector<Person> readItems(const std::string &path) {
    std::vector<Person> persons;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line))
      persons.emplace_back(line);
    return persons;
  }

	// writes persons into filePath
	// every person is stored like ("name;gender;age;")
	static void writeAllItems(const std::vector<Person> &v, const std::string &filePath) {
    std::ofstream file(filePath);
    for (size_t i = 0; i < v.size(); i++)
      file << v[i].print() << std::endl;
  }
  
	 // This function is used to show value information from persons in a vector
	 // show info about person by using print()
   // show one person per one line
	 static void showItems(const std::vector<Person> &v) {
    for (size_t i = 0; i < v.size(); i++)
      std::cout << v[i].print() << std::endl;
   }

 	 // writes persons splitted by gender either to file on "pathMen" or to file on "pathWomen"
	// per line only name and gender are stored ("name;age;")
	static void writeSplitedItems(const std::vector<Person> &v, const std::string &pathMen, const std::string &pathWomen) {
    std::ofstream fileMen(pathMen), fileWomen(pathWomen);
    for (size_t i = 0; i < v.size(); i++)
      (v[i].gender() == 'm' ? fileMen : fileWomen) << v[i].writeString() << std::endl;
  }

};

//////////////////
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class Person {
private:
  std::string _name;
  char _gender;
  int _age;
  
public:
	Person(const std::string& line){
    std::istringstream ss(line);
    std::getline(ss, _name, ';');
    ss>>_gender;
    ss.ignore();
    ss>>_age; 
  }
  
	std::string print() const {
    return _name + ";" + _gender + ";" + std::to_string(_age) + ";";
  } // "name;gender;age;"
  
	std::string writeString() const {
    return _name + ";" + std::to_string(_age);
  } // "name;age"
  
	char gender() const {
    return _gender;
  }
  
	std::string name() const {
    return _name;
  }
  
	friend std::ostream& operator<<(std::ostream& os, const Person& p) {
    os<<p.print();
    return os;
  }
  
	int age() {
    return _age;
  }
};

class Worker {
public:
  
	static std::vector<Person> readItems(const std::string &path){
    std::vector<Person> people;
    std::ifstream file(path);
    if(!file){
      std::cerr<<"Error!"<<std::endl;
      return people;
    }
    std::string line;
    while(std::getline(file, line)){
      people.emplace_back(line);
    }
    file.close();
    return people;
  }

	// writes persons into filePath
	// every person is stored like ("name;gender;age;")
	static void writeAllItems(const std::vector<Person> &v, const std::string &filePath){
    std::ofstream file(filePath);
    if(!file){
      std::cerr<<"Error!"<<std::endl;
      return;
    }
    
    for (const Person& person : v){
      file<<person.print()<<std::endl;
    }
    file.close();
  }
  
	 // This function is used to show value information from persons in a vector
	 // show info about person by using print()
   // show one person per one line
	 static void showItems(const std::vector<Person> &v){
     for(const Person& person : v){
       std::cout<<person.print()<<std::endl;
     }
   }

 	 // writes persons splitted by gender either to file on "pathMen" or to file on "pathWomen"
	// per line only name and gender are stored ("name;age;")
	static void writeSplitedItems(const std::vector<Person> &v, const std::string &pathMen, const std::string &pathWomen){
    std::ofstream fileMen(pathMen);
    std::ofstream fileWomen(pathWomen);
    
    if(!fileMen || !fileWomen){
      std::cerr<<"Error!"<<std::endl;
      return;
    }
    
    for(const Person& person : v){
      if(person.gender()=='m'){
        fileMen<<person.writeString()<<std::endl;
      }
      else if(person.gender()=='w'){
        fileWomen<<person.writeString()<<std::endl;
      }
    }
    
    fileMen.close();
    fileWomen.close();
  }

};

////////////////////////
