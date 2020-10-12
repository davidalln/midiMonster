#include "mmContainer.h"

std::shared_ptr<mmModel> mmContainer::spawnModel() {
	return std::make_shared<mmContainerModel>();
}

std::shared_ptr<mmView> mmContainer::spawnView() {
	return std::make_shared<mmContainerView>();
}

std::shared_ptr<mmController> mmContainer::spawnController() {
	return std::make_shared<mmContainerController>();
}

