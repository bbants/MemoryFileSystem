//
//  MFile.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "MFile.hpp"
#include <ctime>

MFile::MFile(const string& path): MElement(path) {
}

MFile::~MFile() {
}

string MFile::cat() {
    return m_content;
}

void MFile::write(const string& content) {
    m_content = content;
    m_size = content.length();
}

string MFile::getName() {
    return m_name;
}

int MFile::getSize() {
    return m_size;
}

