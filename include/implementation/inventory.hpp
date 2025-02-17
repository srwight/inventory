#pragma once
#include <unordered_map>
#include "i-inventory.hpp"

namespace inventory{
    class Inventory : public IInventory {
    public:
        // Constructor
        Inventory();
        Inventory(std::shared_ptr<IItemFactory> factory);

        // Destructor
        virtual ~Inventory();

        // Implement the virtual methods from IInventory
        bool addItem(
            std::string const &name, 
            double const &initialValueDollars, 
            TimePoint const &purchaseDate,
            std::uint32_t const &lifespanMonths) override;
        std::weak_ptr<const IItem> viewItem(std::string const &key) const override;
        std::unique_ptr<IItem> copyItem(std::string const &key) const override;
        bool removeItem(std::string const &key) override;
        std::vector<std::string> getKeys() const override;
        std::size_t size() const override;
        bool empty() const override;
        void clear() override;
        bool itemExists(std::string const &key) const override;
        
    private:
        std::unordered_map<std::string, std::shared_ptr<IItem>> items;
        std::shared_ptr<IItemFactory> factory;
    };
}
