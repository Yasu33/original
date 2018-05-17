//
//  Balls.cpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/06.
//

#include "Balls.hpp"
Balls::Balls(){
    ofEnableAlphaBlending();
    
    gravity=0.25;
    friction=0.999;
    
    for (int i = 0; i<NUM; i++) {
        circle_x[i] = ofRandom(20, ofGetWidth()-20); //円のx座標の初期値
        circle_y[i] = ofGetHeight() - ofSoundGetSpectrum(1)[0] * 10000; //円のy座標の初期値
        speed_x[i] = ofRandom(-10, 10); //円のx軸方向のスピードの初期値
        speed_y[i] = ofRandom(0,5); //円のy軸方向のスピードの初期値
        color_h[i] = ofRandom(0,255);
        alpha[i] = 180;
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
            speed_y[i] = -speed_y[i] * 0.8;
            boundNum[i] = boundNum[i] + 1;
            circle_y[i] = ofGetHeight();
        }
        
        alpha[i] = 180 - boundNum[i]*45;

    }
}

void Balls::draw(){
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
//    ofEnableAlphaBlending();
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE)
//    ofDisableBlendMode();
//    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE);
    for (int i = 0; i<NUM; i++) {
        if (boundNum[i] < 4) {
            ofEnableAlphaBlending();
            circle_r[i] = volume[0]*500; //円の半径の設定
            ofSetColor(color_h[i], 255, 255, 120);
            ofDrawCircle(circle_x[i], circle_y[i], circle_r[i]); //円の描画
        }
    }
}
