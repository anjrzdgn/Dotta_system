//
// Created by Ali on 2024-03-30.
//

#ifndef DOTTA_RAM_COURSES_HEADER_H
#define DOTTA_RAM_COURSES_HEADER_H

#include "universal_header.h"

std::vector<course> read_courses_from_file();
void save_courses_to_file(const std::vector<course>& courses);

#endif //DOTTA_RAM_COURSES_HEADER_H
