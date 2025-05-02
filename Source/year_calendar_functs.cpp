#include "../Header/year_calendar_functs.h"

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

  while (!InputVerrifier(usr_cfrm, 1))
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

