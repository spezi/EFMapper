#pragma once

#include "ofMain.h"
#include "GuiApp.h"
//#include "ofxPiMapper.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    ofPath polysToPath(ofPolyline polylines);
    void nearestVertex();
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    shared_ptr<GuiApp> gui;
    shared_ptr<GuiApp> datagui;

    bool  	bFullscreen;
    bool  	bpaining;

    ofPolyline line;
    ofPath path;
    float pct;

    ofNode baseNode;
    ofNode childNode;
    ofNode grandChildNode;

    ofEasyCam cam;

    // This is our mapper object.
    //ofxPiMapper mapper;
};


