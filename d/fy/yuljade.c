inherit ROOM;
void create()
{
    set("short", "玉龙珠宝店");
    set("long", @LONG
珠宝店的正中是条千年古玉雕成的祥龙，玉龙活灵活现，穿梭于祥云之中。龙
嘴中含玉球，玉球有拳头大小，翠绿欲滴。龙眼半睁半闭。四周的墙上挂满了各种
金玉制品和各种护身吉祥玉器。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"swind2",
      ]));
    set("objects", ([
	__DIR__"npc/jadeowner" : 1,
      ]) );

    set("coor/x",-20);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
