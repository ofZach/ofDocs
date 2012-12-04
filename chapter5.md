# Basic Programming Principles and Elements

Until now we have drawn different shapes on the screen. But the real magic around programming comes when you can abstract the positions and start playing with relative numbers. Abstraction is a concept taken from mathematics that allows us to separate ourselves from numbers and turn them into concepts, that we can define and change in our program.

That brings us to math and the concept of variables. Variables are spaces in the computer memory that can have different values. We create them when we start writing code so we can later refer to them, or create them as we go. The main thing to remember is that the variable can be many different things, affecting position, size, shape, color and so many other things.

So instead of saying:


	ofNoFill()
	ofSetWindowsShape(400,400);
	ofCircle(200,200,100);
	ofCircle(200,200,50);
	ofCirlce(200,200,75);
	ofCirlce(200,200,25);


We can use variable to say:


	width = 400;
	height = 400;
	radius = width/4;

	ofSetWindowsShape(width,height);
	ofCircle(width/2, height/2, radius);
	ofCircle(width/2, height/2, radius/2);
	ofCircle(width/2, height/2, radius/3);
	ofCircle(width/2, height/2, radius/4);


In this way if we want to change the look of our drawing we just need to change the width and the height and all it's going to change automatically.
That's the magic of using variables in code.

<br />

---
<br />

