inherit ROOM;

void create()
{
	set("short", "山雾中");
	set("long", @LONG
雾气越来越浓，打湿了你的衣襟，四周白蒙蒙的难以辨出轮廓，脚下不再是平
整的石英岩，山道已到了尽头。你费力地向上看去，山虽陡，但还有落脚之处。你
似乎可以试着爬(climb)上去。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"road4",
]));
        set("item_desc", ([
      		"mountain": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
      		"山": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
      		"up": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
        ]) );
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",-20);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "山" || arg == "mountain" || arg == "up")
        {
        	me = this_player();
        	message_vision("$N慢慢地往山上爬去。\n", me);
        	me->move(__DIR__"ping_tai.c");
        	return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}

