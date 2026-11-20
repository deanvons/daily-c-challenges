/*
 * printf_demo.c - one example of every printf formatting option.
 *
 * Build & run:
 *   gcc -Wall -std=c11 printf_demo.c -o printf_demo.exe
 *   .\printf_demo.exe
 *
 * Square brackets [ ] are printed around each result so padding is visible.
 */
#include <stdio.h>
#include <stddef.h>   /* size_t, ptrdiff_t */
#include <stdint.h>   /* intmax_t, int64_t */
#include <inttypes.h> /* PRId64 etc. */
#include <wchar.h>    /* wchar_t */

int main(void)
{
    int    n  = 42;
    int    neg = -42;
    double pi = 3.14159265;

    /* ===================== SPECIFIERS ===================== */
    printf("===== Specifiers =====\n");
    printf("%%d   -> [%d]\n", neg);              /* signed decimal          */
    printf("%%i   -> [%i]\n", neg);              /* same as %d for printf   */
    printf("%%u   -> [%u]\n", 42u);              /* unsigned decimal        */
    printf("%%o   -> [%o]\n", 8);                /* octal                   */
    printf("%%x   -> [%x]\n", 255);              /* hex, lowercase          */
    printf("%%X   -> [%X]\n", 255);              /* hex, uppercase          */
    printf("%%f   -> [%f]\n", pi);               /* fixed-point, 6 decimals */
    printf("%%F   -> [%F]\n", 1.0 / 0.0);        /* like %f, but INF/NAN uppercase */
    printf("%%e   -> [%e]\n", 1234.5);           /* scientific, lowercase e */
    printf("%%E   -> [%E]\n", 1234.5);           /* scientific, uppercase E */
    printf("%%g   -> [%g]\n", 1234.5);           /* shortest of %f / %e     */
    printf("%%g   -> [%g]  (big number switches to %%e)\n", 1234567890.0);
    printf("%%G   -> [%G]\n", 0.00000123);       /* like %g, uppercase E    */
    printf("%%a   -> [%a]\n", 1.0);              /* hex float, lowercase    */
    printf("%%A   -> [%A]\n", 1.0);              /* hex float, uppercase    */
    printf("%%c   -> [%c]\n", 'A');              /* character               */
    printf("%%s   -> [%s]\n", "hello");          /* string                  */
    printf("%%p   -> [%p]\n", (void *)&n);       /* pointer (cast to void*) */
    printf("%%%%   -> [%%]\n");                  /* literal percent sign    */

    /* %n: writes the count of characters printed so far into an int.
       Disabled by default in Microsoft's runtime; shown here for completeness. */
    int count = 0;
    printf("12345%n", &count);
    printf("  <- %%n stored %d\n", count);

    /* ======================= FLAGS ======================== */
    printf("\n===== Flags =====\n");
    printf("%%-6d  -> [%-6d]  left-align\n", n);
    printf("%%6d   -> [%6d]  right-align (default)\n", n);
    printf("%%+d   -> [%+d]     always show sign\n", n);
    printf("%%+d   -> [%+d]     (negative)\n", neg);
    printf("%% d   -> [% d]     space instead of +\n", n);
    printf("%%06d  -> [%06d]  zero-pad\n", n);
    printf("%%#x   -> [%#x]   0x prefix\n", 255);
    printf("%%#X   -> [%#X]   0X prefix\n", 255);
    printf("%%#o   -> [%#o]    leading 0 for octal\n", 8);
    printf("%%#.0f -> [%#.0f]     keeps the decimal point\n", 3.0);
    printf("%%.0f  -> [%.0f]      (without #)\n", 3.0);
    printf("%%#g   -> [%#g] keeps trailing zeros\n", 1.5);
    printf("%%g    -> [%g]      (without #)\n", 1.5);
    printf("%%-+8.2f -> [%-+8.2f] flags combined\n", pi);

    /* ======================= WIDTH ======================== */
    printf("\n===== Width =====\n");
    printf("%%8s   -> [%8s]\n", "hi");
    printf("%%-8s  -> [%-8s]\n", "hi");
    printf("%%8d   -> [%8d]\n", n);
    printf("%%*d   -> [%*d]  width 8 passed as an argument\n", 8, n);
    printf("%%-*d  -> [%-*d]  negative-style: left-aligned via flag\n", 8, n);
    printf("%%2d   -> [%2d]  width too small: never truncates\n", 12345);

    /* ===================== PRECISION ====================== */
    printf("\n===== Precision =====\n");
    printf("%%.2f  -> [%.2f]       decimals for %%f\n", pi);
    printf("%%.0f  -> [%.0f]          rounds to integer\n", 2.5);
    printf("%%.3e  -> [%.3e]  decimals for %%e\n", 1234.5);
    printf("%%.3g  -> [%.3g]       significant digits for %%g\n", pi);
    printf("%%.5d  -> [%.5d]    minimum digits for ints\n", n);
    printf("%%.3s  -> [%.3s]        max chars for strings\n", "hello");
    printf("%%.*f  -> [%.*f]      precision 3 passed as an argument\n", 3, pi);
    printf("%%10.3f -> [%10.3f] width + precision\n", pi);
    printf("%%*.*f -> [%*.*f] both passed as arguments\n", 10, 2, pi);

    /* ================== LENGTH MODIFIERS ================== */
    printf("\n===== Length modifiers =====\n");
    signed char        sc  = -5;
    unsigned char      uc  = 250;
    short              sh  = -30000;
    unsigned short     ush = 60000;
    long               l   = -2000000000L;
    unsigned long      ul  = 4000000000UL;
    long long          ll  = -9000000000000000000LL;
    unsigned long long ull = 18000000000000000000ULL;
    intmax_t           im  = -123456789;
    uintmax_t          uim = 123456789;
    size_t             sz  = sizeof(double);
    int arr[10];
    ptrdiff_t          pd  = &arr[7] - &arr[2];
    long double        ld  = 3.14159265358979323846L;
    wchar_t            wc  = L'W';
    const wchar_t     *ws  = L"wide";
    int64_t            i64 = -1234567890123LL;

    printf("%%hhd  -> [%hhd]\n", sc);
    printf("%%hhu  -> [%hhu]\n", uc);
    printf("%%hd   -> [%hd]\n", sh);
    printf("%%hu   -> [%hu]\n", ush);
    printf("%%ld   -> [%ld]\n", l);
    printf("%%lu   -> [%lu]\n", ul);
    printf("%%lld  -> [%lld]\n", ll);
    printf("%%llu  -> [%llu]\n", ull);
    printf("%%llx  -> [%llx]\n", ull);
    printf("%%jd   -> [%jd]\n", im);
    printf("%%ju   -> [%ju]\n", uim);
    printf("%%zu   -> [%zu]  sizeof(double)\n", sz);
    printf("%%td   -> [%td]  pointer difference\n", pd);
    printf("%%Lf   -> [%Lf]\n", ld);
    printf("%%lf   -> [%lf]  same as %%f for double\n", pi);
    printf("%%lc   -> [%lc]\n", (wint_t)wc);
    printf("%%ls   -> [%ls]\n", ws);
    printf("PRId64 -> [%" PRId64 "]\n", i64);

    /* ================== ESCAPE SEQUENCES ================== */
    printf("\n===== Escape sequences =====\n");
    printf("\\n   -> line one\nline two\n");
    printf("\\t   -> [a\tb]\n");
    printf("\\\\   -> [\\]\n");
    printf("\\\"   -> [\"]\n");
    printf("\\'   -> [\']\n");
    printf("\\r   -> on the next line, YY overwrites the start of XXXXX:\n");
    printf("XXXXX\rYY\n");
    printf("\\b   -> [abc\bd]  (backspace: d overwrites c)\n");
    printf("\\x41 -> [\x41]\n");
    printf("\\101 -> [\101]  (octal 101 = 'A')\n");
    char hidden[] = "abc\0this is never printed";
    printf("\\0   -> [%s]  %%s stops at the first \\0\n", hidden);
    printf("\\a   -> [\a]  (beep, if your terminal supports it)\n");

    return 0;
}
