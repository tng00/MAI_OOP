#pragma once
#include <fstream>

#include "knight.hpp"
#include "merchant.hpp"
#include "npc.hpp"
#include "squirrel.hpp"
#include "observer.hpp"

class NPCFactory {
public:
    NPCFactory() = default;
    ~NPCFactory() = default;
    std::shared_ptr<NPC> createNPC(NPC_type type, int x, int y);
    void save(const set_t& s, const std::string& file_name);
    set_t load(const std::string& file_name);
};

// std::shared_ptr<NPC> NPCFactory::createNPC(NPC_type type, int x, int y) {
//     std::shared_ptr<NPC> result;
//     switch (type) {
//     case knight:
//         result = std::make_shared<Knight>(x, y);
//         break;
//     case merchant:
//         result = std::make_shared<Merchant>(x, y);
//         break;
//     case squirrel:
//         result = std::make_shared<Squirrel>(x, y);
//         break;

//     default:
//         break;
//     }

//     return result;
// }

// void NPCFactory::save(const set_t& s, const std::string& file_name) {
//     std::ofstream out(file_name);
//     out << s.size() << std::endl;
//     for (auto& npc : s) {
//         out << npc->getType() << std::endl
//             << npc->getX() << std::endl
//             << npc->getY() << std::endl;
//     }

//     out.flush();
//     out.close();
// }

// set_t NPCFactory::load(const std::string& file_name) {
//     set_t result;
//     std::ifstream in(file_name);
//     std::shared_ptr<Observer> console_observer, file_observer;
//     console_observer = std::make_shared<ConsoleObserver>();
//     file_observer = std::make_shared<FileObserver>();

//     if (in.good() && in.is_open()) {
//         int count;
//         in >> count;
//         while (count--) {
//             std::shared_ptr<NPC> npc;
//             int x, y;
//             std::string type;
//             in >> type;
//             if (type == "Knight") {
//                 in >> x >> y;
//                 npc = std::make_shared<Knight>(x, y);
//                 result.insert(npc);
//             } else if (type == "Merchant") {
//                 in >> x >> y;
//                 npc = std::make_shared<Merchant>(x, y);
//                 result.insert(npc);
//             } else if (type == "Squirrel") {
//                 in >> x >> y;
//                 npc = std::make_shared<Squirrel>(x, y);
//                 result.insert(npc);
//             }
//             npc->attach(console_observer);
//             npc->attach(file_observer);
//         }
//     }

//     return result;
// }