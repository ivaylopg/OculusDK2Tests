#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetLogLevel( OF_LOG_VERBOSE );
    ofSetVerticalSync( true );
    
    camera.setup();
    camera.target(ofVec3f(1,0,0));
    
    showOverlay = false;
    predictive = true;
    
    ofHideCursor();
    oculusRift.baseCamera = &camera;
    oculusRift.setup();
    
    
    for (int i = 0; i < 50; i++) {
        cylinders[i].set(20,100);
        cylinders[i].setPosition(ofRandom(0,ofGetWidth()), 0, ofRandom(-600,600));
    }
    
    
    //ofHideCursor();
    ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, ofGetScreenHeight()/2 - ofGetHeight()/2);
    
    camera.begin();
    camera.end();


}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(oculusRift.isSetup()){
        
        if(showOverlay){
            
            oculusRift.beginOverlay(-230, 320,240);
            ofRectangle overlayRect = oculusRift.getOverlayRectangle();
            
            ofPushStyle();
            ofEnableAlphaBlending();
            ofFill();
            ofSetColor(255, 40, 10, 200);
            
            ofRect(overlayRect);
            
            ofSetColor(255,255);
            ofFill();
            ofDrawBitmapString("ofxOculusRift by\nAndreas Muller\nJames George\nJason Walters\nElie Zananiri\nFPS:"+ofToString(ofGetFrameRate())+"\nPredictive Tracking " + (oculusRift.getUsePredictiveOrientation() ? "YES" : "NO"), 40, 40);
            
            ofSetColor(0, 255, 0);
            ofNoFill();
            ofCircle(overlayRect.getCenter(), 20);
            
            ofPopStyle();
            oculusRift.endOverlay();
        }
        
        ofSetColor(255);
        glEnable(GL_DEPTH_TEST);
        
        
        oculusRift.beginLeftEye();
        drawScene();
        oculusRift.endLeftEye();
        
        oculusRift.beginRightEye();
        drawScene();
        oculusRift.endRightEye();
        
        oculusRift.draw();
        
        glDisable(GL_DEPTH_TEST);
    }
    else{
        camera.begin();
        drawScene();
        camera.end();
    }
}

//--------------------------------------------------------------
void ofApp::drawScene(){
    //ofBackground(0);

    
    
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
    
    if(oculusRift.isSetup()){
        
        ofPushMatrix();
        oculusRift.multBillboardMatrix();
        ofSetColor(255, 0, 0);
        ofCircle(0,0,.5);
        ofPopMatrix();
        
    }
    
    
    /*
    ofSetColor(255);
    ofDrawBitmapString("use mouse to look around\nw: forward\ns: backwards\na: strafe left\nd: strafe right\n\nspace bar: reset camera to (0,0,0)\ne: toggle movement ease-in\nf: toggle full-screen\nsee testApp.cpp for available methods and vars", ofPoint(30, 30));
    
    if (camera.easeIn) {
        ofDrawBitmapString("easing is ON", ofPoint(30, ofGetHeight()-30));
    } else {
        ofDrawBitmapString("easing is OFF", ofPoint(30, ofGetHeight()-30));
    }
    */

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
    
    if(key == 's'){
        oculusRift.reloadShader();
    }
    
    if(key == 'l'){
        oculusRift.lockView = !oculusRift.lockView;
    }
    
    if(key == 'o'){
        showOverlay = !showOverlay;
    }
    if(key == 'r'){
        oculusRift.reset();
        
    }
    if(key == 'h'){
        ofHideCursor();
    }
    if(key == 'H'){
        ofShowCursor();
    }
    
    if(key == 'p'){
        predictive = !predictive;
        oculusRift.setUsePredictedOrientation(predictive);
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
