/*============================================================================================================
Brief  : Program for constructor, copy constructor and copy assignment operator
Author : Karthick

Compiled and build using Visual Studio 2022 community
==============================================================================================================*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define MAX_SIZE 20
//===================================================================================
//D E C L A R A T I O N
//===================================================================================

class Constructor {
	
private:
	int m_intVal;
	std::string m_strVal;
	char* m_pCharVal;
	
public:
	//Default constructor : Does not initilaize any of the class members.
	//Only responsible for object creation
	Constructor();
	
	//Initialized/Parameterized constructor
	//Creates an object and Initilaizes all or some of the members for the object.
	Constructor(int value, std::string cPtr);
	
	//Copy constructor
	//To copy the contents of one object to the other
	//The argument should be a constant reference.
	//constant  : Complier generates a temporary object which cannot be assigned to non-const reference
	//reference : Copy constructor is called when value is passed. If argument is not reference than
	//            it will further invoke a copy constructor which can lead to infinite invoking of constructor
	Constructor(const Constructor& copyConstr);
	
	//Copy Assignment
	//Similar ot copy constructor the argument should be constant reference
	//Need not necessarily return the object.
	//The beow syntax is particularly useful when copying multiple objects a = b = c;
	void operator=(const Constructor& assgnConstr);
	
	//Prints the members of the object
	void PrintVal();
	
	//To set the value fo the members
	void SetVal(int value, std::string str);

	//Destructor
	~Constructor();
};

//==================================================================================================
// D E F I N I T I O N
//==================================================================================================
Constructor::Constructor()
{
	cout << "Default constructor" << endl;
    }
    
Constructor::Constructor(int val, std::string str)
{
	cout <<"Parameterized constructor : "<< this << endl;
	m_intVal = val;
	m_strVal = str;
	m_pCharVal = new char[20];
	strncpy_s(m_pCharVal, MAX_SIZE, str.c_str(), MAX_SIZE);
}
    
Constructor::Constructor(const Constructor& constr)
{
	cout << "Copy Constructor : " << endl;
	m_intVal = constr.m_intVal;
	m_strVal = constr.m_strVal;
	//default copying behavior and this should cause the program to crash during object destruction.
	//When the destructo is called the same memory location will be deleted twice which causes the crash
	m_pCharVal = constr.m_pCharVal;
}
    
void Constructor::operator=(const Constructor& constr)
{
	cout << "Copy assignment operator : " << endl;
	m_intVal = constr.m_intVal;
	m_strVal = constr.m_strVal;
	//Allocating a memory and then assigning the value to be copied.
	//This way the copy and the actual value will have different memory locations
	m_pCharVal = new char[MAX_SIZE];
	strncpy_s(m_pCharVal, MAX_SIZE, constr.m_pCharVal, strlen(constr.m_pCharVal));  //Assigning memory and copying the value
}
    
void Constructor::PrintVal()
{
	cout << "Int value : " << m_intVal <<"\tString Value : " <<m_strVal << "\tChar Value : " << m_pCharVal << endl;
}
    
void Constructor::SetVal(int value, std::string str)
{
	m_intVal = value;
	m_strVal = str;
	strncpy_s(m_pCharVal, MAX_SIZE, str.c_str(), strlen(str.c_str()));
}	

Constructor::~Constructor()
{
	if (m_pCharVal != NULL) {
		cout << "Destructing object" << endl;
		delete m_pCharVal;
		m_pCharVal = NULL;
	}
}

int main()
{
    cout << "Main function" << endl;
    Constructor Obj;
    Constructor Obj2 = Constructor();
    Constructor param(2, "Sample String");
    param.PrintVal();
	//Calling the copy constructo using method 1 (direct initialization)
    cout << "Copy constructor Method 1 called" << endl;
    Constructor copyConst = param;
    copyConst.PrintVal();
	//Calling the copy constructo using method 2 (passing the object as a parameter to constructor)
    cout << "Copy constructor method 2 called" << endl;
    Constructor copyConst2(param);
    copyConst2.PrintVal();
    cout << "Copy assignment operator called" << endl;
    Constructor assgConst;
    assgConst = param;
    assgConst.PrintVal();
    cout << "Modifying the values of param object" << endl;
    param.SetVal(10, "New String");
    cout << "Modified constructor value" << endl ;
    param.PrintVal();
	//The modified value of m_pCharVal of the param and the copy constructor will point to the same meory location
    cout << "Copy Constructor Value" << endl;
    copyConst.PrintVal();
	//The value of m_pCharVal of copy assignment object will be different
    cout << "Copy assignment value" << endl;
    assgConst.PrintVal();
    return 0;
	//On destruction of the object the program should crash here
}