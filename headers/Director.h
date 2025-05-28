#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "OfferBuilder.h"

class Director {
private:
	OfferBuilder* offerBuilder;

public:
	Director();

	explicit Director(OfferBuilder* offerBuilder);

	void setOfferBuilder(OfferBuilder* offerBuilder);

	void buildOffer();

	Offer* getOffer();
};

#endif
