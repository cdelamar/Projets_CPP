#include <iostream>
#include <fstream>
#include <string>

void file_replace(std::string filename, std::string s1, std::string s2)
{
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return;
    }

    std::ifstream in_file(filename.c_str()); //c_str() plus simple pour c++98
    if (!in_file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    std::ofstream out_file((filename + ".replace").c_str());
    if (!out_file.is_open()) {
        std::cerr << "Error: Cannot create .replace file." << std::endl;
        in_file.close();
        return;
    }

    // Lecture et traitement ligne par ligne (gnl c++)
    std::string line;
    while (std::getline(in_file, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        out_file << line;
        if (!in_file.eof()) {
            out_file << std::endl; //sauf de ligne sauf pour la last
        }
    }

    in_file.close();
    out_file.close();
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "invalid amount of arguments" << std::endl;
        return 1;
    }

    file_replace(argv[1], argv[2], argv[3]);
    return 0;
}
