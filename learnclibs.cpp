/* 
C/C++ Libraries
The libraries considered here are:
 ---> vector
 ---> Other containers: array, bitset, deque, map, queue, set, stack, list and forward_list
 
 ---> boost
 ------> shared_array
 ------> scoped_ptr
 etc...

 ---> GTK+ (2.0)
 ---> QT
 
 ---> C++ Standard Library (except containers)
 ------> algorithm
 ------> chrono
 ------> complex
 ------> functional
 ------> exception
 ------> tuple
 etc...


VECTOR LIBRARY
Vector is a very useful library for working with data. <vector> is like an array that can change size. The library comes with plenty of
tools that can be used with the vectors to make things easier. For example, creating vectors of objects, multiple types, or bits. 

Needless to say, it would be helpful to firmly understand the C/C++ language. Specifically, it would be a good idea to review templates in 
C++.

BOOST LIBRARY
Boost is a really large pack of libraries. More than 100 header files, boost helps programmers by providing libraries for data management, 
algorithms and math, data structures, files, and so-on. Obviously with so much to cover, it's not easy to start at any one place. It's probably
best to break things up into topics.


Boost topics:
-- Memory management
-- Macros
-- Strings and Structures
-- Containers
-- Algorithms and Programming
-- Files and Streams
-- Error and Number Handling
-- Communication and Time

GTK+ 2.0 LIBRARY/FRAMEWORK
GTK is used for developing GUI applications. It works pretty well for cross-platform work, and is known for being used in a ton of open
source projects like Inkscape, Chromium, and GIMP. GTK in its typical form works only for C, as opposed to C++. 

QT LIBRARY/FRAMEWORK
QT is another GUI framework/library/toolkit, which is very common. Also good for cross-platform, programs likek Autodesk Maya, Spotify (for Linux), 
VLC media player, and Google Earth. 

*/


//INCLUDES ============================
//When you're working with the vector library, you must use:
#include <vector>

//For other STL containers:
#include <pair>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <array>
#include <bitset>

//For boost, the various libraries are included in boost/ , like this:
#include <boost/scoped_ptr.hpp>
//You have to know which libs in boost you'll be using, and their associated includes. 

//The GTK library's big include is:
#include <gtk/gtk.h>


//VECTOR ==============================
//Uses typical C++ template format with four possible constructors:
vector<int> foo; //empty integer vector
vector<char> bar(15); //a character vector with 15 spaces preallocated
vector<double> initialized(10,2.0); //a double with 10 spaces, each initialized to 2.0
vector<double> mycopy(initialized); //a copy of the 'initialized' vector we just made
vector<userObject> myObj; //A vector of the myObj type

//If you want to create a bunch of objects at once, you'll need a default constructor, or
// you can create a vector with pointers to the object(s). 


//you can, of course, create multiple vectors at once.
vector<float> first,second;

//accessing elements is simple with 'at':
vector<int> age(10,21);
age.at(0); // => 21
age.at(6); // => 21
age.at(10); // => exception thrown
age.front(); //reference to at(0)
age.back();  //reference to at(9)

//you can also use brackets:
age[0]; // => 21
age[6]; // => 21
age[11]; // => error (no exception thrown)

//Since the brackets won't throw an exception, it is generally viewed as unsafe for accessing the elements of the vector.

//A programmer will naturally want to alter the elements of the vector - nobody wants their vector to have identical data all
//the way through! There are a bunch of ways to do this. 
vector<int> grade(5,0);

//the 'at' method will access existing places in the vector:
grade.at(0) = 100;
grade.at(1) = 89;
grade.at(2) = 90;
grade.at(3) = 67;
grade.at(4) = 95;
grade.at(5) = 80; //Exception thrown

grade.insert(grade.begin(), 100); //insert a new grade of 100% to the front, slide everything down
grade.erase(grade.begin());	   //then delete that grade, and slide everything back.  
grade.insert(grade.begin()+1, 77); //insert a new grade after the first element
grade.push_back(15); //add a grade of 15% to the end of the vector
grade.pop_back(); 	 //and remove the last grade from the vector
//^^^^^^^^ These last two are very helpful

