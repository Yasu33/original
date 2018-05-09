#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "Balls.hpp"
#include <vector>
#include <algorithm>

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
    
    int mesh_w; //メッシュの幅
    int mesh_h; //メッシュの高さ
    int mode; //切り替え
    float time; //今の時間
    float time_b; //前の時間
    
    
    vector <Balls> circle;
    
    
    ofEasyCam cam;
    ofSoundPlayer music;
    ofMesh mesh;
    
    Balls balls;
    
    ProcessFFT fft;
		
};
