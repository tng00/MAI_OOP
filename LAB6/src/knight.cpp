#include "../include/knight.hpp"

Knight::Knight(int x, int y) : NPC(NPC_type::knight, x, y, "knight_" + std::to_string(id++)) {}

std::string Knight::getType() {
    return "Knight";
}

bool Knight::accept(std::shared_ptr<NPC> visitor) {
    if (visitor->fight(*this)) {
        this->_alive = false;
        return true;
    }
    return false;
}

bool Knight::fight(Knight& accepter) {
    return false;
}

bool Knight::fight(Merchant& accepter) {
    notify_killed(accepter);
    return true;
}

bool Knight::fight(Squirrel& accepter) {
    return false;
}
