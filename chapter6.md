# Working with media (test)

## Introduction, How oF deals with files. 
A lot of our daily life experience passes through our senses. 
The last 30 years we have seen how the computer gets smarter about how to deal with the information to record, process and how it reproduces it. We have seen the transition from orange monitors to black and white, 255 colors to VGA, HDMI and so on. The same has happened with how we represent sound. We have witnessed the whole process from bit sound to soundBlaster 16bits, MIDI control up to to the mp3 revolution.

OpenFrameworks as a creative coding toolbox gives you easy access to use video and sound and play with them. The use of media files like jpeg, png, videos and sound files is so powerful that they have a special folder. We care that much :)

OpenFrameworks uses the same standard name than Processing uses. It's called the "data" folder and it stores files in the same folder that our executable file is located. 

But why does it have its own folder? Isn't it better to put the media all together with the executable file? Well, it's set that way to make our life easy. When we compile on MacOS you finally get a executable file that has all the libraries that it uses inside. It's a self-contained package that you can explore by right-clicking on it and choosing "show package contents". But other operating systems like Windows and Linux don't do this. So at the end of the compiling process you get and executable file (*.exe in windows cases) and some other strange files called libraries (we talk about them in chap 2).
Because we probably are going to compile, re-compile and share our work it's clearer to separate data files from the executable ones. That's the goal of it.

Because openFrameworks is cross platform, it's enough intelligent to understand that for each different OS the distance and relationship between this data folder and the executable file will change. Once again, on Mac, the executable file is inside this little self-contained package so in order to see the data files it has to go down in the tree structure of the file system a couple of levels to see and access the data file ("../../data/") but in Linux and Windows the data folder is right next to the executable ( "data/").

By default you are going to use some oF tools to open and handle our media files. In case you want to do the old school way of loading a file you need to know how to get to the "data" folder. To do that you you can get the string of the full path to the data folder by using;

~~~~{.cpp}

	ofToDataPath( "myFile.txt" ); // return the complete data path to that specific file.
	
~~~~
	
In case you want to use another data file instead of the ```data/``` you can change it by doing 

~~~~{.cpp}

	ofSetDataPathRoot( "myNewAndDifferentDataFolder/" );

~~~~


## Introduction about Objects and "oF style"
In last chapter we ended with two oF special variable types: ```ofColor()``` and ```ofPoint()```. We present them as variables but they do so much more than contain information. The also have some handy functions embedded in it. Functions call methods that lets us do mathematical operations, rotations, translations and so much more. This conjunction of variables ( ```float x```, ```float y``` and ```float z```; or ```char r```, ```char g``` and ```char b```) are called objects. 

Object Oriented Programing is the core concept of C++. It's basically about the possibility of having data contained together with handy methods that know how to deal with the information in what we are going to call **classes**. 

**NOTE**: I would highly recommend opening the ```libs/openFrameworks/``` folder and taking a look at ```libs/openFrameworks/types/ofColor.h``` or ```libs/openFrameworks/types/ofVec3f.h``` (what's really ```ofPoint``` ) and see how these classes work. You don't need to understand everything you see, just take a look to all the wonderful functions that openFrameworks community have made for us to use. There is a lot of potential down there.

The same way the oF community prepares these objects they also put together some wonderful objects to handle media files. If we explore the ```libs/openFrameworks/``` a little more you will notice that there are classes for images ( ```ofImage``` ), sound ( ```ofSoundPlayer```), video ( ```ofVideoPlayer```) and typography (```ofTrueType```). Also there are some objects that help you deal with media buffers related to devices like our camera ( ```ofVideoGrabber```) and microphone (```ofSoundStream```).

These objects tend to repeat a pattern in the way of using them. That's what gives consistency to a framework. In the same way we have a ```setup()```, ```update()``` and ```draw()``` functions on the testApp, we have methods for media related objects to setup, update and draw. When dealing with files related objects you will find "loading" functions. For example:

~~~~{.cpp}

	ofImage myImage;
	myImage.loadImage("myJpegImage.jpg");

~~~~

or

~~~~{.cpp}

	ofVideoPlayer myVideo;
	myVideo.loadMovie("myVideo.mov");

~~~~
	
or 

~~~~{.cpp}

	ofSoundPlayer mySound;
    mySound.loadSound("mySound.mp3");

~~~~
    
or

~~~~{.cpp}

	ofTrueTypeFont myFont;
    myFont.loadFont("arial.ttf", 14);
    
~~~~

As you probably notice these "objects" are defined in the same way you define native C variables. So it's not strange to the eye. Then, once we make that object we can access the methods that "live" in it using a dot ```.```. So every time you want to access the object variables like:

~~~~{.cpp}

	ofPoint pos;
	pos.x = 100;
	
~~~~
	
or you access to one of his methods:

~~~~{.cpp}

	float length = pos.length()
	
~~~~

We are using ```.``` to access to inside of the object and deal with the information of that content.

Going back to the media object we just saw and the respective loading functions we then place the "settings" methods inside the ```setup()``` function. Why? Because it is in initial condition so we want to do it only once and at the beginning of the program. But, if you define the object in the setup you will not be able to call this object from another place like the ```update()``` or the ```draw()``` functions. Yes, because if you define them inside a function only lives inside it. It's the all problem related to scope that we saw in the last chapter. 

So we define them in the ```testApp.h```file:

~~~~{.cpp}

	#include "ofMain.h"

	class testApp : public ofBaseApp{
	public:
    
    	void setup();
    	void update();
    	void draw();
    	void exit();

    	void keyPressed  (int key);
    	void keyReleased(int key);
    	void mouseMoved(int x, int y );
    	void mouseDragged(int x, int y, int button);
    	void mousePressed(int x, int y, int button);
    	void mouseReleased(int x, int y, int button);
    	void windowResized(int w, int h);
    	void dragEvent(ofDragInfo dragInfo);
    	void gotMessage(ofMessage msg);
    
    	ofVideoPlayer  myVideo;
	};
	
~~~~

and then load the movie in ```setup()```, update in ```update()``` and of course , draw in ```draw()```.

~~~~{.cpp}

	#include "testApp.h"

	void testApp::setup(){
    	ofSetVerticalSync(true);
    	
    	myVideo.loadMovie("myVideo.mov");
    	myVideo.play();
	}
	
	void testApp::update(){
    	myVideo.update();
	}
	
	void testApp::draw(){
    	ofBackground(0);
    
    	myVideo.draw(0, 0);
	}

~~~~

You can see how in the case of ```ofVideoPlayer``` we play the file by using a method. But why do you need an ```update()```?  Well, that method is in charge of updating the image to the  next frame of our video. 

Also we are going to see more further in this chapter how in the ```.update()``` method we keep the information about pixels and texture. This is one step further.

First we have to get used to using these objects. The last step we have in the previous code is the drawing. As you can see using the autocompletion of our IDE, you can choose the place where you can ```.draw(int x, int y)``` and also the width and height of the area of the canvas.  ```.draw(int x, int y, int width, int height)```

//// EXAMPLE HERE

As you probably notice, by default it draws the images by the top right corner. You can change that default parameter in the same way we do that using ```ofSetRectMode(OF_RECTMODE_CENTER);``` for ofRects using one of these two commands

~~~~{.cpp}

	image.setAnchorPoint(x,y); 
	image.setAnchorPercent(x/100,y/100); 

~~~~
 
//// GRAPHICS HERE