//It is important to notice how 'insert' and 'erase' have grade.begin() in their first argument. These methods require
// an ITERATOR object to tell it where to be. This is somewhat similar to a pointer. The grade.begin() and grade.end()
// methods will return an iterator object for use in this way. Iterators are helpful, and deserve a tutorial in their own. 

//There are plenty of ways to see properties of the vector. Vector sizing and resizing is common and is done like so.
vector<int> foo(10); //vector of size 10
foo.size(); //=> 10
foo.resize(11); //resize the vector
foo.size(); //=> 11
foo.zero(); //=> false
foo.clear(); //=> deletes all the element values in foo. Capacity usually stays the same, but size() = 0.

//There are two methods that are useful in terms of memory allocation. The first is capacity(), and the second is 
// max_size(). capacity() will tell how much memory is currently allocated to the vector. Sometimes the vector can reserve
// memory that is not in use, and this is how capacity() is used. If you resize the vector to be greater than capacity(), 
// it will reallocate memory. 
//The max_size() method describes the maximum possible number of elements that the vector can hold, taking into account
// the parameters of the given computer, compiler, etc. For example, when I ran max_size for an int vector on my compiler, 
// it returned 4,611,686,018,427,387,903. The same value returned on an online compiler. 

//For changing large sections of the vector, you can use assign() and swap().
// Assign(value) will change all the values in the vector to the given value. Swap(vector) will literally swap all of 
// the values of the current vector with the given vector. 

vector<int> num1, num2;
num1.resize(3);
num2.resize(3);

num1.at(0) = 1;
num1.at(1) = 2;
num1.at(2) = 3;

num2.at(0) = 9;
num2.at(1) = 8;
num2.at(2) = 7; //num1 = [1 2 3], num2 = [9,8,7]

//swapping vectors
num1.swap(num2); //num1 = [9 8 7], num2 = [1 2 3]

//assigning a value to a whole vector
num1.assign(5); //num1 = [5 5 5]


//Performance with vectors can really very important when dealing with large amounts of data. For example, a database that is completely 
// stored in a vector might have gigabytes of data that needs to be accessed. Some methods work in constant time (takes the same amount of
// time for everything) and others work in linear time (size of vector, location of iterator determine time it takes). 

/* Constant time methods:
-- at()
-- back()
-- begin()
-- capacity()
-- end()
-- front()
-- max_size()
-- pop_back()
-- push_back()
-- rbegin()
-- rend()
-- swap()

Linear time methods:
-- assign()
-- clear()
-- empty()
-- erase()
-- insert()
-- reserve()
-- resize()
-- size()

Keep this information in mind when working with vector. 
*/

//Bit vectors can be created which use a single bit (instead of a byte) for boolean vectors.
vector<bool> bitData; //a bit vector optimized for space
bitData.flip(); // inverts all the bits in the vector. 1's become 0's, and 0's become 1's. 

//There is more to vector, such as C++11 additions emplace(), data(), and shrink_to_fit() . For up-to-date information, see the documentation 
// at http://www.cplusplus.com/reference/vector/vector/

//OTHER STL CONTAINERS=======================
//There is a whole slew of containers defined in the C++ Standard Template Library (STL).
//They all do the same thing: store data in a certain fashion. Some are simple, such as
//std::pair which stores a pair of values. Others have a bit more to them, such as the binary-tree formatted
//objects.
//
//Common to all containers: (for some container 'obj')
obj.empty(); //Boolean for if the container is empty
obj.size(); //Predicts the second coming of God
obj.clear(); //Delete all elements of obj
obj.swap(other_obj); //Move all items of obj to other_obj. Note that obj is now EMPTY

//Iterators are also common to containers. For example:
std::vector<int>::iterator iter; //An iterator for an int vector

//Iterators come in a few types:
//--> Random access
//--> Bidirectional
//--> Forward
//Where random access iterators can access elements anywhere, bidirectional iterators can
//move forwards and backwards, and forward iterators can _only_ move forwards. 
//Random access iterators can be moved:
iter += 5;
iter -= 4;
iter++;
iter--;

