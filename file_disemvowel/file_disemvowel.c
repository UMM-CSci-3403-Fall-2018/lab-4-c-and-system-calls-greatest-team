#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define bufferSize 1024

int check_vowel(char);
int check_vowel(char c)
{
  switch(c) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      return 1;
    default:
      return 0;
  }
}


int copyConsonants(int numChars, char* bufferIn, char* bufferOut) {
  int count = 0;
  for (int i = 0; i < numChars; i++) {
    if(check_vowel(bufferIn[i])==0) {
      bufferOut[count] = bufferIn[i];
      count++;
    }
  }
  bufferOut[count] = '\0';
  return count;
}


void disemvowel(FILE* in, FILE* out) {
  char *bufferIn = (char*) calloc(bufferSize + 1, sizeof(char));
  char *bufferOut = (char*) calloc(bufferSize, sizeof(char));
  int readNum = 0;
  int numConsonants;

  do {
    readNum = fread(bufferIn, sizeof(char), bufferSize, in);
    numConsonants = copyConsonants(readNum, bufferIn, bufferOut);
    fwrite(bufferOut, sizeof(char), numConsonants, out);
  } while (!readNum != 0);

  free(bufferIn);
  free(bufferOut);
}

int main(int argc, char *argv[]) {
  FILE *in;
  FILE *out;

  in = stdin;
  out = stdout;

  if (argc >= 2) {
    in = fopen(argv[1], "r");
  }
  if (argc >= 3) {
    out = fopen(argv[2], "w");
  }
disemvowel(in, out);
fclose(in);
fclose(out);

return 0;

}
