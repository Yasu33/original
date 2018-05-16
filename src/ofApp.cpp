#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(64);
    ofEnableAlphaBlending();
    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE);
    ofEnableDepthTest();
    ofBackground(10);
    
    //音楽
    music.load("革命のエチュード.mp3");
    music.setLoop(true);
    music.setVolume(1);
    music.play();
    
    //画面切り替え
    mode = 0;
    
    //ボールバウンド
    time_b = 0.0;
    circle.push_back(*new Balls());
//    circle[0].setup();
    
    //mesh
    mesh_w = 256;
    mesh_h = 256;
    cam.setDistance(40);
    
    for (int i = 0; i<mesh_w; i++) {
        for (int j = 0; j<mesh_h; j++) {
            mesh.addColor(ofColor(180, 150, 255));
        }
    }
    
    //triangle

    triarray[0] = new Triangle(ofVec3f(0,0,40));
    triarray[1] = new Triangle(ofVec3f(40*cos(PI/6),10,-20));
    triarray[2] = new Triangle(ofVec3f(-40*cos(PI/6),-10,-20));
    
    //FFT解析
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    //時間取得
    time = ofGetElapsedTimef();
    
    // ボールバウンド
    if (time - time_b > 0.4) {
        circle.push_back(*new Balls());
        time_b = time;
    }

    for (int i = 0; i < circle.size(); i++) {
        circle[i].update();
        if (*circle[i].boundNum == 5) {
            circle.erase(circle.begin() + i);
        }
    }
    
    //mesh
    balls.volume = ofSoundGetSpectrum(1);
    mesh.clearVertices();
    for (int i = 0; i < mesh_w; i++) {
        for (int j = 0; j < mesh_h; j++) {
            float mesh_x = sin(i*0.1 + time*5)*balls.volume[0]*400;
            float mesh_y = sin(j*0.15 + time)*balls.volume[0]*100;
            float mesh_z = mesh_x + mesh_y;
            mesh.addVertex(ofVec3f(i-mesh_w/2, j-mesh_h/2, mesh_z));
        }
    }
    
    //FFT解析
    fft.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (mode) {
        case 0: //ボールバウンド
            for (int i = 0; i < circle.size(); i++) {
                circle[i].draw();
            }
            break;
            
        case 1: //mesh
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
            break;
            
        case 2: //triangle
            lowValue = ofMap(fft.getLowVal(), 0, 1, 1, 3);
            midValue = ofMap(fft.getMidVal(), 0, 1, 1, 3);
            heighValue = ofMap(fft.getHighVal(), 0, 1, 1, 3);
            triarray[0]->vol = lowValue;
            triarray[0]->hue = ofMap(fft.getLowVal(), 0, 1, 0, 50);
            triarray[0]->draw();
            triarray[1]->vol = midValue;
            triarray[1]->hue = ofMap(fft.getMidVal(), 0, 1, 60, 110);
            triarray[1]->draw();
            triarray[2]->vol = heighValue;
            triarray[2]->hue = ofMap(fft.getHighVal(), 0, 1, 140, 190);
            triarray[2]->draw();
            break;
            
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
        case '2':
            mode = 2;
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
