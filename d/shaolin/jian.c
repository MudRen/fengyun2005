// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "僧监");
        set("long", @LONG
一处清幽所在，如不是密密的的[33m铁栏[32m（ｂａｒｓ），也想不到这是监狱，这里
囚禁的都是少林的败类或者闯少林的邪徒，能被关进这里的都是非凡之人，可惜品
行不端，四长老每日早晚都要念颂金刚经加以点化，已有不少人由此改恶从善，虔
心向佛。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"laon",
  		"south" : __DIR__"laos",
  		"west": __DIR__"lao",
  		"east" : __DIR__"laoe",
		]));
        set("objects", ([
                __DIR__"obj/mantou" : 2,
                __DIR__"obj/purewater" : 2,
				BOOKS"skill/daode_50" : 1,
       	]) );
		set("NONPC", 1);
		set("coor/x",20);
		set("coor/y",120);
		set("coor/z",20);
		setup();
}

void init()
{
	if(this_player()->query_skill("daode",1) < 10)
		this_player()->set("startroom", base_name(this_object()));

}
