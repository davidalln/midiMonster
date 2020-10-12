#include "mmDelegator.h"

void mmDelegator::connectComponents(std::weak_ptr<mmDelegator> head) {
	log() << "connecting components";

	// create the MVC in memory
	model = std::move(spawnModel());
	view = std::move(spawnView());
	controller = std::move(spawnController());

	// link them together (M -> V -> C -> M)
	model->connectView(view);
	view->connectController(controller);
	controller->connectModel(model);

	// link MVC to this delegator
	model->connectDelegator(head);	
	view->connectDelegator(head);
	controller->connectDelegator(head);

	// initialize everything in the MVC order
	model->setup();
	view->setup();
	controller->setup();
}

void mmDelegator::renderAll() {
	// tell the view to draw, and get the list of placeholders we still need to render
	std::vector<mmId> placeholders = view->renderAll();

	std::vector<mmId>::iterator placeholder = placeholders.begin();
	for(; placeholder != placeholders.end(); ++placeholder) {
		log() << "found placeholder";
	}
}

void mmDelegator::handleMouseAction(mmMouseAction action, mmVec2f mousePosition, int mouseButton) {
	// check if thie mouse is in the boundaries of this view
	mmVec2i mouseoverData = view->checkMouseover(mousePosition);
}

void mmDelegator::setup() {
}

