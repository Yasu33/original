#pragma once

#include "ofMain.h"
#define NUM 50

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSoundPlayer music;
    
    float *volume;
    int circle_r[NUM];
    int s_circle_x[NUM];
    int s_circle_y = ofGetHeight()/2;
    int circle_x[NUM];
    int circle_y;
    int change_x[NUM];
    int change_y = 1;
    int color_r[NUM];
    int color_g[NUM];
    int color_b[NUM];
    float time;
		
};
