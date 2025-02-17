#include <catch2/catch_test_macros.hpp>

#include "item.hpp"

TEST_CASE("ItemFactory creates Item", "[item]")
{
    inventory::ItemFactory factory;
    auto item = factory("name", 1.0, std::chrono::system_clock::now(), 1);
    REQUIRE(item->getName() == "name");
    REQUIRE(item->getinitialValueDollars() == 1.0);
    REQUIRE(item->getPurchaseDate() <= std::chrono::system_clock::now());
}

TEST_CASE("ItemFactory creates Item with cents", "[item]")
{
    inventory::ItemFactory factory;
    auto item = factory("name", 1.01, std::chrono::system_clock::now(), 1);
    REQUIRE(item->getName() == "name");
    REQUIRE(item->getinitialValueDollars() == 1.01);
    REQUIRE(item->getPurchaseDate() <= std::chrono::system_clock::now());
}
