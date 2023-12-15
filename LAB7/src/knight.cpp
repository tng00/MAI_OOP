#include "../include/knight.hpp"

Knight::Knight(int x, int y) : NPC(NPC_type::knight, x, y, "knight_" + std::to_string(id++)) {}

std::string Knight::get_type() {
    return "Knight";
}

int Knight::get_damage_range() const {
    return 10;
}

bool Knight::accept(std::shared_ptr<NPC> visitor) {
    if (visitor->fight(std::shared_ptr<Knight>(this, [](Knight *) {}))) {
        return true;
    }
    return false;
}

bool Knight::fight(std::shared_ptr<Knight> accepter) {
    return false;
}

bool Knight::fight(std::shared_ptr<Merchant> accepter) {
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return false;
}

bool Knight::fight(std::shared_ptr<Squirrel> accepter) {
    return false;
}

void Knight::move(int max_x, int max_y) {
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100 * 30;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
