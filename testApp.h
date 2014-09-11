#pragma once

#include "ofMain.h"
#include "ofxUI.h"

typedef struct {
    
	float 	x;
	float 	y;
	bool 	bBeingDragged;
	bool 	bOver;
	float 	radius;
	
}draggableVertex;

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void drawGrid(float x, float y);
    void drawGridWave(float x, float y);
    void drawCircleEasy();
    void drawNumbers();
    void drawLetters();
    void drawCircleHard();
    void drawBackground();
    //void drawRenderWave(float x, float y);
    void drawGridNoise(float x, float y);
	void setGUI1();
	void setGUI2();
	void setGUI3();
	void setGUI4();
	void setGUI5();
	void clear();
    
	ofxUISuperCanvas *gui1;
	ofxUISuperCanvas *gui2;
	ofxUISuperCanvas *gui3;
    ofxUISuperCanvas *gui4;
    ofxUISuperCanvas *gui5;
    
	bool hideGUI;
	
	float red, green, blue;
    float framerate;
    float theta;
    int totalPts;
	bool bdrawGrid;
    bool bdrawGridWave;
    bool bdrawGridNoise;
    bool bdrawCircleEasy;
    bool bdrawCircleMedium;
    bool bdrawCircleHard;
	bool bdrawPadding;
	bool bclear;
    bool bdrawBackground;
    bool bdrawLetters;
    

	
    void guiEvent(ofxUIEventArgs &e);
    
    ofxUIMovingGraph *mg;
    float *buffer;
    ofImage *img;
    float *yvalues;
    
    ofPoint position;
    float radius;
    
 	int nCurveVertices;
    draggableVertex curveVertices[7];
    draggableVertex bezierVertices[4];
    
    float a,b, t, z;
    float amp, angle;
    float thickness;
    float r;
    
};
