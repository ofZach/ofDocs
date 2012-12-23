# Pixels and Textures

OpenFrameworks have different ways to handle images. One in your CPU ant the other on the GPU (graphic card). The last one is significant faster but implies much more complex process to handle it and manage it.

When you work on the CPU each image is composed by pixels. Those little tiny color boxes are align as a to dimensional table. OpenFrameworks have a class for that call ofPixels.
GPU use another approach that doesn't "divide" the image in this way, it consider it as a texture. Once again in openFrameworks the class in charge of that is call ofTexture.

In this chapter we are going to walk through both ways of working with it. Is important to know that everything we see here is going to be consistent on all the image classes. That is: ```ofImage```, ```ofVideoGrabber``` and ```ofVideoPlayer```.

### Preparing the stuff 

One thing is common to all of the image object like: ofPixels, ofTextures, ofImage, ofVideoGrabber, ofVideoPlayer and ofFbo, is that they have data. That data is going to be store on the GPU or the CPU RAM. But in any case you have to prevously define how amount of memory you need to separate to work with data. For all cases you do that using:

	imageObject.allocate(width,height);
	
As you can imagine the total amount of memory reserve for this image object is going to depend on the size of the width and the height. We normally think of it as the width x height, but it's another factor here, the amount of channels. 

One image can have only one channel. That image is call grayscale and it only can store one channel of information what make it black and white. Or can have three channels, one for the red, other for the green and the last one for the blue. Having this three channels working together the computer can digitalize almost all the viewable spectrum. But could be one more channel, it's call the alpha channel and it allow you to set the opacity or transparent of a pixels. 

It's a catch here cameras doesn't record on alpha channel so everything you get from ofVideoGrabber will be in at maximum of three channels. You have to be smart enough to see how you can deal with it.

## Pixels by Pixels CPU processing 

Well let's start to the implementation of this on code from the easiest approach, ```ofPixels```. We can request this class to the ```ofImage```, ```ofVideoGrabber``` and ```ofVideoPlayer``` objects in this way:
 
	ofPixels pixels = image.getPixelsRef();

The method ```.getPixelsRef()``` gives a sort of a "packet" to the pixels information of an image. Once you have the ```ofPixel``` object it have all sort of handy methods to read the data of a specify color of a pixels giving the `x` and `y` position.

	ofColor color = pixels.getColor(x,y);

Also it's possible to **set** color by using:

	pixels.setColor(x, y, ofColor(255,0,0,255)); // a red dot with full opacity

What is very handy about ```ofPixels``` is that you can pass it then back to an image by:

	image.setFromPixels(pixels);

This way you can pass pixels between images in order to process it and do interest things. 
A less flexible approach but much more simple is directly doing:

	image.setColor.setColor(x, y, ofColor(255,0,0,255));

Let's say that you want to grab each frame of the camera and make a new image with it but making some changes.

In your testApp.h

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
		
    	ofVideoGrabber  videoIn;
    	ofImage         imageOut;
    
	};

In your testApp.cpp

	void testApp::setup(){
    	videoIn.initGrabber(640, 480);
    	imageOut.allocate(640, 480, OF_IMAGE_COLOR); // force to use 4 channels
	}

Note that we are forcing the image to be a 3 channels one using OF_IMAGE_COLOR other wise you can use 4 channesl by saying OF_IMAGE_COLOR_ALPHA

Now what we need is to "play" the camera. That is usually done in the ```update()```

	void testApp::update(){
    	videoIn.update();
	}

In order to show this on screen on the ```draw()``` we do:

	void testApp::draw(){
		videoIn.draw(0, 0);
    	imageOut.draw(640, 0);
	}

Let's run it. 
If everything goes well you could be able to see your self. Congratulations you make your first mirror application. A new media artist is born. 

Well in order to do something more interesting we are going to focus on the ```update()```. The first thing we need to do is just to analyze and work only on the new frames of the video. Your camera probably can handle a maximum of 60 frames per second but your program can actualy go more that 300 frames per second. That's a lot of frames processes with the same information. We are going to do it asking the video witch frames are new.

