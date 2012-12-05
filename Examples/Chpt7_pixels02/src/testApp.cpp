#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    videoIn.initGrabber(640, 480);
    imageOut.allocate(640, 480, OF_IMAGE_COLOR); // force to use 4 channels
}

//--------------------------------------------------------------
void testApp::update(){
    videoIn.update();
    
    if (videoIn.isFrameNew()){
        ofPixels pixels = videoIn.getPixelsRef();
        
        for (int x = 0; x < pixels.getWidth(); x++){
            for(int y = 0; y < pixels.getHeight(); y++){
                ofColor color = pixels.getColor(x, y);
                color.r = 255 - color.r;
                color.g = 255 - color.g;
                color.b = 255 - color.b;
                pixels.setColor(x,y, color);
            }
        }
        
        imageOut.setFromPixels(pixels);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	videoIn.draw(0, 0);
    imageOut.draw(640, 0);
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