// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上草", ({ "girl cao", "cao", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上草，碧翠浪通津。
修带不为歌舞缓，浓铺堪作醉人茵，无意衬香衾。
晴霁后，颜色一般新。
游子不归生满地，佳人远意正青春，留咏卒难伸。
\n");
	set("attitude", "friendly");
	set("title", HIM "湖上八娇"NOR);
	set("age", 17);
        set("gender", "女性" );

	set("combat_exp", 45000);
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(100));
	setup();
    carry_object(__DIR__"obj/cao")->wear();

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
		message_vision(another->name()+ "走了过来。\n", this_object() );
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
    
    if( (string) obj->query("name") == "嫩藕")
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
		command("say 哇．．我最喜欢吃的耶！太谢谢你了！这个给你！\n");
		pai = new(__DIR__"obj/caopai");
		if(pai)
			pai->move(me);
        message_vision("$N拿出草玉璧给$n。\n",this_object(),me);
		return 1;	
	}
	command("say 这可不是本姑娘喜欢的耶！");
	return 0;
}

