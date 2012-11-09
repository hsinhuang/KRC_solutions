#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	printf("in limits.h:\n");
	printf("signed char:\t%13d\t%13d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char:\t%13u\t%13u\n", 0, UCHAR_MAX);
	printf("signed short:\t%13d\t%13d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short:\t%13u\t%13u\n", 0, USHRT_MAX);
	printf("signed int:\t%13d\t%13d\n", INT_MIN, INT_MAX);
	printf("unsigned int:\t%13u\t%13u\n", 0, UINT_MAX);
	printf("signed long:\t%13ld\t%13ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long:\t%13lu\t%13lu\n", 0L, ULONG_MAX);

	printf("\n======\n");

	printf("calculate by myself:\n");

	signed char sc = 0, sc_min = 0, sc_max = 0;
	unsigned char uc = 0, uc_min = 0, uc_max = 0;
	signed short ss = 0, ss_min = 0, ss_max = 0;
	unsigned short us = 0, us_min = 0, us_max = 0;
	signed int si = 0, si_min = 0, si_max = 0;
	unsigned int ui = 0, ui_min = 0, ui_max = 0;
	signed long sl = 0, sl_min = 0, sl_max = 0;
	unsigned long ul = 0, ul_min = 0, ul_max = 0;
	while(++sc != 0){
		if(sc > sc_max)
			sc_max = sc;
		if(sc < sc_min)
			sc_min = sc;
	}
	printf("signed char:\t%13d\t%13d\n", sc_min, sc_max);
	while(++uc != 0){
		if(uc > uc_max)
			uc_max = uc;
		if(uc < uc_min)
			uc_min = uc;
	}
	printf("unsigned char:\t%13u\t%13u\n", uc_min, uc_max);
	while(++ss != 0){
		if(ss > ss_max)
			ss_max = ss;
		if(ss < ss_min)
			ss_min = ss;
	}
	printf("signed short:\t%13d\t%13d\n", ss_min, ss_max);
	while(++us != 0){
		if(us > us_max)
			us_max = us;
		if(us < us_min)
			us_min = us;
	}
	printf("unsigned short:\t%13u\t%13u\n", us_min, us_max);

	printf("Warning: it may take __long__ time to calculate the rest values\n");
ask:
	printf("Continue? [Y/n] ");
	switch(getchar()){
		case 'Y':
		case 'y':
			getchar();
			goto rest;
		case 'N':
		case 'n':
			getchar();
			return 0;
		default:
			getchar();
			printf("Sorry, I don't understand your mind.\n");
			goto ask;
	}
rest:
	while(++si != 0){
		if(si > si_max)
			si_max = si;
		if(si < si_min)
			si_min = si;
	}
	printf("signed int:\t%13d\t%13d\n", si_min, si_max);
	while(++ui != 0){
		if(ui > ui_max)
			ui_max = ui;
		if(ui < ui_min)
			ui_min = ui;
	}
	printf("unsigned int:\t%13u\t%13u\n", ui_min, ui_max);
	while(++sl != 0){
		if(sl > sl_max)
			sl_max = sl;
		if(sl < sl_min)
			sl_min = sl;
	}
	printf("signed long:\t%13ld\t%13ld\n", sl_min, sl_max);
	while(++ul != 0){
		if(ul > ul_max)
			ul_max = ul;
		if(ul < ul_min)
			ul_min = ul;
	}
	printf("unsigned long:\t%13lu\t%13lu\n", ul_min, ul_max);
	
	return 0;
}