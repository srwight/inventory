#include <catch2/catch_test_macros.hpp>
#include "inventory.hpp"
#include "mock-item.hpp"

namespace inventory {

    TEST_CASE("Inventory AddItem", "[inventory]") {
        MockItem::clearConstructorCalls();
        auto factory = std::make_shared<MockItemFactory>();
        Inventory inventory(factory);

        TimePoint purchaseDate; // Assume this is properly initialized
        bool result = inventory.addItem("TestItem", 100.0, purchaseDate, 12);

        REQUIRE(result == true);

        auto constructorCalls = MockItem::getConstructorCalls();
        REQUIRE(constructorCalls.size() == 1);
        REQUIRE(constructorCalls[0].name == "TestItem");
        REQUIRE(constructorCalls[0].initialValueDollars == 100.0);
        REQUIRE(constructorCalls[0].purchaseDate == purchaseDate);
        REQUIRE(constructorCalls[0].lifespanMonths == 12);

        REQUIRE(inventory.size() == 1);
    }

} // namespace inventory