//And compared
if(iter1 > iter2);

//While directional iterators can only be incremented or decremented, and forward iterators can
//only be incremented. 
//Other iterator types are input iterators and output iters, where an input iter is used to move
//forward while reading and processing. The output iterator is the same, with output. These
//both can _only_ move forward.

//The first container is another sequence container like vector, called deque.
//A <deque> object can have objects inserted in either the beginning or the end
//This is similar to vector, but vector only had push_back
std::deque<int> d;
d.push_front(100); // d = {100}
d.push_front(200); // d = {200 100}
d.push_back(300);  // d = {200 100 300}

//Deque is very similar to vector, so you can access it in the same way. Both <deque> and <vector> represent
// SEQUENCE CONTAINERS, which stored elements in order, as opposed to ASSOCIATIVE CONTAINERS, which are
// usually a binary tree.
// There are two more sequence containers, <list> and <forward_list>:
std::list<string> mylist;

//You can push_front and push_back:
mylist.push_front("Hello");
mylist.push_back("STL"); // => {"Hello" "STL"}

//But list items also store pointers to the items on either side of them. That means you can insert. BUT
// to insert items, you actually need to use an iterator object. In fact, the same goes for both deque
// and vector, though there is nothing wrong with using .at() for those. 
std::list<string>::iterator i = mylist.begin();
//or
std::list<string>::iterator i = std::find(mylist.begin(), mylist.end(), "Hello") //Gives an iter at 0
itr++; //Move the iterator past the first word
mylist.insert(itr, "and Welcome to"); // => {"Hello" "and Welcome to" "STL"}

//You can splice two lists together:
listA.splice(itr, listB, itrStart, itrStop); //Splices listB (from start to stop points) into listA at itr.
//The great thing about splice is that it is CONSTANT TIME! You can splice large amounts of data. 
//In general, though, list is slower than the other sequence containers, so keep that in mind. 

//And you can erase
mylist.erase(itr); // => {"Hello" "STL"}

//NOTE: There is NO random access for lists! You must use iterators

//Similar to a <list> is the <forward_list>, which can only access from beginning to end. You
//cannot iterate backwards through a forward_list, which makes it an interesting data type.

//In associative containers we first have sets, which are a binary tree. Sets have one of each
//object, not more. The set is always sorted, and searching, inserting, and erasing take log time. 
set<int> reals;
reals.insert(5);
reals.insert(2);
reals.insert(5); //=> {2 5}

//Insert returns a pair, the first object is an iterator for the object, the second is a bool for
//whether the insertion succeeded or not.
std::pair<std::set<int>::iterator, bool> insReturn;
insReturn = reals.insert(2); //=> {2 5}, insReturn holds an iterator at item 2, and a the bool 'false'
// because 2 is already in the set

//Erasing can be done with iterators, or by specifying the value:
myset.erase(iter);
myset.erase(2);

//There is also <multiset> which allows duplicate items
//IMPORTANT NOTE: You can't modify values, because it's a binary tree, and changing values would
//need a new tree.

//The containers <map> and <multimap> are really similar to <set> and <multiset>, except as you
//might guess they use key/value pairs. 
std::map<std::string, int> configMap;
configMap["Sally"] = 1;
configMap["Joe"] = 32;
configMap["Owner"] = 774;
configMap["Data"] = 2;

//*****This page was borrowed heavily from Bo Quian's series on YouTube.
//
//BOOST=======================================

/*
As previously mentioned, it is better to break boost up into several categories:
-- Memory management
-- Macros
-- Strings and Structures
-- Containers
-- Algorithms and Programming
-- Files and Streams
-- Error and Number Handling
-- Communication and Time
*/

// MEMORY MANAGEMENT
// The libraries for memory management generally make things like deletion of pointers and objects simpler. This helps with RAII (resource acquired is initialized). 
// Libraries are:
// --SmartPointer
// --PointerContainer
// --ScopeExit
// --Pool

