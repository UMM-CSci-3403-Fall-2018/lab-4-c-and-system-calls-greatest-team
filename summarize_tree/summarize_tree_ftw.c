#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ftw.h>
#include <sys/stat.h>

#define MAX_FTW_DEPTH 16
static int num_dirs, num_reg;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    if (typeflag == FTW_F) {
          ++num_reg;
          return 0;
    }

    else if (typeflag == FTW_D){
        ++num_dirs;
        return 0;
    }

    else return 0;

}


int main(int argc, char** argv) {
    num_dirs = 0, num_reg = 0;

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    printf("There were %d directories. \n", num_dirs);
    printf("There were %d regular files. \n", num_reg);
}
