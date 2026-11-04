# Shopping Cart Calculator

A C++ command-line application designed to manage shopping list items, process tiered discounts, identify high-value inventory, and search for specific items by name.

## Features

- **Product Management:** Struct-based data representation storing name, unit price, and quantity.
- **Input Validation:** Restricts item count between 1 and 100 and validates non-negative pricing/quantities.
- **Automatic Tiered Discounts:**
  - **> 500 AZN:** 5% total discount applied.
  - **> 1000 AZN:** 10% total discount applied.
- **Analytics:** Finds and outputs the single most expensive item in the list by unit price.
- **Lookup System:** Interactive search function to look up product details by exact name.

## How to Compile & Run

### Prerequisites
- GCC / G++ compiler installed (`g++ --version`)

### Compilation
```bash
g++ main.cpp -o ShoppingCart
