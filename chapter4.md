#### Chapter_04:
# Setting up the drawing environment and Drawing basic 2d Graphics


### Intro to OpenGL:

To draw to the screen, OpenFrameworks uses a cross-language API that allows us to interact and draw to the GPU (Graphics Processing Unit). OpenGL has been around since 1992 and has been widely used in computer graphics.
OpenFrameworks makes it easier for us to draw to the GPU using OpenGL, providing us with more abstract, high level functions.


### Scopes/functions:

####1. setup( ); -- Setting up the environment

In order for us to start drawing in openFrameworks, we need to setup our drawing environment first, typically done in the scope of our setup(); function. setup(); is a function that runs only once at the beginning, and is used to set up things that will apply on the whole app/class. 

The most basic drawing settings are `ofBackground(r,g,b);` and `ofSetColor(r,g,b);` which respectively set up the background color and the color in which we our drawing will be rendered. `ofSetFrameRate(60);` will determine the number of frames per second and will affect the smoothness and speed of the moving objects we'll soon create.


    void testApp::setup(){
   		ofSetFrameRate(60);
        ofBackground(255,255,255);
        ofSetCircleResolution(100);
    }
    
You probably noticed a new function here which is ofSetCircleResolution(); in OpenFrameworks, circles are rendered by drawing repeating triangles that rotate around a common vertex. This function accepts one integer as input. The integer passed to this function is the number of triangles used to draw circles in our OpenFramworks application. Increasing the number of triangles will result in a smoother circle. 

_____________________________________________________________________________


#### 2. draw( ); -- OpenFrameworks draw function
Whenever you want to print something to the screen, static or dynamic, the function that draws that object (rectangle, circle, ellipse, etc....) should be placed within the draw function of our OpenFrameworks application:

        void testapp::draw(){
                    //PLACE YOUR DRAWING FUNCTIONS WITHIN HERE
        }
    
Much like the update(); function in OpenFrameworks which is repititevly being update, the draw function also loops. Both update() and draw() functions will loop at same rate of frames per second, as specified in the setup() `ofSetFrameRate(60)`;  What separates the two is that whatever is placed within the draw function should be dealing with shapes, images, text, or anything else you would like to be shown to the viewer. The update() is where the math and calculations are made. 

Everytime the draw function in openFrameworks is called, whatever was on the screen from the previous frame is wiped clear and replaced by what should be in the new frame.  If you decide you don't want to update/refresh your background you can then use `ofSetBackgroundAuto(boolean bManual)` and set the boolean value to `(false)`.
######Simple Graphics
To change the origin to the center of the rectangle instead of the left-top edge --
`ofSetRectMode(OF_RECTMODE_CENTER);`

###### Color and Transparency
Before drawing our custom shapes we should set a color and a drawing mode. The drawing mode in our program determines whether or not our line or shape will have a fill. To draw with fill, call the function `ofFill()` after you declare your drawing color and before drawing anything to the screen. 

* Note: the code is being read top to bottom, meaning, the drawing mode and color will affect any shape below it in the code, until specified other.

e.g: 

    ofSetColor(200,30,10);
    ofFill();
    ofRect(400,100,200,200);
    
In the same way, we can also draw without a fill color:

    ofSetColor(200,30,10);
    ofFill();
    ofRect(400,100,200,200);

######Displaying transparency in OpenFrameworks:

In OpenFrameworks, the alpha channel is turned off by default. In order to start using the alpha channel and blending, and to play with transparency and see the mixture and blending of overlaying colors, we call the function `ofEnableAlphaBlending();`
    Note: `ofEnableAlphaBlending();` should be called in the draw(); before drawing our shape, and should be terminated right after we are done with our shape by calling ofDisableAlphaBlending(); This is done for performance considerations.

e.g: 

	ofEnableAlphaBlending(0);
        ofSetColor(255,0,0,127);   // red, 50% transparent
        ofRect(450,430,100,33);


######OpenFrameworks and Blending Modes
        
Meet `ofEnableBlendMode(ofBlendMode blendMode)`

