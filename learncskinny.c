////////////////////////////////////////////////////////////////////
//LANGUAGE REFERENCE INFO
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

		// Constants: #define <keyword>
		// Constants are written in all-caps out of convention, not requirement
		#define DAYS_IN_YEAR 365

		// Enumeration constants are also ways to declare constants.
		// All statements must end with a semicolon
		enum days {SUN = 1, MON, TUE, WED, THU, FRI, SAT};
		// MON gets 2 automatically, TUE gets 3, etc.


		// Declare function signatures in advance in a .h file, or at the top of
		// your .c file.
		void function_1();
		int function_2(void);

		// Must declare a 'function prototype' before main() when functions occur after
		// your main() function.
		int add_two_ints(int x1, int x2); // function prototype
		// although `int add_two_ints(int, int);` is also valid (no need to name the args),
		// it is recommended to name arguments in the prototype as well for easier inspection

		///////////////////////////////////////
		// Types
		///////////////////////////////////////

		// All variables MUST be declared at the top of the current block scope
		// we declare them dynamically along the code for the sake of the tutorial

		// ints are usually 4 bytes
		int x_int = 0;

		// shorts are usually 2 bytes
		short x_short = 0;

		// chars are guaranteed to be 1 byte
		char x_char = 0;
		char y_char = 'y'; // Char literals are quoted with ''

		// longs are often 4 to 8 bytes; long longs are guaranteed to be at least
		// 64 bits
		long x_long = 0;
		long long x_long_long = 0;

		// floats are usually 32-bit floating point numbers
		float x_float = 0.0f; // 'f' suffix here denotes floating point literal

		// doubles are usually 64-bit floating-point numbers
		double x_double = 0.0; // real numbers without any suffix are doubles

		// integer types may be unsigned (greater than or equal to zero)
		unsigned short ux_short;
		unsigned int ux_int;
		unsigned long long ux_long_long;

		// chars inside single quotes are integers in machine's character set.
		'0'; // => 48 in the ASCII character set.
		'A'; // => 65 in the ASCII character set.

		// sizeof(T) gives you the size of a variable with type T in bytes
		// sizeof(obj) yields the size of the expression (variable, literal, etc.).
		printf("%zu\n", sizeof(int)); // => 4 (on most machines with 4-byte words)

		// If the argument of the `sizeof` operator is an expression, then its argument
		// is not evaluated (except VLAs, see below).
		// The value it yields in this case is a compile-time constant.
		int a = 1;
		// size_t is an unsigned integer type of at least 2 bytes used to represent
		// the size of an object.
		size_t size = sizeof(a++); // a++ is not evaluated


		/////////////////////////////////////////////////
		//Operators
		/////////////////////////////////////////////////
		// Logic works on ints
		!3; // => 0 (Logical not)
		!0; // => 1
		1 && 1; // => 1 (Logical and)
		0 && 1; // => 0
		0 || 1; // => 1 (Logical or)
		0 || 0; // => 0

		// Conditional ternary expression ( ? : )
		int e = 5;
		int f = 10;
		int z;
		z = (e > f) ? e : f; // => 10 "if e > f return e, else return f."

		// Bitwise operators!
		~0x0F; // => 0xFFFFFFF0 (bitwise negation, "1's complement", example result for 32-bit int)
		0x0F & 0xF0; // => 0x00 (bitwise AND)
		0x0F | 0xF0; // => 0xFF (bitwise OR)
		0x04 ^ 0x0F; // => 0x0B (bitwise XOR)
		0x01 << 1; // => 0x02 (bitwise left shift (by 1))
		0x02 >> 1; // => 0x01 (bitwise right shift (by 1))

		// Be careful when shifting signed integers - the following are undefined:
		// - shifting into the sign bit of a signed integer (int a = 1 << 31)
		// - left-shifting a negative number (int a = -1 << 2)
		// - shifting by an offset which is >= the width of the type of the LHS:
		//   int a = 1 << 32; // UB if int is 32 bits wide



		///////////////////////////////////////
		// Typecasting
		///////////////////////////////////////

		// Every value in C has a type, but you can cast one value into another type
		// if you want (with some constraints).

		int x_hex = 0x01; // You can assign vars with hex literals

		// Casting between types will attempt to preserve their numeric values
		printf("%d\n", x_hex); // => Prints 1
		printf("%d\n", (short) x_hex); // => Prints 1
		printf("%d\n", (char) x_hex); // => Prints 1

		// Types will overflow without warning
		printf("%d\n", (unsigned char) 257); // => 1 (Max char = 255 if char is 8 bits long)

		// For determining the max value of a `char`, a `signed char` and an `unsigned char`,
		// respectively, use the CHAR_MAX, SCHAR_MAX and UCHAR_MAX macros from <limits.h>

		// Integral types can be cast to floating-point types, and vice-versa.
		printf("%f\n", (float)100); // %f formats a float
		printf("%lf\n", (double)100); // %lf formats a double
		printf("%d\n", (char)100.0);


