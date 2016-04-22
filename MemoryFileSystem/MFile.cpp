//
//  MFile.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "MFile.hpp"
#include <ctime>

MFile::MFile(const string& path) {
    m_name = path;
    time_t now = time(0);
    m_create_time = ctime(&now);
    // remove \n in the last
    m_create_time = m_create_time.substr(0, m_create_time.length()-1);
}

MFile::~MFile() {
}

string MFile::getName() {
    return m_name;
}

void MFile::write(const string& content) {
    m_content = content;
}

string MFile::cat() {
    return m_content;
}

string MFile::getTime() {
    return m_create_time;
}