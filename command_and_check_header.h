//
// Created by Ali on 2024-03-28.
//

#ifndef DOTTA_COMMAND_AND_CHECK_HEADER_H
#define DOTTA_COMMAND_AND_CHECK_HEADER_H

#include "universal_header.h"

void sos_ADDITION_COMMANDS_admin();
void sos_OBSERVATION_COMMANDS_admin();
void sos_MODIFICATION_COMMANDS_admin();
void sos_DELETION_COMMANDS_admin();
void sos_RESTORATION_COMMANDS_admin();
void sos_HELPER_COMMANDS_admin();
void command_and_check_for_admin();

void sos_COURSE_COMMANDS_teacher();
void sos_DUTY_COMMANDS_teacher();
void sos_PARTICIPATION_COMMANDS_teacher();
void sos_OBSERVATION_COMMANDS_teacher();
void sos_HELPER_COMMANDS_teacher();
void command_and_check_for_teacher();

void sos_OBSERVATION_COMMANDS_student();
void sos_DUTY_COMMANDS_student();
void command_and_check_for_student();

#endif //DOTTA_COMMAND_AND_CHECK_HEADER_H