//Smart pointers are used because typical pointers in C++ have no owner. This can result in memory leaks (objects are left over in heap memory) which is bad.
//There are a few types of smart pointers included in the boost libraries. 
#include <boost/shared_ptr.hpp>		// Pointer shares the ownership of the space in memory
#include <boost/weak_ptr.hpp>		// 
#include <boost/scoped_ptr.hpp>		// Pointer becomes the sole owner of the space in memory
#include <boost/intrusive_ptr.hpp>	// Specialized pointer 
#include <boost/scoped_array.hpp>	// Specialized pointer 
#include <boost/shared_array.hpp>	// Specialized pointer 

//The scoped pointer is the same as a conventional pointer, except that it cannot be copied (e.g. into a vector) or shared. 
//It is a template, and is defined by the type that it points to.
int myValue = 10;
int * hello = &myValue; //Conventional pointer
boost::scoped_ptr<int> goodbye(myValue); //Scoped pointer
//The benefit, of course, is the scoped pointer deletes immediately once it has fallen out of scope. 

//The shared pointer, as the name suggests, is a pointer that can be owned by several instances
// in the same program. As long as it has _any_ owner, the pointer will not be deleted. 
// For example, if A, B, and C all share a pointer, and A and B are deleted, then C will still
// have access to the pointer. 
boost::shared_ptr<int> farewell(myValue);



//GTK 2.0===========================================

#include <gtk/gtk.h>

//GTK is organized with a few basic functions that interface with the GUI components. Similar to 
// other GUI toolkits, it works in signals, events, and widgets. Each component in the GUI is
// a widget, and when you have one or more widgets inside another (like buttons in a popup)
// the 'outside' widget is called a container. 

// NOTE: There is a great tool called "Glade" that is available for designing GUIs rather nicely

//ESSENTIALS
gtk_init(&argv, &argc);   //Initializes GTK with any arguments sent through CLI
gtk_main(); //Starts the main loop, wherein the program waits for events and signals

//TYPES OF WIDGETS
//There are many different types of widgets. For example:
GtkWidget *myWindow; 	//Windows
GtkWidget *myAlignment; //Alignment tools (horizontal alignment, vertical alignment, etc)
GtkWidget *myButton; 	//Buttons

myWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); //GTK_WINDOW_TOPLEVEL is one of two possible
//constants you can use for types of windows. The other is GTK_WINDOW_POPUP - don't use it.
myAlignment = gtk_alignment_new(0,0,0,0); //Input params are Xalign, Yalign, Xscale, and Yscale
//More on these later
myButton = gtk_button_new_with_label("Hello world"); //A button with a label
//These are obviously just a couple different types, and there are tons of different
//widget objects. Others include entry boxes, cursors, images, containers, etc.
//There's also a wide variety of functions for use with widgets. GNOME has good doc on this. 

//CONTAINERS
//Containers are the GTK tool for layout of applications. They don't work in pixels or pts,
// they are fluid and versatile. 

//Creating a window:
GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//Windows are "toplevel" because they have no features or characteristics, they
// simply hold all the other widgets. They are the 'top level' container.

//Section up your window with:
GtkWidget *box1 = gtk_hbox_new(FALSE,0); //HBoxes: Horizontal window dividers. Arguments are: (gboolean homogenous, gint spacing)
GtkWidget *box2 = gtk_vbox_new(FALSE,0); //VBoxes: Vertical dividers
//Homogenous is used when you want every section to be equally spaced (no resizing)
//The spacing parameter is for distance between the sections. The resulting leftover space
// is empty.


//Pack widgets (children) into the boxes either from the left (top) or from the right (bottom)
gtk_box_pack_start(box1, myButton,FALSE, FALSE,0); //Left side (hbox) or top (vbox). Args: *box, *child, gboolean expand, gboolean fill, gint padding									   
//'expand' will let the widget fill the entire space. If this is 
// TRUE, then 'fill' decides if the entire space is allocated to the child object, or to padded space.

gtk_box_pack_end(box1,myOtherButton,FALSE,FALSE,0); //Right side (hbox) or bottom (vbox). Same args.
//These will fill the next available position in the box.
//Example of four buttons of a calculator across the bottom of the window:
GtkWidget *button_add;
GtkWidget *button_subtract;
GtkWidget *button_multiply;
GtkWidget *button_divide;

