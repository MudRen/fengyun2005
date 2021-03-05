// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "油锅狱");
        set("long", @LONG
这里是最常听闻的油锅狱，所谓“战战兢兢，悲悲切切，皆因强暴欺良善，藏
头缩颈苦伶仃”说得便是这里。在牛头，马面的驱赶下，犯人一个个得走进油锅，
被炸的骨焦肉烂，随后立刻被复原，一次一次，过往囚犯的诚惶诚恐之色让你暗叹
地狱法度之严。下面一层不闻人声，亦无亮光，不知道又会是什么。
LONG
        );
        set("exits", ([
		"up" : __DIR__"chouchang",
		"down" : __DIR__"heian",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-130);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
