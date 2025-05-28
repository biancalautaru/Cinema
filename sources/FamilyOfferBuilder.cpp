#include "../headers/FamilyOfferBuilder.h"

FamilyOfferBuilder::FamilyOfferBuilder() {
}

void FamilyOfferBuilder::buildName() {
	offer->setName("Family Offer");
}

void FamilyOfferBuilder::buildTickets() {
	offer->setTickets(-1);
}

void FamilyOfferBuilder::buildPercentage() {
	offer->setPercentage(20);
}

void FamilyOfferBuilder::buildOffer() {
	buildName();
	buildTickets();
	buildPercentage();
}
