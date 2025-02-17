#include "inventory.hpp"
#include "item.hpp"

namespace inventory{
    Inventory::Inventory() : factory(std::make_shared<ItemFactory>()){}

    Inventory::Inventory(std::shared_ptr<IItemFactory> factory)
        : factory(factory) {}
    
    Inventory::~Inventory() {}
    
    bool Inventory::addItem(
        std::string const &name, 
        double const &initialValueDollars, 
        TimePoint const &purchaseDate,
        std::uint32_t const &lifespanMonths)
    {
        std::shared_ptr<IItem> item = (*factory)(name, initialValueDollars, purchaseDate, lifespanMonths);
        if(!item){
            return false;
        }
        items[name] = item;
        return true;
    }
    
    std::weak_ptr<const IItem> Inventory::viewItem(std::string const &key) const
    {
        if (items.find(key) == items.end())
        {
            return std::weak_ptr<const IItem>();
        }
        return items.at(key);
    }

    std::unique_ptr<IItem> Inventory::copyItem(std::string const &key) const
    {
        if (items.find(key) == items.end())
        {
            return std::unique_ptr<IItem>();
        }
        return items.at(key)->clone();
    }

    bool Inventory::removeItem(std::string const &key)
    {
        if (items.find(key) == items.end())
        {
            return false;
        }
        items.erase(key);
        return true;
    }

    std::vector<std::string> Inventory::getKeys() const
    {
        std::vector<std::string> keys;
        for (auto const &item : items)
        {
            keys.push_back(item.first);
        }
        return keys;
    }

    std::size_t Inventory::size() const
    {
        return items.size();
    }

    bool Inventory::empty() const
    {
        return items.empty();
    }

    void Inventory::clear()
    {
        items.clear();
    }

    bool Inventory::itemExists(std::string const &key) const
    {
        return items.find(key) != items.end();
    }

}