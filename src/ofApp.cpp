#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    count = logLength();
    fileName = ofToString(count,5,'0') + ".png"; 
    log();
    w = ofGetWindowWidth();
    h = ofGetWindowHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    // bg texture
    ofBackground(ofColor::fromHsb(30, 20, 230));
    canvas(80);

//////////////////////////////////////////////
    ofPushMatrix();
    //!s!// 
    print.colour(180,200,200,100);
    print.read(p0000,100,100,200,0);
    print.read(p0001,100,100,200,0);
    //!e!//
    ofPopMatrix();
//////////////////////////////////////////////

    img.grabScreen(0,0,w,h);
    img.saveImage(fileName);


    ofExit();
}

//--------------------------------------------------------------
void ofApp::canvas(int alpha){
    for(int i = 0; i<w; i+=2){
        for(int j=0; j<h; j+=2){
            int f = floor(ofRandom(220,250));
            ofSetColor(f,f,f,alpha);
            ofRect(i,j,2,2);
        }
    }
    for(int i = 0; i<18; i++){
        int f = floor(ofRandom(160,210));
        ofSetColor(f,f,f,ofRandom(alpha*1.6,alpha*2.6));
        ofRect(ofRandom(0,w),ofRandom(0,h),ofRandom(1,3),ofRandom(1,3));
    }
}

//--------------------------------------------------------------
void ofApp::log(){
  ofstream logfile ("log.csv",ios::out | ios::app);
  if (logfile.is_open())
  {
    logfile << fileName << ",";
    logfile << ofToString(count) << "\n";
    logfile.close();
  }
  else cout << "Unable to open file";
}
//--------------------------------------------------------------
int ofApp::logLength(){
    int numLines = 0;
    std::string line;
    std::ifstream logFile("log.csv");

    while (std::getline(logFile, line))
        ++numLines;
    return numLines;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
