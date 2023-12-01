#pragma once
#include <cmath>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

class NPC;
class Knight;
class Merchant;
class Squirrel;

using set_t = std::set<std::shared_ptr<NPC>>;

enum NPC_type { unknown = 0,
                knight = 1,
                merchant = 2,
                squirrel = 3 };

class Observer {
public:
    Observer() = default;
    virtual void report_killed(const NPC& attacker, const NPC& defender) = 0;
};

class NPC {
protected:
    NPC_type _type;
    int _x = 0, _y = 0;
    std::string _name;
    bool _alive;
    std::vector<std::shared_ptr<Observer>> observers;
    static int id;

    NPC(NPC_type type, int x, int y, std::string name);
    virtual ~NPC() = default;

public:
    virtual std::string getType() = 0;
    const int getX() const;
    const int getY() const;
    const std::string& getName() const;
    const bool alive() const;

    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    virtual bool fight(Knight& accepter) = 0;
    virtual bool fight(Merchant& accepter) = 0;
    virtual bool fight(Squirrel& accepter) = 0;

    void attach(std::shared_ptr<Observer> observer);
    void notify_killed(const NPC& defender) const;

    bool near(const std::shared_ptr<NPC>& enemy, int distance) const;

    friend std::ostream& operator<<(std::ostream& out, const NPC& npc);
};

// NPC::NPC(NPC_type type, int x, int y, std::string name) : _type(type), _x(x), _y(y), _name(name), _alive(true) {}

// const int NPC::getX() const {
//     return _x;
// }

// const int NPC::getY() const {
//     return _y;
// }

// const std::string& NPC::getName() const {
//     return _name;
// }

// const bool NPC::alive() const {
//     return _alive;
// }

// void NPC::notify_killed(const NPC& defender) const {
//     for (auto& o : observers) {
//         o->report_killed(*this, defender);
//     }
// }

// void NPC::attach(std::shared_ptr<Observer> observer) {
//     observers.push_back(observer);
// }

// bool NPC::near(const std::shared_ptr<NPC>& enemy, int distance) const {
//     return std::pow(_x - enemy->_x, 2) + std::pow(_y - enemy->_y, 2) <= std::pow(distance, 2);
// }

// std::ostream& operator<<(std::ostream& out, const NPC& npc) {
//     return out << npc._name << " {x : " << npc._x << ", y : " << npc._y << "}";
// }

// int NPC::id = 0;
