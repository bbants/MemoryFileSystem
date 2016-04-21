//
//  CLI.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "CLI.hpp"
#include <sstream>

CLI::CLI() {
    m_file_system = new MFileSystem();
}

CLI::~CLI() {
}

void CLI::run() {
    while(1) {
        cout << m_file_system->getCurrentDirectory() << " $ ";
        string input = "", command = "", path = "", content = "";
        getline(cin, input);
        stringstream ss(input);
        ss >> command;
        if(command == "ls") {
            cout << m_file_system->ls();
        } else if(command == "mkdir") {
            ss >> path;
            m_file_system->mkdir(path);
        } else if(command == "touch") {
            ss >> path;
            m_file_system->touch(path);
        } else if(command == "cat") {
            ss >> path;
            cout << m_file_system->cat(path) << endl;
        } else if(command == "write") {
            ss >> path >> content;
            m_file_system->write(path, content);
        } else if(command == "cd") {
            ss >> path;
            if(path != "" && path[path.length()-1] != '/') {
                path = path + "/";
            }
            m_file_system->cd(path);
        } else if(command == "rm") {
            ss >> path;
            m_file_system->rm(path);
        } else if(command == "exit") {
            return;
        }
    }
}