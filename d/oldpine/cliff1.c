// Room: /d/oldpine/cliff1.c

inherit ROOM;

void create()
{
        set("short", "山壁上的窄穴");
        set("long", @LONG
你现在正栖身在一个山壁上勉强足以容纳一个人休息的小穴中，从这里无论是
要往上爬或往下爬都有一段不算短的距离，最好先歇一歇，喘口气再走。
LONG
        );
        set("outdoors", "oldpine");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        if( !arg || (arg!= "up" && arg!="down") )
                return notify_fail("你要往上(up)爬还是往下爬(down)？\n");

        if( arg=="up" ) {
                message_vision("$N试了试脚边的岩石稳不稳，开始小心翼翼地往上攀爬。\n",
                        this_player() );
                this_player()->move(__DIR__"cliffside");
        } else if( arg=="down" ) {
                message_vision("$N试了试脚边的岩石稳不稳，开始小心翼翼地往山涧中攀了下去。\n",
                        this_player() );
                this_player()->move(__DIR__"riverbank1");
        }
        return 1;
}

