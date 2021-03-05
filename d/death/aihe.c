// Silencer@FY4

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "奈河桥");
        set("long", @LONG
许多人只知道奈何桥，却不知道奈河桥，其实奈河桥名来自奈河，奈河贯穿地
府，到这儿上面有一座石桥，桥的一端连着平安道，另一端[37m迷雾[32m缭绕，竟已无了去
路。诗云『风弥黄泉路，人过奈何桥，三生石留恨，望乡台缘绕』，这里是地府与
人间的交接之处，过了奈何桥，便是来生了。
LONG
        );
        set("exits", ([
		"north" : __DIR__"pingan",
		
        ]) );
        
        set("item_desc", ([
        	"迷雾": "奈何桥的尽头迷雾缭绕，若是你下定决心，就走进去吧(dash mist)。\n",
        	"mist":  "奈何桥的尽头迷雾缭绕，若是你下定决心，就走进去吧(dash mist)。\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/yurui" : 1,
        ]) );
        
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-190);
	set("no_fight",1);
	set("no_meal","你忽然发现口中的食物饮水成了苦涩的浊泥，赶快哇哇地吐了出来。\n");
	setup();
}


void	init()
{
	add_action("do_dash","dash");
	return;
}


int	do_dash(string arg)
{
	string *revive_loc= ({   AREA_FY"church",   AREA_GUANWAI"tower",});
	object me, cloth;
	mapping buff;
	
	if (!arg)
		return notify_fail("你要往哪儿闯？\n");
	
	if (arg!= "mist" && arg!= "迷雾")
		return notify_fail("你不能走进"+arg+"去。\n");
			  	   	
   	me = this_player();
	
	if (!me->query_temp("marks/ready_incar"))
		return notify_fail("你还没喝孟婆汤，那里能够还阳呢？\n");
		
	if (ANNIE_D->check_buff(me,"mengpo-soup")>0)
		return notify_fail("你上世的恩怨未尽，还是再等一阵儿吧。（需要等到"HIB"地域幽魂"NOR"的状态消失）\n");
			
	me->delete_temp("marks/ready_incar");  	
   	message_vision(WHT"\n$N狠了狠心，一头闯进了迷雾之中，只听鬼哭狼嚎，眨眼间失了踪影。。。。\n"NOR,me);
   	
   	if (!REWARD_D->check_m_success(me,"遨游地宫")) {
   		REWARD_D->riddle_done(me,"遨游地宫",50,1);
   		me->add("combat_exp",1500);
   		tell_object(me,WHT"你的江湖历练提高了。\n"NOR);
   	}
   	   	
   	if(me->is_ghost()){
		me->reincarnate();
		cloth = new("/obj/armor/cloth");
		if(objectp(cloth)) {
			cloth->move(me);
			cloth->wear();
		}
		
		// 5 mins NO_PK mark
/*		buff =
			([
				"caster":me,
				"who": 	 me,
				"type":	"no-pk",
				"att":	"bless",
				"name":	"隐退江湖",
				"buff1": "NO_PK",
				"buff1_c":1,
				"time":  300,
				"buff_msg":""NOR,
			]);
		ANNIE_D->buffup(buff);*/
				
//		me->unconcious();
		if (F_LEVEL->get_level(me->query("combat_exp"))< 11)
			me->move(AREA_FY"church");
		else
			me->move(revive_loc[random(sizeof(revive_loc))]);
		me->set("startroom", base_name(environment(this_player())));
		me->perform_busy(1);
		message("vision",
        	        "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
            	    "很久了，只是你一直没发觉。\n", environment(this_player()), this_player());
   	
   		me->set("kee",10);
   		me->set("gin",10);
   		me->set("sen",10);
   		me->set("force",0);
		me->set("atman",0);
		me->set("mana",0);
		me->set("death_revive",time());
		me->force_status_msg("all");
		me->status_msg("all");
			
		// THis just serves as a timer, all checks use query(death_time), so even relogin can't bypass
		buff =
		([
			"caster":me,
			"who":me,
			"type":"revive-sickness",
			"att":"curse",
			"name":"还魂·虚弱不堪",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$N身子虚弱到了极点，连站都站不稳了。\n"NOR,
		]);
		ANNIE_D->buffup(buff);
   	   	
   	}	
  	return 1;
		
}
	