///////////////////////////////////////
// SPECIFIC TOPICS
///////////////////////////////////////
///////////////////////////////////////


///////////////////////////////////////
// Pointers
///////////////////////////////////////

// A pointer is a variable declared to store a memory address. Its declaration will
// also tell you the type of data it points to. You can retrieve the memory address
// of your variables, then mess with them.

// Pointers start with * in their declaration
int x = 0; //Int that will be pointed to

int *px, not_a_pointer; // px is a pointer to an int
px = &x; // Stores the address of x in px

std::cout << px << endl;// => Prints some address in memory

// To retrieve the value at the address a pointer is pointing to,
// put * in front to dereference it.
// Note: yes, it may be confusing that '*' is used for _both_ declaring a
// pointer and dereferencing it. 
std::cout << *px << endl; // => Prints 0, the value of x 

// NOTE: It is more appropriate to say that we have the pointer types:
int *;	//A pointer type
// Which define pointer variables which store addresses:
int * x; //Declar x
x; 	//A pointer variable
// And those pointer variables can be dereferenced to their location's value:
*x;	//The value in memory that x is pointing to
// So when you're assigning things to pointers, be careful that this:
int * x = &y;
//Means "pointer x points to the address of y", and this:
x = &y;
//Assigns a pointer object to a location, while this:
*x = &y;
//Means "value in memory that was pointed to is now assigned a memory address", 
// and unless x is pointing to another pointer, this isn't going to work. An int
// won't properly hold a memory address.

//This becomes really important when dealing with pointers as parameters/returns for functions,
// where the function will be defined and prototyped with the pointer type:
int * pointerFunction()
{
	return &g;	//Returns an address. Note that 'g' must be outside the function scope 
				// i.e. not defined in pointerFunction()
	return x;	//A pointer being returned. Note that it is not dereferenced. Also note that
				//whatever 'x' is _pointing_ to must be outside the function scope or else the
				//memory will be garbage. 
}

int notPointerFunction()
{
	return *x;	//'x' is dereferenced to return an int value, not a pointer value. Assuming
				// here that x is pointing to an int. 
}

void pointerParameterFunction(int *)
{
	return;
}
void notPointerParamFunc(int)
{
	return;
}
int y = 2;
int * x = &y;
pointerParameterFunction(x);	//The pointer x is sent in, not dereferenced
notPointerParamFunc(*x);		//The value that x is pointing to, 2, is sent as x is dereferenced


// Arrays are a good way to allocate a contiguous block of memory
int x_array[20]; //declares array of size 20 (cannot change size)
// Initialize x_array to 20, 19, 18,... 2, 1
for (int xx = 0; xx < 20; xx++) {
x_array[xx] = 20 - xx;
} 
//This array object is actually a pointer, that is dereferenced to whatever [x]. It points to the 
// start of the array and the bracket is like an offset. So we can assign pointers to the array object.

// Declare a pointer of type int and initialize it to point to x_array
int* x_ptr = x_array;
// x_ptr now points to the first element in the array (the integer 20).
// This works because arrays often decay into pointers to their first element.
// For example, when an array is passed to a function or is assigned to a pointer,
// it decays into (implicitly converted to) a pointer.

