#include "mmView.h"

// -- RENDERABLE

int mmRenderable::addRenderable(std::unique_ptr<mmRenderable> renderable) {
	mmId id = nRenderables++;
	renderables.emplace(std::make_pair(id, std::move(renderable)));

	renderables[id]->setup();
	return id;
}

bool mmRenderable::isPlaceholder() {
	return false;
}

mmId mmRenderable::getPlaceholderId() {
	return placeholderId;
}

void mmRenderable::setup() {
	nRenderables = 0;
	placeholderId = -1;
}

void mmRenderable::render() {
}

std::vector<mmId> mmRenderable::renderAll() {
	// call the object specific render
	render();

	std::vector<mmId> placeholders;
	std::map<mmId, std::unique_ptr<mmRenderable>>::iterator renderable = renderables.begin();
	for (; renderable != renderables.end(); ++renderable) {
		std::vector<mmId> childPlaceholders = renderable->second->renderAll();
		placeholders.reserve(placeholders.size() + childPlaceholders.size());
		placeholders.insert(placeholders.end(), childPlaceholders.begin(), childPlaceholders.end());
	}

	return placeholders;
}

// -- RENDERABLE PLACEHOLDER

bool mmRenderable_Placeholder::isPlaceholder() {
	return true;
}

std::vector<mmId> mmRenderable_Placeholder::renderAll() {
	std::vector<mmId> placeholder;
	placeholder.push_back(getPlaceholderId());
	return placeholder;
}

// -- RENDERABLE RECTANGLE

void mmRenderable_Rectangle::render() {
}

// -- VIEW

mmVec2i mmView::checkMouseover(mmVec2f mousePosition) {
	return mmVec2i(-1, -1);
}

void mmView::setup() {
	log() << "setting up view";
	mmRenderable::setup();
}

void mmView::connectController(std::weak_ptr<mmController> _controller) {
	log() << "connecting controller";
	controller = _controller;
}

