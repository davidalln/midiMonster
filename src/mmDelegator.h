#pragma once

#include "mmMain.h"

#include "mmModel.h"
#include "mmView.h"
#include "mmController.h"

class mmDelegator : public mmAbstract {
	private:
		// the model, view, and controller
		std::shared_ptr<mmModel> model;
		std::shared_ptr<mmView> view;
		std::shared_ptr<mmController> controller;

		std::weak_ptr<mmDelegator> parent;

		std::shared_ptr<ofThreadChannel<int>> messages;

		std::map<mmId, std::unique_ptr<mmDelegator>> children;

	protected:
		// spawn the specific components
		virtual std::shared_ptr<mmModel> spawnModel() = 0;
		virtual std::shared_ptr<mmView> spawnView() = 0;
		virtual std::shared_ptr<mmController> spawnController() = 0;

	public:
		virtual std::string name() {
			return "mmDelegator";
		}

		// render all children
		void renderAll();

		// handle mouse input
		void handleMouseAction(mmMouseAction action, mmVec2f mousePosition, int mouseButton);

		void connectComponents(std::weak_ptr<mmDelegator> head);
		void setup();
};

