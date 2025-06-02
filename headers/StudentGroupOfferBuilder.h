#ifndef STUDENTGROUPOFFERBUILDER_H
#define STUDENTGROUPOFFERBUILDER_H

#include "OfferBuilder.h"

/**
 * @class StudentGroupOfferBuilder
 * @brief Concrete builder that constructs an offer for groups of students.
 *
 * This builder sets a predefined name, number of tickets and discount percentage for the
 * student group offer.
 */
class StudentGroupOfferBuilder : public OfferBuilder {
private:
	/**
	 * @brief Builds the name of the offer.
	 */
	void buildName() override;

	/**
	 * @brief Builds the required number of tickets.
	 */
	void buildTickets() override;

	/**
	 * @brief Builds the discount percentage.
	 */
	void buildPercentage() override;

public:
	StudentGroupOfferBuilder();

	/**
	 * @brief Constructs the full student group offer by calling all build steps.
	 */
	void buildOffer() override;
};

#endif
