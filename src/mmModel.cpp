#include "mmModel.h"

void mmModel::setup() {
	log() << "setting up model";
}

void mmModel::connectView(std::weak_ptr<mmView> _view) {
	log() << "connecting view";
	view = _view;
}

