
inherit ROOM;

void create()
{
        set("short", "寺院");
        set("long", @LONG
壮丽的寺院，光线却十分阴森幽暗。数千只巨烛和用牛油作燃料的青铜灯在风
中闪动着神秘的火焰。高耸的寺墙上画着无数的神龛，供奉着面目狰狞的巨人七色
像，在闪动的烛光中，更显得鬼秘可怖。
LONG
        );

        set("exits", ([ 
		"south" : __DIR__"tower",
	]));
        set("outdoors", "guanwai");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
