#pragma once

#include "mmDelegator.h"
#include "mmContainerModel.h"
#include "mmContainerView.h"
#include "mmContainerController.h"

class mmContainer : public mmDelegator {
	protected:
		std::shared_ptr<mmModel> spawnModel();
		std::shared_ptr<mmView> spawnView();
		std::shared_ptr<mmController> spawnController();

	public:
		std::string name() {
			return "mmContainer";
		}

};

