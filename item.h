//
// Created by dalexiv on 11.12.15.
//

#ifndef RRRRRR_ITEM_H
#define RRRRRR_ITEM_H


class item {
private:
    int id;
    int w;
    int cost;

public:
    item(int id, int w, int cost) : id(id), w(w), cost(cost) { }

    int getId() const {
        return id;
    }

    int getCost() const {
        return cost;
    }

    int getW() const {
        return w;
    }
};


#endif //RRRRRR_ITEM_H
