#include "../headers/OfferBuilder.h"

OfferBuilder::OfferBuilder() {
	offer = std::make_shared<Offer>();
}

OfferBuilder::~OfferBuilder() {
}

OfferBuilder::OfferBuilder(const OfferBuilder& copy):
	offer(copy.offer) {
}

OfferBuilder& OfferBuilder::operator=(const OfferBuilder& copy) {
	offer = copy.offer;
	return *this;
}

const std::shared_ptr<Offer>& OfferBuilder::getOffer() const {
	return offer;
}
