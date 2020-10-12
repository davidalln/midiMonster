#pragma once

#include "mmController.h"

class mmContainerController : public mmController {
	public:
		std::string name() {
			return "mmContainerController";
		}
};
