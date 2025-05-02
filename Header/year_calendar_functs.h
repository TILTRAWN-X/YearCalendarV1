
#ifndef YEAR_CALENDAR_FUNCTS_H
#define YEAR_CALENDAR_FUNCTS_H

#include <cctype>
#include <iostream>
#include <string>

bool InputVerrifier(std::string input_to_verrif, short signed int brl_chbr);

void ErrorDisplayer(short signed int err_arg);

void YearManager(std::string &r_usr_year);

void DayManager(std::string &r_usr_1st_day);

#endif