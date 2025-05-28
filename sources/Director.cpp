#include "../headers/Director.h"

Director::Director() {
}

void Director::setOfferBuilder(OfferBuilder* offerBuilder_) {
	offerBuilder = offerBuilder_;
}

Director::Director(OfferBuilder* offerBuilder):
	offerBuilder(offerBuilder) {
}

void Director::buildOffer() {
	offerBuilder->buildOffer();
}

Offer* Director::getOffer() {
	return offerBuilder->getOffer();
}
