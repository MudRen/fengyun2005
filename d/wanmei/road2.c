inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "梅林之中");
        set("long", @LONG
脚下枯枝断碎，发出吱吱声。枯叶随风飘舞，盘旋落下。偶尔一两声茑叫，划
破宁静。密林深处，似有重重人影晃动。远方一幡白旗随风翻飞摆动。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"entrance_road",
  "east" : __DIR__"village",
]));
        set("outdoors", "wanmei");
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
void init()
{
	if(interactive(this_player()))
	{
		remove_call_out("dropleaf");
		call_out("dropleaf",random(10)+10,this_player());
	}
}

int dropleaf(object me)
{
	object leaf;
	if(me)
	if(environment(me) == this_object())
	{
		tell_object(me,"一片枯叶随风飘下．．．．\n");
		leaf = new(__DIR__"obj/leaf");
		leaf->move(this_object());	
	}
}
