#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(120);

    bFullscreen	= 0;

    ofSetVerticalSync(false);
    ofBackground(0);
    ofSetCircleResolution(200);
    ofHideCursor();
    //mapper.setup();

    ofEnableDepthTest();
    baseNode.setPosition(0, 0, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, 0, 200);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(0,50,0);

        path.setMode(ofPath::POLYLINES);
        path.setStrokeColor(ofColor::white);
        path.setFillColor(ofColor::white);
        path.setFilled(true);
        path.setStrokeWidth(2);

}

//--------------------------------------------------------------
void ofApp::update(){
    //mapper.update();
    for (auto &vert : line.getVertices()){
        vert.x += ofRandom(-1,1);
        vert.y += ofRandom(-1,1);
    }

        baseNode.pan(1);
        childNode.tilt(3);

        //line.addVertex(grandChildNode.getGlobalPosition());
        if (line.size() > 10){
            line.getVertices().erase(
                                     line.getVertices().begin()
                                     );
        }

        pct+=0.01;
            if (pct >1) {
                pct = 0;
            }
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

    //line.draw();

      //cam.begin();
      //uncomment these 3 lines to understand how nodes are moving
      //baseNode.draw();
      //childNode.draw();
      //grandChildNode.draw();
    //line.draw();
      //cam.end();

        path.draw();

        ofSetColor(ofColor::red);

        //ofDrawCircle(path.getOutline().back().getPointAtPercent(pct), 20);
        //ofDrawCircle(path.getOutline().back().getVertices(), 20);



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
    else if (key == 'c') {
        //line.clear();
        path.close();
    } else if (key == 'b') {
        line.clear();
        path.clear();
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
    //path.getCommands().back().to.set(ofPoint(x,y));

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //mapper.mousePressed(x, y, button);
    std::printf("button");

    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);
    path.lineTo(x,y);

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
