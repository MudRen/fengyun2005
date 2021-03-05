#include <ansi.h>
inherit NPC;

void create()
{
        set_name("小叶子", ({ "xiao yezi","yezi" }) );
        set("long","
小叶子是狄青麟的书童，看起来只有十四五岁的样子，眉清目秀，
穿着一套鲜红的衣裳，很是讨人喜欢的样子。\n");
	
	set("title", "书童");
    set("attitude", "friendly");
    set("class", "assassin");
    set("reward_npc", 1);
	set("difficulty", 3);
	
	set("age",15);
    set("combat_exp", 3500000);

	set("inquiry", ([
                "正月初三":	"正月初三是我的生日耶！\n",
                "di qinglin" : 	"叫小侯爷！\n",
                "狄青麟" : 	"叫小侯爷！\n",
        ]));
        
	set_skill("sword",200);
	set_skill("sharen-sword",170);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("lefthand-sword",170);
	set_skill("jinhong-steps",160);
	set_skill("unarmed",160);
	set_skill("flame-strike",150);
		
	map_skill("unarmed","flame-strike");
	map_skill("dodge","jinhong-steps");
	map_skill("parry","lefthand-sword");
	map_skill("sword","sharen-sword");

	set("death_msg","\n$N尖叫道：“天青如水，飞龙在天，小侯爷不会放过你的！！！” \n"NOR);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"sword.sharenruma"  :),
        }) );

        setup();
        carry_object("/obj/armor/cloth",([	
    					"name":  RED"鲜红的衣裳"NOR,
    					"long": "一套鲜红的衣裳，可惜下摆撕了个口子。\n",
    					 ]))->wear();
        carry_object(__DIR__"obj/bishou");
}


int accept_object(object who, object ob)
{
	if (ob->is_fighting())
		return notify_fail("小叶子正忙着呢，没空理你。\n");
	
	if(ob->query("libie_evidence")) 
	{
		if(!who->query_temp("libie/lian_corpse"))
		{
    			message_vision(CYN"小叶子说：哇，红布头，我喜欢红色，不过这块脏兮兮的，我不要耶！\n"NOR,who);
    			return 0;
    		}
    		
    		message_vision(YEL"小叶子的脸色忽然变了，天真的笑容忽然消失。\n"NOR,who);
    		kill_ob(who);
		who->set_temp("libie/di_1",1);
		return 1;
	}
	
	return 0;
}


void heart_beat()
{	object dagger;
	
	dagger=present("dagger",this_object());
	if(objectp(dagger))
	{
	if(!this_object()->is_fighting())
	{
		if (dagger->query("equipped"))
			this_object()->ccommand("unwield dagger");
	}
	else if (!dagger->query("equipped"))
			this_object()->ccommand("wield dagger");
	}
	::heart_beat();
}
