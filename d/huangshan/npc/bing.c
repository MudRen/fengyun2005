inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("冰冰", ({ "bingbing","bing" }) );
        set("gender", "女性" );
        set("long",     "
她实在是个男人们引以为荣的女人，她很年轻，非常年轻。
她的皮肤稍微显得太苍白了一些，却使她看起来更娇弱，
她的眼睛也像是孩子般纯真明亮，却又带着种说不出的忧郁。\n");
        set("age", 15);
        set("per", 37);
        set("attitude", "peaceful");
        set("combat_exp",4500000);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );

        auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        setup();
        carry_object("/obj/armor/cloth",([	"name": RED"红纱长裙"NOR,
    						"long": "一件红纱长裙，穿上后肌肤若隐若现。\n",
    						 ]))->wear();  
}


void init()
{
	object me;
	me = this_player();
	::init();
	if(interactive(me) 
		&& me->query_temp("friend_to_xiao")) 
		call_out("ask_him", 1,me );


} 
int ask_him(object me)
{
	if(environment(me) == environment())
	{
		tell_object(me,name()+"道：我哥哥逍遥侯虽然死了，可是这个秘密的天宗
并没有瓦解。\n");
		me->set_temp("listened",1);
	};
	return 1;
}
