inherit __DIR__"no_killing_place";
void create()
{
        set("short", "打谷场");
        set("long", @LONG
宽阔的打谷场上均匀地铺着一层黄澄澄的稻米粒儿，一架土制的扬谷机正在喀
咔喀咔地转着，几个农人端着碗正蹲在一边吃饭，还不时地注意着防止麻雀来偷吃谷
粒儿。打谷场边上放着几个已经吃完了的碗和筷子。
LONG
        );

    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"nongjia1",
	]) );

    set("objects", ([
    	__DIR__"obj/bowl": 1,
       	__DIR__"npc/farmer":3,
    ]) );
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}


void reset()
{
        object *inv;
        object item1, bowl;
        ::reset();
        bowl = present("bowl", this_object());
        inv = all_inventory(bowl);
        if( !sizeof(inv)) {
        item1 = new(__DIR__"obj/fishbone");
        item1->move(bowl);
        }
}

