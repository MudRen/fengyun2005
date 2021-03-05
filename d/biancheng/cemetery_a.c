inherit ROOM;

void create()
{
        set("short", "坟场北端");
        set("long", @LONG
阴惨惨的夜色，笼罩着阴惨惨的大地，这儿孤零零地有座十米见方的坟冢，四
周有石人石马，显然主人是附近的富绅。但是现在石人石马已经缺头断腿，连坟头
也被掘开。一口崭新的棺材，里面有陪葬的金珠和一个站着的人。这人脸上朦朦胧
胧，仿佛有层雾。据说刚死的人，脸上是会有种死气，看来就像是雾。
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-90);
		set("coor/y",30);
		set("coor/z",0);
		set("no_lu_letter",1);
		set("objects", ([
        	__DIR__"npc/guoyi" : 1,
        	__DIR__"obj/coffin2": 1,
        ]) );
	
		set("exits", ([
			"south" : __DIR__"cemetery12",
		]));

	setup();
}


void reset(){
	object item, coffin;
	object *inv, *players;
	::reset();
	if (!objectp(coffin=present("coffin",this_object()))) return;
	inv=all_inventory(this_object());
	players=filter_array(inv,(: userp($1) :));
	if (sizeof(players)) return;
	
	if (!present("paper",coffin)) {
		item=new(__DIR__"obj/paper1");
		item->move(coffin);
	}
	return;
}
	