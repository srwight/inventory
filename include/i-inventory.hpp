#pragma once
#include <string>
#include <memory>
#include <vector>
#include "i-item.hpp"

namespace inventory{
    
    class IInventory{
    public:
        virtual ~IInventory() = default;

        virtual bool addItem(
            std::string const &name, 
            double const &initialValueDollars, 
            TimePoint const &purchaseDate,
            std::uint32_t const &lifespanMonths) = 0;
        virtual std::weak_ptr<const IItem> viewItem(std::string const &key) const = 0;
        virtual std::unique_ptr<IItem> copyItem(std::string const &key) const = 0;
        virtual bool removeItem(std::string const &key) = 0;
        virtual std::vector<std::string> getKeys() const = 0;
        virtual std::size_t size() const = 0;
        virtual bool empty() const = 0;
        virtual void clear() = 0;
        virtual std::weak_ptr<const IItem> operator[](std::string const &key) const { return viewItem(key); }
        virtual bool itemExists(std::string const &key) const = 0;
    };

    class IInventoryFactory{
    public:
        virtual ~IInventoryFactory() = default;

        virtual std::shared_ptr<IInventory> operator()() = 0;
    };
}