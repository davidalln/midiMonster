#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	drawGrid = false;
	cellSize = mmVec2f(32, 32);

	if (head == NULL) {
		head = std::make_shared<mmContainer>();
		head->connectComponents(head);
	}

	windowResized(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	head->renderAll();

	if (drawGrid) {
		ofSetColor(30);
		mmVec2f screenDim = mmVec2f(ofGetWidth(), ofGetHeight());
		mmVec2f screenCenter = screenDim / 2;

		mmVec2f centerCellTL = screenCenter - (cellSize / 2);
		mmVec2i gridDim = mmVec::to_i((screenDim - centerCellTL) / cellSize);
		mm2dVec2i grid = mmVec::boundaryFromSize(gridDim);

		for (int y = grid.tl.y; y < grid.br.y; y++) {
			for (int x = grid.tl.x; x < grid.br.x; x++) {
				mmVec2f lineCoords = (mmVec2f(x, y) * cellSize) + centerCellTL;
				ofDrawLine(lineCoords.x, 0, lineCoords.x, screenDim.y);
				ofDrawLine(0, lineCoords.y, screenDim.x, lineCoords.y);
			}
		}

		ofSetColor(200);
		ofDrawLine(screenCenter.x, 0, screenCenter.x, screenDim.y);
		ofDrawLine(0, screenCenter.y, screenDim.x, screenCenter.y);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case '`':
			drawGrid = !drawGrid;
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
