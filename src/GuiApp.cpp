/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"

void GuiApp::setup(){
	parameters.setName("parameters");
	parameters.add(radius.set("radius",50,1,100));
	parameters.add(color.set("color",100,ofColor(0,0),255));
	gui.setup(parameters);
	ofBackground(0);
    ofSetVerticalSync(true);

    datagui->addFRM();
    datagui->addToggle("Crosshair");
    datagui->addSlider(radius);
    //datagui->addColorPicker("color", color);
    datagui->addButton("Click!");

    datagui->onToggleEvent(this, &GuiApp::onToggleEvent);
    datagui->onColorPickerEvent(this, &GuiApp::onColorPickerEvent);
}

void GuiApp::update(){

}

void GuiApp::onToggleEvent(ofxDatGuiToggleEvent e)
{
    //cout << "onSliderEvent: " << e.target->getLabel() << " " << endl;

    if(e.checked){
      cout << "bumms: " << e.checked << " " << endl;
      crosshair = true;
    } else {
      crosshair = false;
    }

    //if (e.target->is("datgui opacity")) gui->setOpacity(e.scale);
}

void GuiApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    cout << "onSliderEvent: " << e.target->getLabel() << " " << e.target->getValue() << endl;
    //if (e.target->is("datgui opacity")) gui->setOpacity(e.scale);
}

void GuiApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
    cout << "onColorPickerEvent: " << e.target->getLabel() << " " << e.target->getColor() << endl;
    //ofSetBackgroundColor(e.color);
    color = e.color;
}

//--------------------------------------------------------------
void GuiApp::mouseMoved(int x, int y ){
    ofShowCursor();
}


void GuiApp::draw(){
	gui.draw();
}
