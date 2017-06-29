cmake_minimum_required(VERSION 3.8)
project(POS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Item.cpp Item.h TaxableItem.cpp TaxableItem.h BookItem.cpp BookItem.h GroceryItem.cpp GroceryItem.h)
add_executable(POS ${SOURCE_FILES} Item.cpp Item.h TaxableItem.cpp TaxableItem.h BookItem.cpp BookItem.h GroceryItem.cpp GroceryItem.h)