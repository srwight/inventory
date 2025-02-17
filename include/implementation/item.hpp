#pragma once
#include "i-item.hpp"

namespace inventory{

    class ItemFactory : public IItemFactory{

    public:
        ~ItemFactory() = default;

        std::shared_ptr<IItem> operator()(
            std::string const &name, 
            double const &initialValueDollars, 
            TimePoint const &purchaseDate,
            std::uint32_t const &lifespanMonths
            ) override;
    };


    class Item : public IItem {
    public:
        Item() = delete;
        Item(std::string const &name, 
             double const &initialValueDollars, 
             TimePoint const &purchaseDate,
             std::uint32_t const &lifespanMonths
             );

        std::string getName() const override;
        TimePoint getPurchaseDate() const override;
        std::unique_ptr<IItem> clone() override;

    protected:
        std::uint32_t getinitialValueCents() const override;

    private:
        const std::string name;
        const std::uint32_t initialValueCents;
        const TimePoint purchaseDate;
        const std::uint32_t lifespanMonths;
    };
}
