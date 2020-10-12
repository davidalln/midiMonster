#pragma once

#include "mmComponent.h"

class mmModel;

class mmController : public mmComponent {
	private:
		std::weak_ptr<mmModel> model;

		template<class T>
			std::shared_ptr<T> getModel() {
				std::shared_ptr<mmModel> m = model.lock();
				return std::dynamic_pointer_cast<T>(std::move(m));
			}

	public:
		virtual std::string name() {
			return "mmController";
		}

		virtual void setup();

		void connectModel(std::weak_ptr<mmModel> _model);
};

