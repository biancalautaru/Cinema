#include "../headers/Director.h"

Director::Director() {
}

Director::Director(const std::shared_ptr<OfferBuilder>& offerBuilder):
	offerBuilder(offerBuilder) {
}

void Director::buildOffer() {
	offerBuilder->buildOffer();
}

void Director::setOfferBuilder(const std::shared_ptr<OfferBuilder>& offerBuilder_) {
	offerBuilder = offerBuilder_;
}

const std::shared_ptr<Offer>& Director::getOffer() const {
	return offerBuilder->getOffer();
}
