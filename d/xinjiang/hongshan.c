/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "红山");
        set("long", @LONG
红山因山呈红褐色得名，山不是很高，也不是很雄伟，但还是很有名。山顶有
一塔，称“镇龙塔”。从这里向乌拉泊方向眺望，高大的城门和城里袅袅的炊烟尽
收眼底。
LONG
        );
        set("exits", ([ 
  		"up" : __DIR__"zhenlong",
  		"southdown" : __DIR__"tulu",
	]));

        set("objects", ([
			__DIR__"npc/hong" : 1,
	]) );

	
        set("outdoors", "xinjiang");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
