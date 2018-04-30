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
    float circle_r[NUM]; //円の半径
    float circle_x[NUM]; //円のx座標
    float circle_y[NUM]; //円のy座標
    float speed_x[NUM]; //x軸方向のスピード
    float speed_y[NUM]; //y軸方向のスピード
    float gravity; //重力
    float friction; //摩擦力
    int boundNum[NUM]; //跳ね返った回数
    int color_r[NUM];
    int color_g[NUM];
    int color_b[NUM];
    
    ofEasyCam cam;
		
};
