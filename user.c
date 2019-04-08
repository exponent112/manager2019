#include "user.h"

int load_file(LOGIN *list[], char *filename)
{
#ifdef DEBUG_MODE
  printf("DEBUG>> load_file opened! \n");
#endif
  int count = 0;
  int choice = 0;
  FILE *datafile = fopen(filename, "r");
  if (datafile == NULL)
  {
    printf("%s file not exist! make anyway? (YES 1, NO 2)>>", filename);
    scanf("%d", &choice);
    getchar();
    if (choice == 1)
    {
      // fclose(datafile);
      FILE *datafile = fopen(filename, "wt");
      printf("Welcome!!\n");
      fclose(datafile);
    }
    else
      exit(1);
  }
  else
  {
    while (!feof(datafile))
    {
      list[count] = (LOGIN *)malloc(sizeof(LOGIN));
      fscanf(datafile, "%s %s", list[count]->id, list[count]->password);
      //    if(feof(datafile)==0) break;
      count++;
    }
    fclose(datafile);
  }
  count--;
  printf("%d records read!\n", count);
  return count;
}

void join(LOGIN *list[], int *count)
{
#ifdef DEBUG_MODE
  printf("DEBUG>> join opened! \n");
#endif
  char id[20], pass[20];
  while (1)
  {
    printf("Enter new user id >> ");
    scanf("%s", id);
    int dup = 0;
    for (int i = 0; i < *count; i++)
    {
      if (strcmp(id, list[i]->id) == 0)
      {
        dup = 1;
        break;
      }
    }
    if (dup == 1)
    {
      printf("Already exist!!\n");
    }
    else
    {
      printf("Enter password >> ");
      scanf("%s", pass);
      list[*count] = (LOGIN *)malloc(sizeof(LOGIN));
      strcpy(list[*count]->id, id);
      strcpy(list[*count]->password, pass);
      printf("New user added!\n");
      (*count)++;
      break;
    }
  }
}

int login(LOGIN *list[], int count)
{
#ifdef DEBUG_MODE
  printf("DEBUG>> login opened! \n");
#endif
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  int dup = 0, found;
  for (int i = 0; i < count; i++)
  {
    if (strcmp(id, list[i]->id) == 0)
    {
      dup = 1;
      found = i;
      break;
    }
  }
  if (dup != 1)
  {
    printf("No such user!!\n");
    return 0;
  }
  else
  {
    printf("Enter password >> ");
    scanf("%s", pass);
    getchar();
    if (strcmp(list[found]->password, pass) == 0)
    {
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else
    {
      printf("Password incorrect!!\n");
      return 0;
    }
  }
}

void logout(int *is_login)
{
#ifdef DEBUG_MODE
  printf("DEBUG>> logout opened! \n");
#endif
  *is_login = 0;
  printf("Logout!!\n");
}

void save_file(LOGIN *list[], int count, char *filename)
{
  FILE *datafile = fopen(filename, "wt");
  for (int i = 0; i < count; i++)
  {
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%d records saved to %s!\n", count, filename);
  fclose(datafile);
}

void save(LOGIN *list[], int count, char *filename)
{
#ifdef DEBUG_MODE
  printf("DEBUG>> save opened! \n");
#endif
  FILE *datafile = fopen(filename, "wt");
  for (int i = 0; i < count; i++)
  {
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  fclose(datafile);
}

void list_p(LOGIN *list[], int count)
{
#ifdef DEBUG_MODE
  printf("DEBUG>> list_p opened! \n");
#endif
  printf("User list (id/password)\n");
  for (int i = 0; i < count; i++)
  {
    printf("[%d] %s / %s\n", i, list[i]->id, list[i]->password);
  }
}
