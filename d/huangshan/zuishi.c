// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "醉石");
        set("long", @LONG
传说这是李白醉酒卧眠之处，石上人形依稀可见，观其形状恰似酒至鼾处，石
侧有醉石二字，笔力遒劲，边上立有牌坊一座，历代文人题字皆在此处。由醉石继
续南行便是试剑石。
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"shijian",
  "northeast" : __DIR__"qingluan",
  "westdown" : __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone2" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}

/*
void init() {
	add_action("do_laydown", "laydown");
	add_action("do_getup", "getup");
}

int do_laydown(){
	
	object me, walnut,who;
	int i, j;
	
	me = this_player();
	i = NATURE_D->get_season();
	j = random(10);

	
	who=query("laydown_person");
	
	if(me==who) return  notify_fail("你已经躺下了呀！？\n");		
	if(who&&present(who,this_object()))
		return notify_fail("已经有人躺在大石上了。。。\n");
	message_vision("$N转身躺到大石头上。\n", me);
	return 1;
}*/
