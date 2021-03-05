#include <ansi.h>
inherit NPC;
void create()
{
        set_name("梅汝甲", ({ "mei rujia", "rujia" }) );
        set("long","黑衣服，黑靴子脸上蒙着黑巾连身後背着的一柄剑，剑穗也是乌黑色的。\n");
    	set("int",50);
	set("dur",25);
	set("con",30);
	set("cor",50);
	set("agi",45);
	set("combat_exp", 900000);
	
	set_skill("dodge",100);
	set_skill("move",100);
	set_skill("jinhong-steps",100);
	set_skill("sharen-sword",100);
	set_skill("sword",120);
	set_skill("parry",120);
	set_skill("force",120);
	map_skill("sword","sharen-sword");
	map_skill("parry","sharen-sword");
	map_skill("dodge","jinhong-steps");
	map_skill("move","jinhong-steps");
	set("chat_chance_combat",50);
	set("chat_msg_combat",	({
		(:perform_action,"sword.sharenruma":),
	}));
	
	setup();

        carry_object("/d/qianfo/npc/obj/black_suit")->wear();
	carry_object("/obj/weapon/sword")->wield();

}

void init()
{
	::init();
       add_action("do_look","look");
}

int do_look(string arg)
{

	if (arg == "figure")
	{
		write("一身黑衣服，黑靴子，脸上蒙着黑巾，连身後背着的一柄剑的剑鞘都\n是乌黑色的。\n");
		write("他静静的站在那里仿佛已经和这杀人之夜溶为体。\n");
		write("他看起来约三十多岁。\n");
		write("武功看起来好象"+HIR "深不可测"NOR+"，出手似乎极轻。\n");
		write("他"+HIG "精神饱满，正处于巅峰状态。"NOR+"\n");
		write("他身上带著：\n");
		write("  "+HIC "√"NOR+"夜行衣(Black suit)\n");
		return 1;
	}
	return 0;
}
				
void die()
{
	object ob;
	object *enemy;
	ob = query_temp("last_damage_from");
	if(!ob)
	{ 
		enemy = this_object()->query_enemy();
		ob=enemy[0];
	}
	if(userp(ob)) 	ob->set_temp("marks/killmeirujia",1);
	::die();
}
