#Working with media

## Introduction, How oF deals with files. 
A lot of your daily life experience pass through your senses. 
The last 30 years we have seen how computer more and more smart about how to deal with the information to record, process and reproduces it. We have seen the transition from orange monitors to black and white, 255 colors to VGA, HDMI and so on. The same on sound, we have witness the hole process from bit sound to soundBlaster 16bits, MIDI control up to to mp3 revolution.

OpenFrameworks as creative coding toolbox gives you easy access to use them and play with them. The use of media files like jpeg, png, videos and sound files it's so command that that they have a special folder. That much we care : )

For it openFrameworks use the same standard name than Processing uses. it's call the "data" folder and it's store on the same folder that your executable file it's. 

But why it have his own folder? Isn't better to put the media all together with the executable file? Well, it's set that way to make your life easy. 
When you compile on MacOS you finally get a executable file that it have all the libraries that it use inside. It's a self-contain package that you can explore by right-clicking on it and choosing "show package". But the rest of the OS like windows and linux don't do this. So at the end of the compiling process you get and executable file (*.exe in windows cases) and some other estrange files call libraries ( we speak about them on chap 2).
Because you probably are going to compile, re-compile and share your work it's more clear to separate data files from the executable ones. That's the final goal of it.

Because openFrameworks its cross platform, it's enough intelligent to understand that for each different OS the distance and relationship between this data folder and the executable file will change. Once again, on Mac, the executable file it's inside this little self-contain package so in order to see the data files it have to go down in the tree structure of the file system a couple of levels to see and access the data file ("../../data/") but in linux and windows the data folder it's right next to the executable ( "data/").

By default you are going to use some oF tools to open and handle your media files. In case you want to do an old school loading of a file you want to know how to get to the "data" folder. To do that you you can get the string of the full path to the data folder by using;


	ofToDataPath( "myFile.txt" ); // return the complete data path to that specific file.

In case you want to use another data file instead of the ```data/``` you can change it by doing 

	ofSetDataPathRoot( "myNewAndDifferentDataFolder/" );


## Introduction about Objects and "oF style"
On last chapter we end up seen two oF special variable types: ```ofColor()``` and ```ofPoint()```. We present them as variables but they do so much more than contain information. The also have some handy functions embedded in it. Functions call methods that let you do mathematical operations, rotations, translations and so much more. This conjunction of variables ( ```float x```, ```float y``` and ```float z```; or ```char r```, ```char g``` and ```char b```) are call objects. 

Object Oriented Programing it's the core concept of C++. It's basically about this possibility of having data contained together with handy methods that know how to deal with this information in what we are going to call **classes**. 

