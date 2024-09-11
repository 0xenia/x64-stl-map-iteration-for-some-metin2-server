# x64 Metin2 Manual `std::map` Iteration

This project contains a manual iteration of `std::map` for the x64 version of the Metin2 private servers. The code is written to retrieve a list of ground items from the game's internal memory structure.

## Function Overview

The function `GetGroundItemList` is a manual implementation to iterate through an internal memory map structure and return a list of ground items with their respective `ItemID` and `TGroundItemInstance` pointer. 

It checks ownership and retrieves only items that are either unowned or belong to the current player.
