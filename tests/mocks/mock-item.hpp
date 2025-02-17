#pragma once
#include "i-item.hpp"
#include <vector>

namespace inventory{

    class MockItem : public IItem
    {
    public:
        struct ConstructorCalls
        {
            std::string name;
            double initialValueDollars;
            TimePoint purchaseDate;
            std::uint32_t lifespanMonths;
        };
        MockItem(std::string const &name, 
                 double const &initialValueDollars, 
                 TimePoint const &purchaseDate,
                 std::uint32_t const &lifespanMonths
                 )
            : getNameCalls(0)
            , getPurchaseDateCalls(0)
            , getinitialValueCentsCalls(0)
            , cloneCalls(0)
        {
            constructorCalls.push_back({name, initialValueDollars, purchaseDate, lifespanMonths});
        }
        ~MockItem() override = default;

        std::string getName() const override
        {
            getNameCalls++;
            return "";
        }
        TimePoint getPurchaseDate() const override
        {
            getPurchaseDateCalls++;
            return TimePoint();
        }
        std::uint32_t getinitialValueCents() const override
        {
            getinitialValueCentsCalls++;
            return 0;
        }
    
        std::unique_ptr<IItem> clone() override
        {
            cloneCalls++;
            return std::make_unique<MockItem>("", 0, TimePoint(), 0);
        }

        static std::vector<ConstructorCalls> getConstructorCalls()
        {
            return constructorCalls;
        }

        static void clearConstructorCalls(){
            constructorCalls.clear();
        }

        std::uint32_t getGetNameCalls() const
        {
            return getNameCalls;
        }

        std::uint32_t getGetPurchaseDateCalls() const
        {
            return getPurchaseDateCalls;
        }
        
        std::uint32_t getGetinitialValueCentsCalls() const
        {
            return getinitialValueCentsCalls;
        }
        private: 
        mutable std::uint32_t getNameCalls;
        mutable std::uint32_t getPurchaseDateCalls;
        mutable std::uint32_t getinitialValueCentsCalls;
        mutable std::uint32_t cloneCalls;
        static std::vector<ConstructorCalls> constructorCalls;
    };
    
    std::vector<MockItem::ConstructorCalls> MockItem::constructorCalls;
    class MockItemFactory : public IItemFactory
    {
    public:
        std::shared_ptr<IItem> operator()(
            std::string const &name, 
            double const &initialValueDollars, 
            TimePoint const &purchaseDate,
            std::uint32_t const &lifespanMonths
            ) override
        {
            return std::make_shared<MockItem>(
                name,
                initialValueDollars,
                purchaseDate,
                lifespanMonths
            );
        }

        ~MockItemFactory() override = default;

    };

}