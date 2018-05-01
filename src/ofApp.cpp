#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    music.load("革命のエチュード.mp3");
    music.setLoop(true);
    music.setVolume(1);
    music.play();
    
    ofSetFrameRate(64);
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    
    gravity=0.15;
    friction=0.999;
    
    mode = 0;
    
    mesh_w = 256;
    mesh_h = 256;
    cam.setDistance(40);
    
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
    
    for (int i = 0; i<mesh_w; i++) {
        for (int j = 0; j<mesh_h; j++) {
            mesh.addColor(ofColor(120, 200, 255));
        }
    }
    
    ofBackground(10, 10, 10);
}

//--------------------------------------------------------------
void ofApp::update(){
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
    
    mesh.clearVertices();
    for (int i = 0; i < mesh_w; i++) {
        for (int j = 0; j < mesh_h; j++) {
            float mesh_x = sin(i*0.1)*volume[0]*400;
            float mesh_y = sin(j*0.15)*volume[0]*100;
            float mesh_z = mesh_x + mesh_y;
            mesh.addVertex(ofVec3f(i-mesh_w/2, j-mesh_h/2, mesh_z));
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (mode) {
        case 0:
            for (int i = 0; i<NUM; i++) {
                if (boundNum[i] < 7) {
                    ofSetColor(color_r[i], color_g[i], color_b[i], 180-boundNum[i]*30); //円の色の設定
                    circle_r[i] = volume[0]*500; //円の半径の設定
                    ofDrawCircle(circle_x[i], circle_y[i], circle_r[i]); //円の描画
                }
            }
            break;
            
        case 1:
            cam.begin();
            ofPushMatrix();
            ofRotateX(ofGetFrameNum());
            ofRotateY(ofGetFrameNum()/6);
            ofRotateZ(ofGetFrameNum()/4);
            glPointSize(1.0);
            glEnable(GL_POINT_SMOOTH);
            mesh.drawVertices();
            ofPopMatrix();
            cam.end();
            
        default:
            break;
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            mode = 0;
            break;
        case '1':
            mode = 1;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
