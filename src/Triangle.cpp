//
//  Triangle.cpp
//  original
//
//  Created by Namikawa Emiko on 2018/05/12.
//

#include "Triangle.hpp"
Triangle::Triangle(ofVec3f center){
    _center = center;
    triMesh = ofSpherePrimitive(1000, 10).getMesh(); //meshを作成
    size = triMesh.getVertices().size();

    for (int i = 0; i < size; i++) {
        triMesh.addColor(ofFloatColor(0.5, 1.0, 1.0, 0.5));
        pos.push_back(triMesh.getVertices()[i]/100);
//        triMesh.setVertex(i,pos[i]);
        pos.push_back(pos[3*i] + ofVec3f(ofRandom(4)-2, ofRandom(4)-2, ofRandom(4)-2));
        pos.push_back(pos[3*i] + ofVec3f(ofRandom(4)-2, ofRandom(4)-2, ofRandom(4)-2));

//        triMesh.
        cout << pos[3*i] << endl;
        cout << pos[3*i+1] << endl;
        cout << pos[3*i+2] << endl;
    }
    cout << pos.size() << endl;
    
        cam.setDistance(100);


}

void Triangle::draw(){
    cam.begin();
    ofTranslate(_center);
    for(int i = 0; i < size; i++){ //頂点の数だけ繰り返す
        ofSetColor(255, 0, 0, 120);
//        ofNoFill();
        ofDrawTriangle(pos[3*i]*vol, pos[3*i+1]*vol, pos[3*i+2]*vol);
//        triMesh.addColor(ofFloatColor(0.5, 1.0, 1.0, 0.5));
//        pos.push_back(triMesh.getVertices()[i]/100.0);
//        triMesh.setVertex(i, pos[i]);
        
//        triMesh.addColor(ofFloatColor(0.5, 1.0, 1.0, 0.5));
//        ofVec3f point = triMesh.getVertices()[i]/100.0;
//        triMesh.setVertex(i, point);
//        triMesh.addVertex(pos[i] + ofVec3f(ofRandom(20)-10,ofRandom(20)-10,ofRandom(20)-10));
//        triMesh.addVertex(pos[i] + ofVec3f(ofRandom(20)-10,ofRandom(20)-10,ofRandom(20)-10));
        
//        cout<< &triMesh.getVertices() << endl;
        
//        triMesh.addIndex(i);
//        triMesh.addIndex(triMesh.getVertices().size()-2);
//        triMesh.addIndex(triMesh.getVertices().size()-1);
    }
    ofPushMatrix();

    ofRotateY(ofGetFrameNum());
    
//    triMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
//    triMesh.draw();
//    triMesh.drawWireframe();
    ofPopMatrix();
    cam.end();
}
