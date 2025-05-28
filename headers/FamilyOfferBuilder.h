#ifndef FAMILYOFFERBUILDER_H
#define FAMILYOFFERBUILDER_H

#include "OfferBuilder.h"

class FamilyOfferBuilder : public OfferBuilder {
private:
	void buildName() override;
	void buildTickets() override;
	void buildPercentage() override;

public:
	FamilyOfferBuilder();

	void buildOffer() override;
};

#endif
