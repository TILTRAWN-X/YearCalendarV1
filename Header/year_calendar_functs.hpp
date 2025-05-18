#ifndef YEAR_CALENDAR_FUNCTS_H
#define YEAR_CALENDAR_FUNCTS_H

#include <string>

void DayInMonthPrint(int &r_day_pos, int year_in,int mounth_in);

int DayInMonthQtt(int year_in, int actu_month);

void DayManager(std::string &day_pos);

std::string DayPrinter(size_t day_nbr);

void ErrorDisplayer(short signed int err_arg);

bool InputVerrifier(std::string input_to_verrif, short signed int brl_chbr);

std::string MonthPrinter(size_t mounth_nbr);

void YearManager(std::string &r_usr_year);

void YearShow(std::string usr_year, std::string day_pos);

#endif