Width that cover we are going to get the pixels of the video and pass it to the image one.

	void testApp::update(){
    	videoIn.update();
    
    	if (videoIn.isFrameNew()){
        	ofPixels pixels = videoIn.getPixelsRef();
        	imageOut.setFromPixels(pixels);
    	}
	}
	
If we compile you can see how we duplicate the image. Good job! Next, process this image.
for that we need to go for each one of the pixels and change the information of it. For that we need what is call a double loop. That's it two for loops one inside the other that goes all thought the ```x``` and ```y``` axes of the image.

Each channel range goes from 0 to 255 doing some light maths we can invert every single pixel value by doing:


	void testApp::update(){
    	videoIn.update();
    	
   	 	if (videoIn.isFrameNew()){
        	ofPixels pixels = videoIn.getPixelsRef();
        
        	for (int x = 0; x < pixels.getWidth(); x++){
            	for(int y = 0; y < pixels.getHeight(); y++){
                	ofColor color = pixels.getColor(x, y);
                	color.r = 255 - color.r;
                	color.g = 255 - color.g;
                	color.b = 255 - color.b;
                	pixels.setColor(x,y, color);
            	}
        	}
        
        	imageOut.setFromPixels(pixels);
    	}
	}

Play… and there you have! Your ghost image right next to the other one.

### Old School approach

So far so good. Isn't? There is another approach to this that is a little more complicated and downlevel but it's much more powerful and very educative of how your computer works. So instead of getting a "packet" of the pixels we can ask to get a link to the place on RAM memory where your video stream is arriving. Yes! is that crazy downlevel we are going! Nothing more hardcore than this.

So in memory things are not so fancy that with ofPixels. We are going to get the beginning of an array. Yes, one large array of pixels. 

