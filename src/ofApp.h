#pragma once

#include "ofMain.h"

#include "mmMain.h"
#include "mmDelegator.h"
#include "./elements/gui/container/mmContainer.h"

class ofApp : public ofBaseApp{
	private:
		bool drawGrid;
		mmVec2f cellSize;

	public:
		std::shared_ptr<mmDelegator> head;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
