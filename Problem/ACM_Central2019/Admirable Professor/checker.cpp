// default_validator from kattis problemtools package
// licensed under MIT license
//
// modified: float comparison
#include <bits/stdc++.h>

using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

ifstream judgein, judgeans;
FILE *judgemessage = NULL;
FILE *diffpos = NULL;
int judgeans_pos, stdin_pos;
int judgeans_line, stdin_line;
int option_arg;

/* The floating point type we use internally: */
typedef long double flt;
typedef long long ll;

void wrong_answer(const char *err, ...) {
	va_list pvar;
	va_start(pvar, err);
	fprintf(judgemessage, "Wrong answer on line %d of output (corresponding to line %d in answer file)\n",
			stdin_line, judgeans_line);
	vfprintf(judgemessage, err, pvar);
	fprintf(judgemessage, "\n");
	if (diffpos) {
		fprintf(diffpos, "%d %d", judgeans_pos, stdin_pos);
	}
	exit(EXIT_WA);
}

void judge_error(const char *err, ...) {
	va_list pvar;
	va_start(pvar, err);
	// If judgemessage hasn't been set up yet, write error to stderr
	if (!judgemessage) judgemessage = stderr;
	vfprintf(judgemessage, err, pvar);
	fprintf(judgemessage, "\n");
	assert(!"Judge Error");
}

bool isfloat(const char *s, flt &val) {
	char trash[20];
	flt v;
	if (sscanf(s, "%Lf%10s", &v, trash) != 1) return false;
	val = v;
	return true;
}

bool isint(const char *s, ll &val) {
	char trash[20];
	ll v;
	if (sscanf(s, "%lld%10s", &v, trash) != 1) return false;
	val = v;
	return true;
}

template <typename Stream>
void openfile(Stream &stream, const char *file, const char *whoami) {
	stream.open(file);
	if (stream.fail()) {
		judge_error("%s: failed to open %s\n", whoami, file);
	}
}

FILE *openfeedback(const char *feedbackdir, const char *feedback, const char *whoami) {
	string path = string(feedbackdir) + "/" + string(feedback);
	FILE *res = fopen(path.c_str(), "w");
	if (!res) {
		judge_error("%s: failed to open %s for writing", whoami, path.c_str());
	}
	return res;
}

/* Test two numbers for equality, accounting for +/-INF, NaN and
 * precision. Float f2 is considered the reference value for relative
 * error.
 */
int equal(flt f1, flt f2, flt float_abs_tol, flt float_rel_tol)
{
	flt absdiff, reldiff;
	/* Finite values are compared with some tolerance */
	if ( isfinite(f1) && isfinite(f2) ) {
		absdiff = fabsl(f1-f2);
		reldiff = fabsl((f1-f2)/f2);
		return !(absdiff > float_abs_tol && reldiff > float_rel_tol);
	}
	/* NaN is equal to NaN */
	if ( isnan(f1) && isnan(f2) ) return 1;
	/* Infinite values are equal if their sign matches */
	if ( isinf(f1) && isinf(f2) ) {
		return signbit(f1) == signbit(f2);
	}
	/* Values in different classes are always different. */
	return 0;
}

const char *USAGE = "Usage: %s judge_in judge_ans feedback_dir [options] < team_out";

// argument analyzing for testing on local
void test_local(int argc, char **argv)
{
    option_arg = 5;
    if(argc < option_arg) {
		judge_error(USAGE, argv[0]);
	}
	judgemessage = openfeedback(argv[3], ("judgemessage" + string(argv[4]) + ".txt").c_str(), argv[0]);
	diffpos = openfeedback(argv[3], ("diffposition" + string(argv[4]) + ".txt").c_str(), argv[0]);
	openfile(judgein, argv[1], argv[0]);
	openfile(judgeans, argv[2], argv[0]);
}

// argument analyzing for testing on server
void test_OJ(int argc, char **argv)
{
    option_arg = 4;
    if(argc < option_arg) {
		judge_error(USAGE, argv[0]);
	}
	judgemessage = openfeedback(argv[3], "judgemessage.txt", argv[0]);
	diffpos = openfeedback(argv[3], "diffposition.txt", argv[0]);
	openfile(judgein, argv[1], argv[0]);
	openfile(judgeans, argv[2], argv[0]);
}