![ofTexture5](https://raw.github.com/ofZach/ofDocs/master/img/chapter07/pixels.png)

As you can see  that array is going to have the the 3 or 4 channels one before the other. The type of each one of this values is going to be a ```unsigned char```. If you do some research you will find that char variables can store values between -127 and 127 if we only consider the unsigned (positive numbers) the amount of value can store duplicate to 256. Found this familiar? yes! that why colors runs between 0 - 255.

So to ask for this array we are going to type: 
 
	unsigned char * pixels = image.getPixels();

We use a pointer ```*``` because we want the data and pointers are a way to do that without having to use more memory. Remember all variables are memory cells, and the points just points to the information By pointing to the pixel we want to see, we can change it when we do our image processing. Understanding pointers and how to use them in not only openFrameworks but in C++ in general is a realy powerful thing to know and will allow us to do really cool thing. To learn more on pointers and how they actually work, go to the C++ reference page to read more on pointers [here](http://www.cplusplus.com/doc/tutorial/pointers/).

Once we call ```image.getPixels()``` we have the pixel information, which is the width and height of the image we a referencing. If we wanted to get the pixel information of a specific pixel, we would think of it as looking into a grid, width by height, and each pixel is a cell in this grid.

The complex stuff here is how we can process the pixels one by one like the other example going through the double loop, we need to "translate" from x/y to and index of the pixels of the image. For that the complete code will be:

	void testApp::update(){
    	videoIn.update();
    
    	if (videoIn.isFrameNew()){
        	unsigned char *pixels = videoIn.getPixels();
        
        	int width = videoIn.getWidth();
        	int height = videoIn.getHeight();
        
        	for (int x = 0; x < width; x++){
            	for(int y = 0; y < height; y++){
                
                	int i = y * width + x;
                
                	pixels[i * 3 + 0] = 255 - pixels[i * 3 + 0];
                	pixels[i * 3 + 1] = 255 - pixels[i * 3 + 1];
                	pixels[i * 3 + 2] = 255 - pixels[i * 3 + 2];
            	}
        	}
        
        	imageOut.setFromPixels(pixels, width, height, OF_IMAGE_COLOR);
    	}
	}

## Textures

What is a texture and why is it so different from the idea of an image?

Well when we think about images we tend to think in pictures and pixels. That usually means a image inside a rectangular frame, that has pixels inside. Those pixels as we know now are essentially an array list that the computer knows how to arrange in a specific way. All that it's usually related to the way CPU processes and works with images.
But as computers got more advanced, the GPU appeared and engineers realized that there could be different ways to use images in order to give much more flexibility and decided to empower new ways of drawing with specific hardware tweaks.
That's when textures were born. They where conceived as 1D, 2D or 3D arrays of fragments of images that are mount on top of wireframes made by vertex. This lead to new and powerful ways of creating 3D elements. 

It's pretty much like the making of a armchair. First you assemble the wood pieces that will be the rigid structure where the fabric will be mounted. To keep things easy we are going to speak only about 2D Textures and we are going to imagine them as the fabric. 

![ofTexture1](https://raw.github.com/ofZach/ofDocs/master/img/chapter06/ofTexture01.jpeg)

In the beginning 2D Textures had to be squared (power of 2). And they were used as wallpapers so they repeat them self once and once over again. 

// IMAGE HERE

This makes things really complicated to use regular images like the ones we are going to use. So after a while a new type of texture was develop call ARB 2D Textures. This last type of texture it's the default one in openFrameworks. Of course you can switch this ON of OFF by using:

	ofEnableArbTex();
    ofDisableArbTex();

Going back to the armchair metaphor, the first step positioning the vertex and how they are going to be linked together. We already have done something similar to this on the Chapter 4 when we make 2D shapes using ```ofVertex(x,y);```. It's the same concept of connecting the dots. But now that you already know that we can go further and learn the different ways that these points are going to be linked together.

![ofTexture2](https://raw.github.com/ofZach/ofDocs/master/img/chapter06/ofTexture02.jpeg)

When we want to mount textures over these shapes at the same time we are setting vertexes position we have to specify which part of this "fabric" that we call Texture is going to be mounted where. Here we are playing the role of a carpenter and a upholsterer at the same time. 

Let's jump to the code. For that we are going make what is called a **mesh** (ofMesh).
Meshes are this pack of information of vertices, how to arrange them and its relation to where to mount the texture on top of them.

I know, it sounds complex. But the good news is that all this is powered by the GPU card. The engineers that work on Graphics Cards provide them with their own memory. This memory is attached to a lot of mini-micro-processors that run in parallel at super fast speed. Each one of these micro-processors only take care on the positioning of one vertex and one fragment of image. It's like having a big army of little ants doing very specific tasks all at the same time. The power of this army is related to its number and the fact that each one does only one thing in parallel to the other one. First, all are going to process the vertex, then how they are going to link this vertex and finally how they are going to mount and process the fragments of images stored in the GPU memory. 

![ofTexture3](https://raw.github.com/ofZach/ofDocs/master/img/chapter06/ofTexture03.jpeg)

This is what is call GPU Pipeline. You know what's the best of it? It could be re-programmed! Just like a lot of Arduinos you could reprogram the firmware of these ants to treat vertices, geometries or fragments in a different way. That's what is called replace the default shaders. But we are not going to go so far on this chapter. 

Any way what's important here is to remember that all this is super fast, but what takes lot of time it's uploading or getting the pixels of the images to and from GPU. We can visualize this by thinking on a beautiful ship in a bottle. It looks super nice at the end but the process of pushing and getting the pixels to and from it is really time expensive because the mouth of the bottle is a certain width and cannot be stretched. 

![ofTexture4](https://raw.github.com/ofZach/ofDocs/master/img/chapter06/ofTexture04.png)

Let's start making a simple mesh. And play with it.

	ofMesh myMesh;
	
We are going to start by deciding which type of Primitive mode you want. This means how we want to group our vertex. The most frequent and common is a triangle. Because they are flexible and could be arranged into any shape. Just like we learn in Chapter 4 when we see how circles are made.

So let's start by making a 640x480 rectangle using 6 vertexes grouped inside 2 triangles.
	
	void testApp::draw(){
    	ofBackground(0);
    
    	ofSetColor(255);
    
    	ofMesh myMesh;
    
    	myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    	myMesh.addVertex(ofPoint(0,0));			// A
    	myMesh.addVertex(ofPoint(640,0));		// B
    	myMesh.addVertex(ofPoint(640,480));		// C
    
    	myMesh.addVertex(ofPoint(640,480));		// C
    	myMesh.addVertex(ofPoint(0,480));		// D
    	myMesh.addVertex(ofPoint(0,0));			// A
    
    	myMesh.draw();
	}
	

![ofTexture5](https://raw.github.com/ofZach/ofDocs/master/img/chapter06/ofTexture05.jpeg)

	
Play a little with this code by changing the parameters and commenting some lines. Try to push the limits of this example to have a concrete idea of how openGL works. Oops… I almost forgot, congratulations you are almost one step away to direct openGL programming. Feel great about yourself because we are using one of the most powerful and heavy graphics engine ever made. OpenFrameworks here is just helping you with the cross platform compatibility but you are learning the roots of openGL and how it works. Congratulations.

But this white rectangle doesn't seem so exiting. Isn't?
We are going to add some excitement to it by adding the coordinates where to mount this textures. 

	//	A
	myMesh.addTexCoord(ofPoint(0,0));
    myMesh.addVertex(ofPoint(0,0));
    
    //	B
    myMesh.addTexCoord(ofPoint(640,0));
    myMesh.addVertex(ofPoint(640,0));
    
    //	C
    myMesh.addTexCoord(ofPoint(640,480));
    myMesh.addVertex(ofPoint(640,480));
    
    //	C
    myMesh.addTexCoord(ofPoint(640,480));
    myMesh.addVertex(ofPoint(640,480));
    
    //	D
    myMesh.addTexCoord(ofPoint(0,480));
    myMesh.addVertex(ofPoint(0,480));
    
    //	A
    myMesh.addTexCoord(ofPoint(0,0));
    myMesh.addVertex(ofPoint(0,0));
    
    
The last step here is to "bind" a interesting texture on top of this mesh. For that we are going to use the ```ofVideoGrabber``` and request for the ```ofTexture```of it. As we saw previously all image based objects like: ```ofImage```, ```ofVideoGrabber``` and ```ofVideoPlayer```have both types information attached to them. One for CPU RAM and the other on GPU RAM. ```ofTextures```can't be loaded directly from a file. Basically they are links to the place they are on our Graphics Card Memory. We can get this "link" and pass it to our ```ofTexture```by doing ```.getTextureReference()```on any of this image based objects. In the case of our video grabber we can do that by typing:

	ofTexture myTexture = myVideo.getTextureReference();
	
It's always a good idea to explore openFrameworks objects. You can learn so much by simply reading the ```.h``` where this classes are defined. In XCode in MacOSX, you can right click over ```ofTexture```and clicking over "Jump To Definition".

Any way, once you have the ```ofTexture``` you can apply it over this mesh by using:


	ofTexture myTexture = myVideo.getTextureReference();
	
	myTexture.bind();
    myMesh.draw();
    myTexture.unbind();
    

Also as you know in Object Oriented Programing you can get into objects by using the dot ```.``` so instead of getting the texture and then using it you can do it all in one step by saying.


	myVideo.getTextureReference().bind();
    myMesh.draw();
    myVideo.getTextureReference().unbind();
    

Any way the complete code for this example is:

testApp.h


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


On the testApp.cpp

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


Take time to play and explore this example by changing, commenting out, etc. Try to play as much as you can with the Texture Coordinates by replacing some coordinates for the mouse position:


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


You will see how openGL automatically tries to fit the image to the coord that you are giving and what happened when you go outside of the texture size.
Also you can play with it by trying to rotate and flip the image. These are good exercises to train yourself.

Powerful and flexible, right? Well there are more options. If you see the vertex, we are repeating lot of positions and texture coordinates. That's because it's making one triangle every three vertices. We can tell openGL to make triangles by re-using the last two vertexes. This mode is called **TRIANGLE STRIP** and we need to change the order we deliver the vertex to re-use the information of the first triangle.

![ofTexture6](https://raw.github.com/ofZach/ofDocs/master/img/chapter06/ofTexture06.jpeg)


	ofMesh myMesh;
    myMesh.setMode( OF_PRIMITIVE_TRIANGLE_STRIP );
        
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
[http://www.creativeapplications.net/tutorials/guide-to-meshes-in-cinder-cinder-tutorials/](http://www.creativeapplications.net/tutorials/guide-to-meshes-in-cinder-cinder-tutorials/)
[http://www.creativeapplications.net/tutorials/images-in-cinder-tutorials-cinder/](http://www.creativeapplications.net/tutorials/images-in-cinder-tutorials-cinder/)


