#include "../headers/StudentGroupOfferBuilder.h"

StudentGroupOfferBuilder::StudentGroupOfferBuilder() {
}

void StudentGroupOfferBuilder::buildName() {
	offer->setName("Student Group Offer");
}

void StudentGroupOfferBuilder::buildTickets() {
	offer->setTickets(4);
}

void StudentGroupOfferBuilder::buildPercentage() {
	offer->setPercentage(30);
}

void StudentGroupOfferBuilder::buildOffer() {
	buildName();
	buildTickets();
	buildPercentage();
}