// Exceptions: when the array is the argument of the `&` (address-of) operator:
int arr[10];
int (*ptr_to_arr)[10] = &arr; // &arr is NOT of type `int *`! (i.e. it is not a pointer to an integer)
// It's of type "pointer to array" (of ten `int`s).
// or when the array is a string literal used for initializing a char array:
char otherarr[] = "foobarbazquirk";
// or when it's the argument of the `sizeof` or `alignof` operator:
int arraythethird[10];
int *ptr = arraythethird; // equivalent with int *ptr = &arr[0];
printf("%zu, %zu\n", sizeof arraythethird, sizeof ptr);
// probably prints "40, 4" or "40, 8"

// Pointers are incremented and decremented based on their type
// (this is called pointer arithmetic)
printf("%d\n", *(x_ptr + 1)); // => Prints 19
printf("%d\n", x_array[1]); // => Prints 19

// You can also dynamically allocate contiguous blocks of memory with the
// standard library function malloc, which takes one argument of type size_t
// representing the number of bytes to allocate (usually from the heap, although this
// may not be true on e.g. embedded systems - the C standard says nothing about it).
int *my_ptr = malloc(sizeof(*my_ptr) * 20);
for (xx = 0; xx < 20; xx++) {
*(my_ptr + xx) = 20 - xx; // my_ptr[xx] = 20-xx
} // Initialize memory to 20, 19, 18, 17... 2, 1 (as ints)

// Note that there is no standard way to get the length of a
// dynamically allocated array in C. Because of this, if your arrays are
// going to be passed around your program a lot, you need another variable
// to keep track of the number of elements (size) of an array. See the
// functions section for more info.
int size = 10;
int *my_arr = malloc(sizeof(int) * size);
// Add an element to the array
my_arr = realloc(my_arr, ++size);
my_arr[10] = 5;

// Dereferencing memory that you haven't allocated gives
// "unpredictable results" - the program is said to invoke "undefined behavior"
printf("%d\n", *(my_ptr + 21)); // => Prints who-knows-what? It may even crash.

// When you're done with a malloc'd block of memory, you need to free it,
// or else no one else can use it until your program terminates
// (this is called a "memory leak"):
free(my_ptr);

//////////////////////////////////////////////
// References
//////////////////////////////////////////////
//It can often be troublesome to pass large objects to functions in C++. Instead,
// you'll want to pass a pointer to the object, which can be used _as_ the object.
// Most of the time, this is the only option. Thus came into being: References.

// In addition to pointers like the ones in C,
// C++ has _references_.
// These are pointer types that cannot be reassigned once set
// and cannot be null.
// They also have the same syntax as the variable itself:
// No * is needed for dereferencing and
// & (address of) is not used for assignment of an address.

// Thus we get the reference type:
int& ;		// A reference to an integer
string& ;	// To a string
char& ;		// To a character
bool& ;		// To a bool

using namespace std;

string foo = "I am foo";
string bar = "I am bar";


string& fooRef = foo; // This creates a reference to foo.
fooRef += ". Hi!"; // Modifies foo through the reference
cout << fooRef; // Prints "I am foo. Hi!"

// Doesn't reassign "fooRef". This is the same as "foo = bar", and
//   foo == "I am bar"
// after this line.
cout << &fooRef << endl; //Prints the address of foo
fooRef = bar;
cout << &fooRef << endl; //Still prints the address of foo
cout << fooRef;  // Prints "I am bar"

//The address of fooRef remains the same, i.e. it is still referring to foo.

//The only time you would use the 'address of' operator on a reference is when
// you want the address in memory of whatever the reference is referencing. It
// is the same object. The '&' is only used for the declaration of the reference.

const string& barRef = bar; // Create a const reference to bar.
// Like C, const values (and pointers and references) cannot be modified.
barRef += ". Hi!"; // Error, const references cannot be modified.

// Sidetrack: Before we talk more about references, we must introduce a concept
// called a temporary object. Suppose we have the following code:
string tempObjectFun() { ... }
string retVal = tempObjectFun();

// What happens in the second line is actually:
//   - a string object is returned from tempObjectFun
//   - a new string is constructed with the returned object as argument to the
//     constructor
//   - the returned object is destroyed
// The returned object is called a temporary object. Temporary objects are
// created whenever a function returns an object, and they are destroyed at the
// end of the evaluation of the enclosing expression (Well, this is what the
// standard says, but compilers are allowed to change this behavior. Look up
// "return value optimization" if you're into this kind of details). So in this
// code:
foo(bar(tempObjectFun()))

