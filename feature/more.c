// more.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

#include <ansi.h>
#define DISPLAY_LINES 40

void more(string cmd, string *text, int line)
{
	int i/*,j*/;

	switch( cmd ) {
		case "q":
		case "Q":
			return;
/* showing previous page is disabled here.
		case "b":
		case "B":
			line = line-DISPLAY_LINES-DISPLAY_LINES;
			if( line < -DISPLAY_LINES) {
				return;
			}
			for( i = line+DISPLAY_LINES; line < i; line++ ) {
				write(text[line]+"\n");
			}
			break;
*/
		case "":
		default:
			for( i = line+DISPLAY_LINES; line < sizeof(text) && line < i; line++ ) {
				write(text[line] + "\n");
			}
			if( line >= sizeof(text) ) {
				return;
			}
			break;
	}
	printf("== 未完继续 " HIY "%d%%" NOR " == (ENTER 继续下一页，q 离开)", line*100/sizeof(text));
	input_to("more", text, line);
}

void start_more(string cmd, string msg, int offset)
{
	if ( !msg || strlen(msg) <= 0 ) {
		return;
	}

	more(cmd, explode(msg, "\n"), 0);
}