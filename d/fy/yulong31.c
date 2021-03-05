inherit ROOM;
void create()
{
    set("short", "鱼龙小巷");
    set("long", @LONG
鱼龙小巷地处东城，地如其名，鱼龙混杂，地头蛇结党成群，而据说也有不少
世外高人隐居于此。巷子里到处都是嘈杂的叫卖声，此起彼伏的吆喝声，和一些很
古怪的声音，甚至还有打斗刀械碰撞的声响；而整条街上更是飘荡着各式各样的味
道，香的，臭的，说得出的，说不出的。。。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"stone1",
	"east" : __DIR__"futhur",
	"south" : __DIR__"yulong3",
	"northwest" : __DIR__"lssquare3",
      ]));
    set("objects", ([
	//        __DIR__"npc/wanfan" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
