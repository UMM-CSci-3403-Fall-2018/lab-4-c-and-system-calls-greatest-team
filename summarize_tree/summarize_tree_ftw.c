#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ftw.h>
#include <sys/stat.h>

static int callback(const char *fpath, const struct stat *sb, int typeflag)
// and pass it in as the second argument of ftw(), something like this:

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    // Define stuff here
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check arguments and set things up

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results
}
