inherit ROOM;
#include <ansi.h>
#define FATEMARK "宿命A/昆仑_槐树"

void create()

{
        set("short", "道路");
        set("long", @LONG
路旁是一片葱绿的田野和浓荫的树丛。翠绿色的山坡上，一排排青灰色的屋顶
在太阳下闪着光。向北一条石板路通向袁家的白云庄。路口长着一棵大槐树，树下
有几个行人正在歇息。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"road1d",
		"north": __DIR__"yuanvillage",

	]));
        set("objects", ([
        	
	]) );
	set("item_desc", ([
		"大槐树":	"这棵树大约有上百年了，浓荫遮天蔽日。\n",
		"槐树":		"这棵树大约有上百年了，浓荫遮天蔽日。\n",
		"tree":		"这棵树大约有上百年了，浓荫遮天蔽日。\n",       	
	]) );
	set("outdoors", "eren");
        set("coor/x",-50);
        set("coor/y",10);
        set("coor/z",10);
	set("map","eren");
	setup();

}


void init(){

	add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object 	me;
		me = this_player();
		if (me->is_fighting() || me->is_busy())
		{
			write("你现在正忙，空不出手来爬树。\n");
			return 1;
		}

		if(!arg) 
		{
			write("你要爬向哪里？\n");
			return 1;
		}

		if( arg == "up" || arg == "tree" || arg=="树" || arg == "槐树"
			|| arg == "大槐树")
        {
				message_vision("$N手脚并用，麻利地向大槐树上爬去。\n",me);
				me->perform_busy(2);
        		call_out("fliping",2,me);
        		return 1;
        }
        else
        {
                write("你不可以爬"+arg+"。\n");
                return 1;
        }
}


int fliping(object me)
{
		object room;
		if( !me->is_ghost() && environment(me) == this_object()) 
		{
			room=find_object(__DIR__"tree1");
			if (!objectp(room)) room=load_object(__DIR__"tree1");
			tell_room(room, me->name() + "从大槐树下爬了上来。\n");
			me->move(room);      		
		}
        return 1;
}


void init_scenery()
{
        remove_call_out("flower_drop");
        call_out("flower_drop",1, random(2), 0);
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(3)) {
		ob->set(FATEMARK,num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}


void flower_drop(int sunrise, int sunrise_stage)
{
	object *ppls;
    	object ob;
    	function f = (:add_fate_mark:);
    	ob = this_object();
    	
    	message("vision", WHT"\n轻柔的风吹过，大槐树的叶子发出沙沙的响声，几片浅白色的槐树花飘落下来。\n"NOR, ob);
        message("vision", WHT"温湿的风儿，夹着淡淡的清香来，让人精神为之一爽。\n"NOR, ob);
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
        if(sizeof(ppls))
		map_array(ppls,f);
}