GtkWidget *box1;
GtkWidget *box2;

button_add = gtk_button_new_with_label("+");
button_subtract = gtk_button_new_with_label("-");
button_multiply = gtk_button_new_with_label("x");
button_divide = gtk_button_new_with_label("/");

gtk_box_pack_end(GTK_BOX(box1),box2,false,false,0); //notice casting, from GTK_BOX

gtk_box_pack_start(GTK_BOX(box2),button_add,true,true,0);
gtk_box_pack_start(GTK_BOX(box2),button_subtract,true,true,0);
gtk_box_pack_start(GTK_BOX(box2),button_multiply,true,true,0);
gtk_box_pack_start(GTK_BOX(box2),button_divide,true,true,0);

gtk_container_add(GTK_CONTAINER(window),box1);
//This assumes that the window is called " *window "


//Another really helpful container is GtkTable. In GTK+3, GTKTable was deprecated, and
// replaced with GTKGrid. Though similar, anyone using GTK+3 should look up the doc
// on GTKGrid to avoid errors. 
//This file is for GTK+2, so GtkTable is used.

// Assignment:
GtkWidget myTable = gtk_table_new(3,2,false); //3 rows down, 2 columns across, last param is homogeneous

//Since assigning widgets to certain locations isn't as simple as left to right or top to bottom,
// a function gtk_table_attach() is used
gtk_table_attach_defaults(GTK_TABLE(myTable), myButton,0,1,0,1);
//This places a button at the far left, one square across, and at the top, one square down. 
/*
The grid we've made:

 0        1          2
0+--------+----------+
 |########|          |
1+--------+----------+
 |		  |          |
2+--------+----------+
 |		  |          |
3+--------+----------+

The table_attach function specifies the attachment for the left side of the object, then
the right side, and then the top side, and the bottom. So for the example of 0,1,0,1, the
button starts at the 0 line for the left, and its right side is on the 1 line. The top
side is at the 0 line (the top) and the bottom side is on the 1 line.
*/

//If you want more control, the function gtk_table_attach() includes 4 more args, for
// packing settings on the x and y axes, and padding for the x and y. 
// The packing options are:
// --> fill - make widgets fill the entire space requested
// --> shrink - make widgets smaller if they don't have enough space
// --> expand - expand the table so it fills up all remaining space in the window

