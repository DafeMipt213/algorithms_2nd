#include "testlib.h"

#include <algorithm>
#include <string>

using namespace std;

const int T = 100'000;
const int N = 1'000'000;

const int N_GROUP3 = 13;
const int N_GROUP4 = 40;
const int N_GROUP5 = 60;
const int NI_GROUP6 = 100'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int groupId = inf.readInt(0, 7, "T");
    inf.readEoln();
    int group = atoi(validator.group().c_str());
    ensuref(groupId == group, "group mismatch");

    const int testCount = inf.readInt(1, T, "T");
    inf.readEoln();

    int summarySize = 0;
    for (int testid = 0; testid < testCount; ++testid) {
        setTestCase(testid);
        const string s = inf.readLine("[a-c]{1,1000000}", "S");
        summarySize += s.size();
        ensuref(summarySize <= N, "Summary length of strings mustn't be greater than %d", N);
        
        if (groupId == 1) {
            ensuref(find(s.begin(), s.end(), 'c') == s.end(), "In group 1 char c is forbiden");
        } else if (groupId == 2) {
            for (int i = 0; i + 1 < s.size(); ++i) {
                ensuref(min(s[i], s[i+1]) != 'a' || max(s[i], s[i+1]) != 'c', "In group 2 substring ab and ba are forbiden");
            }
        } else if (groupId == 3) {
            ensuref(s.size() <= N_GROUP3, "In group 3 summary length of strings mustn't be greater than %d", N_GROUP3);
        } else if (groupId == 4) {
            ensuref(summarySize <= N_GROUP4, "In group 4 summary length of strings mustn't be greater than %d", N_GROUP4);
        } else if (groupId == 5) {
            ensuref(summarySize <= N_GROUP5, "In group 5 summary length of strings mustn't be greater than %d", N_GROUP5);
        } else if (groupId == 6) {
            ensuref(s.size() <= NI_GROUP6, "In group 6 length of string mustn't be greater than %d", NI_GROUP6);
        }
    }

    inf.readEof();
}