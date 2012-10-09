Chap_4: DRAWING


open GL - library for interfacing with graphics card in your computer
- people will typically draw to the screen using their open GL
- its been around for a while, so there is a lot of documentation for it
Openframeworks provides us with high level drawing tools that are translated to a more complicated OPENGL language.

Other options for drawing to screen: other graphics engines like Cairo



OpenGL is an engine that draws in triangles. Other shapes are based on triangles. (ofSetCircleResolution() increases the number of triangles that make up that circle, effectively making it smoother)
Insert circle graphic here, there's one in the OF documentation website in ofSetCircleResolution()


Graphic state:
setting states like ofSetColor - adjusting the color
ofSetFill - allows you to create shapes with filling or with no filling
that applies to any graphic  until there's a new state 

For all drawing functionalities, the user should be in the draw function
- at the beginning of the draw function, the entire screen is cleared. This happens every time the draw loop starts over

Drawing in the update will be updated every frame, you won't even see it.
ofSetBackgroundAuto(boolean value);

ofSetVerticalSync = whenever you draw it is synchronized with your screen refresh rate

ofsetFrameRate = how fast frames are refreshed (60 frames / per sec);
limits the the frame rate by giving a maximum upper bound


Primitive Shapes

primitive shapes in OF (include primitive shape functions here): 
- ofRect();
- ofCircle();
- ofLine(); 
- ofTriangle();

coordinate system is based on upper left corner (0,0) [insert a simple coordinate system illustration here] [ code example - with graphics that explains exactly which line of code doing what in the graphic(commented code)]

more complex drawing example explained, line by line, describing what each and every function, variable and value does. - i.e: draw the OF logo.


If you want to draw a red rectangle located at (0,0) that is 20px by 10px you would write the following lines in the draw loop:
    ofFill();
    ofSetColor (255,0,0);
    ofRect (0,0,20,10);

include examples here that use native variables (i.e., mouseX, mouseY, etc)

To draw a polyline (a line with multiple points, and no color filling (just outline)):
    
    ofNoFill();
    ofBeginShape();
        ofVertex(100,100);
        ofVertex(200,100);
        ofVertex(250,150);
        ofVertex(50,150);
    ofEndShape(true); //the 'true' tells oF to connect the last point to the first

More complex shapes:
    
To draw a polygon - a filled in shapeWhen with ofFill() - creates a filled shape = polygon  
    
    ofSetColor (255,0,0);
    ofFill();
    ofBeginShape();
        ofVertex(100,100);
        ofVertex(200,100);
        ofVertex(250,150);
        ofVertex(50,150);
    ofEndShape(true); //the 'true' tells oF to connect the last point to the first


Two types of curves that we use in OF:

- Bezier (using controll points) - your line goes from the first point to the second point, going through the third and fourth points as controllers)
    ofBezier [illustration of bezier first and last points + two control points]
     [illustration of Catmull first and last points + two control points]

- Catmull (we have four points, the first and the last point are controlles, and the two in the middle are the beginning and end of our curved line)

-ofpath and polyline are objects that help us draw complex objects more easily.

Color

 RGB, Alpha - the 4th parameter. alpha values- 0 to 255 (same as the RGB channels)
By default alpha channel is turned off. In order to start using the alpha channel and blending, meaning that if we want to play with transparency and see the mixture of overlaying colors, we call the ofEnableAlphaBlending();

To set the color to a blue 50% opacity:
 Enable and disable the alpha processing to keep it light

ofEnableAlphaBlending();
ofSetColor (0, 250, 0, 127);
Don't forget to Disable when done 'using' alpha

Painter's algorithm 

ofColor object.
Enable HSB color mode (hue - saturation - brigthness) 

Super useful for drawing:
ofPath();
ofPolyLine();
ofMesh();

we can use the ofMesh object to define different properties for different points. ofMesh object allows us to draw on a lower level.



