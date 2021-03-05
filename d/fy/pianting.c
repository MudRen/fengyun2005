inherit ROOM;
void create()
{
    set("short", "银钩赌坊偏厅");
    set("long", @LONG
四面的墙壁粉刷的象雪洞一样，上面挂满了古今名家的[33m字画[32m。最大的一幅山水，
排在正中，却是个无名小卒画的，把云雾凄迷的远山，画得就象打翻了墨水缸一样。
和那些名家的杰作一比，实在是不堪入目，令人不敢恭维。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"dating",
      ]));
    set("item_desc", ([
	"picture": "这幅字画似乎可以掀开(open)。\n",
	"字画": "这幅字画似乎可以掀开(open)。\n",
	"山水": "这幅字画似乎可以掀开(open)。\n",
	"hua": "这幅字画似乎可以掀开(open)。\n",

      ]) );

    set("objects", ([
	__DIR__"npc/leng" : 1,
	__DIR__"npc/fangyufei" : 1,
      ]) );

    set("coor/x",-180);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

void init()
{
    add_action("do_open", "open");
}
int do_open(string arg)
{
    object obj;
    object me;
    if(!arg || arg=="")
    {
	write("你要打开什么？\n");
	return 1;
    }
    if( arg == "picture" || arg == "字画" || arg == "hua")
    {
	me = this_player();
	message_vision("$N拉起墙上的字画，发现了一个暗门。\n", me);
	if( !query("exits/westdown") ) {
	    set("exits/westdown", __DIR__"zhoulang");
	    call_out("close_path", 1);
	}
	return 1;
    }
    else
    {
	write("你不可以打开"+arg+"\n");
	return 1;
    }
}
void close_path()
{
    if( !query("exits/westdown") ) return;
    message("vision",
      "山水画荡了回来，又遮住了暗门。\n",
      this_object() );
    delete("exits/westdown");
}

