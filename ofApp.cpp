#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(1.5);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.4, ofGetHeight() * 0.5);

	for (int radius = 150; radius < 350; radius += 10) {

		int start_deg = ofGetFrameNum() + radius * 5;

		ofBeginShape();
		for (int deg = start_deg; deg < start_deg + 180; deg++) {

			ofVertex(this->make_point(radius, deg));
		}
		ofEndShape();
	}

}

//--------------------------------------------------------------
ofPoint ofApp::make_point(int radius, int deg) {

	deg = deg % 360;
	
	if ((deg >= 0 && deg < 90) || (deg >= 270 && deg < 360)) {

		return ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}
	else if (deg >= 90 && deg < 110) {

		return ofPoint(radius * cos(deg * DEG_TO_RAD), radius);
	}
	else if (deg >= 110 && deg < 250) {

		return ofPoint(radius * cos(110 * DEG_TO_RAD), ofMap(deg, 110, 250, radius, -radius));
	}
	else if (deg >= 250 && deg < 270)
	{
		return ofPoint(radius * cos(deg * DEG_TO_RAD), -radius);
	}

	return ofPoint();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}