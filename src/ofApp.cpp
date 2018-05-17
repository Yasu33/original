#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    ofBackground(255);
    
    //音楽
    music.load("スペイン舞曲shortver.mp3");
    music.setLoop(true);
    music.setVolume(1);
    music.play();
    
    //画面切り替え
    mode = 0;
    
    //ボールバウンド
    time_b = 0.0;
    alball.push_back(*new AlphaBall());

    //mesh
    mesh_w = 256;
    mesh_h = 256;
    
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
    
    switch (mode) {
        case 0:
            // ボールバウンド
            if (time - time_b > 0.3) {
                alball.push_back(*new AlphaBall());
                time_b = time;
            }
            for (int i = 0; i < alball.size(); i++) {
                alball[i].update();
                if (*alball[i].boundNum == 3) {
                    alball.erase(alball.begin() + i);
                }
            }
            break;
        case 1:
            //mesh
            alphaball.volume = ofSoundGetSpectrum(1);
            mesh.clearVertices();
            for (int i = 0; i < mesh_w; i++) {
                for (int j = 0; j < mesh_h; j++) {
                    float mesh_x = sin(i*0.1 + time*5)*alphaball.volume[0]*400;
                    float mesh_y = sin(j*0.15 + time)*alphaball.volume[0]*100;
                    float mesh_z = mesh_x + mesh_y;
                    mesh.addVertex(ofVec3f(i-mesh_w/2, j-mesh_h/2, mesh_z));
                }
            }
            break;
        case 2:
            //FFT解析
            fft.update();
            break;
        default:
            break;
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (mode) {
        case 0: //ボールバウンド
            cam.setDistance(650);
            cam.begin();
            for (int i = 0; i < alball.size(); i++) {
                alball[i].draw();
            }
            cam.begin();
            break;
            
        case 1: //mesh
            ofBackground(20);
            ofPushView();
            cam.setDistance(40);
            cam.begin();
            ofPushMatrix();
            ofRotateX(ofGetFrameNum());
            ofRotateY(ofGetFrameNum()/5);
            ofRotateZ(ofGetFrameNum()/3);
            glPointSize(2.0);
            glEnable(GL_POINT_SMOOTH);
            mesh.drawVertices();
            ofPopMatrix();
            cam.end();
            ofPopView();
            break;
            
        case 2: //triangle
            lowValue = ofMap(fft.getLowVal(), 0, 1, 1, 3);
            midValue = ofMap(fft.getMidVal(), 0, 1, 1, 3);
            heighValue = ofMap(fft.getHighVal(), 0, 1, 1, 3);
            triarray[0]->vol = lowValue;
            cout << fft.getLowVal() << endl;
            triarray[0]->hue = ofMap(fft.getLowVal(), 0, 1, 0, 50);
            triarray[0]->draw();
            triarray[1]->vol = midValue;
            triarray[1]->hue = ofMap(fft.getMidVal(), 0, 1, 50, 120);
            triarray[1]->draw();
            triarray[2]->vol = heighValue;
            triarray[2]->hue = ofMap(fft.getHighVal(), 0, 1, 130, 200);
            triarray[2]->draw();
            break;
            
        default:
            break;
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a') {
        for (int i = 0; i<235; i++) {
            ofBackground(255-i);
        }
        ofBackground(20);
    }
    if (key == 's') {
        ofBackground(255);
    }
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


