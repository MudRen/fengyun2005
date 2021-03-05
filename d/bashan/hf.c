
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", YEL"回风山庄"NOR);
    set("long", @LONG
距离小巴山古佛窟只不过百尺之遥，坐落着一座与古佛窟齐名的庭院。庭院看
上去与百姓人家并没有什么差别，却是武林中一处圣地，因为它就是回风山庄，而
回风山庄的庄主，就是二十年前以一手回风拂柳剑法名动江湖，三月内挑破西北十
八座山寨的顾道人，巴山剑客顾剪秋。
LONG
    );
    set("exits",([
	"southup" : __DIR__"wl",
	"northdown" : "/d/xiangsi/jieyu",
      ]) );
    set("objects", ([
	__DIR__"npc/hfguard1" : 1,
	__DIR__"npc/hfguard2" : 1,
      ]));

    set("no_fly",1);
    set("coor/x",20);
    set("coor/y",-10);
    set("coor/z",10);
    setup();
}


/*

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

