#include <iostream>
#include <string>
#include "../Header/year_calendar_functs.h"

int main()
{
  std::string usr_year{}, usr_first_day_pos{}, week[]{"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"};

  std::cout << "Welcome to the manual year calendar !" << std::endl;

  std::cout << "<<<==========================================>>>" << std::endl;

  std::cout << "Enter the year. Acepted format [yyyy | -yyyy] : ";

  std::cin >> usr_year;std::cout << std::endl; 

  YearManager(usr_year);

  std::cout << "Now that the year is set, ";

  std::cout << "please chose the 1st of januarry " << usr_year << std::endl;

  for (size_t i{}; i < 7; i++)
  {
    std::cout << i + 1 << ": " << week[i] << std::endl;
  }
  
  std::cout << "1st Day: ";

  std::cin >> usr_first_day_pos;

  DayManager(usr_first_day_pos);

  std::cout << "Calendar for " << usr_year << std::endl;

  YearShow(usr_year, usr_first_day_pos);

  return 0;
}