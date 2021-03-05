
inherit ROOM;

void create()
{
        set("short", "白云阁");
        set("long", @LONG
一幅张天师的画像挂在西面的墙上, 画像的下方摆著张覆著红布的桌子, 桌上
整齐地堆放著一叠叠的线装书籍。屋子虽大，却空空荡荡，正中有张蒲团，蒲团上
盘膝端坐着一个妇人，轻纱遮面，长袍及地，身后肃立一个道姑。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"book_room2",
	]));
        set("objects", ([
	__DIR__"npc/taolord2" : 1,
	__DIR__"npc/jing1" : 1,
	__DIR__"obj/desk" : 1,
 	]) );
	set("no_lu_letter",1);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",30);
	setup();
}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) ) {
        item = new(__DIR__"obj/specialbook");
        item->move(con);
        }
}
