# oF structure

## Download

One of the important things to have in mind when we download our openFrameworks release zip file from [http://www.openframeworks.cc/download/](http://www.openframeworks.cc/download/) is that inside it we are going to find a bunch of files. Yes!! Many files and folders without an executable file (or anything that gives us the idea that this is openFrameworks). It's not like [Processing](http://processing.org/), where we download an actual application that we can run and say to ourselves *"Hey! this is great I'm working in Processing"*. 
Here it is a different picture and that may be scary for us at the beginning. 
Think of it like this; openFrameworks is really a bunch of libraries that wraps, or contains, other powerful libraries. So in essence openFrameworks is 100% pure code. It's completely independent of the [IDE](https://github.com/ofZach/ofDocs/blob/master/glossary.md#ide) we are using.  

The core of openFrameworks is a library, and the code we write is based on that library.  The OF library extends other libraries, such as [FMOD](http://www.fmod.org/), [OpenG](http://www.opengl.org/), [Cairo](http://cairographics.org/), etc.  

For more information about libraries, see the [Glossary](https://github.com/ofZach/ofDocs/blob/master/glossary.md).

## What you see in oF?

So, we downloaded the latest release, unzipped it and are looking at the files and folders. What we are looking at is a package of libraries and examples that know how to work together. The OF core classes and methods are in the ```/lib``` folder together with the other openSource powerful libraries that they wrap. In this package we can also find some ```/examples``` and ```/addons``` that are specially designed for those libraries. 

When we say that these libraries "know how to work with each other" we mean not only that they call functions and objects related with the same syntax and design logic, we also mean they know where and how to find them. The way the folders in the ```/lib``` folder are organized is part of this. For example: All oF programs search for the ```ofMain.h``` file, and they are going to look for it in the ```/lib/openFrameworks``` directory. But what is important to know is that for getting there they use relative folders. So if we look under the hood you will see ```../../../lib/openFramework/ofMain.h```. That means all examples and projects descend three levels up to the oF root folder and from there search for the ```ofMain.h```.

> **Relative Paths**
> The openFrameworks package is designed to be self contained, and one of the most important ideas to know is that project files refer relatively to the ```/libs``` and ```/addons``` folder.  For example, if you were to open up an example project, you'd actually see include lines that look like ```../../../libs/...```  This means the OF project has a certain height it wants to be away from the libs from the ```/libs``` folder into order to compile.  If you move the project around, it might not work for this reason. 

***[screen shot to show folder heights]***


At the same time ```ofMain.h``` loads all the other headers files that define all the oF existing objects and methods. We could say they know where they live.

***IMPORTANT***: That's the reason why we probably don't want to be mixing different oF versions, renaming folder or moving things around.
 
Think the oF main folder as a little village of pieces of code that are related and know each other very well. What we certainly can do is rename this whole folder or place to some place it's easy to access. We are going to be coming back to this folder many times. A good location to place it is on our desktop for example.


## FOLDER ORGANIZATION
Let's take a closer look at the folder organization in order to have a clear and transparent view of how openFrameworks works.

###Addons
This contains all the added-on features for openFrameworks that have been contributed by users in the past. These libraries often change, and new ones are added frequently, so it’s important to remember that these are dynamic if we’re planning on using these libraries in a project, because we need to explicitly include them in your program.

###App 
This is where our projects should be stored. If we have a a real need to, we can organize them in other ways, but that would go against the flow and would break some of our code. The example programs that use the core oF libraries are stored here, as are the example programs that show us how to use each of the add-on libraries. These are some of our best learning resources because they give us wonderful starting points for exploring oF and C++, and because they’re usually well commented and documented.

###Examples
These are example applications that ship with each release of openFrameworks. 

Libs: This is where the libraries that oF relies on are stored. They range from external libraries like [FMOD](http://www.fmod.org/), which is used for two- and three-dimensional sound manipulation, to the GLee library, which is used for [OpenGL](http://www.opengl.org/) graphics. Most important, we'll see the core openFrameworks  folder, which stores the header files that define all the core oF functionality in six folders. As we find our ideas and techniques becoming more and more sophisticated, we'll probably need more libraries than those provided here. 

### Other
This folder includes an [Arduino](http://www.arduino.cc/) sketch in it. (It allows OF to interface with Arduino?)

### Project Generator
project generator
copy / pasting older projects
 
 
## OF event system (setup, update , draw, key & mouse events) 
all the main events
OF interfaces with testApp, (main).
(callout : testApp extends baseApp ) <--- processing 
setup / update / draw Ref = http://www.openframeworks.cc/tutorials/developers/001_how_openFrameworks_works.html
setup as the starting point
most OF objects have a setup function (or loadFunction)
avoid constructors
get's called once
why update / draw 
separate some the logic of code
code runs faster
loops repeatedly
game loop + hardware events