/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Terminus-8",
	"DejaVu Sans Mono",
	"MS Gothic",
	"NSimSun",
	"Fixed"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *normbgcolor = "#121212"; /* -nb option; normal background                 */
static const char *normfgcolor = "#facb70"; /* -nf option; normal foreground                 */
static const char *selbgcolor  = "#373b41"; /* -sb option; selected background               */
static const char *selfgcolor  = "#ffffff"; /* -sf option; selected foreground               */
static const char *outbgcolor  = "#d5d9d6";
static const char *outfgcolor  = "#121212";
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " -_";
