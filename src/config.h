
/* appearance */
static const unsigned int borderpx = 0; /* border pixel of windows */
static const unsigned int gappx = 5; // 3
static const unsigned int snap = 32 * 2; /* snap pixel */
static const int showbar = 1;        /* 0 means no bar */
static const int topbar = 1;         /* 0 means bottom bar */

static const char *fonts[] = { "monospace:size=12" };
static const char dmenufont[] = "monospace:size=14";

// ghost rider border: #DB6A0B orange
/* #1771F1 #1EC9E8 #0260E8 */
static const char *colors[][3] = {
    /*                 tags      tags bg  inactive client border   */
    [SchemeNorm] = { "#BBBBBB", "#040404", "#000000" },
    /*               title     title bg    active client border    */
    [SchemeSel]  = { "#FFFFFF", "#040404", "#DB6A0B" },
    /*              active tag   active    useless                 */
    [SchemeAct]  = { "#040404", "#f2f2f2", NULL },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     *
     *  xprop | awk '/^WM_CLASS/{sub(/.* =/, "instance:"); sub(/,/, "\nclass:"); print} /^WM_NAME/{sub(/.* =/, "title:"); print}'
     */
    /* class           instance     title    tags   mask     isfloating   monitor */
    { "discord",        NULL,       NULL,   1 << 8,   0,   -1 },
    { "TelegramDesktop",NULL,       NULL,   1 << 7,   0,   -1 },
    { "TeamSpeak 3",    NULL,       NULL,   1 << 6,   0,   -1 },
    { "Google-chrome",  NULL,       NULL,   1 << 0,   0,   -1 },
    { "firefox",        NULL,       NULL,   1 << 0,   0,   -1 },
    { "Code",           NULL,       NULL,   1 << 1,   0,   -1 },
    { "bunnyblade",     NULL,       NULL,   1 << 3,   0,   -1 },
    { "krita",          NULL,       NULL,   1 << 4,   0,   -1 },
    { "vlc",            NULL,       NULL,   1 << 4,   0,   -1 },
    // { "kitty",          NULL,       NULL,   1 << 2,   0,   -1 },
};

/* ========= layout(s) ========= */

/* factor of master area size [0.05..0.95] */
static const float mfact = 0.6; 
/* number of clients in master area */
static const int nmaster = 1;    

/* 1 means respect size hints in tiled resizals */
static const int resizehints = 1; 

/* 1 will force focus on the fullscreen window */
static const int lockfullscreen = 1; 

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "", tile }, /* first entry is default */
    { "[F]", NULL }, /* no layout function means floating behavior */
    { "[M]", monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY, TAG)                                                     \
    { MODKEY, KEY, view, { .ui = 1 << TAG } },                                \
    { MODKEY | ControlMask, KEY, toggleview, { .ui = 1 << TAG } },            \
    { MODKEY | ShiftMask, KEY, tag, { .ui = 1 << TAG } },                     \
    { MODKEY | ControlMask | ShiftMask,                                       \
        KEY, toggletag, { .ui = 1 << TAG }                                    \
    },

/* ========= commands ========= */
/* component of dmenucmd, manipulated in spawn() */
static char dmenumon[2] = "0"; 
static const char *dmenucmd[] = { 
    "dmenu_run",
    "-m",  dmenumon,
    "-fn", dmenufont,
    "-nb", "#040404",
    "-nf", "#f2f2f2",
    "-sb", "#f2f2f2",
    "-sf", "#040404",
    NULL
};

static const char *termcmd[] = { "kitty", NULL };

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,             XK_p,          spawn,                 { .v = dmenucmd } },
    { MODKEY | ShiftMask, XK_Return,     spawn,                 { .v = termcmd } },
    { MODKEY | ShiftMask, XK_o,          togglebar,             { 0 }         },
    { MODKEY,             XK_j,          focusstack,            { .i = +1 }  },
    { MODKEY,             XK_k,          focusstack,            { .i = -1 }  },
    { MODKEY,             XK_i,          incnmaster,            { .i = +1 }  },
    { MODKEY,             XK_d,          incnmaster,            { .i = -1 }  },
    { MODKEY,             XK_h,          setmfact,              { .f = -0.05 } },
    { MODKEY,             XK_l,          setmfact,              { .f = +0.05 } },
    { MODKEY,             XK_Return,     zoom,                  { 0 } },
	{ MODKEY,             XK_n,          shiftview,             { .i = +1 } },
	{ MODKEY,             XK_b,          shiftview,             { .i = -1 } },
    { MODKEY,             XK_Tab,        view,                  { 0 } },
    { MODKEY | ShiftMask, XK_c,          killclient,            { 0 } },
    { MODKEY,             XK_t,          setlayout,             { .v = &layouts[0] } },
    { MODKEY,             XK_f,          setlayout,             { .v = &layouts[1] } },
    { MODKEY,             XK_m,          setlayout,             { .v = &layouts[2] } },
    /* { MODKEY,             XK_0,          view,                  { .ui = ~0 } }, */
    { MODKEY | ShiftMask, XK_0,          tag,                   { .ui = ~0 } },
    { MODKEY,             XK_comma,      focusmon,              { .i = -1 } },
    { MODKEY,             XK_period,     focusmon,              { .i = +1 } },
    { MODKEY | ShiftMask, XK_comma,      tagmon,                { .i = -1 } },
    { MODKEY | ShiftMask, XK_period,     tagmon,                { .i = +1 } },
    { MODKEY | ShiftMask, XK_q,          quit,                  { 0 } },
    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6)
    TAGKEYS(XK_8, 7)
    TAGKEYS(XK_9, 8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    { ClkWinTitle,     0,        Button2,   zoom,                    { 0 } },
    { ClkStatusText,   0,        Button1,   spawn,                   { .v = termcmd } },
    { ClkClientWin,    MODKEY,   Button1,   movemouse,               { 0 } },
    { ClkClientWin,    MODKEY,   Button2,   togglefloating,          { 0 } },
    { ClkClientWin,    MODKEY,   Button3,   resizemouse,             { 0 } },
    { ClkTagBar,       0,        Button1,   view,                    { 0 } },
    { ClkTagBar,       0,        Button3,   toggleview,              { 0 } },
    { ClkTagBar,       MODKEY,   Button1,   tag,                     { 0 } },
    { ClkTagBar,       MODKEY,   Button3,   toggletag,               { 0 } },
};