// ofPath;
    // ofPolyline;
    ofMesh myMesh;
    myMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    myMesh.addColor(ofColor::red);
    myMesh.addVertex(ofPoint(100,100));
    myMesh.addColor(ofColor::white);
    myMesh.addVertex(ofPoint(200,100));
    // myMesh.addColor(ofColor::white);
    myMesh.addVertex(ofPoint(100,200));
     //myMesh.addColor(ofColor::white);
    myMesh.addVertex(ofPoint(200,200));
    
    myMesh.draw();

Transformations

Imagine when you are drawing, you're drawing on a graph paper. In this case out graph paper is the pixel grid. What if we want to transform our drawing somehow? 


Linear Algebra: A box numbers of for transformation, rotation, translation, etc..
This box of numbers takes anything you pass into it and it outcomes a point.
Matrix = a box of numbers
push() = takes the beginning state. Taking a snapshot of the matrix that exists now
pop = gives the end result
[illustration: show the original coordinate system + a translated one]
[illustration: show a nested push/pop matrix, ontop of the original matrix] //maybe a gif animation here

ofRotate(); ofScale();
are all made in corellation to the 0,0, the origin point.
Push /pop matrix, and set a new origin point with the ofTranslate(x,y). Everything shape drawn between the push/pop and beneath the ofTranslate will be drawn in corellation to the ofTranslate given x and y.  

if we want to have a shape rotate around itsel, we should ofTranslate() first, and then start ofRotate(). Here, we're effectively translating the whole coordinate system including the (0,0) point to a new location and use that as the basis for our ofRotate() function.
note that this all happens inside the push and pop matrix.

ofSetRectMode(OF_RECTMODE_CENTER); //use this to change the origin to the center of the rectangle instead of the left-top edge

------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------


Chap_4: DRAWING (written by Michael Gonzalez + Mani Nilchiani)

INTRO:
open GL - library for interfacing with graphics card in your computer

To draw to the screen, OpenFrameworks uses a cross-language API that allows it to interact and draw to the GPU (Graphicd Processing Unit). OpenGL has been around since 1992 and has been widely used in computer graphics.
OpenFrameworks makes it easier for us to draw to the GPU using OpenGL, by providing us with more abstract, high level functions.
_____________________________________________________________________________

1 - Setting up the environment:
In order for us to start drawing in openFrameworks, we need to setup our drawing environment first.
The most basic drawing settings are ofBackground(r,g,b); and ofSetColor(r,g,b); which respectively set up the background color and the color in which we our drawing will be rendered.

Typically, setting up the drawing environment is done in the scope of our setup(); function.  

    void testApp::setup(){
        ofBackground(255,255,255);
        ofSetCircleResolution(100);
    }
    
You probably noticed a new function here which is ofSetCircleResolution(); in OpenFrameworks, circles are rendered by drawing repeating triangles that rotate around a common vertex. This function accepts one integer as input. The integer passed to this function is the number of triangles used to draw circles in our OpenFramworks application. 
Increasing the number of triangles will result in a smoother circle. 

_____________________________________________________________________________


2 - OpenFrameworks draw function:
Whenever you want to print something to the screen, static or dynamic, the function that draws that object (rectangle, circle, ellipse, etc....) should be placed within the draw function of our OpenFrameworks application:

        void testapp::draw(){
                    //PLACE YOUR DRAWING FUNCTIONS WITHIN HERE
        }
    
Much like the update() function in OpenFrameworks which is repititevly being update, the draw function also has a recursive nature.  What separates the two is that whatever is placed within the draw function should be dealing with shapes, images, text, or anything else you would like to be shown to the viewer. 

Everytime the draw function in openFrameworks is called, whatever was on the screen from the previous frame is wiped clear and replaced by what should be in the new frame.  If you decide you don't want to update/refresh your background you can then use ofSetBackgroundAuto(boolean bManual) and set the boolean value to false.

/* Color and Transparency */
Before drawing in OpenFrameworks, we should set out drawing mode. The drawing mode in our program determines whether or not our line or shape will have a fill. To draw with fill, call the function ofFill(); after you declare your drawing color and before drawing anything to the screen.

