#include "mmComponent.h"
#include "mmDelegator.h"

void mmComponent::connectDelegator(std::weak_ptr<mmDelegator> & thisDelegator) {
	log() << "connecting delegator";
	delegator = thisDelegator;

	std::shared_ptr<mmDelegator> d = delegator.lock();
	log() << "delegator memory: " << d.get();
}

