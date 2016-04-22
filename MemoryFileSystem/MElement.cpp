//
//  MElement.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/22/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "MElement.hpp"
#include <ctime>

void MElement::setName(const string& name) {
    m_name = name;
}

void MElement::setCreateTime(const string& create_time) {
    m_create_time = create_time;
}

void MElement::setLastUpdateTime(const string& last_update_time) {
    m_last_update_time = last_update_time;
}

void MElement::setSize(const int& size) {
    m_size = size;
}

string MElement::getCreateTime() {
    return m_create_time;
}

string MElement::getLastUpdateTime() {
    return m_last_update_time;
}

MElement::MElement(const string& name) {
    m_name = name;
    m_size = 0;
    time_t now = time(0);
    m_create_time = ctime(&now);
    m_create_time = m_create_time.substr(0, m_create_time.length()-1);
    m_last_update_time = m_create_time;
}

MElement::~MElement() {
}