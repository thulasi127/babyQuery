#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "babies.h"

int main ( int argc, char *argv[] ) {

   FILE *f1;
   int i = 0;
   int decade;
   int rankNumber;
   int gen;
   int gen2;
   int a = 0;
   int b = 0;
   int c = 0;
   int d = 0;
   int e = 0;
   int f = 0;
   int g = 0;
   struct pNames popNames;
   char maleSNumber[20];
   char femaleSNumber[20];
   char string[100];
   char all[20]; /*all = rank, search and top ten*/
   char name[20];
   char gender[20];
   char gender2[20];
   char text[20];
   char rankNum[20];
   char answer[20];
   char answer2[20];

while(a == 0){
   printf("What decade do you want to a at? [1880 to 2010]:\n");
   scanf("%s", text);
   decade = atoi(text);

b = 0;
while (b == 0){
   if (decade >= 1880 && decade <= 2010){
     printf("Would you like to see a rank, search for a name, or see the top 10? [rank, search, top]:\n");
     scanf("%s", all);


     strcat(text,"Names.txt");

     if ( (f1 = fopen(text, "r")) != NULL ) {
       while ( fgets(string, 100, f1) != NULL ) {
       sscanf (string, "%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
       /*printf ( "%d %s %s %s %s\n",.rank[i], popNames.maleName[i],maleSNumber,popNames.femaleName[i],femaleSNumber );*/
       removeCommas ( maleSNumber );
       removeCommas ( femaleSNumber );
       popNames.maleNumber[i] = atoi ( maleSNumber );
       popNames.femaleNumber[i] = atoi ( femaleSNumber );
       i++;
     }
   } else {
        printf ( "Cannot open %s\n", text);
        return ( -2 );
   }
   fclose(f1);
 } else {
   printf("No other numbers are acceptable\n");
 }


   if (strcmp (all, "rank") == 0) {
     c = 0;

      while (c == 0){
       printf("What rank would you wish to see? [1-200]:\n");
       scanf("%s",rankNum);
       rankNumber = atoi(rankNum);

         if (rankNumber>0 && rankNumber<201){
           d = 0;
          while (d==0){
         printf("Would you like to see the male(0), female(1), or both(2) name(s)? [0-2]:\n");
         scanf("%s", gender);
         gen = atoi(gender);

         if (gen >= 0 && gen <=2){

           if ( (f1 = fopen(text, "r")) != NULL ) {
             while ( fgets(string, 100, f1) != NULL ) {
             sscanf (string,"%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
             removeCommas ( maleSNumber );
             removeCommas ( femaleSNumber );
             popNames.maleNumber[i] = atoi ( maleSNumber );
             popNames.femaleNumber[i] = atoi ( femaleSNumber );

           if (rankNumber == popNames.rank[i]){
          if (strcmp (gender, "0") == 0){
            printf("Rank %s: Male: %s (%s)\n", rankNum, popNames.maleName[rankNumber-1], maleSNumber);
          }
          if (strcmp (gender, "1") == 0){
            printf("Rank %s: Female: %s (%s)\n", rankNum, popNames.femaleName[rankNumber-1], femaleSNumber);
          }
          if (strcmp (gender, "2") == 0){
            printf("Rank %s: Male: %s (%s) and Female: %s (%s)\n", rankNum, popNames.maleName[rankNumber-1], maleSNumber, popNames.femaleName[rankNumber-1], femaleSNumber);
        }
      }
    }
  } else {
       printf ( "Cannot open %s\n", text);
       return ( -2 );
     }
} else{
        printf("Only the numbers 0, 1 and 2 are acceptable.\n");
        return (0);
      }
      d = 1;
    }

    } else {
      printf("Only numbers between 1 and 200 are acceptable\n");
      }
      c = 1;
    }

  } else if (strcmp (all, "search") == 0) {
      e = 0;
      while (e == 0){
        printf("What name do you want to search for? [case sensitive]:\n");
        scanf("%s", name);

        f = 0;
        while (f == 0){
        printf("Do you wish to search male(0), female(1), or both(2) name? [0-2]:\n");
        scanf("%s", gender2);
        gen2 = atoi(gender2);

        if (gen2 >= 0 && gen2 <=2){

          if ( (f1 = fopen(text, "r")) != NULL ) {
            while ( fgets(string, 100, f1) != NULL ) {
            sscanf (string,"%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
            removeCommas ( maleSNumber );
            removeCommas ( femaleSNumber );
            popNames.maleNumber[i] = atoi ( maleSNumber );
            popNames.femaleNumber[i] = atoi ( femaleSNumber );

            if (strcmp(name, popNames.maleName[i]) == 0){
              if (strcmp(gender2, "0") == 0){
                printf("In %d, the male name %s ranked %d with a count of %s.\n", decade, name, popNames.rank[i], maleSNumber);
              } else if (strcmp(gender2, "1") == 0) {
                printf("In %d, the female name %s is not ranked.\n", decade, name);
              } else if (strcmp(gender2, "2") == 0) {
                printf("In %d, the female name %s is not ranked and the male name %s is ranked %s with a count of %s.\n", decade, name, name, femaleSNumber, maleSNumber);
              }
            } else if (strcmp(name, popNames.femaleName[i]) == 0) {
              if (strcmp(gender2, "0") == 0) {
                printf("In %d, the male name %s is not ranked.\n", decade, name);
              } else if (strcmp(gender2, "1") == 0) {
                printf("In %d, the female name %s is ranked %d with a count of %s.\n", decade, name, popNames.rank[i], femaleSNumber);
              } else if (strcmp(gender2, "2") == 0) {
                printf("In %d, the female name %s is ranked %d with a count of %s and the male name %s is not ranked.\n", decade, name, popNames.rank[i], femaleSNumber, name);
              }
          }
        }
      } else {
           printf ( "Cannot open %s\n", text );
           return ( -2 );
      }

    } else {
      printf("Only the numbers 0, 1, or 2 are acceptable.\n");
    }
    f = 1;
  }
e = 1;
}
}else if (strcmp (all, "top") == 0) {

        if ( (f1 = fopen(text, "r")) != NULL ) {
          while ( fgets(string, 100, f1) != NULL ) {
          sscanf (string,"%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
          removeCommas ( maleSNumber );
          removeCommas ( femaleSNumber );
          popNames.maleNumber[i] = atoi ( maleSNumber );
          popNames.femaleNumber[i] = atoi ( femaleSNumber );

          if (popNames.rank[i]<11){
          printf("%-5d %-5s     \t%s     \t %s     \t%s\n",popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
          }
      }

    }
      else {
           printf ( "Cannot open %s\n", text);
           return ( -2 );
}
}  else {
  printf("Please type in rank, search, or top exactly as requested.\n");
}

g = 0;
while (g==0){
printf("Do you want to ask another question about %d? [Y or N]:\n", decade);
scanf("%s", answer);

if (strcmp(answer, "Y") != 0 && strcmp(answer, "y") != 0) {
  printf("Only the single characters Y or N are acceptable.\n");
}
g = 1;
}

  if (strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0){

    f = 1;
    e = 1;
    d = 1;
    c = 1;
    b = 0;
    continue;

  } else if (strcmp(answer, "N") == 0 || strcmp(answer, "n") == 0) {

    printf("Would you like to select another year? [Y or N]:\n");
    scanf("%s", answer2);

    if (strcmp(answer2, "Y") != 0 && strcmp(answer2, "y") != 0) {
      printf("Only the single characters Y or N are acceptable.\n");

  }

     if (strcmp(answer2, "Y") == 0 || strcmp(answer2, "y") == 0) {

       f = 1;
       e = 1;
       d = 1;
       c = 1;
       b = 1;
       a = 0;
       continue;


   } else if (strcmp(answer2, "N")== 0 || strcmp(answer2, "n") == 0) {
     printf("Thank you for using babyQuery\n");
     return(1);
  }
}
}
}


}
