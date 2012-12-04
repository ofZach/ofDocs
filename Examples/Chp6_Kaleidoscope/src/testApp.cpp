#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    width = 640;
    height = 480;
    video.initGrabber(width, height);
}

//--------------------------------------------------------------
void testApp::update(){
    video.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofVec2f radio = ofVec2f(0,-height*0.5);
    //  A
    ofVec2f A= ofVec2f(width*0.5, height*0.5);
    ofVec2f p[2];
    //  B
    p[0] = radio + A;
    //  C
    p[1] = radio.getRotated(60) + A;
    
    ofMesh mesh;
    
    video.getTextureReference().bind();
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.addTexCoord( A );
    mesh.addVertex( A );
    for(int i = 0; i < 7; i++){
        mesh.addTexCoord(p[i%2]);
        ofVec2f e = radio.getRotated(60*i) + A;
        mesh.addVertex(e);
    }
    
    mesh.draw();
    video.getTextureReference().unbind();
    
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