//LIST OF WIDGETS
//Some widgets require windows, while others can be without them. If you want events in these,
// youll have to use an EventBox
/*
GObject
 |  
 GtkObject
  +GtkWidget
  | +GtkMisc
  | | +GtkLabel
  | | | `GtkAccelLabel
  | | +GtkArrow
  | | `GtkImage
  | +GtkContainer
  | | +GtkBin
  | | | +GtkAlignment
  | | | +GtkFrame
  | | | | `GtkAspectFrame
  | | | +GtkButton
  | | | | +GtkToggleButton
  | | | | | `GtkCheckButton
  | | | | |   `GtkRadioButton
  | | | | `GtkOptionMenu
  | | | +GtkItem
  | | | | +GtkMenuItem
  | | | |   +GtkCheckMenuItem
  | | | |   | `GtkRadioMenuItem
  | | | |   +GtkImageMenuItem
  | | | |   +GtkSeparatorMenuItem
  | | | |   `GtkTearoffMenuItem
  | | | +GtkWindow
  | | | | +GtkDialog
  | | | | | +GtkColorSelectionDialog
  | | | | | +GtkFileSelection
  | | | | | +GtkFontSelectionDialog
  | | | | | +GtkInputDialog
  | | | | | `GtkMessageDialog
  | | | | `GtkPlug
  | | | +GtkEventBox
  | | | +GtkHandleBox
  | | | +GtkScrolledWindow
  | | | `GtkViewport
  | | +GtkBox
  | | | +GtkButtonBox
  | | | | +GtkHButtonBox
  | | | | `GtkVButtonBox
  | | | +GtkVBox
  | | | | +GtkColorSelection
  | | | | +GtkFontSelection
  | | | | `GtkGammaCurve
  | | | `GtkHBox
  | | |   +GtkCombo
  | | |   `GtkStatusbar
  | | +GtkFixed
  | | +GtkPaned
  | | | +GtkHPaned
  | | | `GtkVPaned
  | | +GtkLayout
  | | +GtkMenuShell
  | | | +GtkMenuBar
  | | | `GtkMenu
  | | +GtkNotebook
  | | +GtkSocket
  | | +GtkTable
  | | +GtkTextView
  | | +GtkToolbar
  | | `GtkTreeView
  | +GtkCalendar
  | +GtkDrawingArea
  | | `GtkCurve
  | +GtkEditable
  | | +GtkEntry
  | |   `GtkSpinButton
  | +GtkRuler
  | | +GtkHRuler
  | | `GtkVRuler
  | +GtkRange
  | | +GtkScale
  | | | +GtkHScale
  | | | `GtkVScale
  | | `GtkScrollbar
  | |   +GtkHScrollbar
  | |   `GtkVScrollbar
  | +GtkSeparator
  | | +GtkHSeparator
  | | `GtkVSeparator
  | +GtkInvisible
  | +GtkPreview
  | `GtkProgressBar
  +GtkAdjustment
  +GtkCellRenderer
  | +GtkCellRendererPixbuf
  | +GtkCellRendererText
  | +GtkCellRendererToggle
  +GtkItemFactory
  +GtkTooltips
  `GtkTreeViewColumn
  
GtkAlignment
GtkArrow
GtkBin
GtkBox
GtkButton
GtkCheckButton
GtkFixed
GtkImage
GtkLabel
GtkMenuItem
GtkNotebook
GtkPaned
GtkRadioButton
GtkRange
GtkScrolledWindow
GtkSeparator
GtkTable
GtkToolbar
GtkAspectFrame
GtkFrame
GtkVBox
GtkHBox
GtkVSeparator
GtkHSeparator
*/



// QT =====================================

/*
 * Let's start clasically
 */

// all headers from Qt framework start with capital letter 'Q'
#include <QApplication>
#include <QLineEdit>

int main(int argc, char *argv[]) {
	 // create an object to manage application-wide resources
    QApplication app(argc, argv);

    // create line edit widget and show it on screen
    QLineEdit lineEdit("Hello world!");
    lineEdit.show();

    // start the application's event loop
    return app.exec();
}

/*
 * Let's create a label and a button.
 * A label should appear when a button is pressed.
 * 
 * Qt code is speaking for itself.
 */
 
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDialog dialogWindow;
    dialogWindow.show();
    
    // add vertical layout 
    QVBoxLayout layout;
    dialogWindow.setLayout(&layout);  

    QLabel textLabel("Thanks for pressing that button");
    layout.addWidget(&textLabel);
    textLabel.hide();

    QPushButton button("Press me");
    layout.addWidget(&button);
    
    // show hidden label when the button is pressed
    QObject::connect(&button, &QPushButton::pressed,
                     &textLabel, &QLabel::show);

    return app.exec();
}

// counterlabel.hpp

#ifndef COUNTERLABEL
#define COUNTERLABEL

#include <QLabel>

class CounterLabel : public QLabel {
    Q_OBJECT  // Qt-defined macros that must be present in every custom widget

public:
    CounterLabel() : counter(0) {
        setText("Counter has not been increased yet");  // method of QLabel
    }

public slots:
    // action that will be called in response to button press
    void increaseCounter() {
        setText(QString("Counter value: %1").arg(QString::number(++counter)));
    }

private:
    int counter;
};

#endif // COUNTERLABEL

// main.cpp
// Almost the same as in previous example

#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include "counterlabel.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDialog dialogWindow;
    dialogWindow.show();

    QVBoxLayout layout;
    dialogWindow.setLayout(&layout);

    CounterLabel counterLabel;
    layout.addWidget(&counterLabel);

    QPushButton button("Push me once more");
    layout.addWidget(&button);
    QObject::connect(&button, &QPushButton::pressed,
                     &counterLabel, &CounterLabel::increaseCounter);

    return app.exec();
}


