// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","山坡顶");
  set("long",@LONG
这里视野顿然开阔，数万金军和宋军在眼前的一块平原上混战。呐喊声，金军
的胡号和宋军的战鼓交杂，震耳欲聋。一位银盔银甲，顶梁飘撒红缨的中年将军正
关注着这眼前的战局。
LONG
  );
	set("exits",([
		"northdown" : __DIR__"shanpo",
    ]));
	set("objects", ([
		__DIR__"npc/yue" : 1,
	]));
//    set("valid_startroom",1);
    set("outdoors", "dreamland");
	set("no_fight", 1);
	set("no_magic", 1);
	setup();
}
