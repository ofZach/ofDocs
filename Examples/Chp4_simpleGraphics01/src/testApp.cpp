
#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(100, 200, 240); //r,g,b 
    ofSetCircleResolution(100); // makes the circle edge nice and smooth
    
    bSmooth = true;

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
    ofSetRectMode(OF_RECTMODE_CENTER); //rectangle drawn from the center, instead of the default top left 
    ofRect(176, 145, 26, 26);
    
    ofSetColor(30, 100, 220);
    ofCircle(176, 145, 10); //x,y,radius 
    
    
    //round eye
    ofFill();
        ofSetColor(100,200,240, 255); // r,g,b + alpha 255 meaning - 100% opacity
        ofCircle(300, 145, 15);
        ofSetColor(60); // meaning, r+g+b == 60, giving a shade of grey
        ofCircle(300, 145, 8); //x,y,radius 
   
    
    // enable to smooth the lines (nose and mouth)
    if (bSmooth){
		ofEnableSmoothing();
	}

    ofSetColor(100); // meaning, r+g+b == 100, giving a shade of grey
    ofSetLineWidth(3);
    
    //nose

    ofLine(250, 180, 250, 250);
    ofLine(250, 250, 270, 240);
    
    
    // smile 

    ofNoFill();
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



	if (bSmooth){
		ofDisableSmoothing();
	}
    
    
    // cheeks
    
    ofEnableAlphaBlending();
//    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY); 
        ofFill();
        ofSetColor(235, 95, 95, 127); // 4th value is the alpha - 50% opacity 
        ofCircle(100, ofGetHeight()/2, 40);
        ofCircle(400, ofGetHeight()/2, 40);
//    ofDisableAlphaBlending();
    ofDisableBlendMode();

    
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