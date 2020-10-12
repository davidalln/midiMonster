#pragma once

#include "mmView.h"

class mmContainerView : public mmView {
	public:
		std::string name() {
			return "mmContainerView";
		}

		void createRenderables();
};

