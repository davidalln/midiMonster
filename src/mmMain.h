#pragma once

#include "ofMain.h"
#include "mmLog.h"
#include "mmMath.h"

typedef int mmId;
class mmAbstract {
	protected:
		mmLog log() {
			return mmLog(name());
		}

	public:
		virtual std::string name() {
			return "mmAbstract";
		};

		mmAbstract() {
		}
};

typedef enum {
	MOUSE_NONE,
	MOUSE_MOVED,	
	MOUSE_LEFT_PRESSED,
	MOUSE_LEFT_RELEASED
} mmMouseAction;

