// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上雪", ({"girl xue", "xue", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上雪，风急堕还多。
轻片有时敲竹户，素华无韵入澄波，望外玉相磨。
湖水远，天地色相和。
仰面莫思梁苑赋，朝来且听玉人歌，不醉拟如何？
\n");
	set("attitude", "friendly");
	set("title", HIM "湖上八娇"NOR);
	set("age", 17);
        set("gender", "女性" );

	set("per", 40);
	set("combat_exp", 50000);
        set("chat_chance", 1);
        set("chat_msg", ({
"湖上雪眼中含泪，低声悲泣：
什么时候才能见到我的唯一的亲哥哥＂花满城＂\n",
        }) );

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(200));
	setup();
        carry_object(__DIR__"obj/xue")->wear();


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
    if( (string) me->name() == "花满城" 	&& me->query("name") != "花满城" )
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
		command("say 哥！终于见到你了！这个给你！听说里面有个大秘密．\n");
		pai = new(__DIR__"obj/xuepai");
		if(pai)
		pai->move(me);
        message_vision("$N拿出雪玉璧给$n。\n",this_object(),me);
		return 1;	
	}
	
	command("say 这可不是本姑娘喜欢的耶！");
	return 0;
	
}

