#include <stdio.h>

int validateDate(int y, int m, int d);
int wd(int year, int month, int day);

int main()
{
  //variables
    int year, month, day, weekDay = 0;
    char dayNames[50];
    FILE *readFile;
    //input
    readFile = fopen("week.txt", "r");
    if (readFile == NULL)
    {
      printf("There is no 'week.txt' file.");
      return 1;
    }

    printf("Input date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &year, &month, &day);


    if (validateDate(year, month, day) == 1)
    {
      printf("Date is correct.\n");
      weekDay = wd(year, month, day);
    }
    
    else
    {
      printf("Date is in-correct.\n");
      return 1;
    }

    for (int i = 0; i <= weekDay; ++i)
    {
      fscanf(readFile, "%s", dayNames);
      if (i == weekDay)
      {
        printf("%s\n", dayNames);
      }
    }
    return 0;
}

//validacija buvo pasiskolinta :)
int validateDate(int y, int m, int d)
{
    //check year validity
    if (y >= 1800 && y <= 2999) {
        //check month validity
        if (m >= 1 && m <= 12) {
            //check day validity
            if (d >= 1 && d <= 31) {
                if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                    return 1; //valid date
                else if ((d >= 1 && d <= 30) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                    return 1; //valid date
                else if ((d >= 1 && d <= 28) && (m == 2))
                    return 1; //valid date
                else if (d == 29 && m == 2 && ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)))
                    return 1; //valid date
                else
                    return 0; //invalid day
            }
            else {
                return 0; //day is invalid
            }
        }
        else {
            return 0; //month is invalid
        }
    }
    else {
        return 0; //year is invalid
    }
}

//Function to return week day
int wd(int year, int month, int day)
{
    int wday = 0;
    wday = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
               + (365 * (year + 4800 - ((14 - month) / 12)))
               + ((year + 4800 - ((14 - month) / 12)) / 4)
               - ((year + 4800 - ((14 - month) / 12)) / 100)
               + ((year + 4800 - ((14 - month) / 12)) / 400)
               - 32045)
        % 7;
    return wday;
}
