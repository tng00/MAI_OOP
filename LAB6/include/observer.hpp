#pragma once

#include <fstream>
#include <memory>

#include "knight.hpp"
#include "merchant.hpp"
#include "npc.hpp"
#include "squirrel.hpp"

class ConsoleObserver : public Observer {
public:
    ConsoleObserver() = default;

    void report_killed(const NPC& attacker, const NPC& defender) override;
};

class FileObserver : public Observer {
    std::ofstream os;

public:
    FileObserver() : os(std::ofstream("battle_stats.txt")) {}

    void report_killed(const NPC& attacker, const NPC& defender) override;
};

// void ConsoleObserver::report_killed(const NPC& attacker, const NPC& defender) {
//     std::cout << defender << " | killed by | " << attacker << std::endl;
// }

// void FileObserver::report_killed(const NPC& attacker, const NPC& defender) {
//     os << defender << " | killed by | " << attacker << std::endl;
// }
