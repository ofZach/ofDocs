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


## Introduction about Objects and oF style




A little and light introduction about objects ( OOP ). And how oF make you things easy by giving this packets that load media and let you play it... draw it... etc. 
So this object are variables with content and also with methots! This specially handy when dealing with media! 

This objects are like variables so they have a scoope. This object repeat the idea of seting, updating and drawing. 
The user probably want to  difined in the .h file in order to be acces on setup() for seting it up or loading the content, the doing an update on the update() and drawing it on the draw(). This methot have the same name.

### Images
On testApp.h
    ofImage myImage;
    ofImage is a data type, and you create an object of this datatype in the .h = myImage.
    

On testApp.cpp

    void testApp::setup(){
        ofEnableAlphaBlending(); // Don't forget this if you are using a .png width alpha!!
        
        image.loadImage( image.png );
        image.setAnchorPoint(x,y); //similar to setRectMode();*
        image.setAnchorPercent(x/100,y/100); //similar to setRectMode(); 
        
    }
    
   
set anchor point - allows you to set a point to rotate around. 
* For anything that has pixels, like ofImage, ofVideo --  you can set any anchor point with ofSetAnchorPoint();


void testApp::update(){
        image.update();
    }
    
    void testApp::draw(){
        ofBackground(0);
        
        ofSetColor(255,255,255); // we have to set color on white other wise it s going to be tinted
        image.draw(0,0);
    }
    
In order to load an impage in setup, draw it draw, we have to initial the object in te .h file.


oF objects with media has a "load" function. load allocate memory space. 
you want to load assets only once in setup.  The take time of the processor and memory... so you don t want to put them on the update.

the load function should be run in the setup. loading images inside the recursive loops (update() or draw() ) will slam your hard drive.


loadimage();
loadmovie();
ofSoundPlayer.loadsound();  - stream from your hardrive. 
load font -- assign anti-alising, ect. special case. 
some have morre parameters that adjust how you load things.

There are some loadings functions more complex than others. EXAMPLES 

---- IMAGE MEDIA

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


#### Pixels

##### Old school
EXAMPLE of goign throught an image pixels OLD SCHOOL "unsigned char *" way + EXPLANATION of the math involve int pos = y * width + x

##### New way
EXAMPLE of getPixelsRef() 

#### ofTexture 

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