e.g: 
    ofSetColor(200,30,10);
    ofFill();
    ofRect(400,100,200,200);
    
In the same way, we can also draw without a fill color:

    ofSetColor(200,30,10);
    ofFill();
    ofRect(400,100,200,200);

Displaying transparency in OpenFrameworks:

In OpenFrameworks, the alpha channel is turned off by default. In order to start using the alpha channel and blending, and to play with transparency and see the mixture and blending of overlaying colors, we call the function ofEnableAlphaBlending();
    Note: ofEnableAlphaBlending(); should be called in the draw(); before drawing our shape, and should be terminated right after we are done with our shape by calling ofDisableAlphaBlending(); This is done for performance considerations.

e.g: 
ofEnableAlphaBlending(0);
        ofSetColor(255,0,0,127);   // red, 50% transparent
        ofRect(450,430,100,33);
ofDisableAlphaBlending();

OpenFrameworks and Blending Modes

OpenFrameworks allows us to also experiment with other blending modes:

    1- OF_BLENDMODE_DISABLED - The default. No blending
    2- OF_BLENDMODE_ALPHA - calling ofEnableAlphaBlending(); activates this blending mode 
    3- OF_BLENDMODE_ADD - This will add the values of overlaying colors
    4- OF_BLENDMODE_SUBTRACT - This will substract the values of overlaying golors
    5- OF_BLENDMODE_MULTIPLY - This will multiply the color values for each pixel of the top layer with the corresponding pixel for the bottom layer.
    6- OF_BLENDMODE_SCREEN - With Screen blend mode the values of the pixels in the two layers are negated, multiplied, and then negated again. This yields an inverse effect from multiply.
    
    To use different blending modes in OpenFrameworks:
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        ofSetColor(255,0,0,127);   // red, 50% transparent
        ofRect(450,430,100,33);
    ofDisableBlendMode();
    
Setting colors in openframeworks:

To set a color, use the ofSetColor(); function.
Using ofSetColor(); we can directly pass either color values or ofColor objects to instantly change the drawing color. We can use this function in a number of different ways:
    1 - Defining R, G, and B values (all ranging from 0 - 255)
    e.g: ofSetColor(255,23,10);

   2 - Defining R, G, B and Alpha values (The Alpha value determines the opacity of the color* - All ranging from 0 - 255)
   e.g: ofSetColor(255,23,10,255);
  
  3 - Passing an object of the datatype ofColor to the function.
   e.g: ofSetColor(myColor);
   Note that in this case, you should have already declared and initialized 'myColor' to be able to use it here:
   // testApp.h
   ofColor myColor;
   // testApp.cpp
   void testApp::Setup(){
       // setting up myColor to be orange 
        myColor.r = 255;
        myColor.g = 130;
        myColor.b = 0;   
    }
    void testApp::draw(){
        ofSetColor(myColor);
        ofCircle(200,200,20);    
    }    
   
   4 - Passing an object of the datatype ofColor along with an alpha value to the function:
   e.g: ofSetColor(myColor,100);
    // testApp.h
   ofColor myColor;
   // testApp.cpp
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
        

Creating Colors in openFrameworks:

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
    5 - passing one integer that determines the shade of gray.
    e.g: ofSetColor(140);
    Note: You can maging that by passing one integer, you are effectively passing three equal values for Red, Blue and Green to the function, which will result in a gray color
    
    6 - passing a Hexadecimal value to the function
    e.g: ofSetHexColor(0xff0033);
    Note: The first two characters passed to the function (0x) indicates that the following expression is a hexadecimal value, so our program will know how to interpret that.
  
/* Smoothing */
We can smooth out our lines in OpenFrameworks by simply calling:
    ofEnableSmoothing();
and turning it off using:
    ofDisableSmoothing();
    
