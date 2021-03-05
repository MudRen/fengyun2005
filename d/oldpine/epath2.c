// Room: /d/oldpine/epath2.c

inherit ROOM;

void create()
{
        set("short", "小石桥");
        set("long", @LONG
你现在正站在一座长满青苔的古桥上，桥下是一条山涧，几股清泉在乱石之中
向山下奔流，桥北边不远处有一个[37m瀑布[32m，从山壁上犹如一条白练般垂了下来，瀑布
两旁的石壁十分陡峭，高度和山涧旁的松林相差了近三、四十丈。
LONG
        );
        set("item_desc", ([
                "waterfall":
                        "这个瀑布从数百丈高的山壁上冲激而下，流入一个山涧底的小水潭，\n"
                        "水潭两边的石壁垂下许多的[37m藤蔓[32m(vine)，你注意到瀑布後面似乎\n"
                        "有什麽东西在发著光。\n",
                "瀑布":
                        "这个瀑布从数百丈高的山壁上冲激而下，流入一个山涧底的小水潭，\n"
                        "水潭两边的石壁垂下许多的[37m藤蔓[32m(vine)，你注意到瀑布後面似乎\n"
                        "有什麽东西在发著光。\n",
                "vine":
                        "其中有一根藤蔓距离你比较近，你可以试著抓住(hold)藤蔓，看看\n"
                        "能不能荡过去，也许可以知道瀑布後面有什麽？\n"
                        "对了，提醒你一点，这座石桥下面是高约百丈的山涧深谷....。\n"
        ]) );
        set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"epath1",
	  "east" : __DIR__"epath3",
	]));
        set("outdoors", "oldpine");

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_hold_vine", ({ "hold", "grab" }) );
}

int do_hold_vine(string arg)
{
        if( !arg || arg!= "vine" )
                return notify_fail("你要抓住什麽？\n");
        message_vision("$N爬上石桥的护栏，伸手往不远处的一根藤蔓抓去....\n",
                this_player());
        if( random((int)this_player()->query_skill("dodge")) < 5 ) {
                message_vision("\n只听见一声杀猪般的惨叫，$N已经往山涧中坠了下去。\n\n", this_player());
                tell_room(__DIR__"waterfall",
                        "你听到有人高声惊叫，一条人影从上方掉了下来，「扑通」一声跌进潭中。\n");
                this_player()->move(__DIR__"waterfall");
        } else {
                message_vision("$N手脚俐落地攀附著藤蔓，慢慢地爬下山涧....。\n",
                        this_player() );
                tell_room(__DIR__"passage",
                        "忽然一条人影从南边的帘幕穿了出来。\n");
                this_player()->move(__DIR__"passage");
        }
        return 1;
}
