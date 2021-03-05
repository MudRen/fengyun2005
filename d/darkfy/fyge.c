// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "风云阁");
	set("long", @LONG
风云阁的主人就是当今天下侠名鼎鼎的小李飞刀。李探花长年行侠在外，但还是
有很多客人慕名来到此阁，以求一面之缘。阁中大红波斯地毯铺地，富丽堂煌。朱红
的大门两侧各挂一幅石刻的对联儿：
[33m
                	一门七进士，
                	父子三探花。
[37m
LONG
	);
	set("valid_startroom", 1);
	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
		"west"    	: __DIR__"nwind1",
		"up"		: __DIR__"fyyage",
	]) );

	set("objects", ([
		__DIR__"npc/" : 1,

			]) );

	set("coor/x",10);
	set("coor/y",10);
        set("coor/z",-300);
	setup();

	// To "load" the board, don't ever "clone" a bulletin board.
	call_other( "/obj/board/common_fy", "???" );
}

string look_sign(object me)
{
	if( wizardp(me) )
		return "招牌写著：风云阁。旁边一排小字：阿铁题。\n";
	else
		return "招牌写著：风云阁。旁边刻着一排小字：屠神到此一游。\n";
}
