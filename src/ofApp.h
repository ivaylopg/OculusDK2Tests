#pragma once

#include "ofMain.h"
#include "ofxFPSCamera.h"
#include "ofxOculusDK2.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void drawScene();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxFPSCamera camera;
    ofCylinderPrimitive cylinders [50];
    
    ofxOculusDK2		oculusRift;
    
    ofLight				light;
    bool showOverlay;
    bool predictive;
    
    ofVec3f cursor2D;
    ofVec3f cursor3D;
    
    ofVec3f cursorRift;
    ofVec3f demoRift;
    
    ofVec3f cursorGaze;
};
