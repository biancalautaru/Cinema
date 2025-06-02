#ifndef OFFERBUILDER_H
#define OFFERBUILDER_H

#include "Offer.h"

#include <memory>

/**
 * @class OfferBuilder
 * @brief Abstract Builder for constructing Offer objects step by step.
 *
 * The OfferBuilder class defines the interface for building different parts of an Offer.
 * Concrete subclasses must implement the steps to customize offer creation.
 * The Builder design patter is used to separate complex construction logic from the Offer class.
 */
class OfferBuilder {
protected:
	std::shared_ptr<Offer> offer; ///< The Offer object being constructed.

	/**
	 * @brief Builds the name of the offer.
	 *
	 * This method must be implemented by the derived classes to set the offer's name.
	 */
	virtual void buildName() = 0;

	/**
	 * @brief Builds the required number of tickets.
	 *
	 * This method must be implemented by the derived classes to define how many tickets
	 * are needed.
	 */
	virtual void buildTickets() = 0;

	/**
	 * @brief Builds the discount percentage.
	 *
	 * This method must be implemented by the derived classes to specify the discount.
	 */
	virtual void buildPercentage() = 0;

public:
	OfferBuilder();

	virtual ~OfferBuilder();

	OfferBuilder(const OfferBuilder& copy);

	OfferBuilder& operator=(const OfferBuilder& copy);

	/**
	 * @brief Triggers the full construction process of the offer.
	 *
	 * This method orchestrates the call to the build steps and must be implemented by
	 * the concrete builders.
	 */
	virtual void buildOffer() = 0;

	const std::shared_ptr<Offer>& getOffer() const;
};

#endif
