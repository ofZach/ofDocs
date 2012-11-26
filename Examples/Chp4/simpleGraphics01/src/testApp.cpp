
#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(100, 200, 240); //r,g,b 
    ofSetCircleResolution(100); // makes the circle edge nice and smooth
    ofSetWindowTitle("simple drawing");
    ofSetWindowPosition(400, 0);
    // smooth the lines (nose mouth and smile)
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofFill();
    ofSetColor(255, 230, 190);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
    
    //square eye
    ofSetColor(255, 255, 255); //white
    //rectangle drawn from the center, instead of the default top left
    ofSetRectMode(OF_RECTMODE_CENTER);  
    ofRect(176, 145, 26, 26);
    ofSetColor(30, 100, 220);
    ofCircle(176, 145, 10); //x,y,radius 
    
    //round eye
    ofFill();
    ofSetColor(100,200,240, 255); // r,g,b + alpha 255 meaning - 100% opacity
    ofCircle(300, 145, 15);
    ofSetColor(60); // meaning, r+g+b == 60, giving a shade of grey
    ofCircle(300, 145, 8); //x,y,radius 
   
    //setting the lines
    ofSetColor(100); // meaning, r+g+b == 100, giving a shade of grey
    ofNoFill();
    ofSetLineWidth(3);
    
    //eyebrows
    ofLine(150, 120, 200, 120);
    ofLine(300, 120, 350, 100);
    
    //nose
    ofBeginShape(); 
        ofVertex(250, 180);
        ofVertex(250, 250);
        ofVertex(270, 240);
    ofEndShape(); 
    
    // smile 
    ofBeginShape(); 
        ofCurveVertex(100, 280); // begin point
        ofCurveVertex(100, 280);
        ofCurveVertex(150, 340);
        ofCurveVertex(200, 325);
        ofCurveVertex(250, 340);
        ofCurveVertex(300, 325);
        ofCurveVertex(350, 340);
        ofCurveVertex(400, 280);
        ofCurveVertex(400, 280); // end point
    ofEndShape(); // (true) will close the shape for you     
    
    // cheeks 
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY); 
        ofFill();
        ofSetColor(235, 95, 95, 127); // 4th value is the alpha - 50% opacity 
        ofCircle(100, ofGetHeight()/2, 40);
        ofCircle(400, ofGetHeight()/2, 40);
    ofEnableAlphaBlending();
    
    ofSetColor(0); // Black
    ofDrawBitmapString("Drawing with oF", 20,480);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

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