#include "../include/merchant.hpp"

Merchant::Merchant(int x, int y) : NPC(NPC_type::merchant, x, y, "merchant_" + std::to_string(id++)) {}

std::string Merchant::get_type() {
    return "Merchant";
}

int Merchant::get_damage_range() const {
    return 10;
}

bool Merchant::accept(std::shared_ptr<NPC> visitor) {
    if (visitor->fight(std::shared_ptr<Merchant>(this, [](Merchant *) {}))) {
        return true;
    }
    return false;
}

bool Merchant::fight(std::shared_ptr<Knight> accepter) {
    return false;
}

bool Merchant::fight(std::shared_ptr<Merchant> accepter) {
    return false;
}

bool Merchant::fight(std::shared_ptr<Squirrel> accepter) {
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return false;
}

void Merchant::move(int max_x, int max_y) {
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100 * 10;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
