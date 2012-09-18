

#OF DOWNLOAD

One of the first important things to have in mind when you download your openFrameworks release version from http://www.openframeworks.cc/download/ it's that when you unzip it you are going to see a bonch of files. Yes lot of files and folders and non executable file to start using. 

Well, the thing is that openFrameworks it's really a libraries that wraps other powerfull libraries. 

What is a library?

A library is a compilation of building blocks that make programmers' lives easier. These building blocks usually help you do things that many people will want to do many times, but that would be a pain to write from scratch.

Take drawing a circle, for example. In openFrameworks, we would draw a circle of radius 20, centered at (50,100), by writing this simple line:
           
           ofCircle(50,100,20);  
           
Our computer does not know what ofCircle is. ofCircle is a bulding block (or shoshortcut created by openFrameworks that allows us to draw a circle with one line of code. When our compiler sees the word ofCircle, it immediately goes to the openFrameworks library and asks, "what is ofCircle?". openFrameworks gives it the formula to draw a circle.

If it weren't for these "shortcuts", every time we wanted to draw a circle we would have to write all of this code:


void ofGLRenderer::drawCircle(float x, float y, float z,  float radius){
        vector<ofPoint> & circleCache = circlePolyline.getVertices();
        for(int i=0;i<(int)circleCache.size();i++){
                circlePoints[i].set(radius*circleCache[i].x+x,radius*circleCache[i].y+y,z);
        }

        // use smoothness, if requested:
        if (bSmoothHinted && bFilled == OF_OUTLINE) startSmoothing();

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, sizeof(ofVec3f), &circlePoints[0].x);
        glDrawArrays((bFilled == OF_FILLED) ? GL_TRIANGLE_FAN : GL_LINE_STRIP, 0, circlePoints.size());

        // use smoothness, if requested:
        if (bSmoothHinted && bFilled == OF_OUTLINE) endSmoothing();

}

One last thing...the collective 

So, this different libraries, that already know how to work together are the core of a OF release. They live in the /lib folder. In this package you can also find some /examples and /addons that are specialy designed for does libraries. 

When we said that that this libraries know how to work with eatch other we mean not only the name of the functions, structure and those type of things. We also mean they know where to find them. The way the folders are organiced are part of this. For example: All OF programs search for a "ofMain.h" file that they are going to look at it in the /lib/openFrameworks directory. But what is important to know it's that for geting there they use relative folders. So if you look under the hood you will see that the do: ../../../lib/openFramework/ofMain.h that means all examples and project descend three leves up to the OF root folder and from there search for the ofMain.h.

At the same time ofMain.h load all the other headers files that define all the OF existing objects and methots. We could say they know where they live.

 That's way you probably don't want to be mixing diferent OF versionions, renaming directories or moving them arround.
 
 See the OF main folder as a little village of peaces of code that its related and know very well each other.

</article>

# FOLDER ORGANIZATION

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


#Relative Paths

The openframeworks package is designed to be self contained, and one of the most important ideas to know is that project files refer relatively to the libs and addons folder.  For example, if you were to open up an example project, you'd actually see include lines that look like "../../../libs/...".  This means the OF project has a certain height it wants to be away from the libs from the libs folder into order to compile.  If you move the project around, it might not wor for this reason. 

[screen shot to show folder heights]

#IDE

Ide is the place where you write code.  IDE stands for integreated development environment.  