/* Drawing custom shapes in OpenFrameworks */
* So far we have seen how we can draw primitive shapes in OpenFrameworks. But what if we want to draw a custom shape to the screen? One way of easily achieving this goal is by calling the ofBeginShape() function. Once this function is called, we can go ahead and add as many point as needed. One way of declaring points in OpenFrameworks is by using the function ofVertex(); and pass the x, y and z values to it. This will in effect draw our point on the screen in desired coordinates on our page. Once we are done declaring points, it is time for us to declare our shape finished. For this purpose, we conveniently call the ofEndShape().
So, simply put, to draw a custom shape in OpenFrameworks:

     ofBeginShape();
          ofVertex(x1,y1,z1);
          ofVertex(x2,y2,z2);
          .
          .
          .
          ofVertex(xn,yn,zn);
     ofEndShape();

Defining a fill color before drawing our custom shape will effect in a convenient fill color for our shape.
* Note: the function ofEndShape() accepts one boolean parameter that determines whether or not we want to close he shape tha we are drawing:    
    ofEndShape(bool bClose);
    The default for this is true. Meaning that OpenFrameworks will conveniently close our polyline object for us. 
    




Shapes and Primitives

When wanting to draw a shape or any object within the window something that is neccesary to know is where you want to draw.  This location can be translated to a  x and y coordinate.  The   top left corner of the screen in which the application lives in is (0, 0) as you move from the left to the right the x-coordinates is increasing.  As you move from top to bottom the y-coordinates are increasing.  The bottom right portion of the screen would equal the dimensions that you set in ofMain.h.  So if you set your screen window size to 1024, 768 then the bottom right coordinates should be  x = 1024 and y = 768.  Openframeworks provides functions to get the width or height of the window, ofGetWidth(); and ofGetHeight().  Which can be set as the value for a variable or simply used for the location of something you want to print to the screen.  So for example if you want to print something to the middle of the screen, you can easily get these coordinates by setting the x to ofGetWidth()/2 and y to ofGetHeight()/2.  Openframeworks has a class called ofPoint in which you can then store an x and y coordinate.  This allows your code to be a little less dense and somewhat more organized by keeping information that is related together.  
To use ofPoint you create an instance of it like:

ofPoint position  -> the first part is telling the computer which type of object to create and the second part (position) is naming that instance so you can then refer to it later.
There are different ways to set the x and y coordinates within our position object.  
First way:
position.x = 100;
position.y = 250;
Second way:
position.set(100, 250);
These both do the same thing.

The simplest way to start experimenting within the draw function is through the use of shapes and primitives.  

Openframeworks has within it classes for drawing a circle, rectangle/square, triangle and a simple line.  

Here is the syntax for each:

ofCircle(x, y, radius);
ofRect(x, y, width, height);
ofTriangle(x1,y1,x2,y2,x3,y3);  


Transformations Matrix Push Pop

Imagine when you are drawing, you're drawing on a graph paper. In this case out graph paper is the pixel grid. What if we want to transform our drawing somehow? 


Linear Algebra: A box numbers of for transformation, rotation, translation, etc..
This box of numbers takes anything you pass into it and it outcomes a point.
Matrix = a box of numbers
push() = takes the beginning state. Taking a snapshot of the matrix that exists now
pop = gives the end result
[illustration: show the original coordinate system + a translated one]
[illustration: show a nested push/pop matrix, ontop of the original matrix] //maybe a gif animation here

ofRotate(); ofScale();
are all made in corellation to the 0,0, the origin point.
Push /pop matrix, and set a new origin point with the ofTranslate(x,y). Everything shape drawn between the push/pop and beneath the ofTranslate will be drawn in corellation to the ofTranslate given x and y.  

if we want to have a shape rotate around itsel, we should ofTranslate() first, and then start ofRotate(). Here, we're effectively translating the whole coordinate system including the (0,0) point to a new location and use that as the basis for our ofRotate() function.
note that this all happens inside the push and pop matrix.

ofSetRectMode(OF_RECTMODE_CENTER); //use this to change the origin to the center of the rectangle instead of the left-top edge