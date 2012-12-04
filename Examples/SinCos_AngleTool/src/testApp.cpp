#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    // This is the center position of the diagram
    //
    center.set(250, 250);
    ofSetWindowShape(1024, 540);
    
    // starting angle and radius
    angle   = 0.0f;
    radius  = 140.0f;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (bPlay) {
        // It it's playing add
        //
        angle += 1.0/ofGetFrameRate();
        
        // Reset the angle when it is more than 2PI
        //
        if (angle > PI*2) {
            angle = 0.0f;
        }
    }
    
    // Get the cartesian coordinates
    //
    dotPos.x = cos(angle) * radius;
    dotPos.y = sin(angle) * radius;
    
    // Store the Y (sin) position
    // We use this to draw the Y Line over time
    sinHistory.push_back(dotPos.y);
    if (sinHistory.size() > 400) {
        sinHistory.erase(sinHistory.begin());
    }
    
    // Store the X (cos) position
    // We use this to draw the X Line over time
    // Then we superimpose over the Y
    // to see the relationship of sin and cos
    cosHistory.push_back(dotPos.x);
    if (cosHistory.size() > 400) {
        cosHistory.erase(cosHistory.begin());
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    ofDrawBitmapString("Press a key or drag with your mouse", 15, 15);
    
    ofPushMatrix();
    // center the matrix so that
    // it is easier to construct the guidelines
    //
    ofTranslate(center);
    
    // Draw Cartesian
    //
    float lengthOfAxis = 200;
    ofSetColor(100);
    
    // use ofPoint(x,y) to sent the 1st and 2nd coordinates of ofLine
    // we draw here the main circle to show the angle
    //
    ofLine(ofPoint(-lengthOfAxis, 0),ofPoint(lengthOfAxis, 0));
    ofDrawBitmapString("-X", -lengthOfAxis - 25, 5);
    ofDrawBitmapString("X", lengthOfAxis + 5, 5);
    ofLine(ofPoint(0, -lengthOfAxis),ofPoint(0, lengthOfAxis));
    ofDrawBitmapString("-Y", -11, -lengthOfAxis - 5);
    ofDrawBitmapString("Y", -3, lengthOfAxis + 15);
    
    // Draw Vector
    //
    ofSetColor(255);
    ofLine(0, 0, dotPos.x, dotPos.y);
    
    // Draw Vector projections on axis
    // they are the vertical / horizontal
    // lines that plot the x,y of the dot
    //
    ofSetColor(255);
    ofLine(0, 0, dotPos.x, 0);  // X
    ofLine(0, 0, 0, dotPos.y);  // Y
    ofSetColor(255, 50);
    ofLine(dotPos.x, dotPos.y, dotPos.x, 0); // X
    ofLine(dotPos.x, dotPos.y, 0, dotPos.y); // Y
    
    // Draw Dot function
    // at the bottom of the draw loop
    //
    drawDot( dotPos );
    
    // Draw angle references
    //
    ofPolyline angleLine;
    angleLine.arc(0, 0, radius*0.3, radius*0.3, 0, ofRadToDeg(angle));
    ofNoFill();
    ofSetColor(255, 180);
    angleLine.draw();    
    ofDrawBitmapString("a = " + ofToString(angle, 2) + " (" + ofToString((int)(ofRadToDeg(angle))) + " deg)", radius * 0.3 + 5, 15);
    
    // Draw sin projected dots
    //
    ofLine(lengthOfAxis + 30, -radius, lengthOfAxis + 30, radius);
    ofDrawBitmapString("-1", lengthOfAxis + 30 - 12, -radius - 5);
    ofDrawBitmapString("1", lengthOfAxis + 30 - 3, radius + 15);
    ofPoint sinPos = ofPoint(lengthOfAxis + 30, dotPos.y);
    ofDrawBitmapString("sin(a).r = " + ofToString( sin(angle), 2), sinPos + ofPoint(15, 3));
    drawSinDot(sinPos);

    // Draw cos projected dots
    //
    ofSetColor(255, 100);
    ofLine(-radius, lengthOfAxis + 30, radius, lengthOfAxis + 30);
    ofDrawBitmapString("-1", -radius - 15, lengthOfAxis + 30 + 5);
    ofDrawBitmapString("1", radius + 5, lengthOfAxis + 30 + 5);
    ofPoint cosPos = ofPoint(dotPos.x, lengthOfAxis + 30);
    ofDrawBitmapString("cos(a).r = " + ofToString( cos(angle), 2), cosPos + ofPoint(-3, 15));
    drawCosDot(cosPos);

    // Draw cos dot on History line
    //
    ofPoint cosHistoryPos = ofPoint(lengthOfAxis + 30, dotPos.x);
    ofDrawBitmapString("cos(a).r = " + ofToString( cos(angle), 2), cosHistoryPos + ofPoint(-3, 15));
    drawCosDot(cosHistoryPos);
    
    
    // Draw the history of sin through time
    //
    ofMesh lineMesh;
    lineMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    for (int i = sinHistory.size() - 1; i > 0; i--){
        float alpha = ofMap(i + 1, 1, sinHistory.size(), 0.0, 1.0);
        
        lineMesh.addColor( ofFloatColor(1.0, alpha) );
        lineMesh.addVertex( ofPoint(lengthOfAxis + 30 + (sinHistory.size() - i), sinHistory[i]));
    }
    
    ofPushStyle();
        ofSetColor(255, 0, 0);
        lineMesh.draw();
    ofPopStyle();
    
    // Draw the history of cos through time
    //
    ofMesh cosLineMesh;
    cosLineMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    for (int i = cosHistory.size() - 1; i > 0; i--){
        float cosAlpha = ofMap(i + 1, 1, cosHistory.size(), 0.0, 1.0);
        
        cosLineMesh.addColor( ofFloatColor(1.0, cosAlpha) );
        cosLineMesh.addVertex(ofPoint(lengthOfAxis + 30 + (cosHistory.size() - i), cosHistory[i]));
    }
    
    ofPushStyle();
        ofSetColor(0, 0, 255);
        cosLineMesh.draw();
    ofPopStyle();
    
    ofPopMatrix();
}

