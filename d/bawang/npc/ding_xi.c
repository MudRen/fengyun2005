inherit NPC;
#include <ansi.h>

void init();
int do_killing(string);
int accept_object(object,object);
void create()
{
	set_name("丁喜", ({ "ding xi", "xi","dingxi" }) );
	set("gender", "男性" );
        set("title", HIG "花喜鹊"NOR);
	set("age", 20);
	set("per", 30);
	set("class","wolfmount");
	set("attitude","friendly");
	set("long",
		"他总是很随和，很自信。嘴边总是带着自信的微笑。\n人们总是称他“讨人喜欢的丁喜”或者“聪明的丁喜”\n"
		);
	
	set("cor",200);
	set("combat_exp", 3000000);
	set("score", 90000);
        
	set_skill("unarmed", 120);
	set_skill("xinyue-dagger", 110);
	set_skill("parry", 180);
	set_skill("dodge", 140);
	set_skill("dagger", 120);
	set_skill("xueyeqianzong",150);
	set_skill("perception",150);
	set_skill("dragonstrike",180);
	set_skill("move",180);
	
	map_skill("unarmed","dragonstrike");
	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","xueyeqianzong");
	map_skill("move","xueyeqianzong");
	map_skill("parry","xinyue-dagger");
	
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
     		(: perform_action, "dagger.douzhuanxingyi" :),
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/shortsword")->wield();
}

void init()
{
	add_action("do_killing", "kill");
	::init();
}

int do_killing(string arg)
{
	object player, victim;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "王若兰")
		{
			message_vision("$N冷冷地道：“看来我是不动手不行了。”\n", this_object());
			this_object()->kill_ob(player);
			player->kill_ob(this_object());
			return 1;
		}
		else if((string)name == "归东景")
		{
			if (REWARD_D->riddle_check( player, "镖局内奸") == 1)
			{
			message_vision( HIM "在这电光火石的一瞬，你眼前一花，只见归东景肩口处已经多了一个血洞！

归东景目瞪口呆地看着自己的伤口，又看了看丁喜，道：“你好快的身手......”
言未迄，他已摇摇欲坠。
原来是$N趁归东景分神之际，不知用了什么手法，击中了他。\n\n"NOR,this_object());	
				victim->set("kee",victim->query("max_kee")/2);
				victim->set("eff_kee",victim->query("kee"));
				REWARD_D->riddle_set( player, "镖局内奸", 2);
			}
		}
	}
	return 0;		
}
