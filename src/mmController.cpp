#include "mmController.h"

void mmController::setup() {
	log() << "setting up controller";
}

void mmController::connectModel(std::weak_ptr<mmModel> _model) {
	log() << "connecting model";
	model = _model;
}

