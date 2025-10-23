#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readInt(-1000, 1000, "x");
    inf.readEoln();
    inf.readEof();
}