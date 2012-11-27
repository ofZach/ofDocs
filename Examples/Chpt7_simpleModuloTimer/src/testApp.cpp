#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowPosition(650, 200);
    ofSetFrameRate(60);
    
    counter = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    
    // counting the frames since the launch of the app
    // 60 times a second (every frame) 
    counter++;

}

//--------------------------------------------------------------
void testApp::draw(){

    // counterModulo will count in cycles of 0->200
    int counterModulo = counter % 200;
    
    // the background color will change when counterModulo is bigger or smaller than 100
    if (counterModulo < 100) {
        ofBackground(200,220,0);
    } else {
        ofBackground(0, 200, 200);
    }
    
    // print the value of the counter to the screen
    ofSetColor(255);
    string modulo = ofToString(counterModulo);
    ofDrawBitmapString(modulo, 50, 60);

    
    //Let's print the values of the counter and the counterModulo to the console
    // To open the Console go to View >> Debug Area >> Activate Console
    
    cout << counter << "  " << counterModulo << endl;

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