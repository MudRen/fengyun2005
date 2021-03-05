#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
        set_name("巡逻士兵", ({ "patrol police","police" }) );
        set("long","
这是个正在执行巡逻任务的士兵，负责维护风云城里的治安。凡当街叫杀者
千万不要给他们看到，否则格杀勿论。无论你以前是干什么的，他们都一视
同仁。\n");
        set("attitude", "heroism");
        set("class","wudang");
    
        set("combat_exp", 3000000);
        
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );	
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chanzijue" :),
				(: summon_more(this_object()) :),
        }) );
        
        
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
	set_skill("taiji-sword",160);
	set_skill("five-steps",160);
	set_skill("lingxi-zhi",160);
	
	map_skill("unarmed","lingxi-zhi");
	map_skill("parry","taiji-sword");
	map_skill("dodge","five-steps");
	map_skill("move","five-steps");
	map_skill("sword","taiji-sword");
        
        set_temp("apply/attack", 70);
	set_temp("apply/dodge", 70);
	set_temp("apply/parry", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);
	
	setup();
        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/sword")->wield();
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
	
	string where;
	if(!ob || environment(ob) != environment()) {
		return;
	}
	
	switch( random(15)){
		case 0:
			say("巡逻士兵说:整天跑来跑去的真累,下岗后去千金楼放松放松.\n");
			break;
		case 1:
			say("巡逻士兵笑嘻嘻地说:请遵守风云城交通规则.\n");
			break;
		case 2:
			say("巡逻士兵把长剑往地上一插,伸了个懒腰.\n");
			break;
		case 3: 
			say("巡逻士兵说:千金楼没狐狸窝好，狐狸窝的姑娘们更有味儿。\n");
			break;
		case 4:
			say("巡逻士兵憧憬地说：狐狸精可真迷人啊，不知道小狐狸多大了。\n");
			break;	
		}
	where=file_name(environment(this_object()));
	if (where[3]!='f') this_object()->move("/d/fy/fysquare");
	if (random(3)>1) this_object()->random_move();
	
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
