//
//  Balls.cpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/06.
//

#include "Balls.hpp"

void Balls::setup(){
    
    gravity=0.15;
    friction=0.999;
    
    for (int i = 0; i<NUM; i++) {
        circle_x[i] = ofRandom(20, ofGetWidth()-20); //円のx座標の初期値
        circle_y[i] = ofGetHeight()/2; //円のy座標の初期値
        speed_x[i] = ofRandom(-10, 10); //円のx軸方向のスピードの初期値
        speed_y[i] = ofRandom(0,5); //円のy軸方向のスピードの初期値（自由落下）
        color_r[i] = ofRandom(120,255);
        color_g[i] = ofRandom(100,255);
        color_b[i] = ofRandom(100,255);
        boundNum[i] = 0;
    }
}

void Balls::update(){
    volume = ofSoundGetSpectrum(1);
    
    for(int i = 0; i<NUM ; i++){
        //スピードの更新
        speed_x[i] = speed_x[i] * friction;
        speed_y[i] = speed_y[i] * friction;
        speed_y[i] = speed_y[i] + gravity;
        
        //座標の更新
        circle_x[i] = circle_x[i] + speed_x[i];
        circle_y[i] = circle_y[i] + speed_y[i];
        
        //円のはね返り
        if(circle_x[i] < 0 || circle_x[i] > ofGetWidth()){
            speed_x[i] = -speed_x[i];
        }
        if (circle_y[i] >= ofGetHeight()) {
            circle_y[i] = ofGetHeight();
            speed_y[i] = -speed_y[i];
            boundNum[i] = boundNum[i] + 1;
        }
        
    }
}

void Balls::draw(){
    for (int i = 0; i<NUM; i++) {
        if (boundNum[i] < 7) {
            ofSetColor(color_r[i], color_g[i], color_b[i], 180-boundNum[i]*30); //円の色の設定
            circle_r[i] = volume[0]*500; //円の半径の設定
            ofDrawCircle(circle_x[i], circle_y[i], circle_r[i]); //円の描画
        }
    }
}
