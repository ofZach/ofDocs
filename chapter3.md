

# oF structure

#### download

One of the important things to have in mind when we download our openFrameworks release zip file from [http://www.openframeworks.cc/download/](http://www.openframeworks.cc/download/) is that inside it we are going to find a bunch of files. Yes!! Many files and folders without an executable file (or anything that gives us the idea that this is openFrameworks). It's not like Processing, where we download an actual application that we can run and say to ourselves "Hey! this is great I'm working in Processing". 
Here it is a different picture and that may be scary for us at the beginning. Think of it like this; openFrameworks is really a bunch of libraries that wraps, or contains, other powerful libraries. So in essence openFrameworks is 100% pure code. It's completely independent of the IDE we are using.  

The core of openFrameworks is a library, and the code we write is based on that library.  The OF library extends other libraries, such as FMOD, OpenGL, Cairo, etc.  

For more information about libraries, see the glossary.

#### what you see in oF

So, we downloaded the latest release, unzipped it and are looking at the files and folders. What we are looking at is a package of libraries and examples that know how to work together. The OF core classes and methods are in the ```/lib``` folder together with the other openSource powerful libraries that they wrap. In this package we can also find some ```/examples``` and ```/addons``` that are specially designed for those libraries. 

When we say that these libraries "know how to work with each other" we mean not only that they call functions and objects related with the same syntax and design logic, we also mean they know where and how to find them. The way the folders in the ```/lib``` folder are organized is part of this. For example: All oF programs search for the ```ofMain.h``` file, and they are going to look for it in the ```/lib/openFrameworks``` directory. But what is important to know is that for getting there they use relative folders. So if we look under the hood you will see ```../../../lib/openFramework/ofMain.h```. That means all examples and projects descend three levels up to the oF root folder and from there search for the ```ofMain.h```.


> ***NOTE***(this is a shorter version more clear an simpler wrote by Zach… )
> 
> Relative Paths
> 
> The openframeworks package is designed to be self contained, and one of the most important ideas to know is that project files refer relatively to the /libs and /addons folder.  For example, if you were to open up an example project, you'd actually see include lines that look like "../../../libs/...".  This means the OF project has a certain height it wants to be away from the libs from the /libs folder into order to compile.  If you move the project around, it might not work for this reason. 
> 
> [screen shot to show folder heights]

At the same time ```ofMain.h``` load all the other headers files that define all the OF existing objects and methods. We could say they know where they live.

***IMPORTANT***: That's the reason why you probably don't want to be mixing different OF versions, renaming folder or moving things arround.
 
See the OF main folder as a little village of peaces of code that its related and know very well each other. What you certainly CAN do it's to rename this hole folder or place to some place it's easy to access. You are going to be coming back to this folders many many times.
A good place to place it it's on your desktop for example.


# FOLDER ORGANIZATION
Let's take a closer look to this folder organization in order to have a clear and transparent view of how openFrameworks works.

###Addons:  
This contains all the added-on features for openFrameworks that have been contributed
by users over the past year or so. These libraries change often, and new
ones are added frequently, so it’s important to remember that these are dynamic
if you’re planning on using these libraries in a program because you need to explicitly
include them in your program.

###Apps:  
This is where your programs should be stored. If you have a strong preference, you
can organize them in other ways, but that would go against the flow and would
break some of your code. The example programs that use the core oF libraries are
stored here, as are the example programs that show you how to use each of the
add-on libraries. These are some of your best learning resources because they give
you wonderful starting points for exploring oF and C++, and because they’re usually
well commented and documented.

###Examples: 
These are example applications that ship with each release of Openframeworks. 

Libs: This is where the libraries that oF relies on are stored. These range from external
libraries like fmodex, which is used for two- and three-dimensional sound manipulation,
to the GLee library, which is used for OpenGL graphics. Most important,
you’ll see the core openFrameworks  folder, which stores the header files that define
all the core oF functionality in six folders. As you find your ideas and techniques
becoming more and more sophisticated, you’ll probably need more libraries than
those provided here. 

###Other: 
This folder includes an arduino sketch in it. (It allows OF to interface with Arduino?)

###Script:
Only the 0071 version of OF has this folder. The project generator relies on the script folder to generate new empty blank projects.


###Making new projects (? PG)
project generator
copy / pasting older projects
 
###OF event system (setup, update , draw, key & mouse events) 
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