int main(int argc, char **argv) {

    // test_local(argc, argv);
    test_OJ(argc, argv);

    // default checker of DOMjudge
	/*bool case_sensitive = false;
	bool space_change_sensitive = false;
	bool use_floats = false;
	flt float_abs_tol = -1;
	flt float_rel_tol = -1;

	for (int a = option_arg; a < argc; ++a) {
		if (!strcmp(argv[a], "case_sensitive")) {
			case_sensitive = true;
		} else if (!strcmp(argv[a], "space_change_sensitive")) {
			space_change_sensitive = true;
		} else if (!strcmp(argv[a], "float_absolute_tolerance")) {
			if (a+1 == argc || !isfloat(argv[a+1], float_abs_tol))
				judge_error(USAGE, argv[0]);
			++a;
		} else if (!strcmp(argv[a], "float_relative_tolerance")) {
			if (a+1 == argc || !isfloat(argv[a+1], float_rel_tol))
				judge_error(USAGE, argv[0]);
			++a;
		} else if (!strcmp(argv[a], "float_tolerance")) {
			if (a+1 == argc || !isfloat(argv[a+1], float_rel_tol))
				judge_error(USAGE, argv[0]);
			float_abs_tol = float_rel_tol;
			++a;
		} else {
			judge_error(USAGE, argv[0]);
		}
	}
	use_floats = float_abs_tol >= 0 || float_rel_tol >= 0;

	judgeans_pos = stdin_pos;
	judgeans_line = stdin_line = 1;

	string judge, team;

	// please don't change anything above this line
	//---------------------------------------------------------------------------------------------------------
	while (true) {
		// Space!  Can't live with it, can't live without it...
		// it means when we get a space in judge_ans
		while (isspace(judgeans.peek())) {
			char c = (char)judgeans.get();
			// too sensitive space change token
			if (space_change_sensitive) {
				int d = cin.get();
				if (c != d) {
					wrong_answer("Space change error: got %d expected %d", d, c);
				}
				if (d == '\n') ++stdin_line;
				++stdin_pos;
			}
			if (c == '\n') ++judgeans_line;
			++judgeans_pos;
		}
		while (isspace(cin.peek())) {
			char d = (char)cin.get();
			if (space_change_sensitive) {
				wrong_answer("Space change error: judge out of space, got %d from team", d);
			}
			if (d == '\n') ++stdin_line;
			++stdin_pos;
		}

		if (!(judgeans >> judge))
			break;

		if (!(cin >> team)) {
			wrong_answer("User EOF while judge had more output\n(Next judge token: %s)", judge.c_str());
		}

        // compare checker works from here
        // ----------------------------------------------------------------------------------------------------------------
		flt jval, tval;
		if (use_floats && isfloat(judge.c_str(), jval)) {
			if (!isfloat(team.c_str(), tval)) {
				wrong_answer("Expected float, got: %s", team.c_str());
			}
			if (!equal(tval, jval, float_abs_tol, float_rel_tol)) {
				wrong_answer("Too large difference.\n Judge: %s\n Team: %s\n Difference: %Lg\n (abs tol %Lg rel tol %Lg)",
							 judge.c_str(), team.c_str(), fabsl(jval-tval), float_abs_tol, float_rel_tol);
			}
		} else if (case_sensitive) {
			if (strcmp(judge.c_str(), team.c_str()) != 0) {
				wrong_answer("String tokens mismatch\nJudge: \"%s\"\nTeam: \"%s\"", judge.c_str(), team.c_str());
			}
		} else {
			if(strcasecmp(judge.c_str(), team.c_str()) != 0) {
				wrong_answer("String tokens mismatch\nJudge: \"%s\"\nTeam: \"%s\"", judge.c_str(), team.c_str());
			}
		}
		judgeans_pos += judge.length();
		stdin_pos += team.length();
	}*/

	int n, g;
    judgein >> n >> g;
    int m = n * g;

    vector<int> v1, v2;
    for (int i = 1; i <= m; i++) {
        int x;
        judgein >> x;
        v1.push_back(x);
    }

    vector<int> outNums;
    
	string team;

	judgeans_line = stdin_line = 1;

	for (judgeans_line = 0; judgeans_line <= v1.size(); judgeans_line++) {
        // if (isspace(cin.peek())) {
        //     wrong_answer("Trailing spaces in output");
        // }
        if (!(cin >> team)) {
			wrong_answer("Missing output\n");
		}
		ll res;
		if (!isint(team.c_str(), res)) {
            wrong_answer("Expected integer, got: %s", team.c_str());
		}
		outNums.push_back(res);
		// ll answer = getAnswer(a[judgeans_line]);
		// if (answer != res) {
  //           wrong_answer("Too different\nTeam answer: %lld\nExpected: %lld", res, answer);
		// }
		bool redundant_char = true;
		while (isspace(cin.peek())) {
            char c = cin.get();
            if (c == '\n') {
                redundant_char = false;
                break;
            }
		}
		// if (redundant_char && cin >> team && judgeans_line % n == 0) {
  //           wrong_answer("Judge EOLN while user had more output, %s", team.c_str());
		// }
		stdin_line++;
	}


	if (cin >> team) {
		wrong_answer("Trailing output:\n%s", team.c_str());
	}

	int res;
    int outRes;
    int sum = 0;
    ll val = 0;

    if (!(judgeans >> res)) {
    	wrong_answer("Missing ans file\n");
    }
    
    if (outNums[0] != res) {
    	wrong_answer("Too different\nTeam answer: %d\nExpected: %d", outNums[0], res);
    }

    for (int i = 1; i <= m; i++) {
    	int x = outNums[i];
        if (i % n == 1) {
            val += sum;
            sum = x % n;
        }
        else {
            sum = (sum + x) % n;
        }
        v2.push_back(x);
    }
    val += sum;

    if (res != val) {
    	wrong_answer("Your division does not give the result %d, it gives %d \n", res, val);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    assert(v1.size() == v2.size());
    
    for (int i = 0; i < v1.size(); i++) {
    	if (v1[i] != v2[i]) {
    		wrong_answer("Your division misses balloon %d\n", v1[i]);
    	}
    }

	exit(EXIT_AC);
}
