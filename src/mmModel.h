#pragma once

#include "mmComponent.h"

class mmView;

class mmModel : public mmComponent {
	private:
		std::weak_ptr<mmView> view;

		template<class T>
			std::shared_ptr<T> getView() {
				std::shared_ptr<mmView> v = view.lock();
				return std::dynamic_pointer_cast<T>(std::move(v));
			}

	public:
		virtual std::string name() {
			return "mmModel";
		}

		virtual void setup();
		void connectView(std::weak_ptr<mmView> _view);
};

