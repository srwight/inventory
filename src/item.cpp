#include "item.hpp"

namespace inventory{
    std::shared_ptr<IItem> ItemFactory::operator()(
        std::string const &name, 
        double const &initialValueDollars, 
        TimePoint const &purchaseDate,
        std::uint32_t const &lifespanMonths
        )
    {
        return std::make_shared<Item>(
            name,
            initialValueDollars,
            purchaseDate,
            lifespanMonths
        );
    }

    Item::Item(std::string const &name, 
               double const &initialValueDollars, 
               TimePoint const &purchaseDate,
               std::uint32_t const &lifespanMonths
               )
        : name(name)
        , initialValueCents(static_cast<std::uint32_t>(initialValueDollars * 100))
        , purchaseDate(purchaseDate)
        , lifespanMonths(lifespanMonths)
    {}
    std::string Item::getName() const
    {
        return name;
    }
    TimePoint Item::getPurchaseDate() const
    {
        return purchaseDate;
    }

    std::unique_ptr<IItem> Item::clone()
    {
        return std::make_unique<Item>(
            name,
            static_cast<double>(initialValueCents) / 100,
            purchaseDate,
            lifespanMonths
        );
    }

    std::uint32_t Item::getinitialValueCents() const
    {
        return initialValueCents;
    }
}
