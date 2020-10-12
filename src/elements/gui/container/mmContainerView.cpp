#include "mmContainerView.h"

void mmContainerView::createRenderables() {
	int rect = addRenderable(std::make_unique<mmRenderable_Rectangle>());

	pushChanges(rect);
		setSize(2, 2);
		setPosition(2, 2);

	popChanges();
}