![variables01](https://raw.github.com/ofZach/ofDocs/master/img/chapter05/variables.png)

## Variables / data Type

There is an important thing about variables in openFrameworks. C++ is a strong type language. So anytime you define a variable as a number, it can't be transformed to a character without making a new variable. Another important thing here is that there are two types of numbers integers, or whole numbers (1,2,3,4,5,15,98) and floating point numbers, or decimal numbers (0.1, 3.6, 32.7, etc). Also both types could be signed and unsigned, meaning they can be positive and negative, respectively. Each number type uses a defined amount of memory space. With a signed number, one bit of memory space is used to set the sign of the number. So pre-defining a variable as a unsigned leaves that extra bit free for use.

This are all the data types, with each respective size and range of values


**NOTE**: take a look to [C++ DATA TYPES](http://www.cplusplus.com/doc/tutorial/variables/)


At the end the most often used data types in oF are:

* ```bool```  	(1 byte)   could be TRUE or FALSE    
* ```chars```	(1 byte)   signed: -128 to 127 / unsigned: 0 to 255
* ```int```    	(4 bytes)  signed: -2147483648 to 2147483647 / unsigned: 0 to 4294967295
* ```float``` 	(4 bytes)  +/- 3.4e +/- 38 (~7 digits)

To addition to it there is a special variable added before to C++ for storing groups of characters call a "string". Strings are use to store words or sentences.

## Making and using variables
So, how can I make a variable?
There is a simple structure for it. This procedure is call ***declaration***

	[type] [variable_name];

For example:

	int myInteger;
	float myFloat;

Also it's possible to declare several variables of the same type in one line

	int firstInteger, secondInteger;

With this we just make room on the memory for storing something. The content it's going to be assigned using ```=``` like this

	int myInteger;
	myInteger = 10;

We can do everything in one move writing:

	int myInteger = 10;

After doing this we can use ```myInteger``` instead of 10. The variable myInteger is now something we can use in many parts of our code, relaying that value where ever it is inserted to in order to make the content relative. That is going to be our way of creating smarter programs and great interaction.


## Scope
Now that we have created a variable, understanding where we can use it in our program is called its scope. Scope is important because it determines whether the variable is visible or usable for the compiler. In short, the scope of the variable is usually defined where ever the curly braces begin ```{``` and end ```}```.


*** GRAPHICS NEED HERE FOR EXPLAINING SCOPE ***


Let say that we declare a variable in the update() method. 


	void testApp:update(){
		int var = 50;
	}



This variable is going to be accessed just inside the update function. If you do this in the draw() function:


	void testApp:draw(){
		ofCircle(100,100,var); 	// ERROR
	}
	


It's not going to work. Why? Because the scope of a variable var is limited to only the update() function, we see that with the ```{ }```.

That means that this is going to work:



	void testApp:update(){
		int var = 50;
    
		if (var > 40){
    		cout << var << endl;	// OK
		}
	}



... but this not:



	void testApp:update(){
		int var = 50;
    
		if (var > 40){
    		int secondVar = 100; 
        	
    		cout << var << endl; // OK
		}
    
		cout << secondVar << endl; // ERROR: variable out of scope
	}
	


What I can do If I want to create a variable that can be accessed from ```setup()```, ```update()``` and ```draw()```?

Because each variable "lives" only inside the scope of the ```{ }``` that was declare it's impossible to make a variable inside the ```setup()```, ```update()``` and ```draw()``` that can be seen from all of them at the same time. We can create three variables, one in each function with the same name, but once that frame ends it's going to be destroyed to be created once again in the next iteration. But in that iteration it's going to lose its value. That's not handy. So what we can do in those cases is to declare that variable on the ```testApp.h```.

Remember, in a previous chapter we define the variables in the .h file as list of ingredients that we are going to use. Well that's the moment to tell the compiler that we want to create a memory container that will store something of some value that is going to be accessed by all the other functions in our testApp. 

For example let's say we want to store the position of the mouse in order to draw a circle. We capture the mouse position in the ```update()``` function and then we draw the circle in the ```draw()```. For that we need to store the x and y position in two integers variables. 


	#pragma once
	#include "ofMain.h"

	class testApp : public ofBaseApp{
	public:
    
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
		int x;
		int y;
	};
	

And then we are going to use to openFrameworks methods to get and assign the values of x and y to the position of the mouse on the x-axis and y-axis. These variables, ```ofGetMouseX()``` and ```ofGetMouseY()``` are native to oF, and allow us to track the position of the mouse on the screen.



	void testApp::update(){
    
    	x = ofGetMouseX();
		y = ofGetMouseY();
	}
	


Because we can ONLY draw in the ```draw()``` function now we write:



	void testApp::draw(){
		ofBackground(70,70,70);
    
		ofSetColor(255,255,255);
		ofCircle(x,y,50);
	}


## Combining Variables and Math operators

Now that we have an understanding of variables and where we can use them, how we use them becomes way more interesting when we start to place them in unexpected places and then include math into our code. Let us begin first by using our new mouse variables and assigning them to some new variables.

	int x = ofGetMouseX();
	int y = ofGetMouseY();

You can make a relationship between the position of the mouse with the color of the circle like this:



	void testApp::draw(){
		ofBackground(70);
    
		ofSetColor(x,y,255);
		ofCircle(x,y,50);
	}


Since color in this case is set to RGB values, this only works when the position is less than 255 on x and y axis. The key point here is to use some math in order to make sure that the number stay within the range that we want, in this case, 0 - 255.


	void testApp::draw(){

		ofBackground(70);
    
		// Here we are setting the size of the window
		ofSetWindowsShape(510,510);
	
		// We divide by 2 in order to get a range of 0 - 255
		ofSetColor(x/2,y/2,255);
		ofCircle(x,y,50);
	}


So Far, so good. 
Going back to the ```update()``` function and how we use variables we can explore the use of math in order to get nice effects. For example instead of making an assignment of ```x``` and ```y```to the mouse position we can add some math to make the circle move more smoothly in relation to the mouse. 



	void testApp::update(){
		x = ofGetMouseX();
		y = ofGetMouseY();
	}

Using math in our code includes using compound assignment operators, allowing us to shorten our code and focusing on what we are doing to the variable. Some of the operators include:

* ```+=```	addition
* ```-=```	subtraction
* ```*=```	multiplication
* ```/=```	division
 

First we subtract the current x value and use one of our compound assignment operators, turning:

	x = x + ofGetMouseX() - x;
	y = y + ofGetMouseY() - y;

which is the same as:

	x += ofGetMouseX() -x
	y += ofGetMouseY() - y;

and then complete it by multiplying by 0.1, giving us:


	void testApp::update(){
		x += (ofGetMouseX() - x ) * 0.1;
		y += (ofGetMouseY() - y ) * 0.1;
	}
	

So in each frame it just going to add a portion of the difference between the circle x&y position to the mouse x&y position 

This is a nice example of how variables and math will help us to make cool effects.

<br />

---
<br />

## Variable and conditions Operators 

There are times when you want to check the information of a variable. You could do that using: equal operator ==

* ```==```	… equal to … 
* ```!=```	… non-equal to … 
* ```>```	… greater than … 
* ```>=```	… greater than or equal to … 
* ```<```	… lesser than … 
* ```<=```	… lesser or equal to … 

The result of that it's a boolean variable. In other words these *"questions"* get true or false values. 

Booleans are the key for logic statements. Programming is pretty much the right use of the logic operator together with math. Sounds like fun, right?

<br />

---
<br />

![IF](https://raw.github.com/ofZach/ofDocs/master/img/chapter05/if.jpeg)

### IF statements

Let's transform our circle into a rectangle each time the ```x``` position is greater than ```300```
For that we are going to use a conditional method call IF. Basically works like this

	if ( THIS_IS_TRUE ){
		DO_THIS
	} else {
		DO_SOMETHING_ELSE
	}

So ..


	void testApp::draw(){
		ofBackground(70);
    
		ofSetColor(x/5,y/5,255);
    
		if ( x > 300){
    		ofSetRectMode(OF_RECTMODE_CENTER);
    		ofRect(x, y, 50, 50);
		} else {
    		ofCircle(x,y,50);
		}
	}
	

Well little by little this is beginning to take shape. In order to make this more complex you can add logic statements. For example, if the ```x``` position is greater that ```300``` **AND** ( represented by ```&&``` ) the y position is also greater than ```200```, 


	void testApp::draw(){
		ofBackground(70);
    
		ofSetColor(x/5,y/5,255);
    
		if ( (x > 300) && (y > 200)){
    		ofSetRectMode(OF_RECTMODE_CENTER);
    		ofRect(x, y, 50, 50);
		} else {
    		ofCircle(x,y,50);
		}
	}

Exercise: Try now something using **OR** ( represented by ```||``` ). 

Beside ***IF*** ( ) statements you can found ***WHILE*** loops, ***FOR*** loops and ***SWITCH***.

<br />

---
<br />

![WHILE](https://raw.github.com/ofZach/ofDocs/master/img/chapter05/while.jpeg)

### WHILE loops

Programming has to do a lot with choices but also is about repetition. Beautiful things come out of complexity and that can be achieved through repetition. Good thing about is, computers are made to do repeat tasks very fast and the don't need to rest, so we can take advantage of that. Every time you see that you are repeating something on your code, you can tell the computer to do it for you. Once again you only need to worry about the relationship with the numbers. 

We start by telling to the computer: while this variable is like this, do this. The code version of that is:

	while( THIS_IS_TRUE ) {
 		DO THIS   
	}

Going back to the previous example we can say:

	width = 400;
	height = 400;
	radius = width/4;

	ofSetWindowsShape(width,height);
    
	ofCircle(width/2, height/2, radius);
	ofCircle(width/2, height/2, radius/2);
	ofCircle(width/2, height/2, radius/3);
	ofCircle(width/2, height/2, radius/4);

As you can see we are repeating here. The only thing that is changing is the number by which we are dividing the radius ( 1, 2, 3, 4). So we can use a variable for that. This variable have to start on 1, and increment by one in each iteration of the loop.



	int divisor = 1;	// declaring and assigning the initial value of the index
    
	while (divisor <= 4 ){				// condition 
    	    ofCircle(width/2,height/2, radius/divisor);	// thing to repeat
    	    divisor++;					// increment 
	}
	


Initially, this seems more complicated but it is powerful and elegant tool to use.

In this case divisor is the number that counts the loops, the index. The increment of the index is what is called step. It is Also used to exit the loop. The risk here is to write a bad condition and the loop goes on forever. It’s called an infinite loop and can be a huge problem.



	int divisor = 1					// Initial value
	while (divisor <= 4 ){ 				// Condition
    	ofCircle(width/2,hegith/2, radius/divisor);
    	divisor++;					// Step
	}
	

<br />

---
<br />

![FOR](https://raw.github.com/ofZach/ofDocs/master/img/chapter05/for.jpeg)

### FOR loops

This structure we just learned is so powerful and you are going to use it so much that there is a specific function for it. Its call **FOR** loop. and work like this:

	for ( INDEX_INITIAL_VALUE ; INDEX_CONDITION ; INDEX_STEP){
		REPEAT THIS while INDEX_CONDITION is TRUE
	}

Applying this to the previous code we write:


	for (int division = 1; division <= 4; division++){
		ofCircle(width/2,hegith/2, radius/divisor);
	}


As you can see, our code its getting shorter and more complex. One important thing to be aware here is the scope of the division variable. If you look in the while loop example the variable was declared outside of the IF statement. Which means that the scope of that variable is contained within the if statement and outside of it. But, in the **FOR** loop this same variable is declared inside the for loop so you can only access it from inside the loop but not from outside of it.

Well this is a powerful tool, and as uncle Ben said, *“With great power comes great responsibility”*. Creating infinite for loops is easy and as you can imagine it will probably crash your program.


	for (int divisor = 1; divisor = 4; divisor++){
		ofCircle(width/2,height/2, radius/divisor);
	}
	

Like this example we forgot to write the < operator so the condition is more like an assignment which true all the time. Tada! You have an infinite loop.

<br />

---
<br />

![Switch](https://raw.github.com/ofZach/ofDocs/master/img/chapter05/switch.jpeg)

### Switch Statements

The last type of conditions are switch statements. They are used when you want to check the same variable through different options. Actually just like for loops are the easy way of having while loops (because it utilizes a commonly used structure ), switch is the easy way of making comparisons without using many **IF** statements.

So instead of saying:


	if ( THIS_IS_EQUAL_TO_THIS ){
		DO A PLAN
	} else if ( OR _THIS ){
		DO B PLAN
	} else if ( OR_THIS_OTHER ){
		DO C PLAN
	} else {	// or if it's not equal to neither this option
		DO D PLAN
	}
	

Using SWITCH we say


	switch ( VARIABLE ){
		case EQUAL_TO_THIS_VARIABLE:
			DO A PLAN
		break;
		case EQUAL_TO_THIS_OTHER_VARIABLE:
			DO B PLAN
		break;
		default:
			DO C PLAN
		break;
	}
	

<br />

---
<br />

![FOR](https://raw.github.com/ofZach/ofDocs/master/img/chapter05/tools.jpeg)

## OpenFrameworks block elements

openFrameworks some some block elements that can be used as variables for colors and positions. These are called ofColor and ofPoint.

These two elements can be passed to other openFrameworks functions like ```ofCircle()```, ```ofRect()``` or ```ofSetColor()``` and work in the right way.  The way we declare them is pretty much the same as any other variable type.

	ofPoint position;
	ofColor color;

But what changes a little bit is how you assign information to it. Because these elements are more like structures of data that contain variables. There are three ways of passing information. One is to "enter" spaces in the memory of the information:


	ofPoint position;
	position.x = 100;
	position.y = 100;

	// or

	ofColor color
	color.r = 255;
	color.g = 0;
	color.b = 0;


The other one it's to pack that information by saying:


	ofPoint position = ofPoint(100,100);
	ofColor color = ofColor(255,0,0);
	

Or the third way is by using what is called a method call ```.set()```:


	ofPoint position;
	position.set(100,100);

	ofColor color;
	color.set(255,0,0);


Then using this variable is easy as:


	float radius = 50;
	ofSetColor(color);
	ofCircle(position, radius);
	

As you can see we replace everything with variables. This is going to give us a lot of freedom to play with the relationship between these variables.

When you discover in the next chapters that ```ofColor``` and ```ofPoint``` have other building methods like ```.set()``` that let you do some AMAZING things really simply. Things like transforming from RGB to HSB, to rotate positions, get angles, add, substract, divides and multiple colors, etc.