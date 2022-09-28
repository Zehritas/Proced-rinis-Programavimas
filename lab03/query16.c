#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[30];
    char surname[30];
    int course;                 // year of study
    double average;             // average grade

    int load;                   // number of courses
    char courses[10][30];       // course names
    int grades[10];             // course grades

    char languages[100];        // spoken languages

} Student;


int main(int argc, char *argv[]) {
    FILE *db = NULL;
    // open database file for reading, provide a parameter or use default "db.bin"
    if (argc > 1)
        db = fopen(argv[1], "rb");
    else
        db = fopen("db.bin", "rb");

    if (db){
        Student students[1000];         // all the data goes here
        int size = 0;                   // how many students in database

        // reading data from file
        fread(&size, sizeof(int), 1, db);

        for (int i = 0; i < size; i++){
            fread(&students[i], sizeof(Student), 1, db);
        }
        printf("%d records loaded succesfully\n", size);


        // MODIFY CODE BELOW

        int counterDemo = 0; // for counting students

        ////////////////////////////////////////////////////////////////////
        //variables for checking if languages repeat
        int check[1000] = {0};
        const char delimeter[4] = " ";
        char *token;
        char languageArray[100][100];
        char tmpString[100];

        for (int i = 0; i < size; i++)
        {

          strcpy(tmpString, students[i].languages);
          //seperate language string into array
          int tmp = 0;
          token = strtok(tmpString, delimeter);
          while (token != NULL)
          {
            strcpy(languageArray[tmp], token);
            token = strtok(NULL, delimeter);
            tmp++;
          }
          //checking if languages repeat
          for (int l = 0; l < tmp; l++)
          {
            for (int m = 0; m < tmp; m++)
            {
              if (l != m)
              {
                if ((strcmp(languageArray[l], languageArray[m]) == 0))
                {
                  check[i] = 1;
                }
              }
            }
          }

          //checking if courses repeat
          for (int j = 0; j < students[i].load; j++)
          {
            for (int k = 0; k < students[i].load; k++)
            {
              if (j != k)
              {
                if ((strcmp(students[i].courses[j], students[i].courses[k]) == 0))
                {
                  check[i] = 1;
                }
              }
            }
          }
        }
        ////////////////////////////////////////////////////////////////////

        for (int i = 0; i < size; ++i){ // process all the student records in database
            Student s = students[i]; // store data for each student in s
            if(check[i]){ // *** first filter, conditions on the student
                printf("Vardas: %s  Pavarde: %s  Kursas: %d  Vidurkis: %f  Kruvis: %d ", s.name, s.surname, s.course, s.average, s.load); // print student data
                int anotherDemo = 0; // for counting courses/grades
                for (int i = 0; i < s.load; ++i){ // process each course taken by the student
                    if(1){ // *** second filter, conditions on the course/grade
                        ++anotherDemo; // counting courses
                        printf(" %s %d ", s.courses[i], s.grades[i]);
                    }
                }
                printf("Kalbos: %s\n", s.languages);

                if (anotherDemo == s.load) // *** third filter, various other conditions
                    ++counterDemo; // counting studfents
            }
        }
        printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
        fclose(db);
    } else {
        printf("File db.bin not found, check current folder\n");
    }

    return 0;
}
