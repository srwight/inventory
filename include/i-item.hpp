#pragma once
#include <string>
#include <chrono>
#include <cstdint>
#include <memory>


namespace inventory{

    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

    class IItem;
    class IItemFactory{

    public:
        virtual ~IItemFactory() = default;

        virtual std::shared_ptr<IItem> operator()(
            std::string const &name, 
            double const &initialValueDollars, 
            TimePoint const &purchaseDate,
            std::uint32_t const &lifespanMonths
            ) = 0;
    };

    class IItem{

    public:
        virtual ~IItem() = default;

        virtual std::string getName() const = 0;
        virtual TimePoint getPurchaseDate() const = 0;
        virtual std::unique_ptr<IItem> clone() = 0;
        double getinitialValueDollars() const {
            return static_cast<double>(getinitialValueCents()) / 100;
        }

    protected:
        virtual std::uint32_t getinitialValueCents() const = 0;
    };
}
