inherit ROOM;
void create()
{
        set("short", "溪边");
        set("long", @LONG
湍急的小溪到了这里，由于溪流的加宽而渐渐平稳安静了下来。溪边有一丛一
人多高的芦苇，还有几株垂柳。柳树把它们的柳丝垂到了溪面上，微风拂过，在平
静的溪面上画著圈圈点点，逗的水中的鱼儿不停地跃出水面。几只羽毛艳丽的野鸭
在水面上荡来荡去，不时地把头探入水中寻找它们的食物，还有几只在岸边休息。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"grass",
  		"west" : __DIR__"naibridge",
  		"east" : __DIR__"smalllake",
	]));
        set("item_desc",([
		"luwei": "几束芦苇长在小溪边，你可以试着摘摘看（pick）。\n",
		"芦苇": "几束芦苇长在小溪边，你可以试着摘摘看（pick）。\n"		
	]));
        
        set("objects", ([
        __DIR__"npc/duck" : 2,
        ]) );

	set("outdoors","fengyun");
	set("coor/x",-80);
	set("coor/y",60);
	set("coor/z",10);
	setup();
}

void init()
{
	add_action("do_pick", "pick");
}



int do_pick(string arg)
{
	object	me, lu;

	if( arg != "luwei" && arg != "芦苇") 
		return notify_fail("什么？\n");
	me = this_player();
	if(me->query_temp("marks/luwei")>10)
		return notify_fail("芦苇已经被你摘没了。\n");
	lu = new(__DIR__"obj/luwei");
	lu->move(me);
	me->add_temp("marks/luwei", 1);
	message_vision("\n$N摘了一根芦苇放在怀里。\n", me);
	return 1;
}
