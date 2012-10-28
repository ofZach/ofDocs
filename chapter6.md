# Working with media

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

// how images are handle on OF ( texture / pixels relation ) 
// GPU vs CPU
// 
// and how in CPU style there are two ways of getting and playing width pixels. Old and new way
// I have a Spanish versions here [https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad4/Cap_1_pixel_x_pixel.md](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad4/Cap_1_pixel_x_pixel.md) but need the new style way… maybe Isac or Juan want to used as reference or translate it.
// 

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


### What's a ofTexture and why it's so powerful (incomplete, I'll work on it - @patriciogv - )

What is a texture and why it's so different from the idea of a Image. Well when we thing about images we tend to think on pictures. That usually means a image inside a rectangle frame, that have pixels inside. That pixels as we know now are essentially an array list that the computer know how to arrange in a specific way. Al that it's usually related to the way CPU process and work with images.
But when GPU start to appear engineers realize that it could be more and different ways to use images in order to give much more flexibility and decide to empower new ways of drawing with specify hardware tweaks.
That's when Textures born. They where conceive as 1D, 2D or 3D arrays of fragments of images that are mount on top of wireframes made by vertex. This lead to new and powerful ways of contracting 3D elements. 

It's pretty much like the making of a armchair. First you assemble the wood peaces that will be the rigid structure where the fabric will be mounted. To keep things easy we are going to speak only about 2D Textures and we are going to image them as the fabric. 

![ofTexture1](https://www.dropbox.com/s/t8k49jspiprgvms/ofTexture01.jpeg)

In fact at the beginning this 2D Textures had to be squared and power of 2. And they were used as wallpapers so they repeat them self once and once over again. 

// IMAGE HERE

This makes things really complicated to use regular images like the once we are going to use. So after a while a new type of texture was develop call ARB 2D Textures. This last type of texture it's the default one on openFrameworks. Ofcourse you can switch this ON of OFF by using:

	ofEnableArbTex();
    ofDisableArbTex();

Going back to the armchair metaphor, the first step it's by positioning the vertex and how they are going to be linked together. We already have done something similar to this on the Chapter 4 when we make 2D shapes using ```ofVertex(x,y);```. It's the same concept of connection dots. But now that you already know that we can go further and learn that you can choose how this point are going to be linked together. There are difference ways. 

// IMAGE HERE

When we want to mount textures over this shapes at the same time we are setting vertexes position we have to specify witch part of this "fabric" that we call Texture it's going to be mount where. 
Here we are making are making the role of a carpenter and a upholsterer at the same time. 

Let's jump to the code. For that we are going make what it's call a **mesh** (ofMesh).
Meshes are this pact of information of vertexes, how to arrange them and it relation to where to mount the texture on top of them.

I know, it sound complex. But the good news it's that all this is empower by the GPU card and will be manufacture by it. This engineers that work on Graphics Cards provide them with his own memory. This memory it's dirtily attached to a lot of mini-micro-processors that run in parallel on super fast speed. Each one of this micro-processors only take care on the positioning of one vertex and one fragment of image. It's like having a big army of little ants that are really dumm. The power of this army it's related to his number and the fact that each one do only one thing in parallel to the other one. But all respect the same time table. First all are going to process the vertex, then how they are going to linked this vertex and finally how the are going to mount and process the fragments of images store in the GPU memory. 

// IMAGE HERE

This is what is call GPU Pipeline. You know what's the best of it? It could be re-programmed! Just like a lot of Arduinos you could reprogram the firmware of this ants to treat vertex, geometrics or fragments on a different way. That's what it's call replace the defaults shaders. But we are not going to go so far on this chapter. 

Let's start making a simple mesh. And play with it.

	ofMesh myMesh;
	
We are going to start by deciding with type of Primitive mode you want. This means how you want to group your vertex. The most frequent and common is triangles. Because they are flexible and could be arrange in any type and shape. Just like we learn in chapter 4 when we see how circles are made.
So let's start by making a 640x480 rectangle using 6 vertexes grouped inside 2 triangles.
	
~~~~{.cpp}

	void testApp::draw(){
    	ofBackground(0);
    
    	ofSetColor(255);
    
    	ofMesh myMesh;
    
    	myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    	myMesh.addVertex(ofPoint(0,0));			// A
    	myMesh.addVertex(ofPoint(640,0));		// B
    	myMesh.addVertex(ofPoint(640,480));	// C
    
    	myMesh.addVertex(ofPoint(640,480));	// C
    	myMesh.addVertex(ofPoint(0,480));		// D
    	myMesh.addVertex(ofPoint(0,0));			// A
    
    	myMesh.draw();
	}

~~~~

//	IMAGE HERE
//
//	A -- B 
//	| \	 |
//	|  \ |
//	D -- C 
//
	
Play a little with this code by changing the parameters and commenting some lines. Try to push the limits of this example to have a concrete idea of how openGL works. Oh ups… I almost forgot, congratulations you are almost one step away to direct openGL programming. Feel great about your self because you are using one of the most powerful and heavy graphics motor ever made. OpenFrameworks here it's just helping you with the cross platform compatibility but you are learning the roots of openGL and how it works. Congratulations.

But this white rectangle doesn't seem so exiting. Isn't?
We are going to add some excitement to it by adding the coordinates where to mount this textures. 

	myMesh.addTexCoord(ofPoint(0,0));
    myMesh.addVertex(ofPoint(0,0));
    myMesh.addTexCoord(ofPoint(640,0));
    myMesh.addVertex(ofPoint(640,0));
    myMesh.addTexCoord(ofPoint(640,480));
    myMesh.addVertex(ofPoint(640,480));
    
    myMesh.addTexCoord(ofPoint(640,480));
    myMesh.addVertex(ofPoint(640,480));
    myMesh.addTexCoord(ofPoint(0,480));
    myMesh.addVertex(ofPoint(0,480));
    myMesh.addTexCoord(ofPoint(0,0));
    myMesh.addVertex(ofPoint(0,0));

The last step here it's to "bind" a interesting texture on top of this mesh. For that we are going to use the ```ofVideoGrabber``` and request for the ```ofTexture```of it. As we saw previously all image based objects like: ```ofImage```, ```ofVideoGrabber``` and ```ofVideoPlayer```have both type information attach to them. One for CPU Ram and the other on GPU Ram. ```ofTextures```can't be load directly from a file. Basically they are links to the place they are on your Graphic Card Memory. You can get this "link" and passed to your ```ofTexture```by doing ```.getTextureReference()```on any of this image based objects. In the case of your video grabber you can do that by typing:

	ofTexture myTexture = myVideo.getTextureReference();
	
It's always a good idea to explore openFrameworks objects. You can learn so much by simply reading the ```.h``` where this classes are defined. You can right click over ```ofTexture```and clicking over "Jump To Definition".

Any way, once you have the ```ofTexture``` you can applied it over this mesh by using:

	ofTexture myTexture = myVideo.getTextureReference();
	
	myTexture.bind();
    myMesh.draw();
    myTexture.unbind();

Also as you know you know you on Object Oriented Programing you can get into objects constantly using the dot ```.``` so instead of getting the texture and then using it you can do all in one step by saying.

	myVideo.getTextureReference().bind();
    myMesh.draw();
    myVideo.getTextureReference().unbind();

Any way the complete code for this example is:

testApp.h

~~~~{.cpp}
	
	#pragma once
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
    
    	ofVideoGrabber  myVideo;
	};

