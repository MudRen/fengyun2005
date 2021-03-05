inherit ROOM;

void create()
{
        set("short", "老井");
        set("long", @LONG
营地西侧是一个半塌的井架，几个破水桶胡乱地倒扣在地上。向下看去，黑咕
隆咚地不见底，丢下一块石子，半晌听见啪的坠地声在井壁回响，原来已经干枯了
不知多少年。阱栏上拴着一匹没精打采的瘦马。
LONG
        );
        set("exits", ([ 
	  	"east" : __DIR__"banditcamp2",
			]));
		set("item_desc", ([
	        "jing": "黑咕隆咚的水井，你似乎可以试着钻(enter)进去。\n",
	        "well": "黑咕隆咚的水井，你似乎可以试着钻(enter)进去。\n",
	        "井": 	"黑咕隆咚的水井，你似乎可以试着钻(enter)进去。\n",
		]) );
		
		set("objects", ([
			__DIR__"npc/horse" : 1,
		]));
		set("outdoors", "zangbei");

        set("coor/x",-460);
		set("coor/y",620);
		set("coor/z",0);
		set("map","zbeast");
		setup();
}

void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    object obj,guo;
    object me;

    if(!arg || arg=="")
    {
        write("你要往哪里钻？\n");
        return 1;
    }
    me = this_player();
    if( arg == "jing" || arg == "well" || arg == "井")
    {
        message_vision("$N壮了壮胆，趁没人注意，深吸一口气钻进了井里。\n", me);
        me->move(__DIR__"jdi");
        return 1;
    }
    else
    {
        write("你不可以往"+arg+"里钻！\n");
        return 1;
    }
}