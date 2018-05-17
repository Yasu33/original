//
//  AlphaBall.cpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/17.
//

#include "AlphaBall.hpp"
AlphaBall::AlphaBall(){
    ofEnableAlphaBlending();

    gravity=-0.25;
    friction=0.999;

    for (int i = 0; i<N; i++) {
        circle_x[i] = ofRandom(-ofGetWidth()/2+20, ofGetWidth()/2-20); //円のx座標の初期値
        circle_y[i] = -ofGetHeight()/2 + ofSoundGetSpectrum(1)[0] * 10000; //円のy座標の初期値
        circle_z[i] = i;
        speed_x[i] = ofRandom(-8, 8); //円のx軸方向のスピードの初期値
        speed_y[i] = ofRandom(-5,0); //円のy軸方向のスピードの初期値
        color_h[i] = ofRandom(0,255);
        color_s[i] = ofRandom(150,255);
        alpha[i] = 120;
        boundNum[i] = 0;
    }
    
}

void AlphaBall::update(){
    volume = ofSoundGetSpectrum(1);
    
    for(int i = 0; i<N ; i++){
        
        //スピードの更新
        speed_x[i] = speed_x[i] * friction;
        speed_y[i] = speed_y[i] * friction;
        speed_y[i] = speed_y[i] + gravity;
        
        //座標の更新
        circle_x[i] = circle_x[i] + speed_x[i];
        circle_y[i] = circle_y[i] + speed_y[i];

        //円のはね返り
        if(circle_x[i] < -ofGetWidth()/2 || circle_x[i] > ofGetWidth()/2){
            speed_x[i] = -speed_x[i];
        }
        
        if (circle_y[i] < -ofGetHeight()/2) {
            speed_y[i] = -speed_y[i] * 0.8;
            boundNum[i] = boundNum[i] + 1;
        }
        
        alpha[i] = 120 - boundNum[i]*30;
        
    }
}

void AlphaBall::draw(){
    cam.begin();
    for (int i = 0; i<N; i++) {
        if (boundNum[i] < 4) {
            circle_r[i] = volume[0]*500; //円の半径の設定
            ofSetColor(ofColor::fromHsb(color_h[i], color_s[i], 255, alpha[i]));
            ofDrawCircle(circle_x[i], circle_y[i], circle_z[i], circle_r[i]); //円の描画
        }
    }
    cam.end();
}
