# Pixels and Textures

** I have a Spanish versions here [https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad4/Cap_1_pixel_x_pixel.md](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad4/Cap_1_pixel_x_pixel.md) but need the new style way… maybe Isac or Juan want to used as reference or translate it. **

**Took a look at the spanish version and it's kinda like what I saw here, [[http://wiki.openframeworks.cc/index.php?title=Image_processing]](http://wiki.openframeworks.cc/index.php?title=Image_processing) edited now **
 

A Very important thing to know about dealing with images type objects like ofImage, ofVideoGrabber and ofVideoPlayer its that have they have to types of data associated with them: Pixels and Textures. 

We have ofPixel which contains the pixel data assoicated with position and color loaded in the RAM memory of the CPU. We also have ofTexture, which is pixel data that is stored on the Graphics Card. There are two different ways of getting this pixel data.

Pixels are … 

Textures are …


## Pixels by Pixels CPU processing 

### Old School

	unsigned char * pixels = image.getPixels(); // Its all up to you

pointer - a specific point in memory where the pixels.

///MORE EXPLANATION OF THIS NEED ( NOT TO DEEP ON PIXELS AND ARRAY because thats goint to be exapling in the future on ARRAYS )

We use a pointer ```*``` because we want the data and pointers are a way to do that without having to use more memory. Remember all variables are memory cells, and the points just points to the information By pointing to the pixel we want to see, we can change it when we do our image processing. Understanding pointers and how to use them in not only openFrameworks but in C++ in general is a realy powerful thing to know and will allow us to do really cool thing. To learn more on pointers and how they actually work, go to the C++ reference page to read more on pointers [here](http://www.cplusplus.com/doc/tutorial/pointers/).

Once we call ```image.getPixels()``` we have the pixel information, which is the width and height of the image we a referencing. If we wanted to get the pixel information of a specific pixel, we would think of it as looking into a grid, width by height, and each pixel is a cell in this grid.

// IMAGE HERE LIKE A GRID FROM THE REFERENCE LINK IN PATRICIO'S NOTE

If we have an image that is five by four pixels large, we could find out the color of the pixel located at x=2 and y=3, like this:

	00000
	00000
	000X0 <--- the pixel we look for is here (image perhaps?)
	00000	
	
	location 	= y * size of the row * bytes per pixel
			 	= 3 * 5 * 4
				= 60
		
	location 	= x * bytes per pixel
				= 2 * 4
	  			= 8
	  
	location 	= y + x
				= 68
				
	red pixel 	= 68
	
	green pixel	= 68+1
	 
	blue pixel	= 68+2
	
	alpha pixel	= 68+3 
	
Once we understand how to get the location of a single pixel, then we can use that same logic to call on all the pixels in the image
    
    for (int i = 0; i < image.getWidth(); i += 4){
        for (int j = 0; j < image.getHeight(); j += 4){
            unsigned char r = pixels[(j * int(vidPlayer.getWidth()) + i) * 3];
            unsigned char g = pixels[(j * int(vidPlayer.getWidth()) + i) * 3 + 1];
            unsigned char b = pixels[(j * int(vidPlayer.getWidth()) + i) * 3 + 2];
            
            ofColor myColor;
            myColor.r = r;
            myColor.g = g;
            myColor.b = b;

So in the example code above we go through each pixel and then pull out the inidividual RGB channels into another ```unsigned char``` variable. We could do anything with these colors now, and in this case we place them into an ```ofColor``` variable. The math does seem complex at first, but like we said it is the old school way of doing things.

### New School style 
 
	ofPixels pixels = image.getPixelsRef();	
	getPixelsRef(); // returns to ofPixels

```getPixelsRef()``` has functions where we can have access to color, as well as have the ability to change color within specific pixels of our image. It is similar to what we discussed in the old school way of getting pixel information.

// j talking about images being a long array of pixels here  [j*w+i], by asigning an x and y

** I tell the reader to refer to the old school way of finding pixels -JP **

> openframeworks works by passing by reference. 
>
> If you change the pixels you will need to call the update()

** I'm not quite sure on how to elaborate on that "passing by reference" -JP **

Now in order to understand the new style, we have to talk about where the image is being stored in the computer. We store the image in two places which are dynamic, changing.
The texture is stored in the GPU (ex: 4GB RAM), that is our graphics card and the pixels are stored in the CPU (ex: 512mb ATI), or the computer memory. These two places are storing copies of the original image, so we can use them and manipulate them.

A lot of times we see the word ```Ref``` in OF functions, and that would be passing by reference as opposed to passing by value. Passing by value, aka passing by copy literally makes a copy of the variable and stores it in the memory whereas passing by reference only passes the address of that object, which reduces the load on our processor by a lot. 
A good example of usage of this would be modifying pixels of a video. For example, if we use pass by value, we will be copying a frame of 640 by 480 large video, 60 times a second, which is not efficient at all. Instead, using pass by reference reduces he processing overhead by a lot lot lot.


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


