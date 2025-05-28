#include "../headers/OfferBuilder.h"

OfferBuilder::OfferBuilder() {
	offer = new Offer();
}

OfferBuilder::~OfferBuilder() {
	delete offer;
}

OfferBuilder::OfferBuilder(const OfferBuilder& copy):
	offer(copy.offer) {
}

OfferBuilder& OfferBuilder::operator=(const OfferBuilder& copy) {
	offer = copy.offer;
	return *this;
}

Offer* OfferBuilder::getOffer() {
	return offer;
}
