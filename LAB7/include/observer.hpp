#pragma once
#include <fstream>
#include <memory>
#include <shared_mutex>

#include "knight.hpp"
#include "merchant.hpp"
#include "squirrel.hpp"

extern std::mutex print_mutex, file_mutex;

class ConsoleObserver : public Observer {
public:
    ConsoleObserver() = default;

    void report_killed(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender) override;
};

class FileObserver : public Observer {
    std::ofstream os;

public:
    FileObserver() : os(std::ofstream("battle_stats.txt")) {}

    void report_killed(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender) override;
};

// std::mutex print_mutex, file_mutex;

// void ConsoleObserver::report_killed(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender) {
//     std::lock_guard<std::mutex> lck(print_mutex);
//     std::cout << *defender.get() << " | killed by | " << *attacker.get() << std::endl;
// }

// void FileObserver::report_killed(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender) {
//     std::lock_guard<std::mutex> lck(file_mutex);
//     os << *defender.get() << " | killed by | " << *attacker.get() << std::endl;
// }
