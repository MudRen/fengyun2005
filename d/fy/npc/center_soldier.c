#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
        set_name("巡逻士兵", ({ "patrol police","police" }) );
        set("long","
虽然风云城里不禁止械斗，但在天机老人的眼皮下捣乱就太过分了，所以，这儿是
城里唯一的一个执行巡逻任务的士兵，负责维护广场的治安，若是有打架行凶的企
图，千万不要给他撞见，无论你以前是干什么的，无论你有什么原因，打扰了天机
老人分配任务，都不会有好下场。
一句话："HIR"在此地杀人者，死！
\n"NOR);
        set("class","wudang");
        set("combat_exp", 11000000);

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chanzijue" :),
				(: summon_more(this_object()) :),
        }) );
                
        set_skill("unarmed", 200);
        set_skill("sword", 350);
        set_skill("parry", 350);
        set_skill("dodge", 350);
        set_skill("move", 350);
		set_skill("taiji-sword",200);
		set_skill("five-steps",200);
		set_skill("lingxi-zhi",200);
	
		map_skill("unarmed","lingxi-zhi");
		map_skill("parry","taiji-sword");
		map_skill("dodge","five-steps");
		map_skill("move","five-steps");
		map_skill("sword","taiji-sword");
        
        set_temp("apply/attack", 170);
		set_temp("apply/dodge", 170);
		set_temp("apply/parry", 170);
        set_temp("apply/armor", 170);
        set_temp("apply/damage", 200);
        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

void init() {
	object ob;
	::init();
	add_action("do_killing", "kill");
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
            if (ANNIE_D->check_buff(victim,"fugitive"))	return 0;
            message_vision(HIW"$N对著$n喝道：大胆狂徒，竟敢在闹市杀人，还不快快束手就缚！\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}


string summon_more(object who)
{
	int i;
	object *enemy;
	object another;
	seteuid(getuid());
	if (random(3)) {
		message_vision(HIW"$N大叫道：顶不住了，快叫总爷来!\n"NOR, this_object());	
		another = new(__DIR__"patrol_officer");
		another->move(environment(who));
		message_vision(HIY"巡逻哨官走了过来。\n"NOR, this_object() );
		message_vision(HIY"巡逻哨官喝道：何方贼民，竟敢在风云城内作乱？\n"NOR,this_object());	
		enemy = who->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
			another->kill_ob(enemy[i]);
			enemy[i]->kill_ob(another);
			another->set_leader(enemy[i]);
			}
		}
		return "1";
	}
	return "0";
}
