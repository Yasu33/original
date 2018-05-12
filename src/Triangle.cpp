//
//  Triangle.cpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/12.
//

#include "Triangle.hpp"
Triangle::Triangle(ofVec3f center){
    _center = center;
}

void Triangle::draw(){
    triMesh = ofSpherePrimitive(vol, 30).getMesh(); //meshを作成
    for(int i = 0; i < triMesh.getVertices().size(); i++){ //頂点の数だけ繰り返す
        triMesh.addColor(ofFloatColor(0.5, 1.0, 1.0, 0.5));
        ofVec3f point = triMesh.getVertices()[i]/100.0;
        triMesh.setVertex(i, point);
    }
    cam.setDistance(100);
    cam.begin();
    ofTranslate(_center);
    
    triMesh.setMode(OF_PRIMITIVE_POINTS);
    triMesh.draw();
    cam.end();
}
