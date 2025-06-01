#include "../headers/Director.h"

Director::Director() {
}

Director::Director(const std::shared_ptr<OfferBuilder>& offerBuilder):
	offerBuilder(offerBuilder) {
}

void Director::setOfferBuilder(const std::shared_ptr<OfferBuilder>& offerBuilder_) {
	offerBuilder = offerBuilder_;
}

void Director::buildOffer() {
	offerBuilder->buildOffer();
}

const std::shared_ptr<Offer>& Director::getOffer() const {
	return offerBuilder->getOffer();
}
