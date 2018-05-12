//
//  Triangle.hpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/12.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "ofMain.h"


//#define num 100

#endif /* Triangle_hpp */

class Triangle{
private:
    ofEasyCam cam; //3D
    ofMesh triMesh;
    ofVec3f _center;
    
public:
    void draw();
    float vol; //円の大きさ
    Triangle(ofVec3f center); //コンストラクタ　center:円の中心座標
    ofFloatColor triColor;
    

};
