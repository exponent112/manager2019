#include "menu.h"

int ask_menu(int is_login){
  #ifdef DEBUG_MODE
         printf("DEBUG>> ask_menu opened! \n");
  #endif
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
  char menu[50];
  char menu2[100];
  if(is_login==0){
    {
      printf(">");
      scanf("%s",menu); //안되면 getchar 해보
      //scanf("%c",&dummy);
      if(strcmp(menu,"login")==0) {return 2;}
      else if(strcmp(menu,"join")==0) {return 1;}
      else if(strcmp(menu,"list")==0) {return 4;}
      else if(strcmp(menu,"exit")==0) {return 5;}
      else
      printf("No such command!\n");
    }
  }
  else{
 printf("#");
 fgets(menu2,sizeof(menu2),stdin);
 menu2[strlen(menu2)-1] = '\0';
 if(strcmp(menu2,"logout")==0) {
   printf("Bye!!\n");
   return 3;
 }
 else
 printf("%s\n",menu2);
 }
 return 0;
}
