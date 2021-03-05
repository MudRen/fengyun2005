
inherit ROOM;

void create()
{
        set("short", "绿洲");
        set("long", @LONG
这绿洲不但美丽，而且还不小，在这丑恶的沙漠中，突然出现如此美丽的地方，
简直就像是神话。青葱的木叶间，不时有银铃般的笑声传出来。这本是欢乐的笑声，
但在这残酷无情的大沙漠中，一个快被渴死的人耳朵里，这笑声却比什麽都要诡秘
可怖。这难道真是神话中的幻境，魔境？隐藏在这青葱木叶里，难道就是神话中那
些专门诱惑孤独的旅人去吞噬的吃人女妖？
LONG
        );
        set("exits", ([ 
	  		"east" : __DIR__"d_tent",
	  		"north": __DIR__"d_bush",
	  		"west": __DIR__"yangguan1",
	  		"southwest": 	__DIR__"yangguan1d",
		]));
	set("objects", ([
		
	]));
	set("item_desc",([
		
	]));
        set("outdoors", "zangbei");
        set("coor/x",-70);
	set("coor/y",310);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}