**NOTE**:I would highly recommend to enter to your ```libs/openFrameworks/``` folder and take a look to ```libs/openFrameworks/types/ofColor.h``` or ```libs/openFrameworks/types/ofVec3f.h``` (what's really ```ofPoint``` ) and see how this classes work. You don't need to understand everything you see, just take a look to all the wonderful functions that openFrameworks community have made for your. There are a lot of potential for you down there.

The same way the oF community prepare this objects they code some wonderful objects to handle media files. If you explore a little more the ```libs/openFrameworks/``` you will notice that there are classes for images ( ```ofImage``` ), sounds ( ```ofSoundPlayer```), videos ( ```ofVideoPlayer```)and typographies (```ofTrueType```). Also there are some objects that help you deal with media buffers related to devices like your camera ( ```ofVideoGrabber```) and microphone (```ofSoundStream```).

This objects tend to repeat a pattern in the way of using them. That's what gives consistency to a framework. In the same way we have a ```setup()```, ```update()``` and ```draw()``` functions on the testApp, we have methods one media related objects to set, update and draw. When dealing with files related objects you will find "loading" functions. For example:

	ofImage myImage;
	myImage.loadImage("myJpegImage.jpg");
	
or

	ofVideoPlayer myVideo;
	myVideo.loadMovie("myVideo.mov");
	
or 

	ofSoundPlayer mySound;
    mySound.loadSound("mySound.mp3");
    
or

	ofTrueTypeFont myFont;
    myFont.loadFont("arial.ttf", 14);
    
As you probably notice this "objects" are defined in the same way as you define native C variables. So it's not strange to your eye. Then, once you make that object you will se you are accessing the methods that "lives" in it using a dot ```.```. So every time you want to access to object variables like:

	ofPoint pos;
	pos.x = 100;
	
or you access to one of his methods:

	float length = pos.lenght()

You are using ```.``` to access to inside of the object and deal with the information that content.

Going back to the media object we just present and the respective loading functions you will probably want to place this "setting" methods inside the ```setup()``` function. Why? Because takes time and you probably want to do it only once. But, if you define the object on the setup you will not be able to call this object from some other place like the ```update()``` or the ```draw()``` functions. Yes, because if you define them inside a function only lives inside it. It's the all problem related to scope that we see in the last chapter. 

So probably you want to define them on the ```testApp.h```file:

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

and then load the movie on the ```setup()```, update on the ```update()``` and, of course , draw it on ```draw()```.

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

You can see how in the case of ```ofVideoPlayer``` we have to give it play by using a method. But what do you need an ```update()```?  Well, that method it's in charge of updating the image to the one of the next frame of your video. 

Also we are going to see more further in this chapter how in the ```.update()``` method of image related object it's where keep the relation between pixels and texture. But this is one step further.

First we have to get used to using this objects. The last step we have in the previous code it's the drawing. As you can see using the autocompletion of your IDE, you can chose the place where you can ```.draw(int x, int y)``` and also the width and height of the canvas ```.draw(int x, int y, int width, int height)```

//// EXAMPLE HERE

As you probably notice, by default it draws the images by the top right corner. You can change that default parameter in the same way we do that using ```ofSetRectMode(OF_RECTMODE_CENTER);``` for ofRect's using one of this two commands

        image.setAnchorPoint(x,y); 
        image.setAnchorPercent(x/100,y/100); 


 
//// GRAPHICS HERE


## Going more into image related objects and what the have inside (incomplete)

What is very important to know about dealing with images objects like ofImage and ofVideoGrabber and ofVideoPlayer its that have to type of data.
One its the pictures... each one of the pictures colors... this is load in the RAM memory on the CPU. And the texture ( ofTexture ) that its store on the Graphic Card.

For the pixels are handy to get them and set them when you want to do image processing.

There are two different ways of getting the pixels.

//    OLD SCHOOL
unsigned char * pixels = image.getPixels(); // Its all up to you

pointer - a specific point in memory where the pixels.
///MORE EXPLANATION OF THIS NEED ( NOT TO DEEP ON PIXELS AND ARRAY because thats goint to be exapling in the future on ARRAYS )

and the

//    NEW STYLE 
ofPixels pixels = image.getPixelsRef();
getPixelsRef(); returns to ofPixels
getPixelsRef()l has functions wehre you can have access to color, as well as changing colors in specific pixels of our image. // j talking about images being a long array of pixels here  [j*w+i], by asigning an x and y

openframeworks works by passing by reference.
If you change the pixels you will need to call the update()

We store the image in two places (which are dynamic, changing):
The texture is stored in the GPU (ex: 4GB RAM), meaning, the graphic card memory
the pixels are stored in the CPU (ex: 512mb ATI) the computer memory, this is the copy of the image we manipulate. If we change the copy - the pixels -> we better update the "original" copy

a lot of times we see the word Ref in OF functions, and that would be passing by reference as opposed to passing by value. paasing by value (passing by copy) essentially makes a copy of the variable and stores it in the memory whereas passing by reference only passes the address of that object, which reducec the load on our procesor a lot. 
A good example of usage of this would be modifying pixels of a a video. If we ue pass by value, we will be copying a fram of (for example) 640*480, 60 times a second, which is not efficient at all. Instead, using pass by reference reducest he processing overhead by a lot lot lot. 

duuhhhhuuuudeee we have to remember our target audience.....i think the people who will be using this book are artists wanting to learn to do stuff with openFrameworks, not necessarily learn about computer science low levels. THOUGHTS?


### Playing with the pixels (incomplete)

#### Old school way
EXAMPLE of goign throught an image pixels OLD SCHOOL "unsigned char *" way + EXPLANATION of the math involve int pos = y * width + x

#### New way 
EXAMPLE of getPixelsRef() 


### What's a ofTexture and why it's so powerful (incomplete, I'll work on it - @patriciogv - )

== Image data stored on the graphic card. 
two different types: back in the days - has to be powers of 2. (regular texture)
Rectangular teture - can have any width and height.  
By default - ARB - an extention for open gl

##### How to use textures
How you are going to make planes from the vertex
ofMesh mesh;

mesh.set

coorners of the frame
mesh.addVertex( ofVec3f ) 

texture coordinate (where the texture it's glue to the canvas)
mesh.addTexCoords( ofVec2f )

// KALEIDOSCOPE EXAMPLE


Reference (GOOD IMAGES HERE SEE!!!! ):
http://www.creativeapplications.net/tutorials/guide-to-meshes-in-cinder-cinder-tutorials/


