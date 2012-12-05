#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    faceImg.loadImage("face.png");
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofSetColor(255,255,255);
    faceImg.draw(0,0);
    

    unsigned char * pixels = faceImg.getPixels();
    for (int i = 0; i < faceImg.getWidth(); i+=10){
        for (int j = 0; j < faceImg.getHeight(); j+=10){
            int pixPos = j*faceImg.getWidth()+i;
            ofSetColor(pixels[pixPos * 3 + 0],
                       pixels[pixPos * 3 + 1],
                       pixels[pixPos * 3 + 2]);
            ofCircle(i,j + 300, 5);
        }
    }
    
    
    
    ofPixels myPixels = faceImg.getPixelsRef();
    
    for (int i = 0; i < faceImg.getWidth(); i+=10){
        for (int j = 0; j < faceImg.getHeight(); j+=10){
            ofColor myColor = myPixels.getColor(i, j);
            ofSetColor(myColor);
            ofCircle(i, j + 600, 5);
        }
    }
    
    
    ofSetColor(255,255,255);
    
    ofTexture myTexture = faceImg.getTextureReference();
    
    ofMesh myTriangle;
    myTriangle.setMode(OF_PRIMITIVE_TRIANGLES);
    
    myTriangle.addTexCoord(ofPoint(0,0));
    myTriangle.addVertex(ofPoint(mouseX, mouseY));
    myTriangle.addTexCoord(ofPoint(faceImg.getWidth(),0));
    myTriangle.addVertex(ofPoint(mouseX + 100, mouseY));
    myTriangle.addTexCoord(ofPoint(faceImg.getWidth()/2,faceImg.getHeight() - ofRandom(0,40)));
    myTriangle.addVertex(ofPoint(mouseX + 50, mouseY+80));
                           
    myTexture.bind();
    myTriangle.draw();
    myTexture.unbind();

    
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