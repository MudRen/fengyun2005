inherit ROOM;

void create()
{
        set("short", "坟场南侧");
        set("long", @LONG
阴惨惨的夜色，笼罩着阴惨惨的大地，这儿孤零零地有座十米见方的坟冢，四
周有石人石马，显然主人是附近的富绅。但是现在石人石马已经缺头断腿，坟头上
长满了荒草，见人走近，几只乌鸦呱呱地一哄而散。
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",0);
	set("no_lu_letter",1);
	set("objects", ([
        	__DIR__"npc/tiehen" : 1,
        	__DIR__"obj/tomb2":	1,
                        ]) );
	set("exits", ([
		"north" : __DIR__"cemetery6",
	]));

	setup();
}


void reset(){
	object item, coffin;
	object *inv, *players;
	::reset();
	if (!objectp(coffin=present("tomb",this_object()))) return;
	inv=all_inventory(this_object());
	players=filter_array(inv,(: userp($1) :));
	if (sizeof(players)) return;
	
	if (!present("paper",coffin)) {
		item=new(__DIR__"obj/paper2");
		item->move(coffin);
	}
	return;
}