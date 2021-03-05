#include <ansi.h>

inherit __DIR__"quicksand.c";

void create()
{
	object san, sna;
	set("short", "大漠风沙");
	set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼的风
声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间仿佛只剩下
你一个人。你脚下缓缓而动的流沙给你如履薄冰的感觉。
LONG
	);
	set("exits", ([ 
  		"west" : __DIR__"desert3",
  		"north" : __DIR__"desert1",
  		"south" : __DIR__"desert2",
  		"east"  : __DIR__"desert_entrance",
  		"down"  : __DIR__"quicksand0",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
		__DIR__"obj/teablock" : 1,
		__DIR__"obj/perfume" : 1,
		"obj/money/silver": 1,
        ]) );

	set("outdoors", "quicksand");
	set("coor/x",-1085);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	san = present("sand", this_object());
        sna = present("teablock", this_object());
        sna->move(san);
        sna = present("perfume", this_object());
        sna->move(san);
        sna = present("silver", this_object());
        sna->move(san);
}
/*
void init()
{	object ob;
	object jade;
	int water, food, bellicosity;
	string outexit;
	if( interactive( ob = this_player()))
	{
	water = ob->query("water");
	food = ob->query("food");
	bellicosity = ob->query("bellicosity");
	water -= (random(4)+ 1) * water / 10;
	food -= (random(2)+ 1) * water / 10;
	bellicosity += random(10);
	ob->set("water", water);
	ob->set("food", food);
	ob->set("bellicosity", bellicosity);	
	if( !objectp(jade = present("jade", ob)))
	{
		if( random(300)< 2)		  drop_him(ob);
	}
	else
	{
		if( random(1000)< 1)	drop_him(ob);
	}
	}
        add_action("do_pull", "pull");
}

int drop_him(object me)
{
	me->start_busy(1);
	call_out("dropnow", 1, me);
	return 1;

}
int dropnow(object me)
{
	if(environment(me) == this_object()){
        message_vision(HIW"$N突然感到脚底软绵绵的，无处着力！", me);
        message_vision("$N大叫一声“不好！”，可是来不及了…\n", me);
		message_vision("$N已陷身流沙之中！！\n"NOR, me); 
        me->move(__DIR__"quicksand0");
    }
        return 1;
}
	
int do_pull ( string arg)
{
	object me, who;
	object room;
	me = this_player();
        if ( !arg  ) return notify_fail("你要拉谁上来？\n");
	room = load_object(__DIR__"quicksand0");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("流沙里没有这个人。\n");
         message_vision(HIW"$N用尽全身力量，将$n从流沙中救了出来。\n"NOR, me,who);
        who->move(__FILE__);
	return 1;

}
*/