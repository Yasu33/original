//
//  Triangle.cpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/12.
//

#include "Triangle.hpp"
Triangle::Triangle(ofVec3f center){
    _center = center;
    triMesh = ofSpherePrimitive(1000, 15).getMesh(); //meshを作成
    size = triMesh.getVertices().size();

    for (int i = 0; i < size; i++) {
        triMesh.addColor(ofFloatColor(0.5, 1.0, 1.0, 0.5));
        pos.push_back(triMesh.getVertices()[i]/100+ ofVec3f(ofRandom(2)-1, ofRandom(2)-1, ofRandom(2)-1));
        pos.push_back(pos[3*i] + ofVec3f(ofRandom(2)-1, ofRandom(2)-1, ofRandom(2)-1));
        pos.push_back(pos[3*i] + ofVec3f(ofRandom(4)-2, ofRandom(4)-2, ofRandom(4)-2));

    }    
        cam.setDistance(100);


}

void Triangle::draw(){
    cam.begin();
    ofRotateY(ofGetFrameNum());
    ofTranslate(_center);
    ofPushMatrix();
    ofRotateX(ofGetFrameNum());
    ofRotateZ(ofGetFrameNum());
    for(int i = 0; i < size; i++){ //頂点の数だけ繰り返す
        color(hue);
        ofDrawTriangle(pos[3*i]*vol, pos[3*i+1]*vol, pos[3*i+2]*vol);

    }
    ofPopMatrix();
    cam.end();
}

void Triangle::color(int h){
    ofSetColor(ofColor::fromHsb(h, ofRandom(120, 255), ofRandom(100, 255)));
}
