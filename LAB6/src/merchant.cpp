#include "../include/merchant.hpp"

Merchant::Merchant(int x, int y) : NPC(NPC_type::merchant, x, y, "merchant_" + std::to_string(id++)) {}

std::string Merchant::getType() {
    return "Merchant";
}

bool Merchant::accept(std::shared_ptr<NPC> visitor) {
    if (visitor->fight(*this)) {
        this->_alive = false;
        return true;
    }
    return false;
}

bool Merchant::fight(Knight& accepter) {
    return false;
}

bool Merchant::fight(Merchant& accepter) {
    return false;
}

bool Merchant::fight(Squirrel& accepter) {
    notify_killed(accepter);
    return true;
}