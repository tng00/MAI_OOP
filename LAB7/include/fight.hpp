#pragma once
#include <iostream>
#include <memory>
#include <optional>
#include <queue>
#include <shared_mutex>
#include <thread>

#include "npc.hpp"

using namespace std::chrono_literals;
extern std::atomic<bool> stop_flag;

struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager {
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get();

    void add_event(FightEvent &&event);

    void operator()();
};

// std::atomic<bool> stop_flag(false);

// FightManager &FightManager::get() {
//     static FightManager instance;
//     return instance;
// }

// void FightManager::add_event(FightEvent &&event) {
//     std::lock_guard<std::shared_mutex> lock(mtx);
//     events.push(event);
// }

// void FightManager::operator()() {
//     while (!stop_flag) {
//         {
//             std::optional<FightEvent> event;

//             {
//                 std::lock_guard<std::shared_mutex> lock(mtx);
//                 if (!events.empty()) {
//                     event = events.back();
//                     events.pop();
//                 }
//             }

//             if (event) {
//                 if (event->attacker->alive() && event->defender->alive()) {
//                     event->defender->accept(event->attacker);
//                 }
//             } else {
//                 std::this_thread::sleep_for(100ms);
//             }
//         }
//     }
// }
