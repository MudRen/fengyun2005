inherit ROOM;
void create()
{
        set("short", "浸满水的冰冷地下暗道");
        set("long", @LONG
透过暗淡昏黄的光线，齐腰深的水中竟然有几棵枯枝．树皮已经泡烂，横七竖
八地立着．水冰冷彻骨，但在缓缓流动．一根略粗的枯枝歪歪斜斜地垂在你的右上
方，上面好象有刀刻过的痕迹．
LONG
        );
	set("item_desc", ([
	"vine": "一根粗粗的枯枝，被水泡得发出一股怪味，上面模模糊糊地刻着几个小字： 
		武当禁地　擅入者死！\n",
	"枯枝": "一根粗粗的枯枝，被水泡得发出一股怪味，上面模模糊糊地刻着几个小字： 
		武当禁地　擅入者死！\n",
	]) );
	set("objects", ([
                __DIR__"obj/vine" : 1,
        ]));
	set("no_magic",1);
	set("coor/x",-30);
	set("coor/y",-60);
	set("coor/z",-30);
        setup();
}

init() 
{
	add_action("do_move", "move");	
	add_action("do_dive","dive");
	add_action("do_search","search");
}


int do_move(string arg)
{
	object me, bat;
	int i;

        if(!arg || arg != "枯枝" && arg != "vine" ) return 0;
	switch (random (2)) {
		case 0:
message_vision("$N用力推了推枯枝，发现枯枝纹丝不动。\n", this_player());
		break;
		case 1:
		bat = present("bian fu", this_object());
		if(!objectp(bat)) {
message_vision("$N刚摇动了一下枯枝，扑录录飞出了几只蝙蝠。\n", this_player());
			for (i=0; i<random(5)+4; i++){
 			bat = new(__DIR__"npc/bat");
			bat->move(this_object());
			bat->kill_ob(this_player());
			return 1;
			}
		}
message_vision("$N摇动了一下枯枝，枯枝发出嘎吱吱快要断裂的声音。\n", this_player());
		break;
	}	
	return 1;
}

int do_dive()
{
	object room;
	message_vision("$N心一横，一个猛子扎入冰冷刺骨的水中！\n",this_player());
	room = load_object(AREA_WUDANG"jing");
	this_player()->move(room);
	tell_object(this_player(),"\n\n你眼前突然一亮！\n\n",this_player());
	message("vision",this_player()->name() + "突然从水下钻了出来。\n", environment(this_player()),this_player());
	return 1;	

}

int do_search()
{
	object me;
	object box, treasure;
	me=this_player();
	if(!me->query_temp("saw_treasure_map"))
	{
	message_vision("$N你伸出双手，在冰冷的水中摸呀摸．．．\n",me);
	return 1;
	}
	message_vision("$N从枯枝的地方左三步，前两步，一弯腰，从水底的泥中
挖出一个铁盒！\n",me);
	box = new(__DIR__"obj/box");
	box->move(me);
	return 1;
}
