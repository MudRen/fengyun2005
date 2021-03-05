// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上水", ({"girl shui", "shui", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上水，流绕禁园中。
斜日暖摇清翠动，落花香暖众纹红，苹末起清风。
闲纵目，鱼跃小莲东。
泛泛轻摇兰棹稳，沉沉寒影上仙宫，远意更重重。
\n");
	set("attitude", "friendly");
	set("title", HIM "湖上八娇"NOR);

	set("age", 17);
        set("gender", "女性" );


	set("per", 40);
	set("combat_exp", 50000);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(100));
	setup();
        carry_object(__DIR__"obj/shui")->wear();
        carry_object(__DIR__"obj/shuipai");

}

string summon_more(object who)
{
	int i;
	object *enemy,*ob;
	object another;
	seteuid(getuid());
	ob=all_inventory(environment(who));
	ob=filter_array(ob,(: $1->query("id")=="jianu" && $1->query("name")=="家奴": ));
	if (sizeof(ob)<1) {
	another = new(__DIR__"jianu");
	another->move(environment(who));
	message_vision(another->name()+ "走了过来。\n"
		, this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			another->kill_ob(enemy[i]);
			enemy[i]->kill_ob(another);
			another->set_leader(enemy[i]);
			}
		}
	}
	return "1";
}


int accept_object(object me, object obj)
{
	message_vision("$N微笑着说：我已经有了我想要的了，我什么都不要了。\n",this_object());
	return 0;
}

