#include <ansi.h>
#include <room.h>
#include <ansi.h>
inherit __DIR__"quicksand.c";


void create()
{
//	object snake,ske,sand,too;
	set("short", "大漠风沙");
	set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼的风
声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间仿佛只剩下
你一个人。你脚下缓缓而动的流沙给你如履薄冰的感觉。
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"desert7",
  "north" : __DIR__"desert6",
  "south" : __DIR__"desert3",
  "east"  : __DIR__"desert1",
  "down"  : __DIR__"quicksand5",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1060);
	set("coor/y",-20);
	set("coor/z",0);
	setup();

}

/*        ske = new(__DIR__"obj/skeleton");
        too = new(__DIR__"obj/budda-tooth");
        too->move(ske);
		snake = new(__DIR__"npc/snake");
        snake->move(ske);
        sand= present("sand", this_object());
        snake = new(__DIR__"npc/snake");
        snake->move(sand);
        ske->move(sand);*/


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
		if( random(50)< 2)		  drop_him(ob);
	}
	else
	{
		if( random(100)< 2)	drop_him(ob);
	}
	}
        add_action("do_pull", "pull");
        add_action("do_get","get");
}

int drop_him(object me)
{
        me->start_busy(1);
        call_out("dropnow", 1, me);
        return 1;

}

int dropnow(object me){
	if(environment(me) == this_object()){
        message_vision(HIW"$N突然感到脚底软绵绵的，无处着力！", me);
        message_vision("$N大叫一声“不好！”，可是来不及了…\n", me);
        message_vision("$N已陷身流沙之中！！\n"NOR, me);
        me->move(__DIR__"quicksand5");
    }
        return 1;
}
 
int do_pull ( string arg)
{
	object me, who;
	object room;
	me = this_player();
        if ( !arg  ) return notify_fail("你要拉谁上来？\n");
	room = load_object(__DIR__"quicksand5");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("流沙里没有这个人。\n");
         message_vision(HIW"$N用尽全身力量，将$n从流沙中救了出来。\n"NOR, me,who);
        who->move(__FILE__);
	return 1;

}

int do_get(string arg)
{
	string what,where;
	if(!arg) return 0;
	if(sscanf(arg,"%s from %s",what,where) !=2) return 0;
	if((what== "skeleton" || what=="all") && where =="sand")
	{
		if (this_player()->is_busy())
			return notify_fail("你现在正忙。\n");
		if (this_player()->query("m_success/赤松",1) || this_player()->query("marks/get_tooth")
			|| this_player()->query_skill("iron-cloth",1)>=150)
		{
			message_vision(RED"响尾蛇嘶嘶地吐着舌头向$N扑来。\n"NOR,this_player());
			message_vision("$N赶忙悻悻地缩回手。\n",this_player());
			this_player()->start_busy(1);
			return 1;
		} else	{
			message_vision(RED"响尾蛇嘶嘶地吐着舌头向$N扑来。\n"NOR,this_player());
			message_vision("$N躲闪不及，被咬了个正着。\n",this_player());
			this_player()->receive_damage("kee",100);
			this_player()->set_temp("last_damage_from","被响尾蛇毒死了。\n");
			tell_object(this_player(),HIR"小心被咬死！！！\n"NOR);
			return 0;
			}
	}
}
*/