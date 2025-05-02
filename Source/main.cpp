#include <iostream>
#include <string>
#include "../Header/year_calendar_functs.h"

int main()
{
  std::string usr_year{}, first_day_year{}, week[]{"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"};

  std::cout << "Welcome to the manual year calendar !" << std::endl;

  std::cout << "<<<==========================================>>>" << std::endl;

  std::cout << "Enter the year. Acepted format [yyyy | -yyyy] : ";

  std::cin >> usr_year;

  YearManager(usr_year);
  
  return 0;
}