// assuming foo and bar exist, the object returned from tempObjectFun is
// passed to bar, and it is destroyed before foo is called.

// Now back to references. The exception to the "at the end of the enclosing
// expression" rule is if a temporary object is bound to a const reference, in
// which case its life gets extended to the current scope:

void constReferenceTempObjectFun() {
  // constRef gets the temporary object, and it is valid until the end of this
  // function.
  const string& constRef = tempObjectFun();
  ...
}

// Another kind of reference introduced in C++11 is specifically for temporary
// objects. You cannot have a variable of its type, but it takes precedence in
// overload resolution:

void someFun(string& s) { ... }  // Regular reference
void someFun(string&& s) { ... }  // Reference to temporary object

string foo;
someFun(foo);  // Calls the version with regular reference
someFun(tempObjectFun());  // Calls the version with temporary reference

// For example, you will see these two versions of constructors for
// std::basic_string:
basic_string(const basic_string& other);
basic_string(basic_string&& other);

// Idea being if we are constructing a new string from a temporary object (which
// is going to be destroyed soon anyway), we can have a more efficient
// constructor that "salvages" parts of that temporary string. You will see this
// concept referred to as "move semantics".

//Passing parameters as references is by far the most important aspect of references. 
// It is quite unavoidable in real C++ code - you need to use pass-by-reference instead
// of the usual pass-by-value. 

//First, a comparison. Passing pointers to functions works like this:
void f(int * i) { ...;  }
//To this function, you can pass (a) the address of a variable or (b) a pointer
int a = 10;
int pa = &a;
f(&a); //Pass an address
f(pa); //Pass a pointer

// Returning a pointer is also possible, as long as the pointer doesn't start in the
// function - it will go out of scope, of course. 
int * f(){ ... return ptr; }	// returning some initialized pointer (assume ptr is properly scoped)
int * f(){ ... return &var; }	// returning the address of a variable (again, assume scope is OK)

// One thing to note is that, as long as & is not next to a type (like int &) it is going to
// give the address of the variable, which is a pointer value
// But when & is used with a type (char &, int &, etc) then it is expecting a reference

//Pointers expect either an address or a pointer during assignment
//References only need the variable to be sent in! You _can't_ send anything else
void f(int & i) { ...; }	//function will use the reference of the param

int a = 10;
int& ra = a;
f(a);		//valid: you can send a normal variable
f(ra);		//INVALID: you cannot send a referenece, because references can not refer to references

//For return a reference, simply return the variable:
int& f(){ ... return var; }
//Again, you cannot return a reference, even though it seems like you need to. Rather,
//the int & indicates that it's going to use a reference to the return variable. 


///////////////////////////////////////////////////////////
//FUNCTIONS
///////////////////////////////////////////////////////////

// if referring to external variables outside function, must use extern keyword.
int i = 0;
void testFunc() {
  extern int i; //i here is now using external variable i
}

// make external variables private to source file with static:
static int j = 0; //other files using testFunc2() cannot access variable j
void testFunc2() {
  extern int j;
}
//**You may also declare functions as static to make them private**

/*
At run time, functions are located at known memory addresses. Function pointers are
much like any other pointer (they just store a memory address), but can be used
to invoke functions directly, and to pass handlers (or callback functions) around.
However, definition syntax may be initially confusing.

Example: use str_reverse from a pointer
*/
void str_reverse_through_pointer(char *str_in) {
  // Define a function pointer variable, named f.
  void (*f)(char *); // Signature should exactly match the target function.
  f = &str_reverse; // Assign the address for the actual function (determined at run time)
  // f = str_reverse; would work as well - functions decay into pointers, similar to arrays
  (*f)(str_in); // Just calling the function through the pointer
  // f(str_in); // That's an alternative but equally valid syntax for calling it.
}

/*
As long as function signatures match, you can assign any function to the same pointer.
Function pointers are usually typedef'd for simplicity and readability, as follows:
*/

typedef void (*my_fnp_type)(char *);

// Then used when declaring the actual pointer variable:
// ...
// my_fnp_type f;

