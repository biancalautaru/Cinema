#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "OfferBuilder.h"

class Director {
private:
	std::shared_ptr<OfferBuilder> offerBuilder;

public:
	Director();

	explicit Director(const std::shared_ptr<OfferBuilder>& offerBuilder);

	void setOfferBuilder(const std::shared_ptr<OfferBuilder>& offerBuilder);

	void buildOffer();

	const std::shared_ptr<Offer>& getOffer() const;
};

#endif
