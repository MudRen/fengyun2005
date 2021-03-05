inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "卧房");
        set("long", @LONG
这是万马堂内堂总管公孙断的屋子。屋里虽显得有些凌乱，但却宽大而舒适，
墙上排满了光泽鲜艳的兽皮，桌上摆满了各种香醇的美酒，在寂寞的晚上只要他愿
意，就有人会从镇上为他将女人送来。这是他应得的享受。因为他流的血和汗都已
够多。
LONG
        );
        set("exits", ([ 
	"west": __DIR__"corridor2",
	]));
        set("objects", ([
	]) );
        set("coor/x",10);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