void testApp::drawDot(ofPoint _pos){
    ofPushStyle();
    
    ofFill();
    ofSetColor(0, 255, 0);
    ofCircle(_pos, 5);
    
    ofPopStyle();
}

void testApp::drawSinDot(ofPoint _pos){
    ofPushStyle();
    
    ofFill();
    ofSetColor(255, 0, 0);
    ofCircle(_pos, 5);
    
    ofPopStyle();
}

void testApp::drawCosDot(ofPoint _pos){
    ofPushStyle();
    
    ofFill();
    ofSetColor(0, 0, 255);
    ofCircle(_pos, 5);
    
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    bPlay = !bPlay;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    ofPoint mouse = ofPoint(x, y) - center;
    
    // Get the angle of the mouse position
    //
    float angleToMouse = atan2( mouse.y, mouse.x );
    
    /* ATAN2 ( http://processing.org/reference/atan2_.html )
     
     Calculates the angle (in radians) from a specified point to the
     coordinate origin as measured from the positive x-axis. Values
     are returned as a float in the range from PI to -PI. The atan2()
     function is most often used for orienting geometry to the position
     of the cursor. Note: The y-coordinate of the point is the first
     parameter, and the x-coordinate is the second parameter, due the
     the structure of calculating the tangent.
     
     Syntax
     atan2(y, x)
     
     Parameters
     y	float: y-coordinate of the point
     x	float: x-coordinate of the point
     */
    
    if (angleToMouse < 0){
        angle = PI + (PI + angleToMouse);
    } else {
        angle = angleToMouse;
    }

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}