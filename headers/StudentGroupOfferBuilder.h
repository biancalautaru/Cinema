#ifndef STUDENTGROUPOFFERBUILDER_H
#define STUDENTGROUPOFFERBUILDER_H

#include "OfferBuilder.h"

class StudentGroupOfferBuilder : public OfferBuilder {
private:
	void buildName() override;
	void buildTickets() override;
	void buildPercentage() override;

public:
	StudentGroupOfferBuilder();

	void buildOffer() override;
};

#endif
