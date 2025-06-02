#ifndef FAMILYOFFERBUILDER_H
#define FAMILYOFFERBUILDER_H

#include "OfferBuilder.h"

/**
 * @class FamilyOfferBuilder
 * @brief Concrete builder that constructs an offer for families.
 *
 * This builder sets a predefined name and discount percentage of the family offer.
 * The number of tickets is marked so that it is clear it's not a required criterion
 * for the family offer.
 */
class FamilyOfferBuilder : public OfferBuilder {
private:
	/**
	 * @brief Builds the name of the offer.
	 */
	void buildName() override;

	/**
	 * @brief Marks the number of tickets so that it's not used since it's not needed
	 * for the family offer.
	 */
	void buildTickets() override;

	/**
	 * @brief Builds the discount percentage.
	 */
	void buildPercentage() override;

public:
	FamilyOfferBuilder();

	/**
	 * @brief Constructs the full family offer by calling all build steps.
	 */
	void buildOffer() override;
};

#endif