~~~~

testApp.cpp

~~~~{.cpp}
	#include "testApp.h"

	void testApp::setup(){
    	ofSetVerticalSync(true);
    	myVideo.initGrabber(640, 480);
	}

	void testApp::update(){
    	myVideo.update();
    
	}
	
	void testApp::draw(){
    	ofBackground(0);
    
    	
    
    	ofMesh myMesh;
    
    	myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    	myMesh.addTexCoord(ofPoint(0,0));
    	myMesh.addVertex(ofPoint(0,0));
    	myMesh.addTexCoord(ofPoint(640,0));
    	myMesh.addVertex(ofPoint(640,0));
    	myMesh.addTexCoord(ofPoint(640,480));
    	myMesh.addVertex(ofPoint(640,480));
    
    	myMesh.addTexCoord(ofPoint(640,480));
    	myMesh.addVertex(ofPoint(640,480));
    	myMesh.addTexCoord(ofPoint(0,480));
    	myMesh.addVertex(ofPoint(0,480));
    	myMesh.addTexCoord(ofPoint(0,0));
    	myMesh.addVertex(ofPoint(0,0));
    
    	ofSetColor(255);
    
    	myVideo.getTextureReference().bind();
    	myMesh.draw();
    	myVideo.getTextureReference().unbind();
	}

~~~~

Take your time to play and explore this example by changing, commenting out, etc. Specially try to play as much as you can with the Texture Coordinates by doing replacing button left coords for the mouse position:

	myMesh.addTexCoord(ofPoint(0,0));
    myMesh.addVertex(ofPoint(0,0));
    myMesh.addTexCoord(ofPoint(640,0));
    myMesh.addVertex(ofPoint(640,0));
    myMesh.addTexCoord(ofPoint(mouseX,mouseY)); // here
    myMesh.addVertex(ofPoint(640,480));
    
     myMesh.addTexCoord(ofPoint(mouseX,mouseY)); // here
    myMesh.addVertex(ofPoint(640,480));
    myMesh.addTexCoord(ofPoint(0,480));
    myMesh.addVertex(ofPoint(0,480));
    myMesh.addTexCoord(ofPoint(0,0));
    myMesh.addVertex(ofPoint(0,0));

You will se how openGL automatically try to fit the image to the coord that you are giving and what happened when you are go outside of the texture size.

Also you can play by trying to put outside down, rotate and flip the image. This are good exercises to train your self.

Powerful and flexible. Isn't? well there are more options. If you see the vertex we are repeating lot of positions and texture coordinates. That's because it's making one triangle every three vertex. We can tell the openGL to make triangles re-using the last to vertexes. This mode it's call **TRIANGLE STRIP** and it will need that we change the order we deliver the vertex in order to re-use the information of the first triangle.

	ofMesh myMesh;
    myMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP );
    
    //
    //	B -- D
    //	| \	 |
    //	|  \ |
    //	A -- C
    //
    
    //  A
    myMesh.addTexCoord(ofPoint(0,480));
    myMesh.addVertex(ofPoint(0,480));
    
    //  B
    myMesh.addTexCoord(ofPoint(0,0));
    myMesh.addVertex(ofPoint(0,0));
    
    //  C
    myMesh.addTexCoord(ofPoint(640,480));
    myMesh.addVertex(ofPoint(640,480));
    
    //  D
    myMesh.addTexCoord(ofPoint(640,0));
    myMesh.addVertex(ofPoint(640,0));

Well know you now much more about how openGL works and you can have a picture of what's behind the ```.draw(x,y,width,height)``` function on the image based objects of openFrameworks.

The challenge now it's to make a kaleidoscope using this knowledge. You can found the answers on the example on this chapter documentation.


// Reference (GOOD IMAGES HERE SEE!!!! ):
// [http://www.creativeapplications.net/tutorials/guide-to-meshes-in-cinder-cinder-tutorials/](http://www.creativeapplications.net/tutorials/guide-to-meshes-in-cinder-cinder-tutorials/)


