#include "../Header/year_calendar_functs.h"
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

bool InputVerrifier(std::string input_to_verrif, short signed int brl_chbr)
{
  bool rtn_condition{true};
  
  switch (brl_chbr)
  {
    case 0:
      for (size_t i = 0; i < input_to_verrif.length(); i++)
      {
        if (i == 0 && input_to_verrif[i] == '-')
        {
          rtn_condition = true;

          continue;
        }
      
        else if (!std::isdigit(input_to_verrif[i]) || (input_to_verrif[0] == '-' && input_to_verrif.length() > 5))
        {
          rtn_condition = false;
        
          break;
        }
      
        else if (!std::isdigit(input_to_verrif[i]) || (input_to_verrif[0] != '-' && input_to_verrif.length() > 4))
      {
        rtn_condition = false;

        break;
      }
      
        else
        {
          rtn_condition = true;
        }
      }
    
      break;

    case 1:
      for (size_t i{}; i < input_to_verrif.length(); i++)
      {
        if (input_to_verrif.length() > 1 || !std::isdigit(input_to_verrif[i]))
        {
          rtn_condition = false;

          break;
        }
      }
      
      break;

    case 2:
      if (input_to_verrif == "Y" || input_to_verrif == "y")
    {
      rtn_condition = true;
    }
    
      else
    {
      rtn_condition = false;
    }
    
      break;

    default:
      break;
  }

  if (rtn_condition == true)
  {
    return true;
  }
  
  else
  {
    return false;
  }

}

void ErrorDisplayer(short signed int err_arg)
{
  switch (err_arg)
  {
  case 0:
    std::cout << std::endl << "ERROR_001: wrong_input_format" << std::endl;
    break;

  case 1:
    
    break;
  default:
    break;
  }
}

void YearManager(std::string &r_usr_year)
{
  std::string usr_cfrm{};

  while (!InputVerrifier(r_usr_year, 0))
  {
    ErrorDisplayer(0);

    std::cout << "Enter a year in this format [yyyy | -yyyy]: ";

    std::cin >> r_usr_year; std::cout << std::endl;
  }

  std::cout << "You chose " << r_usr_year << " as the year you want it ?" << std::endl;

  std::cout << "[Y | N]: ";

  std::cin >> usr_cfrm;std::cout << std::endl;

  while (!InputVerrifier(usr_cfrm, 2))
  {
    if (usr_cfrm == "N" || usr_cfrm == "n")
    {
      std::cout << "You don't want this year ? Got you !" << std::endl;

      std::cout << "Enter your year like [yyyy | -yyyy]: ";

      std::cin >> r_usr_year;std::cout << std::endl;

      while (!InputVerrifier(r_usr_year, 0))
      {
        ErrorDisplayer(0);

        std::cout << "Enter a year in this format [yyyy | -yyyy]: ";

        std::cin >> r_usr_year;
      }

      std::cout << "You chose " << r_usr_year << " as the year you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << std::endl;
    }

    else if ((usr_cfrm != "N" || usr_cfrm != "n") || usr_cfrm.length() > 1)
    {
      ErrorDisplayer(0);

      std::cout << "You chose " << r_usr_year << " as the year you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << std::endl;
    }

  }

}

void DayManager(std::string &r_usr_1st_day)
{
  std::string week[]{"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"}, usr_cfrm{};

  while (!InputVerrifier(r_usr_1st_day, 1))
  {
    ErrorDisplayer(0);

    std::cout << "Chose the day with a single digit in range [1 | 7]." << std::endl;

    DayPrinter();
  
    std::cout << "1st Day: ";

    std::cin >> r_usr_1st_day; std::cout << std::endl;
  }

  std::cout << "You chose " << week[std::stoi(r_usr_1st_day) - 1] << std::endl;

  std::cout << "You take it ? [Y | N]: ";

  std::cin >> usr_cfrm;std::cout << std::endl;

  while (!InputVerrifier(usr_cfrm, 2))
  {
    if (usr_cfrm == "N" || usr_cfrm == "n")
    {
      std::cout << "Youd' like another day ? No wory." << std::endl;

      DayPrinter();

      std::cout << "Enter your day: ";

      std::cin >> r_usr_1st_day;std::cout << std::endl;

      while (!InputVerrifier(r_usr_1st_day, 1))
      {
        ErrorDisplayer(0);

        std::cout << "Enter with only one digit between [1 | 7]: ";

        std::cin >> r_usr_1st_day;
      }

      std::cout << "You chose " << r_usr_1st_day << " as the year you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << std::endl;
    }

    else if ((usr_cfrm != "N" || usr_cfrm != "n") || usr_cfrm.length() > 1)
    {
      ErrorDisplayer(0);

      std::cout << "You chose " << r_usr_1st_day << " as the year you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << std::endl;
    }

  }
}

void DayPrinter()
{
  std::string week[]{"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"};

  for (size_t i{}; i < 7; i++)
  {
    std::cout << i + 1 << ": " << week[i] << std::endl;
  }
}

std::string MonthPrinter(size_t mounth_nbr)
{
  std::string months[]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", 
    "November", "December"};

  return months[mounth_nbr];
}

void YearShow(std::string usr_year, std::string usr_1st_day)
{
  std::cout << "Calendar for " << usr_year << "." << std::endl;

  std::string week[]{"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"};

  for (size_t i{}; i < 11; i++)
  {
    int day_placement{std::stoi(usr_1st_day)};

    std::cout << MonthPrinter(i) << std::endl;
    
    for (size_t i{}; i < 6; i++)
    {
      std::cout << week[i] << std::setw(15);
    }
    
    std::cout << std::endl << std::setw(0);
    
    DayInMonthPrint(std::stoi(usr_1st_day),  std::stoi(usr_year), i);
  }

}

void DayInMonthPrint(int usr_1st_day, int year_in, int mounth_in)
{
  int max_day = DayInMonthQtt(year_in, mounth_in);

  for (size_t i{}; i < max_day; i++)
  {
    
  }
}

int DayInMonthQtt(int year_in, int actu_month)
{
  int day_in_mounth_max{}, div_nbr[]{4, 100, 400};

  switch (actu_month)
  {
    case 0: case 2: case 4: case 6: case 7: case 9: case 11:
      day_in_mounth_max = 31;
      
      break;
    
    case 3: case 5: case 8: case 10:
      day_in_mounth_max = 30;

      break;

    case 1:
       if (year_in % div_nbr[0] == 0 && year_in % div_nbr[1] != 0)
       {
          day_in_mounth_max = 29;
       }
       
       else if (year_in % div_nbr[0] == 0 && year_in % div_nbr[1] == 0)
       {
          if (year_in % div_nbr[2] == 0)
          {
            day_in_mounth_max = 29;
          }
          
          else
          {
            day_in_mounth_max = 28;
          }
       }

       break;

    default:
      break;
  }

  return day_in_mounth_max;
}