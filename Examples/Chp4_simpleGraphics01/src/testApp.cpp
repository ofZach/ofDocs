
#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255, 230, 190); //r,g,b 
    ofSetCircleResolution(100); // makes the circle edge nice and smooth
    
    bSmooth = false;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofFill();
    ofSetColor(190, 90, 70);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
    
    //square eye
    ofSetColor(255, 255, 255); //white
    ofSetRectMode(OF_RECTMODE_CENTER); //rectangle drawn from the center, instead of the default top left 
    ofRect(176, 145, 26, 26);
    
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(30, 100, 220);
    ofCircle(176, 145, 7); //x,y,radius 
    
    ofEnableAlphaBlending();
    //round eye
    ofFill();
        ofSetColor(100,200,240, 255); // r,g,b + alpha 255 meaning - 100% opacity
        ofCircle(300, 145, 15);
        ofSetColor(60, 127); // meaning, r+g+b == 60, giving a shade of grey + 50% alpha
        ofCircle(300, 145, 8); //x,y,radius 
    ofDisableAlphaBlending();
    
    
    // enable to smooth the lines
    
    if (bSmooth){
		ofEnableSmoothing();
	}

    //nose
    
    ofSetLineWidth(3);
    ofSetColor(60); // meaning, r+g+b == 60, giving a shade of grey
    ofLine(250, 180, 250, 250);
    ofLine(250, 250, 270, 240);
    
    
    // smile 
    
    ofSetColor(255);
    
    ofNoFill();
    ofBeginShape(); 
    ofCurveVertex(100, 300); // begin point
        ofCurveVertex(100, 300);
        ofCurveVertex(150, 325);
        ofCurveVertex(200, 300);
        ofCurveVertex(250, 325);
        ofCurveVertex(300, 300);
        ofCurveVertex(350, 325);
        ofCurveVertex(400, 300);
    ofCurveVertex(400, 275); // end point
    ofEndShape(); // (true) will close the shape for you 



	if (bSmooth){
		ofDisableSmoothing();
	}
    
    ofSetColor(0); // Black
    ofDrawBitmapString("Press 's'", 20,480);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // low case or capital case 's' key will toggle between enable and diable the smoothing function. 
    if (key == 's' || key == 'S') {
        bSmooth = !bSmooth; 
    }
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