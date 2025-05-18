#include "../Header/year_calendar_functs.h"
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

const size_t global_width{15};

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
    std::cout << '\n' << "ERROR_001: wrong_input_format" << '\n';
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

    std::cin >> r_usr_year; std::cout << '\n';
  }

  std::cout << "You chose " << r_usr_year << " as the year you want it ?" << '\n';

  std::cout << "[Y | N]: ";

  std::cin >> usr_cfrm;std::cout << '\n';

  while (!InputVerrifier(usr_cfrm, 2))
  {
    if (usr_cfrm == "N" || usr_cfrm == "n")
    {
      std::cout << "You don't want this year ? Got you !" << '\n';

      std::cout << "Enter your year like [yyyy | -yyyy]: ";

      std::cin >> r_usr_year;std::cout << '\n';

      while (!InputVerrifier(r_usr_year, 0))
      {
        ErrorDisplayer(0);

        std::cout << "Enter a year in this format [yyyy | -yyyy]: ";

        std::cin >> r_usr_year;
      }

      std::cout << "You chose " << r_usr_year << " as the year you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << '\n';
    }

    else if ((usr_cfrm != "N" || usr_cfrm != "n") || usr_cfrm.length() > 1)
    {
      ErrorDisplayer(0);

      std::cout << "You chose " << r_usr_year << " as the year you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << '\n';
    }

  }

}

void DayManager(std::string &day_pos)
{
  std::string week[]{"Monday", "Tuesday", "Wednesday", "Thursday", "Fryday", "Saturday", "Sunday"}, usr_cfrm{};

  while (!InputVerrifier(day_pos, 1))
  {
    ErrorDisplayer(0);

    std::cout << "Chose the day with a single digit in range [1 to 7]." << '\n';

    DayPrinter();
  
    std::cout << "1st Day: ";

    std::cin >> day_pos; std::cout << '\n';
  }

  std::cout << "You chose " << week[std::stoi(day_pos) - 1] << '\n';

  std::cout << "You take it ? [Y | N]: ";

  std::cin >> usr_cfrm;std::cout << '\n';

  while (!InputVerrifier(usr_cfrm, 2))
  {
    if (usr_cfrm == "N" || usr_cfrm == "n")
    {
      std::cout << "Youd' like another day ? No wory." << '\n';

      DayPrinter();

      std::cout << "Enter your day: ";

      std::cin >> day_pos;std::cout << '\n';

      while (!InputVerrifier(day_pos, 1))
      {
        ErrorDisplayer(0);

        std::cout << "Enter with only one digit between [1 | 7]: ";

        std::cin >> day_pos;
      }

      std::cout << "You chose " << day_pos << " as the year you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << '\n';
    }

    else if ((usr_cfrm != "N" || usr_cfrm != "n") || usr_cfrm.length() > 1)
    {
      ErrorDisplayer(0);

      std::cout << "You chose " << week[stoi(day_pos)] << " as the first day you want it ?\n";

      std::cout << "[Y | N]: ";

      std::cin >> usr_cfrm; std::cout << '\n';
    }

  }
  
}

void DayPrinter()
{
  std::string week[]{"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"};

  for (size_t i{}; i < 7; i++)
  {
    std::cout << i + 1 << ": " << week[i] << '\n';
  }
}

std::string MonthPrinter(size_t mounth_nbr)
{
  std::string months[]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", 
    "November", "December"};

  return months[mounth_nbr];
}

void YearShow(std::string usr_year, std::string day_pos)
{
  std::string week[]{"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"};
  
  int temp_val{std::stoi(day_pos)};
  
  int &r_day_placement {temp_val};

  for (size_t i{}; i < 12; i++)
  {
    std::cout << std::string(93, '-') << '\n' << MonthPrinter(i) << '\n';
    
    for (size_t i{}; i < 7; i++)
    {
      std::cout << std::setw(global_width) << std::left << week[i];
    }
    
    std::cout << '\n' << std::setw(0);
    
    DayInMonthPrint(r_day_placement,  std::stoi(usr_year), i);

    std::cout << '\n';
  }

}

void DayInMonthPrint(int &r_day_pos, int year_in, int mounth_in)
{
  int max_day = DayInMonthQtt(year_in, mounth_in);

  for (int i = 1; i < r_day_pos; i++)
  {
    std::cout << std::setw(global_width) << std::left << ' ';
  }
  

  for (int current_day = 1; current_day <= max_day; current_day++)
  {
    if (r_day_pos > 7)
    {
      std::cout << '\n';

      std::cout << std::setw(global_width) << std::left << current_day ;

      r_day_pos = 1;

      r_day_pos++;
    }
    
    else
    {
      std::cout << std::setw(global_width) << std::left << current_day ;

      r_day_pos++;
    }
    
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
