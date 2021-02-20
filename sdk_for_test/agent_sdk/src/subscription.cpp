#include "subscription.h"
#include <algorithm>


SubscriptionStruct::SubscriptionStruct() {
}

SubscriptionStruct::~SubscriptionStruct() {
}

SubscriptionStruct::SubscriptionStruct(size_t _floor,const std::string& _room) {
    set_floor_room(_floor, _room);
}

SubscriptionStruct::SubscriptionStruct(const floor_room_pair_t& _floor_room) {
    set_floor_room(_floor_room);
}

SubscriptionStruct::SubscriptionStruct(size_t _floor,const room_stl_t& _rooms) {
    set_floor_rooms(_floor, _rooms);
}

SubscriptionStruct::SubscriptionStruct(const floor_room_stl_t& _floor_room_cnt) {
    set_floor_rooms(_floor_room_cnt);
}

void SubscriptionStruct::set_floor_room(size_t _floor,const std::string& _room) {
    m_floor_room_cnt[_floor].push_back(_room);
}

void SubscriptionStruct::set_floor_room(const floor_room_pair_t& _floor_room) {
    set_floor_room(_floor_room.first, _floor_room.second);
}

void SubscriptionStruct::set_floor_rooms(size_t _floor,const room_stl_t& _rooms) {
    auto insert_all_rooms = [this, _floor](const std::string& _room) { set_floor_room(_floor, _room); };
    std::for_each(_rooms.begin(), _rooms.end(), insert_all_rooms);
}

void SubscriptionStruct::set_floor_rooms(const floor_room_stl_t& _floor_room_cnt) {
    auto all_floors_rooms = [this](const std::pair<size_t,room_stl_t>& _floor_rooms) { 
            set_floor_rooms(_floor_rooms.first, _floor_rooms.second);
        };
    std::for_each(_floor_room_cnt.begin(), _floor_room_cnt.end(), all_floors_rooms);
}