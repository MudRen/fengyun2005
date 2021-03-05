// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上女", ({ "girl nu","nu", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上女，精选正轻盈。
犹恨乍离金殿侣，相将尽是采莲人，清唱谩频频。
轩内好，嬉戏下龙津。
玉管朱弦闻尽夜，踏青斗草争青春，玉辇从群真。
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
	set_skill("unarmed", 1+random(200));
	setup();
        carry_object(__DIR__"obj/nu")->wear();

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
	object pai;
    
    if((NATURE_D->get_current_day_phase() == 0)) {
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
		command("say 你还蛮聪明的！这个给你！\n");
		pai = new(__DIR__"obj/nupai");
		if(pai)
		pai->move(me);
        message_vision("$N拿出女玉璧给$n。\n",this_object(),me);
		return 1;	
	}
	
	command("say 这可不是本姑娘喜欢的耶！");
	return 0;
	
}

