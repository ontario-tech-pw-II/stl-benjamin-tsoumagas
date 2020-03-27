// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{  

	// Write your code for Task 1
    list<Student> c;
    Student s1("John", 86);
    Student s2("Ben", 80);
    Student s3("Sam", 90);

    list<Student>::iterator i;

    i = c.begin();

    c.push_back(s1);
    c.push_back(s2);
    c.push_back(s3);
    
    for (i = c.begin(); i != c.end(); i++){
        cout << *i << endl;
    }

    //cout << c.size() << endl;
		
}