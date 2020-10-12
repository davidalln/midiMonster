#pragma once

#include "mmMain.h"

class mmDelegator;

class mmComponent : public mmAbstract {
	private:
		std::weak_ptr<mmDelegator> delegator;

	public:
		virtual std::string name() {
			return "mmComponent";
		}

		void connectDelegator(std::weak_ptr<mmDelegator> & thisDelegator);

		virtual void setup() = 0;
};

