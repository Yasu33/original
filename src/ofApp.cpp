#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    music.load("革命のエチュード.mp3");
    music.setLoop(true);
    music.setVolume(1);
    music.play();
    
    ofEnableAlphaBlending();
    
    circle_y = s_circle_y;

    
    for (int i = 0; i<NUM; i++) {
        s_circle_x[i] = ofRandom(100, ofGetWidth()-100);
        circle_x[i] = s_circle_x[i];
        change_x[i] = ofRandom(-4, 4);
        color_r[i] = ofRandom(120,255);
        color_g[i] = ofRandom(100,255);
        color_b[i] = ofRandom(100,255);
    }
    
    ofBackground(10, 10, 10);
}

//--------------------------------------------------------------
void ofApp::update(){
    volume = ofSoundGetSpectrum(1);
    
    for(int i = 0; i<NUM ; i++){
        if(circle_x[i] < 0 || circle_x[i] > ofGetWidth()){
            change_x[i] = -change_x[i];
        }
        
        circle_x[i]=circle_x[i] + change_x[i];
    
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(0, ofGetHeight());
    
    ofPushMatrix();
    ofRotateX(180);
    
        for (int i = 0; i<NUM; i++) {
            ofSetColor(color_r[i], color_g[i], color_b[i], 180);
            circle_r[i] = volume[0]*600;
            ofDrawCircle(circle_x[i], circle_y, circle_r[i]);
    
        }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
