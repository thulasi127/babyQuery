#include <string.h>

int removeCommas (char *stringNum){
  int i;
  int length;
  int character;
  int nextChar;
  int remCommas = 0;

  length = strlen(stringNum);

  for (i=0; i<length; i++){
    character = stringNum[i];
    nextChar = stringNum[i+1];

    if ((character>47 && character<58) && remCommas == 0) {
      stringNum[i] = character;

    } else {
      remCommas++;
      stringNum[i] = nextChar;
    }
  }
  return (remCommas);
}
