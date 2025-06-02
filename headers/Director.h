#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "OfferBuilder.h"

/**
 * @class Director
 * @brief Manages the construction process of Offer objects.
 *
 * The Director class is responsible for controlling the sequence of steps in offer constriction.
 * It allows different types of offers to be created without changing the construction code.
 */
class Director {
private:
	std::shared_ptr<OfferBuilder> offerBuilder;

public:
	Director();

	explicit Director(const std::shared_ptr<OfferBuilder>& offerBuilder);

	/**
	 * @brief Executes the building process by calling the builder's build method.
	 */
	void buildOffer();

	void setOfferBuilder(const std::shared_ptr<OfferBuilder>& offerBuilder);

	const std::shared_ptr<Offer>& getOffer() const;
};

#endif
