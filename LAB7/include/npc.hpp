#pragma once
#include <cmath>
#include <iostream>
#include <memory>
#include <set>
#include <shared_mutex>
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
    virtual void report_killed(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender) = 0;
};

class NPC {
protected:
    NPC_type _type;
    int _x = 0, _y = 0;
    std::string _name;
    bool _alive = true;
    mutable std::shared_mutex _mutex;
    std::vector<std::shared_ptr<Observer>> observers;
    static int id;

    NPC(NPC_type type, int x, int y, std::string name);
    virtual ~NPC() = default;

public:
    virtual std::string get_type() = 0;
    const int get_x() const;
    const int get_y() const;
    virtual int get_damage_range() const = 0;
    int get_energy() const;
    const std::string& get_name() const;
    const bool alive() const;

    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    virtual bool fight(std::shared_ptr<Knight> accepter) = 0;
    virtual bool fight(std::shared_ptr<Merchant> accepter) = 0;
    virtual bool fight(std::shared_ptr<Squirrel> accepter) = 0;

    void attach(std::shared_ptr<Observer> observer);
    void notify_killed(const std::shared_ptr<NPC> defender);

    bool near(const std::shared_ptr<NPC>& enemy, size_t distance) const;
    virtual void move(int max_x, int max_y) = 0;
    void must_die();

    friend std::ostream& operator<<(std::ostream& out, const NPC& npc);
};

// NPC::NPC(NPC_type type, int x, int y, std::string name) : _type(type), _x(x), _y(y), _name(name) {}

// const int NPC::get_x() const {
//     std::lock_guard<std::mutex> lck(_mutex);
//     return _x;
// }

// const int NPC::get_y() const {
//     std::lock_guard<std::mutex> lck(_mutex);
//     return _y;
// }

// int NPC::get_energy() const {
//     return rand() % 6 + 1;
// }

// const std::string& NPC::get_name() const {
//     std::lock_guard<std::mutex> lck(_mutex);
//     return _name;
// }

// const bool NPC::alive() const {
//     std::lock_guard<std::mutex> lck(_mutex);
//     return _alive;
// }

// void NPC::attach(std::shared_ptr<Observer> observer) {
//     observers.push_back(observer);
// }

// void NPC::notify_killed(const std::shared_ptr<NPC> defender) {
//     for (auto& o : observers) {
//         o->report_killed(std::shared_ptr<NPC>(this, [](NPC*) {}), defender);
//     }
// }

// bool NPC::near(const std::shared_ptr<NPC>& enemy, size_t distance) const {
//     std::lock_guard<std::mutex> lck(_mutex);
//     return std::pow(_x - enemy->_x, 2) + std::pow(_y - enemy->_y, 2) <= std::pow(distance, 2);
// }

// void NPC::must_die() {
//     _alive = false;
// }

// std::ostream& operator<<(std::ostream& out, const NPC& npc) {
//     return out << npc._name << " {x : " << npc._x << ", y : " << npc._y << "}";
// }

// int NPC::id = 0;
