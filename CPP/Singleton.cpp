/*============================================================================================================
Brief  : Singleton class Program
		 Singleton is a design pattern which restricts the creation of objects to one instances.
		 No matter how many objects are created there will be only one instance
Author : Karthick

Compiled and build using Visual Studio 2022 community
==============================================================================================================*/
#include <iostream>

using namespace std;

//==================================================================
// C L A S S   D E C L A R A T A I O N
//==================================================================
class Singleton {
private:
    //Making the constructor of the class private to avoid object creation from outside the class
	Singleton() {}
	
	/*
	The instance of the class which will be used by the objects created.
    All the objects of the class will only use this instance to access the members & functions.
	Static ensures that there will be once insatnce shared across all the objects.
	*/
	static Singleton* m_spSingleton;

	float m_fVar;
	std::string m_strVar;
	
public:
    //A static function for calling the constructor and create the instance of the class
	static Singleton* Instance();
	
	//Restrict the copy constructor and copy assignment operator.
	//The below 2 functions can be used to create a copy of the instance which would defy the singleton principle.
	Singleton(const Singleton& obj) = delete;
	void operator=(const Singleton& obj) = delete;
	
	//Functions to access the class members
	void SetVariable(float var, std::string str);
	
	float GetFloatVariable() const {
		return m_fVar;
	}
	
	std::string GetStringVariable() const {
		return m_strVar;
	}
};

//Initialize the static object here
Singleton* Singleton::m_spSingleton = NULL;

//==================================================================
// D E F I N I T I O N 
//==================================================================

Singleton* Singleton::Instance()
{
	//Need to be locked
	if (m_spSingleton == NULL) {
		m_spSingleton = new Singleton();
	}
	return m_spSingleton;

}

void Singleton::SetVariable(float var, std::string str)
{
	m_fVar = var;
	m_strVar = str;
}

//===================================================================
// M A I N   F U N C T I O N
//===================================================================
int main()
{
	//Create an object of the class 
	Singleton* SingObj = Singleton::Instance();
	SingObj->SetVariable(12.5, "String");
	cout << "SingObj float var : " << SingObj->GetFloatVariable() << endl;
	cout << "SingObj string var : " << SingObj->GetStringVariable() << endl;
	
	//Create a second object of the class
	Singleton* SingObj2 = Singleton::Instance();
	cout << "SingObj2 string var : " << SingObj2->GetStringVariable() << endl;
	return 0;
}