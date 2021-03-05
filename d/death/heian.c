// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "黑暗狱");
        set("long", @LONG
这里毫无光亮，无数的囚徒将在这里呆上数十年或者更长，没有一种恐惧比黑
暗更能让人丛内心感到绝望了，所以通常这里的犯人很少，一旦进来，想出去可很
难，不过也正是这里，可以给他们一个反省的机会。往下便是刀山狱了。
LONG
        );
        set("exits", ([
		"up" : __DIR__"youguo",
		"down" : __DIR__"daoshan",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-140);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
