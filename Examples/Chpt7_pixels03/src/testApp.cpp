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
        unsigned char *pixels = videoIn.getPixels();
        
        int width = videoIn.getWidth();
        int height = videoIn.getHeight();
        
        for (int x = 0; x < width; x++){
            for(int y = 0; y < height; y++){
                
                int i = y * width + x;
                
                pixels[i * 3 + 0] = 255 - pixels[i * 3 + 0];
                pixels[i * 3 + 1] = 255 - pixels[i * 3 + 1];
                pixels[i * 3 + 2] = 255 - pixels[i * 3 + 2];
            }
        }
        
        imageOut.setFromPixels(pixels, width, height, OF_IMAGE_COLOR);
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