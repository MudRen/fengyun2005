#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;
int kill_him();

void create()
{

	set_name("柳东来",({"liu donglai","liu","donglai"}));
    	set("title",YEL"护花剑客"NOR);
    	set("long", "
一个很体面的中年人，穿着很考究，须发虽已发白，看来却还是风度翩翩，
很能吸引女人。他的手也保养得很好，手指修长、干燥、有力，不但适于
握刀剑，也适于发暗器。\n");

	set("age",59);
	set("combat_exp", 6400000);
        set("attitude", "friendly");
	
	set("inquiry", ([
             "白天羽" : (: kill_him :),
       	]));

	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );

	auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","softsword",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword/sword_liu")->wield();    
}


int kill_him()
{
        object me/*, another*/;
        
        me = this_player();
 		if (this_object()->is_fighting()) {
 		tell_object(me,"柳东来现在没空回答你。\n");
 		return 1;
 		}
        message_vision(CYN"
柳东来道：“那次我们做的事，虽然不够光明磊落，但现在若回到十九年前，我
还是会再同样做的。。。。因为白天羽实在不是个东西。不错，是为了个女人，
她叫做洁如，她本来是我的，但是白天羽却用他的权势和钱财，强占了她！”\n"NOR,this_object());
        return 1;
}