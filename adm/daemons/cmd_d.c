// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// cmd_d.c
//
// By Annihilator (11/07/94)

mapping search = ([]);

void rehash(string dir)
{
	int i;
	string *cmds;

	if( dir[sizeof(dir)-1]!='/' ) dir += "/";
	cmds = get_dir(dir);
	i = sizeof(cmds);
	while(i--)
		if( !sscanf(cmds[i], "%s.c", cmds[i]) ) {
			if( i==0 ) cmds = cmds[1..sizeof(cmds)];
			else if( i==sizeof(cmds) ) cmds = cmds[0..<2];
			else cmds = cmds[0..i-1] + cmds[i+1..<1];
		}
	if( sizeof(cmds) )
		search[dir] = cmds;
}

string find_command(string verb, string *path)
{
	int i;

	if(!pointerp(path)) return 0;

	i = sizeof(path);
	while(i--) {
		if( undefinedp(search[path[i]]) ) rehash(path[i]);
		if( undefinedp(search[path[i]]) ) continue;
		if( member_array(verb, search[path[i]])!=-1 )
			return path[i] + verb;
	}
	if(!stringp(query_notify_fail())) {
		notify_fail("什么？\n");
	}
	return 0;
}