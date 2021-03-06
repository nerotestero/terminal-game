/***
*   Author: Stasiek Fortoński
*   Date: 24.08.17
*   Trade system
*   Version: 2
***/

#ifndef TRADE_HPP
#define TRADE_HPP 1
#include "../inventory/inventory.hpp"

class Trade
{
protected:
    Trade(){}

    void sell(eq::Inventory & playerInventory, Stats & st, eq::Equipment<Item> & botInventory, const unsigned & index);
    int buy(eq::Inventory & playerInventory, Stats & st, eq::Equipment<Item> & botInventory, const unsigned & index);

public:
    static Trade & get()
    {
        static Trade instance;
        return instance;
    }

    void control(eq::Inventory & playerInventory, Stats & st, eq::Equipment<Item> & botInventory);
    int chooseItems(const eq::Equipment<Item> & inv);

    void sellDialogMenu(eq::Inventory & playerInventory, Stats & st, eq::Equipment<Item> & botInventory, const unsigned & index);
    void buyDialogMenu(eq::Inventory & playerInventory, Stats & st, eq::Equipment<Item> & botInventory, const unsigned & index);
};
#endif