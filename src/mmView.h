#pragma once

#include "mmComponent.h"

class mmController;

class mmRenderable {
	private:
		// size of a cell on the grid
		mmVec2i cellSize;

		// boundary of this view in grid size. TODO must be updated based
		// on its children
		mm2dVec2i boundary;

		// position relative to the parent center
		mmVec2i position;

		// the placeholder id to tell the controller if this is a blank.
		// -1 if this is not a placeholder
		mmId placeholderId;

		// maps id to the child renderable objects
		mmId nRenderables;
		std::map<mmId, std::unique_ptr<mmRenderable>> renderables;

	protected:
		// adds a renderable object to the map
		int addRenderable(std::unique_ptr<mmRenderable> renderable);

		// adds a placeholder object
		int addPlaceholder();

		mmId getPlaceholderId();

	public:
		virtual std::string name() {
			return "mmRenderable";
		}

		// checks if this renderable is a placeholder
		virtual bool isPlaceholder();

		// called by mmView::setup or when created by addRenderable
		virtual void setup();

		// called by renderAll, this is the object specific drawing code
		virtual void render();

		// this first calls this object's render, then tells all the children to render.
		// returns all placeholders that need to be rendered
		virtual std::vector<mmId> renderAll();
};

class mmRenderable_Placeholder : public mmRenderable {
	public:
		virtual std::string name() {
			return "mmRenderable_Placeholder";
		}

		bool isPlaceholder();
		std::vector<mmId> renderAll();
};

class mmRenderable_Rectangle : public mmRenderable {
	public:
		virtual std::string name() {
			return "mmRenderable_Rectangle";
		}

		void render();
};
	
class mmView : public mmComponent, public mmRenderable {
	private:
		std::weak_ptr<mmController> controller;

		template<class T>
			std::shared_ptr<T> getController() {
				std::shared_ptr<mmController> c = controller.lock();
				return std::dynamic_pointer_cast<T>(std::move(c));
			}

	public:
		virtual std::string name() {
			return "mmView";
		}

		// checks whether the mouse is over the view. returns:
		// 	x: -1 not in view, 0 in view placeholder, 1 in view no placeholder
		// 	y: either the placeholder id or the renderable id
		mmVec2i checkMouseover(mmVec2f mousePosition);

		virtual void createRenderables() = 0;

		virtual void setup();
		void connectController(std::weak_ptr<mmController> _controller);
};

