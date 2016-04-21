//
//  MFileSystem.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "MFileSystem.hpp"

MFileSystem::MFileSystem() {
    m_root_directory = new MDirectory(NULL, "");
    m_cur_directory = m_root_directory;
}

MFileSystem::~MFileSystem() {
}

string MFileSystem::getCurrentDirectory() {
    return m_cur_directory->getDirectoryName();
}

void MFileSystem::mkdir(const string& path) {
    m_cur_directory->mkdir(path);
}

string MFileSystem::ls() {
    return m_cur_directory->ls();
}

void MFileSystem::touch(const string& path) {
    m_cur_directory->touch(path);
}

string MFileSystem::cat(const string& path) {
    return m_cur_directory->cat(path);
}

void MFileSystem::write(const string& path, const string& content) {
    return m_cur_directory->write(path, content);
}

void MFileSystem::cd(const string& path) {
    if(path == "") return;
    if(path[0] == '/') {
        // absolute path
        // remove the first /
        string remainPath = path.substr(1, path.length()-1);
        m_cur_directory = m_root_directory->cd(remainPath);
    } else {
        // relative path
        m_cur_directory = m_cur_directory->cd(path);
    }
}

void MFileSystem::rm(const string& path) {
    m_cur_directory->rm(path);
}