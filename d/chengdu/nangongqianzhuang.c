// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "南宫钱庄");
        set("long", @LONG
中原南宫世家，家财万贯，产业不可胜数。此间钱庄黑匾红字，正是南宫
产业之一。南宫钱庄的银票信誉极好，大江南北都可兑现。就是富可敌国的金钱
帮，也难望其项背。钱庄中央有一红木柜台，半人多高，上有牌（ｓｉｇｎ）一块。
LONG
        );
	set("exits",([
  		"west" : __DIR__"nandajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}