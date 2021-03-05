// Room: /d/oldpine/npath1.c

inherit ROOM;

void create()
{
        set("short", "林间小路");
        set("long", @LONG
你现在正走在一条林间的小路，往西不远处走出这座林子就是梦仙龛，小路两
旁长满了许多高耸的松树，周围的居民都把这里叫做「老松林」，据说林子里有株
树龄上千的老松树，颇有灵验。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"npath2",
  "west" : AREA_TAISHAN"mengxian",
]));
        set("outdoors", "oldpine");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
