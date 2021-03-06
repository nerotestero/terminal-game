/***
* Author: Stasiek Fortoński
* Date: 14.06.2017
* Crafting
* Version: 3
***/

#ifndef CRAFTING_HPP_
#define CRAFTING_HPP_ 1
#include "../inventory/controllers/controllers.hpp"

namespace eq
{
    class Crafting: public BasicController
    {
    protected:
        Crafting(){}

        void maker(Inventory & inv);
        bool whatIsMissing(Inventory & inv, const Item & it);
        void craft(Inventory & inv, const Item & it);

    public:
        static Crafting & get()
        {
            static Crafting instance;
            return instance;
        }
        virtual void control(Inventory & inv);
    };
}
#endif