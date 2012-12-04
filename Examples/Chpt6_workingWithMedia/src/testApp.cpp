
#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
 
    string completePath = ofToDataPath("myFile.txt"); 
    cout << completePath << endl;
    
    ofSetVerticalSync(true);
    
	myFont.loadFont("Sketch_Block.ttf", 25, true, true);
    
    mySound.loadSound("Rondo Alla Turca Mozart.mp3");
    mySound.setLoop(true);
    mySound.play();

    myImage.loadImage("oFDocs_class.jpg");
    posImage.x = 30;
    posImage.y = 30;
    
    myVideo.loadMovie("Lumberjack Song - Monty Python.mp4");
    myVideo.play();
    myVideo.setSpeed(ofRandom(1,3));
    myVideo.setVolume(0);
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    myVideo.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    myVideo.draw(340, 30);
    myImage.draw(posImage);
    
    ofSetColor(255);
    myFont.drawString("Mani is our class lumberjack", 30, ofGetHeight()-90);
    myFont.drawString("The words are so obscene", 30, ofGetHeight()-60);
    ofDrawBitmapString("that we better play something else", 30, ofGetHeight()-40);

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