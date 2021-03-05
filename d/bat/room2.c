inherit ROOM;
void create()
{
        object con,item;
        set("short", "丹房");
        set("long", @LONG
这是一间炼丹的丹房，你刚进来就闻到一股刺鼻的药草的味道，屋里很凌乱，
似乎刚刚被人翻过，各种各样的瓶罐堆的到处都是。靠墙放着个大药柜。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"zoulang1",
	]));
    	set("objects", ([
      		__DIR__"obj/case": 1,
       		"/obj/specials/ding/ding_bat" : 1,
       		__DIR__"npc/xunluo2" : 1,
	       
  	]) );
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",-10);
	setup();

}

int valid_leave(object me,string dir)
{
        object ob;
	if(userp(me) && me->query("class")!="bat" && dir == "south" && ob=present("xunluo shiwei",this_object()))
	if (ob->query("name")=="巡逻侍卫")
	{
	message_vision("$N对$n道：大胆！竟敢乱闯蝙蝠岛!\n",ob,me);
	return notify_fail("");
	}
	return 1;
}

void   reset() {
	object con, item;
	:: reset();
	con = present("case",this_object());
      	if (con) item = present("bat drug",con);
      	
      	if (!item) {
      		item = new(__DIR__"obj/drug");
      		item->move(con);
      	}
      	
}
