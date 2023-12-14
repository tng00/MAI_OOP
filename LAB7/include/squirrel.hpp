#pragma once
#include "knight.hpp"
#include "merchant.hpp"
#include "npc.hpp"

class Squirrel : public NPC {
public:
    Squirrel(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> accepter) override;
    bool fight(std::shared_ptr<Merchant> accepter) override;
    bool fight(std::shared_ptr<Squirrel> accepter) override;

    void move(int max_x, int max_y) override;
};

// Squirrel::Squirrel(int x, int y) : NPC(NPC_type::squirrel, x, y, "squirrel_" + std::to_string(id++)) {}

// std::string Squirrel::get_type() {
//     return "Squirrel";
// }

// int Squirrel::get_damage_range() const {
//     return 5;
// }

// bool Squirrel::accept(std::shared_ptr<NPC> visitor) {
//     if (visitor->fight(std::shared_ptr<Squirrel>(this, [](Squirrel *) {}))) {
//         return true;
//     }
//     return false;
// }

// bool Squirrel::fight(std::shared_ptr<Knight> accepter) {
//     return false;
// }

// bool Squirrel::fight(std::shared_ptr<Merchant> accepter) {
//     return false;
// }

// bool Squirrel::fight(std::shared_ptr<Squirrel> accepter) {
//     if (this->get_energy() > accepter->get_energy()) {
//         accepter->must_die();
//         notify_killed(accepter);
//         return true;
//     }
//     return false;
// }

// void Squirrel::move(int max_x, int max_y) {
//     std::lock_guard<std::mutex> lck(_mutex);
//     std::srand(std::time(0));
//     int shift_x = std::rand() % 10 - 5,
//         shift_y = std::rand() % 10 - 5;

//     if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
//         _x += shift_x;
//     if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
//         _y += shift_y;
// }
