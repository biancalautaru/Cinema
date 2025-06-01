#ifndef OFFERBUILDER_H
#define OFFERBUILDER_H

#include "Offer.h"

#include <memory>

class OfferBuilder {
protected:
	std::shared_ptr<Offer> offer;

	virtual void buildName() = 0;
	virtual void buildTickets() = 0;
	virtual void buildPercentage() = 0;

public:
	OfferBuilder();
	virtual ~OfferBuilder();

	OfferBuilder(const OfferBuilder& copy);
	OfferBuilder& operator=(const OfferBuilder& copy);

	virtual void buildOffer() = 0;

	const std::shared_ptr<Offer>& getOffer() const;
};

#endif
