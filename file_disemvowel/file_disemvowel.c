#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define bufferSize 1024

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
  int chars;
  int others;
  char bufferIn[bufferSize];
  chars = fread(bufferIn, sizeof(char), bufferSize, in);
  char bufferOut[chars];
  others = copyConsonants(chars, bufferIn, bufferOut);
  fwrite(bufferOut, sizeof(char), others, out);
}

int main(int argc, char *argv[]) {
  FILE *in;
  FILE *out;

  if (argc == 1) {
    in = stdin;
    out = stdout;
    disemvowel(in, out);
  }
  else if (argc == 2) {
    in = fopen(argv[1], "r");
    out = stdout;
    disemvowel(in, out);
  }
  else if (argc == 3) {
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    disemvowel(in, out);
  } else {
    printf("Invalid # arguments.");
    exit(0);
  }

fclose(in);
fclose(out);

return 0;

}
