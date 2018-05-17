//
//  AlphaBall.hpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/17.
//

#ifndef AlphaBall_hpp
#define AlphaBall_hpp

#include <stdio.h>
#include "ofMain.h"
#define N 15
#endif /* AlphaBall_hpp */

class AlphaBall{
private:float circle_r[N]; //円の半径
    float circle_x[N]; //円のx座標
    float circle_y[N]; //円のy座標
    float circle_z[N];
    float speed_x[N]; //x軸方向のスピード
    float speed_y[N]; //y軸方向のスピード
    float gravity; //重力
    float friction; //摩擦力
    int color_h[N];
    int color_s[N];
    int alpha[N];
public:
    void update();
    void draw();
    
    int boundNum[N]; //跳ね返った回数
    float *volume;
    
    AlphaBall();
};