// C++ supports function overloading
// provided each function takes different parameters.

void print(char const* myString)
{
    printf("String %s\n", myString);
}

void print(int myInt)
{
    printf("My int is %d", myInt);
}

int main()
{
    print("Hello"); // Resolves to void print(const char*)
    print(15); // Resolves to void print(int)
}

// You can provide default arguments for a function
// if they are not provided by the caller.

void doSomethingWithInts(int a = 1, int b = 4)
{
    // Do something with the ints here
}

int main()
{
    doSomethingWithInts();      // a = 1,  b = 4
    doSomethingWithInts(20);    // a = 20, b = 4
    doSomethingWithInts(20, 5); // a = 20, b = 5
}

// Default arguments must be at the end of the arguments list.

void invalidDeclaration(int a = 1, int b) // Error!
{
}

///////////////////////////////////////
// User-defined types and structs
///////////////////////////////////////

// Typedefs can be used to create type aliases
typedef int my_type;
my_type my_type_var = 0;

// Structs are just collections of data, the members are allocated sequentially,
// in the order they are written:
struct rectangle {
  int width;
  int height;
};

// The only difference between a struct and a class, is that struct data members are
// public by default. That means structs can have constructors, functions, etc.

// It's not generally true that
// sizeof(struct rectangle) == sizeof(int) + sizeof(int)
// due to potential padding between the structure members (this is for alignment
// reasons). [1]

void function_1()
{
  struct rectangle my_rec;

  // Access struct members with .
  my_rec.width = 10;
  my_rec.height = 20;

  // You can declare pointers to structs
  struct rectangle *my_rec_ptr = &my_rec;

  // Use dereferencing to set struct pointer members...
  (*my_rec_ptr).width = 30;

  // ... or even better: prefer the -> shorthand for the sake of readability
  my_rec_ptr->height = 10; // Same as (*my_rec_ptr).height = 10;
}

// You can apply a typedef to a struct for convenience
typedef struct rectangle rect;

int area(rect r)
{
  return r.width * r.height;
}

// if you have large structs, you can pass them "by pointer" to avoid copying
// the whole struct:
int areaptr(const rect *r)
{
  return r->width * r->height;
}


//////////////////////////////////////////
// Initialization and Operator Overloading
//////////////////////////////////////////

// In C++ you can overload the behavior of operators such as +, -, *, /, etc.
// This is done by defining a function which is called
// whenever the operator is used.

#include <iostream>
using namespace std;

class Point {
public:
    // Member variables can be given default values in this manner.
    double x = 0;
    double y = 0;

    // Define a default constructor which does nothing
    // but initialize the Point to the default value (0, 0)
    Point() { };

    // The following syntax is known as an initialization list
    // and is the proper way to initialize class member values
    Point (double a, double b) :
        x(a),
        y(b)
    { /* Do nothing except initialize the values */ }

    // Overload the + operator.
    Point operator+(const Point& rhs) const;

    // Overload the += operator
    Point& operator+=(const Point& rhs);

    // It would also make sense to add the - and -= operators,
    // but we will skip those for brevity.
};

Point Point::operator+(const Point& rhs) const
{
    // Create a new point that is the sum of this one and rhs.
    return Point(x + rhs.x, y + rhs.y);
}

