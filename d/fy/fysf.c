
inherit ROOM;

void create()
{
    object con,item;
    set("short", "风云书房");
    set("long", @LONG
这间书房是李探花偶而回来小憩时读书之处。屋子布置的精致富丽，正中一张
青玉案，案上两只[33m白玉瓶[32m，瓶里插着几十枝茶花。玉瓶旁铺着几张信筏，放着些笔
墨砚石，还有个斗大的玉钵，想是用来洗笔的。
LONG
    );
    set("exits", ([
	"west" : __DIR__"fyyage",
      ]));
    set("objects", ([
	__DIR__"npc/bookgirl": 1,
	__DIR__"obj/vase" : 2,
	__DIR__"obj/flower" : 1,
      ]) );
    set("coor/x",60);
    set("coor/y",40);
    set("coor/z",10);
    setup();
    con = present("vase",this_object());
    item = present("flower",this_object());
    item->set_amount(3+random(30));
    item->move(con);
}
