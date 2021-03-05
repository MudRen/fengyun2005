#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","小屋");
  set("long",@LONG
你终于离开了诡异的镜中世界，跌进了这间七坪大小的小屋。干干净净仿佛一
尘不染的屋中没有任何摆设，一角竖着的直梯显得分外醒目。从直梯所立着的方洞
中下望，可以清晰的见到岱庙后寝殿神龛中的东岳大帝像。
LONG
  );
  	set("exits",([
       	 "down":__DIR__"houqing",
        ]));
	set("objects", ([
			  __DIR__"npc/feng":	1,
	]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",20);
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

