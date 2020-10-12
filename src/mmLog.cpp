#include "mmLog.h"

mmLog::mmLog(const std::string & _module) {
	module = std::string(_module);
	message.str("");
}

mmLog::mmLog(const mmLog & a) {
	module = a.getModuleName();
}

mmLog::~mmLog() {
	log();
}

void mmLog::log() {
	std::cout << "[" << module << "] " << message.str() << std::endl;
	message.str("");
}

std::string mmLog::getModuleName() const {
	return module;
}

