// INTRODUCTION
// Some basic terms:
// 
// Declaration vs Defintion vs Prototype vs Initialization
// 
// -Declaration- means telling the compiler that a variable, function, or class exists, without actually
// defining what it is. For classes, the declaration includes declarations and definitions of all member
// data. In lieu of this, one can also use a -forward declaration-, declaring only the name. There is
// some disagreement on what constitutes a class declaration; properly speaking, only forward
// declarations are declarations. A function declaration is called a -function prototype-. 

extern int var; // extern is used to declare a variable
double func(int, float); // Function prototype
class obj; // Class forward declaration

// -Definition- means to actually implement or instantiate the identifier, so that it can be
// used in the program. A variable doesn't need a value, but can't be externed, and a function must be
// given a body. A function definition is called its -implementation-. 

int var;
double func(int x, float y) { return x + y; } // Function implementation
class obj { }; // Class definition

// -Initialization- provides an initial value to a variable. 
// 
// An identifier can typically be declared many times with no issue. However, it can be defined only once.
// In projects, class definitions and any or all declarations are placed in header files, and definitions 
// and implementations are placed in source files.

// DEFINITION OF CLASSES
// What needs to be declared and defined with class members, especially during inheritance, is important
// to understand. 
//
// A class or struct can have the following members:
// 	Special member functions (constructors, destructor, assignment operator)
//	Member functions (methods)
//	Data members
//	Operators
//	Bested class declarations
//	Unions
//	Enums
//	Bit fields
//	Aliases, typedefs
//	Friends (not members, but included in class definition)
// 
// Member functions and data can be:
// 	Public
// 	Private
// 	Protected
// 	Virtual
// 	Static - shared among objects (for data) or only accesses static data (functions)
// 
// Be sure to pay attention to static class members. Static member data is shared amongst all objects of
// that class, and they are required to be -initialized-, not just defined, and must be initialized
// -outside- of the class definition. Static member functions can only access the static member data, 
// they are methods that specifically work with static data.
// 
// Here's a guide to declaration, definition, and initialization.
// 	Base class
//		A class that will be used as a base class must be defined (forward declaration
//		is not enough) before derived classes try to implement it. 
//
// 	Public data, private data
// 		Declared with class definition, initialized in class definition or class constructor
// 		or constructor initializer list. In initializer list, data is initialized in order
// 		of -declaration- not the order of the list.
//	
// 	Public functions, private functions
// 		Prototype with class definition, implementation can be inside class (treated as inline) or
// 		outside the class using the scope-resolution operator (::). Many prototypes are allowed,
// 		but the functions themselves can only be implemented once. Functions can be prototyped
// 		and implemented in derived classes without causing problems.
//
// 	Virtual public/protected functions
// 		Prototype in base class uses virtual keyword, implementation outside of class definition 
// 		does not, can be implemented the same way as non-virtual data. Virtual functions in base
// 		class do not need a definition (they can be pure virtual functions). In derived class, no
// 		virtual keyword is necessary unless further overloading is expected, any overloaded
// 		functions must be declared again to be redefined. Virtual or even pure virtual functions
// 		do not need to be overloaded, but a class with pure virtual functions is always abstract
// 		and must be made concrete with further derived classes. Inherited functions that are
// 		not overridden do not need to be declared. 
//
// 	Static data
// 		Declared in class definition, must be defined -and- initialized at file scope, outside of
// 		class definition. Static keyword is needed in declaration, not needed in definition. Type
// 		is needed for both. Derived static data does not need to be redeclared or redefined, and
// 		will be the same variable (static variable is shared with all objects in base and derived
// 		classes). 
// 	
// 	Static functions
// 		Cannot be virtual. Static keyword required in declaration, otherwise is the same as other
// 		member functions for definition and inheritance (no static required in definition).
//
// 	Const data
//		Data that is declared const must be initialized in a constructor initializer list. Data
//		that is const outside of a class must be initialized at declaration. If const membder
//		data is also static, it can be initialized directly in the class definition, but only
//		if it is an int type, otherwise it is initialized like other static data, with a const
//		in the initialization.
//
// 	Const functions
// 		Const methods have const in the declaration and definition, going -after- the parameter
// 		list. Otherwise, it is implemented the same as other class methods. Inherited const
// 		methods can be either const or not. 
//


