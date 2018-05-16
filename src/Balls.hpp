//
//  Balls.hpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/06.
//

#ifndef Balls_hpp
#define Balls_hpp
#include "ofMain.h"

#define NUM 15

#include <stdio.h>

class Balls{
private:
    float circle_r[NUM]; //円の半径
    float circle_x[NUM]; //円のx座標
    float circle_y[NUM]; //円のy座標
    float speed_x[NUM]; //x軸方向のスピード
    float speed_y[NUM]; //y軸方向のスピード
    float gravity; //重力
    float friction; //摩擦力
    int color_h[NUM];
    int alpha[NUM];
    
public:
    void update();
    void draw();
    
    int boundNum[NUM]; //跳ね返った回数
    float *volume;

    Balls();
};

#endif /* Balls_hpp */
