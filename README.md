# Introduction
The goal of this package is to learn about and study:
* Dependency Injection
* Unit Testing
* Mocking
* Obfuscation

## Testing
### **Unit Tests (Using Mocks):**

These tests focus on the `Inventory` class's logic in isolation, using `MockItemFactory` and `MockItem`.  They verify *interactions* and *behavior*, not the specific data of the items.

1.  **`addItem()` Unit Tests:**
    *   Test adding an item. Verify that the `MockItemFactory`'s `operator()` is called with the correct parameters (name, value, date, lifespan).  Verify that `addItem` returns `true`.
    *   Test adding an item with a duplicate key. Verify that `addItem` returns `false`.
    *   Test adding an item when the factory returns a null pointer (simulating factory failure). Verify that `addItem` returns `false`.
    * * Note that this might require creating a new factory
    *   Test adding many items. Verify that the `Inventory`'s internal data structures handle this correctly (no crashes or unexpected behavior).  (This is still a unit test because it's about the `Inventory`'s internal logic, not the items' data.)

2.  **`removeItem()` Unit Tests:**
    *   Test removing an existing item. Verify that `removeItem` returns `true`.
    *   Test removing a non-existent item. Verify that `removeItem` returns `false`.
    *   Test removing an item. Verify that the item is no longer in the inventory (check `size()` or `itemExists()`).

3.  **`clear()` Unit Tests:**
    *   Test clearing a non-empty inventory. Verify that `size()` becomes 0 after `clear()`.
    *   Test clearing an empty inventory.  Verify that `clear()` doesn't cause any errors.

4.  **`size()` and `empty()` Unit Tests:**
    *   Test `size()` after adding different numbers of items.
    *   Test `empty()` on an empty and non-empty inventory.

5.  **`getKeys()` Unit Tests:**
    *   Test `getKeys()` on an empty inventory.
    *   Test `getKeys()` after adding items. Verify that the correct keys are returned.

### **Integration Tests (Using Real Items):**

These tests use the real `Item` and `ItemFactory` classes and verify the *end-to-end* behavior, including the data of the items.

1.  **`addItem()` Integration Tests:**
    *   Test adding an item and then retrieving it using `viewItem()` or `operator[]`. Verify that the retrieved item has the correct data (name, value, date, lifespan).  *This is the test you originally intended*.
    *   Test adding multiple items and retrieving them.

2.  **`copyItem()` Integration Tests:**
    *   Test copying an item and verify that the copied item is a separate object with the same data.  Modify the copied item and ensure the original remains unchanged.

3.  **End-to-End Tests:**
    *   Create a more complex scenario involving adding, viewing, copying, and removing items.  Verify that the `Inventory` behaves correctly in this scenario.

#### **Key Differences and Explanations:**

*   **Unit Tests:**  Use mocks to isolate the class under test. Verify *interactions* and *behavior*.  Fast and easy to run.
*   **Integration Tests:** Use real objects to test the interaction between different parts of the system. Verify *end-to-end* behavior and data correctness.  Slower to run than unit tests.

## Obfuscation
#### **CMakeLists.txt**
* Study the CMakeLists.txt file; why is it set up the way it is? What do PRIVATE and PUBLIC do?

#### **Distribution**
* What files would you need to distribute this library _without_ giving away your source code?
