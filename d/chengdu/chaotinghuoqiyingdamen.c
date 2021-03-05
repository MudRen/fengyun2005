// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "朝廷火器营大门");
        set("long", @LONG
火器营是专门操演火器的军队。火器营分别定时训练，除操演枪、
炮之外，并操演步射、骑射及各项技艺。这里便是火器营的大门，左边
门的门神伸出一指，嘴巴微张，像是在大声喝道：「哈」。右门的门神
则是翘起两指，彷佛发出「哼」的一声。他们就是著名的守护神「哼哈
二将」。 
LONG
        );
	set("exits",([
  		"south" : __DIR__"caochang1",
  		"northwest" : __DIR__"dongdajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}