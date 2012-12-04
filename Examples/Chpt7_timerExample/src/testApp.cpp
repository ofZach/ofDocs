#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowPosition(650, 200);
    ofSetFrameRate(60);

    lastTime = ofGetElapsedTimef();
    duration = 5;
}

//--------------------------------------------------------------
void testApp::update(){
    
    float diffTime = ofGetElapsedTimef() - lastTime;
    if (diffTime > duration) {
        cout << "hi! at time = " << int(ofGetElapsedTimef()) << "  duration = " << int(duration) << endl;
        ofBackground(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
        lastTime = ofGetElapsedTimef();
        duration = ofRandom(1,5);
    }
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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