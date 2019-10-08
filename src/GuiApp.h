#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDatGui.h"

class GuiApp: public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	ofParameterGroup parameters;
	ofParameter<float> radius;
    ofParameter<bool> crosshair;
	ofParameter<ofColor> color;
	ofxPanel gui;
    ofxDatGui* datagui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );

    //void onButtonEvent(ofxDatGuiButtonEvent e);
    void onToggleEvent(ofxDatGuiToggleEvent e);
    void onSliderEvent(ofxDatGuiSliderEvent e);
    //void onTextInputEvent(ofxDatGuiTextInputEvent e);
    //void on2dPadEvent(ofxDatGui2dPadEvent e);
    //void onDropdownEvent(ofxDatGuiDropdownEvent e);
    void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
    //void onMatrixEvent(ofxDatGuiMatrixEvent e);
    void mouseMoved(int x, int y );


};

