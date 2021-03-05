#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "废墟");
        set("long", @LONG
这儿有一片残垣断壁，几间东倒西歪的小土屋，没有门，没有窗，只是一个个
的窟窿，风吹过呜呜的响。屋檐下一面破碎的锦旗，拂去黄尘，依稀可以辨出“龙
门客栈“几个字，想来原是过往行商歇脚之处，不知为什么被废弃了。
LONG
        );
        set("exits", ([ 
	  	"southwest" : __DIR__"qingtongxia",
			]));
	
		set("item_desc", ([
			"废墟" : "废墟后似乎有路，你可以试着转转看。\n",
		]));
	set("objects", ([
		__DIR__"npc/bandit2" : 2,
	]));
	set("outdoors", "zangbei");

        set("coor/x",-450);
	set("coor/y",600);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init() {
	
	 add_action("do_around", "around");
}

int do_around(){
	object me, room;
	object bandit;
	
	me=this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
		
	if (present("bandit") && me->query("combat_exp")<2500000) {
		tell_object(me,"马贼说：瞎转转什么转，嫁过来大爷陪你一起转。\n");
		return 1;
	}
			
	if (present("bandit") && me->query("combat_exp")>2500000) 
		tell_object(me,"马贼看看你，摸了摸刀，想动却没敢动。\n");
		
		
	tell_object(me,YEL"\n你在废墟里仔仔细细转了几个来回，眼前忽然一亮。\n\n"NOR);
	room = find_object(__DIR__"banditcamp1");
    if(!objectp(room)) 
      	room = load_object(__DIR__"banditcamp1");
    me->move(room); 
	message("vision",me->query("name")+"向废墟后跑去，绕了几圈不见了。\n",this_object());
	return 1;
}


