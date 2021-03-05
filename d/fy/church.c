inherit ROOM;

void create()
{
    set("short", "天主教堂");
    set("long", @LONG
这里的建筑别具一格，房顶特别高，成拱形，上面还有个巨大的十字架。房顶
上又有满幅的浮雕。雕的是一些金发碧眼，背生翅膀的小天使。教堂正中的十字架
上钉着一个全身是血，长发披面的塑像。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"swind2",
	"north" : __DIR__"chjian",
      ]));
    set("objects", ([
	__DIR__"npc/priest" : 1,
      ]) );

    set("no_fight",1);
    set("no_magic",1);
    set("NONPC",1);
    set("valid_startroom",1);
    set("coor/x",20);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}

