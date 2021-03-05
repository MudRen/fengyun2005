inherit ROOM;

void create()
{
    set("short", "后院");
    set("long", @LONG
院子四角各种著一株参天松树，中央是一口水井。青石板铺成的地面，没有任
何杂草落叶。院子左面是一排厢房，右面是练武厅。不时可以听到阵阵的拳风声从
里面传出来。
LONG
	);
    set("exits", ([ 
        "out" : __DIR__"wuroad4",
        "north" : __DIR__"wudang4",
        "south" : __DIR__"wudang5",
	]));
    set("item_desc", ([
        "jing": "武当弟子日常用的水井。你似乎可以试着钻(enter)进去。\n",
        "well": "武当弟子日常用的水井。你似乎可以试着钻(enter)进去。\n",
        "井": "武当弟子日常用的水井。你似乎可以试着钻(enter)进去。\n",
	]) );
    set("resource/water",1);
    set("objects", ([
                __DIR__"npc/taoist7" : 1,
    ]));
    
    set("outdoors", "wudang");
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
    setup();
}

void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    object /*obj,*/guo;
    object me;

    if(!arg || arg=="")
    {
        write("你要往哪里钻？\n");
        return 1;
    }
    me = this_player();
    if( arg == "jing" || arg == "well" || arg == "井")
    {
        if (guo = present("guo changxun", this_object()))
        { 
        	guo->ccommand("say 鬼鬼祟祟的想干什么？");
        	return 1;
        }
        message_vision("$N向四周看了一看，趁没人注意，深吸一口气钻进了井里。\n", me);
        me->move(__DIR__"jing.c");
        return 1;
    }
    else
    {
        write("你不可以往"+arg+"里钻！\n");
        return 1;
    }
}

int valid_leave(object me,string dir)
{
        object ob;
	if(userp(me) && me->query("class")!="wudang" 
		&&(dir == "north" ||dir=="south") && ob=present("guo",this_object()))
	{
	message_vision("$N对$n道：武当内室,非弟子不能进入!\n",ob,me);
	return notify_fail("");
	}
	return 1;
}