
#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
   
    angle = 0; // initiate and assign values to variables in the setup
}

//--------------------------------------------------------------
void testApp::update(){
    
    angle = angle - 0.02f; // decrement to orbit the planets counter-clockwise around the Sun
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofColor gray(127,127,127); // ofColor can contain 3 values (r,g,b) in one variable (gray)
    ofColor black(0,0,0);
    ofBackgroundGradient(gray, black);

    //you can also write it like this:
    //    ofBackgroundGradient(ofColor::gray, ofColor::black);
        
    // use indentation and commenting to make a better sense of what function is affecting what shape 
    
    ofPushMatrix();
    
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2); // the (0,0) point is now at the center of the canvas
        ofRotateZ(angle * RAD_TO_DEG);

            //SUN
            ofSetColor(252,242,203);
            ofFill();
            ofCircle(0,0,80);  

            //Mercury
            ofFill();
            ofSetColor(200, 0, 0);
            ofCircle(80, 80, 15);
        
            //Venus
            //adding 30 degrees, to shift Venus from Mercury's path
            ofRotateZ(30);
            ofFill();
            ofSetColor(0, 200, 0);
            ofCircle(120, 120, 28);

            //Earth
            //that's another way to shift a planet:
            //adding 200 degrees on the vecZ
            ofRotate(200, 0, 0, 1); //float degrees, float vecX, float vecY, float vecZ)
            ofFill();
            ofSetColor(0, 0, 200);
            ofCircle(180, 180, 24);

            ofPushMatrix();  
            ofTranslate(180, 180); 

                //Moon
                ofRotateZ(angle * RAD_TO_DEG * 2); // faster!
                ofFill();
                ofSetColor(255);
                ofCircle(30, 30, 6);
            ofPopMatrix();

    ofPopMatrix();
            
    

    
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