// VIRTUAL FUNCTIONS
// The reason for using virtual is not only to allow overriding, but rather it is to allow us to use 
// pointers and references of the base class type, and refer to the derived class's methods when pointing
// to that derived class.

// Component has one virtual member function and one non-virtual member function.
class Component
{
public:
	Component() {};
	~Component() {};

	virtual void printname() { std::cout << "Component \n"; }
	void printvoltage() { std::cout << "No voltage here \n"; }
};

// A derived class Resistor will inherit Component
class Resistor : public Component
{
public:
	Resistor() {}; // Note: This constructor is called, then the base class constructor is called
	~Resistor() {};

	void printname() { std::cout << "Resistor \n"; }
	void printvoltage() { std::cout << "V = 5.02V \n"; }
};

// Now over in main(), let's try making some objects and pointers. 
int main()
{
	// Basic objects
	Component generic1;
	Resistor res1;

	Component* cptr = &res1; // Pointer to base class, points to derived class
	
	// Now we can try to print out from the objects and from the pointer. 
	generic1.printname();		// "Component"
	generic1.printvoltage();	// "No voltage here"

	res1.printname();	// "Resistor"
	res1.printvoltage();	// "V = 5.02V"

	// Even though we didn't declare printvoltage as virtual, it was overridden. The reason we
	// need virtual follows from the Component-type pointer pointing to the resistor.
	cptr->printname();	// "Resistor"
	cptr->printvoltage();	// "No voltage here"

	// The Component pointer resolved the overridden printname() but used the printvoltage() from
	// Component instead of Resistor, even though Resistor had its own printvoltage().

	return 0;
}

// SCOPE, FORWARD-DECLARATION, HEADER FILES
// Understanding what's in scope and what isn't will save many headaches. The six general types of scope
// are:
// 	Global
// 	 - File, translation-unit
// 	Namespace
// 	Local
// 	Class
// 	Statement
// 	Function
// Identifiers have scope. Global scope means they are accessible through the entire program, by being
// declared outside of any block, namespace, or class. File scope means that the identifier is declared
// in a file, outside of any block. If that file is included, or includes other files, the scope is
// shared across all of them, and it is called translation unit scope (a translation unit is the unrolled
// version of the file after includes are put in). An identifier with global scope is shared across 
// all files whether they are in the same translation unit or not, using extern.
//
// The other types of scope should be more or less clear. 
//
// Headers are files that only have declarations, class definitions, include guards, and includes. A
// header file must be safe to run several times, because it is often included several times. That 
// means definitions should be avoided. Inline function definitions (such as those implemented in a
// class which are inline by default) are safe. Inline functions actually place a copy of the code
// for a method whenever it is called. At least, the inline keyword recommends it to the compiler.
//
// When dynamically allocating data, using new, the data is stored on the heap and a pointer to it is
// returned. The pointer scope is no different from any other static data. The memory on the heap will
// be freed when the pointer is deleted with delete. Otherwise you'll have a memory leak (data is not
// cleared after execution). If you don't manage your data, e.g. by "losing" the pointer before deleting,
// you'll also have a memory leak. Use smart pointers to avoid this. 

// RETURN OBJECTS AND REFERENCES
// The object returned by a function is not a proper object, but a temporary object, which is destroyed at the
// end of the current expression. This is very important to understand, so we'll do an example.

// With this function, a string is returned
std::string getNewString() { return "this is a new string"; }

// When using the function, first a string is returned, then it is used to construct a new string, and then it is
// deleted.
std::string mystr = getNewString(); // mystr will copy "this is a new string", it's NOT the same object

// This example is not too interesting, because functionality isn't effected. 

