#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"环天街"NOR);
    set("long", @LONG
环天街环紫禁城而建，一条清澈宛如玉带般的城河静静地流淌，四下一片肃穆，
偶尔的三两行人也神色紧张，快步而行，甚至连四下张望都小心谨慎，甚怕一个不
留意，被专横跋扈，冷血嗜杀的宫中厂卫撞见，大多可没什么好下场。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"huantian3",
	"northwest" : __DIR__"nwind5",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",50);
    set("coor/y",240);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    //	replace_program(ROOM);
}


/*
void init() {
	  add_action("do_dazuo","dazuo");
	}

int do_dazuo(string arg) {
	object me;
	me=this_player();
	tell_object(me,"此地不能打坐。\n");
	return 1;
}*/

