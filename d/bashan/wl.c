
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIG"舞柳阁"NOR);
    set("long", @LONG
回风山庄既名山庄，自然建在山上。山势渐抬，沿着山庄中道路上行，不远处
就是小小飞阁，题号舞柳。有道长江后浪逐前浪，顾道人虽以侠义之心名动天下，
却耐不过岁月相催。今天即是顾道人封剑退隐之日，武林中各门各派都有人来观礼
以示崇敬，小小的舞柳阁上熙熙攘攘挤满了人，分外热闹。
LONG
    );
    set("exits",([
	"northdown" : __DIR__"hf",
      ]) );
    set("objects", ([
	__DIR__"npc/man1" : 1,
	__DIR__"npc/man2" : 1,
	__DIR__"npc/blademaster" : 1,
	__DIR__"npc/man3" : 1,
	__DIR__"npc/man4" : 1,
	__DIR__"npc/stormeye" : 1,
	__DIR__"npc/man5" : 1,
	__DIR__"npc/app2" : 1,
	__DIR__"npc/gu" : 1,
      ]));

    set("no_fly",1);
    set("coor/x",20);
    set("coor/y",-20);
    set("coor/z",20);
    setup();
}


/*

//update /d/bashan/npc/man1;update here;l
　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


