glossary
======


#### IDE

IDE stands for integrated development environment.

[processing has IDE / vs OF on different IDEs]

It's a program where you write your code. Like a Text Editor but with build in functions that make the code editing easier. 

* syntax highlighting
* debugging
* write, read, run your code
* function jumping, etc
* add / alter settings such as include paths, linking paths, etc
* errors, warnings


#### compiler


#### scope


#### variable


#### function


#### library
	
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
	