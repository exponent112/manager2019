#include "user.h"
#include "menu.h"

int main(int argc, char *argv[])
{
#ifdef DEBUG_MODE
  printf("DEBUG>> main opened! \n");
#endif
  LOGIN *userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login = 0;     // 로그인 여부 (0 NO, 1 Yes)
  int menu_id = 0;
  if (argc != 2)
  {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  int count = load_file(userlist, argv[1]);
  while (1)
  {
    menu_id = ask_menu(is_login);
    if (menu_id == 1)
    {
      join(userlist, &count);
      save(userlist, count, argv[1]);
    }
    else if (menu_id == 2)
    {
      is_login = login(userlist, count);
    }
    else if (menu_id == 3)
      logout(&is_login);
    else if (menu_id == 4)
    {
      list_p(userlist, count);
    }
    else if (menu_id == 5)
    {
      return 0;
    }
    //    else if(menu_id==10){menu_id=ask_menu(is_login);}
  }
  save_file(userlist, count, argv[1]);
  return 0;
}
