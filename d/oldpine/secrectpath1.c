// Room: /d/oldpine/secrectpath1.c

inherit ROOM;

void create()
{
        set("short", "秘密通道");
        set("long", @LONG
你现在正站在一个岩石通道之中，从南边隐隐传来哗哗的水声，岩壁上生著厚
厚的青苔，一股恶臭从北边传来，像是什麽野兽，也许你该回头出去了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"passage",
	]));

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
