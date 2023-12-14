#pragma once
#include "merchant.hpp"
#include "npc.hpp"
#include "squirrel.hpp"

class Knight : public NPC {
public:
    Knight(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> accepter) override;
    bool fight(std::shared_ptr<Merchant> accepter) override;
    bool fight(std::shared_ptr<Squirrel> accepter) override;

    void move(int max_x, int max_y) override;
};

// Knight::Knight(int x, int y) : NPC(NPC_type::knight, x, y, "knight_" + std::to_string(id++)) {}

// std::string Knight::get_type() {
//     return "Knight";
// }

// int Knight::get_damage_range() const {
//     return 10;
// }

// bool Knight::accept(std::shared_ptr<NPC> visitor) {
//     if (visitor->fight(std::shared_ptr<Knight>(this, [](Knight *) {}))) {
//         return true;
//     }
//     return false;
// }

// bool Knight::fight(std::shared_ptr<Knight> accepter) {
//     return false;
// }

// bool Knight::fight(std::shared_ptr<Merchant> accepter) {
//     if (this->get_energy() > accepter->get_energy()) {
//         accepter->must_die();
//         notify_killed(accepter);
//         return true;
//     }
//     return false;
// }

// bool Knight::fight(std::shared_ptr<Squirrel> accepter) {
//     return false;
// }

// void Knight::move(int max_x, int max_y) {
//     std::lock_guard<std::mutex> lck(_mutex);
//     std::srand(std::time(0));
//     int shift_x = std::rand() % 60 - 30,
//         shift_y = std::rand() % 60 - 30;

//     if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
//         _x += shift_x;
//     if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
//         _y += shift_y;
// }