Point& Point::operator+=(const Point& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

int main () {
    Point up (0,1);
    Point right (1,0);
    // This calls the Point + operator
    // Point up calls the + (function) with right as its parameter
    Point result = up + right;
    // Prints "Result is upright (1,1)"
    cout << "Result is upright (" << result.x << ',' << result.y << ")\n";
    return 0;
}

/////////////////////
// Exception Handling
/////////////////////
// Exceptions are essential for good programming. They make robust and clean code that's
// easier to develop with. Exceptions simply are errors, and exceptions are "thrown" whenever
// you "try" code. If you're not looking for it, you won't have an exception thrown, you'll
// just get a compilation error.
//
// The exception itself is any type or object, like an int, or a special "exception" object.
// To "catch" the exception, you have to specifically look for _that type_ of exception. 
// You have to throw your own exceptions, and catch any exceptions that might be thrown
// by the system (memory allocation etc) or classes within your code. 
//
// The standard library provides a few exception types
// (see http://en.cppreference.com/w/cpp/error/exception)
// but any type can be thrown an as exception
#include <exception>
#include <stdexcept>

// All exceptions thrown inside the _try_ block can be caught by subsequent
// _catch_ handlers.
try {
    // Do not allocate exceptions on the heap using _new_.
    throw std::runtime_error("A problem occurred");
}

// Catch exceptions by const reference if they are objects
catch (const std::exception& ex)
{
    std::cout << ex.what();
}

// Catches any exception not caught by previous _catch_ blocks
catch (...)
{
    std::cout << "Unknown exception caught";
    throw; // Re-throws the exception
}

////////////////////////////////////
//Other Topics
////////////////////////////////////
/*
Other topics to look into:
--Tuples
--'Range For' loops
--Lambda expressions
--RAII with exception handling
--State machine programming
--Aggregate initialization
--Keywords: auto, union, volatile
--Arrow operator
--New operator
--Initialization lists for constructorss

*/

//The keyword auto can be used for assigning a variable when you don't know
// which type it's assignment will be
int foo = 10;
float bar = 11.0;

auto vari = foo; //assigns vari as an int
auto able = bar; //assign able as a float
auto newVar = 10; //automatically assigns newVar as an int
auto newerVar = 1.3; //automatically assigns newerVar as a float
//Note that all variables are dereferenced i.e. auto will not assign things as
// references or pointers. 


		////////////////////////////////////////////////////////////
		//OBJECT ORIENTED PROGRAMMING
		////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////

		//////////////////////////////////////////
		// Classes and object-oriented programming
		//////////////////////////////////////////

		// First example of classes
		#include <iostream>

		// Declare a class.
		// Classes are usually declared in header (.h or .hpp) files.
		class Dog {
			// Member variables and functions are private by default.
			std::string name;
			int weight;

		// All members following this are public
		// until "private:" or "protected:" is found.
		public:

			// Default constructor
			Dog();

			// Member function declarations (implementations to follow)
			// Note that we use std::string here instead of placing
			// using namespace std;
			// above.
			// Never put a "using namespace" statement in a header.
			void setName(const std::string& dogsName);

			void setWeight(int dogsWeight);

			// Functions that do not modify the state of the object
			// should be marked as const.
			// This allows you to call them if given a const reference to the object.
			// Also note the functions must be explicitly declared as _virtual_
			// in order to be overridden in derived classes.
			// Functions are not virtual by default for performance reasons.
			virtual void print() const;
			//This print method is virtual because it is going to be overridden in child classes
			
			// Functions can also be defined inside the class body.
			// Functions defined as such are automatically inlined.
			void bark() const { std::cout << name << " barks!\n"; }

			// Along with constructors, C++ provides destructors.
			// These are called when an object is deleted or falls out of scope.
			// This enables powerful paradigms such as RAII
			// (see below)
			// The destructor should be virtual if a class is to be derived from;
			// if it is not virtual, then the derived class' destructor will
			// not be called if the object is destroyed through a base-class reference
			// or pointer.
			virtual ~Dog();

		}; // A semicolon must follow the class definition.

		//If you can, avoid including anything that is unneccessary. If you're going to
		//use an outside method or object, consider forward declaring, and only if this
		//will not work should you choose to include.

		// Class member functions are usually implemented in .cpp files.
		Dog::Dog()
		{
			std::cout << "A dog has been constructed\n";
		}

		// Objects (such as strings) should be passed by reference
		// if you are modifying them or const reference if you are not.
		void Dog::setName(const std::string& dogsName)
		{
			name = dogsName;
		}

		void Dog::setWeight(int dogsWeight)
		{
			weight = dogsWeight;
		}

		// Notice that "virtual" is only needed in the declaration, not the definition.
		void Dog::print() const
		{
			std::cout << "Dog is " << name << " and weighs " << weight << "kg\n";
		}

		Dog::~Dog()
		{
			cout << "Goodbye " << name << "\n";
		}

		int main() {
			Dog myDog; // prints "A dog has been constructed"
			myDog.setName("Barkley");
			myDog.setWeight(10);
			myDog.print(); // prints "Dog is Barkley and weighs 10 kg"
			return 0;
		} // prints "Goodbye Barkley"


		////////////////////////////////////////////////////////////
		// Inheritance
		////////////////////////////////////////////////////////////

		// This class inherits EVERYTHING PUBLIC AND PROTECTED from the Dog class
		// as well as private but may not directly access private members/methods
		// without a public or protected method for doing so
		class OwnedDog : public Dog {

			void setOwner(const std::string& dogsOwner);

			// Override the behavior of the print function for all OwnedDogs. See
			// http://en.wikipedia.org/wiki/Polymorphism_(computer_science)#Subtyping
			// for a more general introduction if you are unfamiliar with
			// subtype polymorphism.
			// The override keyword is optional but makes sure you are actually
			// overriding the method in a base class.
			void print() const override;

		private:
			std::string owner;
		};

		// Meanwhile, in the corresponding .cpp file:

		void OwnedDog::setOwner(const std::string& dogsOwner)
		{
			owner = dogsOwner;
		}

		void OwnedDog::print() const
		{
			Dog::print(); // Call the print function in the base Dog class
			std::cout << "Dog is owned by " << owner << "\n";
			// Prints "Dog is <name> and weights <weight>"
			//        "Dog is owned by <owner>"
		}

		//To summarize, ANY class can be inherited. All PUBLIC AND PROTECTED data members
		//(all methods, protected private vars) are included in the inheritance. 
		//Methods CANNOT BE CHANGED unless they are declared VIRTUAL.


		/////////////////////////////////////////
		// Templates
		/////////////////////////////////////////

		// Templates in C++ are mostly used for generic programming.

		//To define a class or function that takes a type parameter:
		template<class T>
		class Box {
		public:
			// In this class, T CAN BE USED AS ANY TYPE
			void insert(const T&) { ... }
		};

		// During compilation, the compiler actually generates copies of each template
		// with parameters substituted, so the full definition of the class must be
		// present at each invocation. This is why you will see template classes defined
		// entirely in header files.

		// To instantiate a template class on the stack:
		Box<int> intBox;

		// and you can use it as you would expect:
		intBox.insert(123);

		// You can, of course, nest templates:
		Box<Box<int> > boxOfBox;
		boxOfBox.insert(intBox);

		// Until C++11, you had to place a space between the two '>'s, otherwise '>>'
		// would be parsed as the right shift operator.

		// You will sometimes see
		//   template<typename T>
		// instead. The 'class' keyword and 'typename' keywords are _mostly_
		// interchangeable in this case. For the full explanation, see
		//   http://en.wikipedia.org/wiki/Typename

		// Similarly, a template function:
		template<class T>
		void barkThreeTimes(const T& input)
		{
			input.bark();
			input.bark();
			input.bark();
		}

		// Notice that nothing is specified about the type parameters here. The compiler
		// will generate and then type-check every invocation of the template, so the
		// above function works with any type 'T' that has a const 'bark' method!

		Dog fluffy;
		fluffy.setName("Fluffy")
		barkThreeTimes(fluffy); // Prints "Fluffy barks" three times.

		// Template parameters don't have to be classes:
		template<int Y>
		void printMessage() {
		  cout << "Learn C++ in " << Y << " minutes!" << endl;
		}

		// And you can explicitly specialize templates for more efficient code. Of
		// course, most real-world uses of specialization are not as trivial as this.
		// Note that you still need to declare the function (or class) as a template
		// even if you explicitly specified all parameters.
		template<>
		void printMessage<10>() {
		  cout << "Learn C++ faster in only 10 minutes!" << endl;
		}

		printMessage<20>();  // Prints "Learn C++ in 20 minutes!"
		printMessage<10>();  // Prints "Learn C++ faster in only 10 minutes!"

		/*
		Another note, with respect to OOP, is that C++ doesn't use the word "abstract". Any
		class can be used as a parent class, and its methods and protected data are inherited. 
		The methods that are 'virtual' can be altered in the child class. There is nothing
		to say that you can or can't use the parent (abstract) class, unless you specifically 
		do not define the methods and data members in the class, which is fine as long as you
		define the child classes. Thus you also have an 'interface' for C++ as well, again
		without having to actually _say_ interface. 
		*/


	
