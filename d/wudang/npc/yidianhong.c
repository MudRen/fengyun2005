#include <ansi.h>

int give_silk();
inherit NPC;
void create()
{
        set_name("中原一点"HIR"红"NOR, ({ "yidian hong", "hong"}) );
        set("title", "剑下一点红" );
        set("gender", "男性" );
        set("age", 35);
        set("long", 
"一袭黑衣，脸如死灰，但一双眼睛却明亮如电，冒着野兽般的绿光。这人便
是天下第一杀手中原一点红。\n");
        set("combat_exp", 3000000);
        
        set("attitude", "friendly");
        set_skill("unarmed", 150);
        set_skill("dragonstrike",200);
		set_skill("lefthand-sword",150);
		set_skill("dodge", 140);
		set_skill("fall-steps",160);
		set_skill("sword",200);
		set_skill("move",200);
		set_skill("sharen-sword",170);
		
		map_skill("unarmed","dragonstrike");
		map_skill("sword","sharen-sword");
		map_skill("dodge","fall-steps");
		map_skill("move","fall-steps");
	
        set("chat_chance_combat", 30);
		set("chat_msg_combat",  ({
	    	(: perform_action, "sword.sharenruma" :)
        }) );
	
	
	
		setup();
		carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/bloodsword")->wield();
}


void win_enemy(object loser)
{
    	message_vision(HIB"\n中原一点红冷笑道：盛名之下，其实难符。\n"NOR,loser);
		command("sigh");
		loser->set("天枫_quest6","失败");	// let TF die then remove this mark
}

void lose_enemy( object winner)
{
    	message_vision(HIR "\n\n中原一点红咬咬牙，凄然长笑一声：伊贺忍侠果然名不虚传，在下佩服。\n"NOR,winner);
		REWARD_D->riddle_set( winner, "浪人的悲哀",6);
	//	winner->set("天枫_quest6","成功");
}

int accept_fight(object me)
{
		object skinmask;
		object who;
	
		who=this_object();
		me=this_player();
	
		if (is_fighting() || is_busy())
        	return notify_fail("中原一点红正在忙着呢，没空和你搭话！\n");
        	
//	if(me->query("天枫_quest5")!="成功") return 0;
		if (REWARD_D->riddle_check( me, "浪人的悲哀" )!=5)	return 0;	
		
		if(!skinmask=present("cloth",me)) return 0;
		if((!skinmask->query("equipped"))||(!skinmask->query("tianfeng_skinmask")))
			return 0;
		
		if (who->query("kee")<who->query("max_kee") || who->query("eff_kee")<who->query("max_kee")
			|| who->query("sen")<who->query("max_sen") || who->query("eff_sen")<who->query("max_sen")
			|| who->query("gin")<who->query("max_gin") || who->query("eff_gin")<who->query("max_gin"))
			{
				tell_object(this_player(),"中原一点红正在疗伤,没空理你.\n");
			return 0;
		}
	
		message_vision(HIY"中原一点红深深吸了一口气,冷冷道：好！东洋武士，拔刀！\n"NOR,me);
		return 1;
}


int do_killing(string arg)
{
    	object player, victim;
    	string id,id_class;
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
			return notify_fail("这里没有这个人。\n");
	    if(living(victim))
	    {
	       	if(victim->query("id")=="hong" || victim->query("id")=="yidian hong")
	        {
	            this_object()->remove_all_enemy();
	            command ("say 好，先杀你!");
	            return 0;
	        } 
	    }
    	return 0;
}


void init()
{
		::init();
		add_action("do_killing", "kill");
						
}