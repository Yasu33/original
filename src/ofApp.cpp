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
    
    time_b = 0.0;
    
    
    circle.push_back(*new Balls());
    circle[0].setup();
    
    mode = 0;
    
    mesh_w = 256;
    mesh_h = 256;
    cam.setDistance(40);
    
    for (int i = 0; i<mesh_w; i++) {
        for (int j = 0; j<mesh_h; j++) {
            mesh.addColor(ofColor(180, 150, 255));
        }
    }
    
    ofBackground(10, 10, 10);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    
    // ball
    if (time - time_b > 0.3) {
        circle.push_back(*new Balls());
        circle[circle.size() -1].setup();
        time_b = time;
    }

    for (int i = 0; i < circle.size(); i++) {
        if (*circle[i].boundNum == 5) {
            circle.erase(circle.begin() + i);
        }
        circle[i].update();
    }
    
//    balls.update();
    balls.volume = ofSoundGetSpectrum(1);
    
    //mesh
    mesh.clearVertices();
    for (int i = 0; i < mesh_w; i++) {
        for (int j = 0; j < mesh_h; j++) {
            float mesh_x = sin(i*0.1 + time*5)*balls.volume[0]*400;
            float mesh_y = sin(j*0.15 + time)*balls.volume[0]*100;
            float mesh_z = mesh_x + mesh_y;
            mesh.addVertex(ofVec3f(i-mesh_w/2, j-mesh_h/2, mesh_z));
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (mode) {
        case 0:
//            balls.draw();
            for (int i = 0; i < circle.size(); i++) {
                circle[i].draw();
            }
            break;
            
        case 1:
            cam.begin();
            ofPushMatrix();
            ofRotateX(ofGetFrameNum());
            ofRotateY(ofGetFrameNum()/6);
            ofRotateZ(ofGetFrameNum()/4);
            glPointSize(2.0);
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
