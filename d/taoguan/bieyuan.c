#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
        set("short", "三清别院");
        set("long", @LONG
三清别院建于明万历年间，有殿堂、道舍二十余间，形成一个精巧的小院。此
处翠竹成林，涧溪流水，被誉三清山十二景的“蔚竹鸣泉”。这里是丁氏兄妹出家
前静修之处，现在改为访客上香之人的憩所。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast" : __DIR__"stoneroad2",
       	]));
       	set("objects", ([
		__DIR__"npc/dingyunhe" : 1,
 	]) );
        set("outdoors", "taoguan");
     	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
