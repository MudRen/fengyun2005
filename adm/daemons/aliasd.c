// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// aliasd.c

string process_global_alias(string arg); // Alias转化

mapping global_alias = ([
	"l":	"look",
	"n":	"go north",
	"e":	"go east",
	"w":	"go west",
	"s":	"go south",
	"nu":	"go northup",
	"eu":	"go eastup",
	"wu":	"go westup",
	"su":	"go southup",
	"nd":	"go northdown",
	"ed":	"go eastdown",
	"wd":	"go westdown",
	"sd":	"go southdown",
	"ne":	"go northeast",
	"se":	"go southeast",
	"nw":	"go northwest",
	"sw":	"go southwest",
	"u":	"go up",
	"d":	"go down",
	"north":	"go north",
	"east":		"go east",
	"west":		"go west",
	"south":	"go south",
	"northup":	"go northup",
	"eastup":	"go eastup",
	"westup":	"go westup",
	"southup":	"go southup",
	"northdown":	"go northdown",
	"eastdown":	"go eastdown",
	"westdown":	"go westdown",
	"southdown":	"go southdown",
	"northeast":	"go northeast",
	"southeast":	"go southeast",
	"northwest":	"go northwest",
	"southwest":	"go southwest",
	"up":		"go up",
	"down":		"go down",
	"i":	"inventory",
	"bt":	"bangtalk",
        "bt*":  "bangtalk*",
	"tt":	"teamtalk",
        "tt*":  "teamtalk*",
	"ot":   "orgtalk",
	"ot*": "orgtalk*",
]);

string process_global_alias(string arg)
{
	string *word;

	if (arg[0]=='\'') return "say " + arg[1..strlen(arg)-1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}
