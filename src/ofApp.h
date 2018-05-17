#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Triangle.hpp"
#include "AlphaBall.hpp"
#include "ofxProcessFFT.h"
#include <vector>
#include <algorithm>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
    int mode; //切り替え
    ofxPanel gui;
    ofEasyCam cam;
    ofSoundPlayer music;
    
    //ballバウンド
    float time; //今の時間
    float time_b; //前の時間
    AlphaBall alphaball;
    vector<AlphaBall> alball;
    
    //mesh
    int mesh_w; //メッシュの幅
    int mesh_h; //メッシュの高さ
    ofMesh mesh;

    //FFT解析
    ProcessFFT fft;
    
    //triangle
    float lowValue; //低周波数の音量
    float midValue; //中周波数の音量
    float heighValue; //高周波数の音量
    Triangle* triarray[3];
    

		
};
