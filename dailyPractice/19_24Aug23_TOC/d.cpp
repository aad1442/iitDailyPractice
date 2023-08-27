#include <iostream>
#include <fstream>
#include <string>

#define MAX_LINE_LENGTH 1000

void identify_comments(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    bool in_multi_line_comment = false;
    int line_number = 1;

    while (std::getline(file, line)) {
        if (in_multi_line_comment) {
            size_t end_comment = line.find("*/");
            if (end_comment != std::string::npos) {
                in_multi_line_comment = false;
                std::cout << line_number << ": Multi-line comment: " << line.substr(0, end_comment) << std::endl;
            }
        } else {
            size_t single_line_comment = line.find("//");
            size_t start_multi_line_comment = line.find("/*");
            size_t end_multi_line_comment = line.find("*/");

            if (single_line_comment != std::string::npos) {
                std::cout << line_number << ": Single-line comment: " << line.substr(single_line_comment) << std::endl;
            }

            if (start_multi_line_comment != std::string::npos) {
                if (end_multi_line_comment != std::string::npos) {
                    std::cout << line_number << ": Multi-line comment: " << line.substr(start_multi_line_comment, end_multi_line_comment - start_multi_line_comment + 2) << std::endl;
                } else {
                    in_multi_line_comment = true;
                    std::cout << line_number << ": Multi-line comment: " << line.substr(start_multi_line_comment) << std::endl;
                }
            }
        }

        line_number++;
    }

    file.close();
}

int main() {
    const std::string filename = "test_code.c"; // Replace with your file name
    identify_comments(filename);
    return 0;
}
