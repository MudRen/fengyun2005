// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "凌云麓");
    set("long", @LONG
凌云麓山势错落，峰石峥嵘，峭壁险突，岭脊两旁是深壑千仞，陡峭一如
绝壁，罡风吹拂之下，令人胆颤心惊。前朝萧小初游遍天下群山，曾为凌云麓
题字「险奇天下」，又有诗云：凌云崔嵬侧，暗暮鸟低徊。放歌星远落，拔剑
气高冲。
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westdown" : "path5",
  		"northup" : "peak2",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",70);
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


