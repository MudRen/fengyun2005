inherit ROOM;

void create()
{
	set("short", "山间丛林");

	set("long", @LONG
这里黑漆漆的，伸出手去几乎看不见自己的手指。脚下磕磕绊绊，也不知道
会踩到什么东西。看来还是尽快找条出路的好。这里树木更加茂盛，繁茂的青藤
爬满树干。借着一点点微光，你似乎发现树丛中有个小木牌子。
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"shanlin",
		"south":__DIR__"shanlin1",
		"west":__DIR__"shanlin2",
		"north":__DIR__"shanlin3",
	]) );
	set("item_desc", ([
                "牌子": "牌子上歪歪斜斜的写着：[爬啊爬，抓着青藤爬回家，王动游玩偶得...哈哈]。\n你可以试着爬爬看（ｃｌｉｍｂ）\n",
                "paizi": "牌子上歪歪斜斜的写着：[爬啊爬，抓着青藤爬回家，王动游玩偶得...哈哈]。\n你可以试着爬爬看（ｃｌｉｍｂ）\n"
        ]) );
	set("coor/x",10);
	set("coor/y",180);
	set("coor/z",40);
	setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing()
{
        object me;
        
        me = this_player();
        message_vision("$N抓着繁茂的青藤，慢慢的顺着青藤向丛林外爬去。\n", me);
        me->start_busy(2);
        call_out("fliping",2,me);
        me->stop_busy();
        return 1;
}

void fliping(object me)
{
	object room;
	if( !me->is_ghost()) {
		if (me->query("class") == "fugui") {
			room =find_object(__DIR__"damen");
			if(!objectp(room)) {
				room = load_object(__DIR__"damen");
       		}
       	} else {
       		room =find_object(__DIR__"shanlin");
			if(!objectp(room)) {
				room = load_object(__DIR__"shanlin");
			}
		}
		me->move(room);     
		message_vision("$N顺着青藤爬了上来。\n", me);  
	}
        return;
}