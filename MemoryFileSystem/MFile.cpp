//
//  MFile.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "MFile.hpp"

MFile::MFile(const string& path, const int& permission) {
    m_name = path;
    m_permission = permission;
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