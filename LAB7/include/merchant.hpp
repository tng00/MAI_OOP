#pragma once
#include "knight.hpp"
#include "npc.hpp"
#include "squirrel.hpp"

class Merchant : public NPC {
public:
    Merchant(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> accepter) override;
    bool fight(std::shared_ptr<Merchant> accepter) override;
    bool fight(std::shared_ptr<Squirrel> accepter) override;

    void move(int max_x, int max_y) override;
};

// Merchant::Merchant(int x, int y) : NPC(NPC_type::merchant, x, y, "merchant_" + std::to_string(id++)) {}

// std::string Merchant::get_type() {
//     return "Merchant";
// }

// int Merchant::get_damage_range() const {
//     return 10;
// }

// bool Merchant::accept(std::shared_ptr<NPC> visitor) {
//     if (visitor->fight(std::shared_ptr<Merchant>(this, [](Merchant *) {}))) {
//         return true;
//     }
//     return false;
// }

// bool Merchant::fight(std::shared_ptr<Knight> accepter) {
//     return false;
// }

// bool Merchant::fight(std::shared_ptr<Merchant> accepter) {
//     return false;
// }

// bool Merchant::fight(std::shared_ptr<Squirrel> accepter) {
//     if (this->get_energy() > accepter->get_energy()) {
//         accepter->must_die();
//         notify_killed(accepter);
//         return true;
//     }
//     return false;
// }

// void Merchant::move(int max_x, int max_y) {
//     std::lock_guard<std::mutex> lck(_mutex);
//     std::srand(std::time(0));
//     int shift_x = std::rand() % 20 - 10,
//         shift_y = std::rand() % 20 - 10;

//     if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
//         _x += shift_x;
//     if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
//         _y += shift_y;
// }
