#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(120);

    bFullscreen	= false;
    bpaining = false;

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
        bpainted = true;
    int nearestIndex = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //mapper.update();
    if(datagui->wiggle){
        for (auto &vert : line.getVertices()){
            vert.x += ofRandom(-1,1);
            vert.y += ofRandom(-1,1);
        }

    }



    for (auto &vert : path.getOutline().back().getVertices()){
        //cout << "path vertice: " <<  vert << " " << endl;
        //vert.x += ofRandom(-1,1);
        //vert.y += ofRandom(-1,1);
    }

        baseNode.pan(1);
        childNode.tilt(3);

        //line.addVertex(grandChildNode.getGlobalPosition());
        //if (line.size() > 10){
        //    line.getVertices().erase(
        //                             line.getVertices().begin()
        //                             );
        //}

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
      //uncomment these 3 lines to understand how nodes are movingv
      //childNode.draw();
      //grandChildNode.draw();
    //line.draw();
      //cam.end();

        if(line.size()) {
            //cout << "line size: " << line.size() << " " << endl;
            //for(int i=0;i<line.size(); i++){
            //    cout << "dat x: " << line.getVertices()[i].x << " " << endl;
            //    path.lineTo(line.getVertices()[i].x, line.getVertices()[i].y);
            //}
            //ofBeginShape();
            //vector<glm::vec3>& vertices = line.getVertices();
            //for(int j = 0; j < vertices.size(); j++) {
            //    ofVertex(vertices[j]);
            //}
            //ofEndShape();


        }

        //polyline.getPath();
        //ofPath path(polyline); // constructor






        //path = polysToPath(line);
        path.draw();



        ofSetColor(ofColor::white);
        ofNoFill();

        //ofDrawCircle(path.getOutline().back().getPointAtPercent(pct), 20);
        //ofDrawCircle(path.getOutline().back().getVertices(), 20);

        // get Vectoren von line oder path
        vector<glm::vec3> vertices = line.getVertices();
        //vector<glm::vec3> vertices = path.getOutline().back().getVertices();

        //cout << "vertex: " << vertices.data() << " " << endl;

        //kreise an den verticiesbpaining
        for (int vertexIndex=0; vertexIndex<vertices.size(); vertexIndex++) {
            auto vertex = vertices[vertexIndex];
            ofDrawCircle(vertex, 10);
            //cout << "vertex: " <<  vertex << " " << endl;
        }

        if(line.hasChanged()){
            path.clear();
            bpainted = false;
        }

        if(!bpainted) {
            for (int i = 0; i < line.getVertices().size(); i++){
                if ( i == 0 ) {
                    path.moveTo(line.getVertices()[i].x,line.getVertices()[i].y);
                    cout << "poli: " <<  line.getVertices()[i].x << " " << endl;
                } else if ( i == line.getVertices().size()){
                      path.close();
                }else {
                    path.lineTo(line.getVertices()[i].x,line.getVertices()[i].y);
                    cout << "poli2: " <<  line.getVertices()[i].x << " " << endl;
                }
                bpainted = true;
            }
       }

        // gt closest vertex

        int n = line.size();
        glm::vec2  nearestVertex;
        float nearestDistance = 0;
        glm::vec3  mouse(ofGetMouseX(), ofGetMouseY(), 0);
        //cout << "closest: " << line.getClosestPoint(mouse) << endl;

        for(int i = 0; i < n; i++) {
            //glm::vec3 cur = cam.worldToScreen(mesh.getVertex(i));
            glm::vec3 cur = line.getVertices()[i];
            distance = glm::distance(mouse, cur);
            //cout << "distance: " <<  distance << " " << endl;
            if(i == 0 || distance < nearestDistance) {
                nearestDistance = distance;
                nearestVertex = cur;
                nearestIndex = i;
            }
        }

        ofSetColor(ofColor::gray);
        ofDrawLine(nearestVertex, mouse);


        ofSetColor(ofColor::blueSteel);
        ofNoFill();
        ofDrawCircle(nearestVertex, 10);


}

ofPath ofApp::polysToPath(ofPolyline polylines) {
  ofPath path;
  for(int outline = 0; outline < polylines.size(); ++outline) {
        for (int i = 0; i < polylines[outline].length(); i++){
            if ( i == 0 ){
                path.moveTo(polylines[outline].x,polylines[outline].y);
                cout << "poli: " <<  polylines[outline].x << " " << endl;
            } else {
                path.lineTo(polylines[outline].x,polylines[outline].y);
                cout << "poli2: " <<  polylines[outline].x << " " << endl;
            }
        }
        path.close();
    }
   return path;
}

//--------------------------------------------------------------
void ofApp::nearestVertex(ofPolyline line){

        // nearest naighbor detection
        int n = line.size();
        float nearestDistance = 0;
        glm::vec2  nearestVertex;
        glm::vec3  mouse(ofGetMouseX(), ofGetMouseY(), 0);

            cout << "mouse: " << mouse << endl;
            //cout << "mouse2: " << path.getOutline().back().getClosestPoint(mouse) << endl;

        for(int i = 0; i < n; i++) {
            //glm::vec3 cur = cam.worldToScreen(mesh.getVertex(i));
            glm::vec3 cur = path.getOutline().back().getVertices()[i];
            float distance = glm::distance(mouse, cur);
            //cout << "distance: " <<  distance << " " << endl;
            if(i == 0 || distance < nearestDistance) {
                nearestDistance = distance;
                nearestVertex = cur;
                nearestIndex = i;
            }
        }

        ofSetColor(ofColor::gray);
        ofDrawLine(nearestVertex, mouse);


        ofSetColor(ofColor::blueSteel);
        ofNoFill();
        ofDrawCircle(nearestVertex, 10);
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
    } else if (key == 'p') {
        bpaining = !bpaining;
    } else if (key == 'v') {
        bpainted = false;
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
    //path.getCommands().back().to = (ofPoint(x,y));
    cout << "nearest index: " <<  nearestIndex << " " << endl;
    //cout << "index distance: " <<  distance << " " << endl;
    glm::vec3  mouse(x, y, 0);
    float nearest_distance = glm::distance(mouse, line.getVertices()[nearestIndex]);
    cout << "index distance: " <<  nearest_distance << " " << endl;

    if (nearest_distance < 10 ) {
        line.getVertices()[nearestIndex].x = x;
        line.getVertices()[nearestIndex].y = y;
    }


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //mapper.mousePressed(x, y, button);

    //std::printf("button");
    if(bpaining){
        //ofPoint pt;
        glm::vec3 pt;
        //pt.set(x,y,0);
        pt.x = x;
        pt.y = y;
        pt.z = 0;
        line.addVertex(pt);
        //path.lineTo(x,y);
    }

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
