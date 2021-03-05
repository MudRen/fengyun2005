
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("守城官兵", ({ "chenxiang garrison", "garrison" }) );
        set("long","
这是个正在执行守城任务的风兵，虽然和许多武林人物比起来，官兵们的武功
实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"[31m你最好也不要招惹他们。 [32m\n");
        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "authority");
        set("combat_exp", 4000000+random(4000000));
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "官兵喝道：还不快放下武器束手就缚？\n",
                "官兵喝道：大胆刁民竟敢拒捕？反了！反了！\n",
                (: perform_action, "spear.suomengchanhun" :),
        }) );

        set_skill("unarmed", 200);
        set_skill("spear", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
        set_skill("changquan",200);
        set_skill("puti-steps",200);
	set_skill("duanhun-spear",151);
	
	map_skill("dodge","puti-steps");
	map_skill("move","puti-steps");
	map_skill("parry","duanhun-spear");
	map_skill("unarmed","changquan");
	map_skill("spear","duanhun-spear");
	
        
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(AREA_FY"npc/obj/spear")->wield();
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
       	if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N对著$n喝道：大胆狂徒,竟敢在闹市杀人,还不快快束手就缚!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}


void init()
{	
	::init();
//	add_action("do_killing", "kill");

}


int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

