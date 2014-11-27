#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    camera.setup();
    camera.target(ofVec3f(1,0,0));
    
    
    for (int i = 0; i < 50; i++) {
        cylinders[i].set(20,100);
        cylinders[i].setPosition(ofRandom(0,ofGetWidth()), 0, ofRandom(-600,600));
    }
    
    
    ofHideCursor();
    ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, ofGetScreenHeight()/2 - ofGetHeight()/2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    camera.begin();
    
    
    ofSetColor(100);
    int step = 20;
    for (int i = 0; i < step; i++) {
        ofLine(i*ofGetWidth()/step, -50, -ofGetWidth(), i*ofGetWidth()/step, -50, ofGetWidth());
        ofLine(0, -50, i*ofGetWidth()/step, ofGetWidth(), -50, i*ofGetWidth()/step);
        ofLine(0, -50, -i*ofGetWidth()/step, ofGetWidth(), -50, -i*ofGetWidth()/step);
    }
    
    ofSetColor(255);
    for (int i = 0; i < 50; i++) {
        cylinders[i].drawWireframe();
    }
    
    
    camera.end();
    
    
    
    ofSetColor(255);
    ofDrawBitmapString("use mouse to look around\nw: forward\ns: backwards\na: strafe left\nd: strafe right\n\nspace bar: reset camera to (0,0,0)\ne: toggle movement ease-in\nf: toggle full-screen\nsee testApp.cpp for available methods and vars", ofPoint(30, 30));
    
    if (camera.easeIn) {
        ofDrawBitmapString("easing is ON", ofPoint(30, ofGetHeight()-30));
    } else {
        ofDrawBitmapString("easing is OFF", ofPoint(30, ofGetHeight()-30));
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            camera.setPosition(0, 0, 0);
            camera.target(ofVec3f(1,0,0));
            break;
            
        case 'f':
            ofToggleFullscreen();
            break;
            
        case 'e':
            camera.easeIn = !camera.easeIn;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