OpenFrameworks allows us to experiment with different blending modes: 

 1. OF_BLENDMODE_DISABLED - The default. No blending
 2. OF_BLENDMODE_ALPHA - calling ofEnableAlphaBlending(); activates this blending mode 
 3. OF_BLENDMODE_ADD - This will add the values of overlaying colors
 4. OF_BLENDMODE_SUBTRACT - This will substract the values of overlaying golors
 5. OF_BLENDMODE_MULTIPLY - This will multiply the color values for each pixel of the top layer with the corresponding pixel for the bottom layer.
 6. OF_BLENDMODE_SCREEN - With Screen blend mode the values of the pixels in the two layers are negated, multiplied, and then negated again. This yields an inverse effect from multiply.
    
To use different blending modes in OpenFrameworks, placed the selected mode within the brackets, like this:
`ofEnableBlendMode(OF_BLENDMODE_MULTIPLY)`

    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        ofSetColor(255,0,0,127);   // red, 50% transparent
        ofRect(450,430,100,33);
    ofDisableBlendMode();
    
######Setting colors in openframeworks

To set a color, use the ofSetColor(); function.
Using ofSetColor(); we can directly pass either color values or ofColor objects to instantly change the drawing color. We can use this function in a number of different ways:

  **1 -** Defining R, G, and B values (all ranging from 0 - 255)
    e.g: `ofSetColor(255,23,10); // r,g,b`

  **2 -** Passing one integer that determines the shade of gray. This one integer effectively passing three equal values for Red, Blue and Green to the function, which will result in a gray color

    e.g: `ofSetColor(140);` // r,g,b == 140


  **3 -** Defining R, G, B and Alpha values (The Alpha value determines the opacity of the color (all ranging from 0 - 255)
   e.g: `ofSetColor(255,23,10,255); // r,g,b,alpha`
   
  **4 -** Passing one integer that determines the shade of gray and Alpha values.
   e.g: `ofSetColor(140, 100); // gray(r,g,b) + alpha`

  **5 -** Using the [ofColor](http://). <br>
  
   Passing an [object](http://) of the [datatype](http://) ofColor to the function in a few steps:
   
   **a** Declared and initialized 'myColor' in the testApp.h: `ofColor myColor;`
   **b** Declared and initialized 'myColor' in the testApp.cpp setup(); : 

      void testApp::Setup(){
       // setting up myColor to be orange 
        myColor.r = 255;
        myColor.g = 130;
        myColor.b = 0;   
    }
  
  **c** Declared and initialized 'myColor' in the testApp.cpp draw(); : 

    void testApp::draw(){
        ofSetColor(myColor);
        ofCircle(200,200,20);    
    }    
   
   **6 -** Passing an object of the datatype ofColor along with an alpha value to the function:
         
  testApp.h
    
    ofColor myColor;
         
   testApp.cpp
   
     void testApp::Setup(){
        // setting up myColor to be orange 
        myColor.r = 255;
        myColor.g = 130;
        myColor.b = 0;   
    }
    
    void testApp::draw(){
        ofSetColor(myColor, 100); // Setting the color to a semi-transparent orange with an alpha value of 100
        ofCircle(200,200,20);    
    } 
        

 Note that we can set the values of our ofColor object in a number of different ways:
        a. testApp.h:
                ofColor myColor;
            testApp.cpp:
                myColor.set(255,130,0); // orange
        b. testApp.h:
                ofColor myColor;
            testApp.cpp:
                myColor.set(130,100); //   gray, with an opacity of 100/255
        c. testApp.cpp:
                ofColor myColor1(255,130,0); // orange
                ofColor myColor2(myColor1); // same as myColor1, orange
        d. testApp.h:
                ofColor myColor;
            testApp.cpp:
                myColor.setHex(0xff0033); // red, passing hexadecimal value to the funciton;
        e. testApp.h:
                ofColor myColor;
            testApp.cpp:
                myColor.setHex(0xff003,100); // red with an opacity of 100/255
        f. testApp.h:
                ofColor myColor;
            testApp.cpp:
                myColor.setHsb(100,255,80); // using hsb colos system, setting Hue, Saturation and Brightness values from 0 - 255 
                  
    
   **7 -** passing a Hexadecimal value to the function
    e.g: `ofSetHexColor(0xff0033);`
    
  * Note: The first two characters passed to the function (0x) indicates that the following expression is a hexadecimal value, so our program will know how to interpret that.

  
######Smoothing


We can smooth out our **lines** in OpenFrameworks by simply calling:
    `ofEnableSmoothing();`
and turning it off using:
    `ofDisableSmoothing();`
    
    
######Drawing custom shapes in OpenFrameworks

So far we have seen how we can draw primitive shapes in OpenFrameworks. But what if we want to draw a custom shape to the screen? One way of easily achieving this goal is by calling the ofBeginShape() function. Once this function is called, we can go ahead and add as many points as we want. One way of declaring points in OpenFrameworks is by using the function ofVertex(); and pass the x, y and z values to it. This will draw our point on the screen in desired coordinates on our page. Once we are done declaring points, it is time for us to declare our shape finished with the `ofEndShape()`.
So, simply put, to draw a custom shape in OpenFrameworks:

     ofBeginShape();
          ofVertex(x1,y1,z1);
          ofVertex(x2,y2,z2);
          .
          .
          .
          ofVertex(xn,yn,zn);
     ofEndShape();

* Note: the function `ofEndShape(bool bClose)` accepts one boolean parameter that determines whether or not we want to close he shape tha we are drawing. The default for this is true. Meaning that OpenFrameworks will close our polyline object for us. 
If you want to leave the shape open, try this: `ofEndShape(false);`



######openFrameworks coordiante system

When wanting to draw a shape or any object within the window, you should know where you want to draw.  This location can be translated to a x and y coordinate.  The top left corner of the screen in which the application lives in is the (0, 0) coordinate. As you move from the left to the right the x-coordinates is increasing.  As you move from top to bottom the y-coordinates are increasing.  The bottom right portion of the screen would equal the app dimensions as you specified in the [ofMain.h.](http://): if you set your screen window size to 1024, 768 then the bottom right coordinates should be  x = 1024 and y = 768.  Openframeworks provides functions to get the width or height of the window, `ofGetWidth()` and `ofGetHeight()`.  Which can be set as the value for a variable or simply used for the location of something you want to print to the screen.  So for example if you want to print something to the middle of the screen, you can easily get these coordinates by setting the x to ofGetWidth()/2 and y to ofGetHeight()/2.

######Creating x and y valuse with ofPoint

Openframeworks has a class called [ofPoint](http://) in which you can then store an x and y coordinate.  This allows your code to be a little less dense and somewhat more organized by keeping information that is related together.  

To use ofPoint you create an instance of it like:

In the testApp.h
`ofPoint position`
The first part is telling the computer which type of object to create and the second part (position) is naming that instance so you can then refer to it later.

In the testApp.cpp
There are different ways to set the x and y coordinates within our position object.  
First way:

	position.x = 100;
	position.y = 250;
Second way:

	position.set(100, 250); //(x,y)
These both do the same thing.

######Shapes and Primitives

The simplest way to start experimenting within the draw function is through the use of shapes and primitives.  

Openframeworks has within it classes for drawing a circle, rectangle/square, triangle and a simple line.  

Here is the syntax for each:


`ofCircle(x, y, radius);` <br>
`ofRect(x, y, width, height);`<br>
`ofTriangle(x1,y1,x2,y2,x3,y3);`<br>



######Transformations Matrix Push Pop

Imagine when you are drawing, you're drawing on a graph paper. In this case the graph paper is the pixel grid. What if we want to shift our drawing somehow? 

Linear Algebra: A box numbers of for transformation, rotation, translation, etc..
This box of numbers takes anything you pass into it and it outcomes a point.
Matrix = a box of numbers
push() = takes the beginning state. Taking a snapshot of the matrix that exists now
pop = gives the end result
[illustration: show the original coordinate system + a translated one]
[illustration: show a nested push/pop matrix, ontop of the original matrix] //maybe a gif animation here

ofRotate(); ofScale();
are both made in corellation to the origin (0,0) point.
Push /pop matrix, and set a new origin point with the ofTranslate(x,y). Everything shape drawn between the push/pop and beneath the ofTranslate will be drawn in corellation to the ofTranslate given x and y.  

if we want to have a shape rotate around itsel, we should ofTranslate() first, and then start ofRotate(). Here, we're effectively translating the whole coordinate system including the (0,0) point to a new location and use that as the basis for our ofRotate() function.
note that this all happens inside the push and pop matrix.

