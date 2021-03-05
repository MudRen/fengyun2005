#include <ansi.h>
inherit NPC;

void create()
{
        set_name("云卒", ({ "fengyun garrison", "garrison" }) );
        set("long","
这是个正在执行守城任务的云卒，虽然和许多武林人物比起来，云卒们的
武功实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"[31m你最好也不要招惹他们。 [32m\n");
        set("attitude", "heroism");
	set("class", "shaolin");
        set("vendetta_mark", "authority");
        set("cor", 40);
        set("combat_exp", 5000000+random(2000000));
        
        set("max_kee",30000);
        set("max_sen",30000);
        set("max_gin",30000);
        set("boss",1);
        
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "云卒喝道：还不快放下武器束手就缚？\n",
                "云卒喝道：大胆刁民竟敢拒捕？反了！反了！\n",
		(: perform_action, "spear.suomengchanhun" :),
        }) );
        
        set_skill("unarmed", 300);
        set_skill("spear", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("duanhun-spear",200);
	set_skill("move",500);
	set_skill("puti-steps",200);
	set_skill("changquan",200);

	map_skill("spear","duanhun-spear");
	map_skill("parry","duanhun-spear");
	map_skill("move","puti-steps");
	map_skill("dodge","puti-steps");
	
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/spear")->wield();
}

void init() {
	object ob;
	::init();
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_killing", "kill");
}

void greeting(object ob) {
	if(!ob || environment(ob) != environment()) {
		return;
	}
	switch( random(10)){
		case 0:
			say("云卒上上下下地打量你一番，又和墙上帖的官府通谍对了对，低声嘀咕道：好象就是了．\n");
			break;
		case 1:
			say("云卒看了你一眼，低声嘀咕道：唉，又是一个江湖人物．\n");
			break;
		case 2:
			say("云卒向你喝道：站住！把脸给我抬起来！\n");
			break;
	}
}

int do_killing(string arg)
{
    object player, victim;
//  string id,id_class;
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

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 100000 ) {
                        say("云卒呵呵的笑道：好说，好说。。。。\n");
                        who->set("vendetta/authority", 0);
                        who->remove_all_killer();
                        this_object()->command("follow none");
                        return 1;
                } else {
                    say("云卒说道：这点钱还不够大爷喝酒的呢！\n");
                        return 0;
                }
        return 0;
} 
