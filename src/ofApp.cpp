#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(120);

    bFullscreen	= 0;

    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetCircleResolution(200);
    ofHideCursor();
    //mapper.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    //mapper.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(gui->color);
    //ofDrawCircle(ofGetWidth()*0.5,ofGetWidth()*0.5,gui->radius);
    ofSetColor(255);
    ofDrawBitmapString(ofGetFrameRate(),20,20);
    //mapper.draw();
    if(datagui->crosshair){
        ofDrawLine(0, ofGetMouseY(), ofGetWidth() , ofGetMouseY());
        ofDrawLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
    }
    //std::printf("value: %f\n", double());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){

        bFullscreen = !bFullscreen;

        if(!bFullscreen){
            ofSetWindowShape(300,300);
            ofSetFullscreen(false);
            // figure out how to put the window in the center:
            int screenW = ofGetScreenWidth();
            int screenH = ofGetScreenHeight();
            ofSetWindowPosition(screenW/2-300/2, screenH/2-300/2);
        } else if(bFullscreen == 1){
            ofSetFullscreen(true);
        }
    }

    //mapper.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //mapper.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //mapper.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //mapper.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //mapper.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
