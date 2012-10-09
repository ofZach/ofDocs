

# OF structure

#### download

One of the important things to have in mind when you download your openFrameworks release zip file from [http://www.openframeworks.cc/download/](http://www.openframeworks.cc/download/) is that inside it you are going to find a bunch of files. Yes!!, lot of files and folders with out any executable file (or un less anyone that gives you the idea that IT IS openFrameworks). It's not like Processing that you download an actual application that you can run it and say to your self "Hey! this is great I'm working on Processing". 
Here is a different picture. This maybe be scary you at the beginning. Why it's this?
Have in mind that openFrameworks it's really a bouncy of libraries that wraps other powerful libraries. So in essences openFrameworks it's 100% pure code. It's completely independed of the IDE you are using.  

The core of open frameworks is a library, and the code you write is based on that library.  The OF library extends other libraries, such as FMOD, opengl, cairo, etc.  

for more information about libraries, see the glossary

#### what you see in OF

So, you download the last release. You unzip it. And you are looking at all that files and folders. What are you looking it's to a package of libraries and examples that know how to work together. The OF core classes and methods are in the ```/lib``` folder together with the other openSource powerful libraries that they wrap. In this package you can also find some ```/examples``` and ```/addons``` that are specially designed for does libraries. 

When we said that this libraries "know how to work with each other" we mean not only that they call functions and objects related with a same syntax and design logic. We also mean they know where and how to find them. The way the folders are organized are part of this. For example: All OF programs search for a ```ofMain.h``` file that they are going to look at it in the ```/lib/openFrameworks``` directory. But what is important to know it's that for getting there they use relative folders. So if you look under the hood you will see that the do: ```../../../lib/openFramework/ofMain.h``` that means all examples and project descend three levels up to the OF root folder and from there search for the ```ofMain.h```.


***NOTE***(this is a shorter version more clear an simpler wrote by Zach… )
```
	#Relative Paths

	The openframeworks package is designed to be self contained, and one of the most important ideas to know is that project files refer relatively to the libs and addons folder.  For example, if you were to open up an example project, you'd actually see include lines that look like "../../../libs/...".  This means the OF project has a certain height it wants to be away from the libs from the libs folder into order to compile.  If you move the project around, it might not work for this reason. 

	[screen shot to show folder heights]
```

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