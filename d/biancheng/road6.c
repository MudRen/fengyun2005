inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "西街");
        set("long", @LONG
再往西走，街道变得泥泞起来，楼房换成了破陋的木屋，街道两旁的门窗，有
的关着，却都已残破败坏。小镇突然换了个面具，前面的繁华太平似乎只是一种假
象，是用来吸引客商的半老徐娘的胭脂粉饰。
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"road5",
	"northwest": __DIR__"temple",
	"north": __DIR__"paifang",	
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
