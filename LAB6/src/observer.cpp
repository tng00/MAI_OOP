#include "../include/observer.hpp"

void ConsoleObserver::report_killed(const NPC& attacker, const NPC& defender) {
    std::cout << defender << " | killed by | " << attacker << std::endl;
}

void FileObserver::report_killed(const NPC& attacker, const NPC& defender) {
    os << defender << " | killed by | " << attacker << std::endl;
}
