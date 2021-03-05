// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上柳", ({ "girl liu","liu", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上柳，烟里不胜催。
宿雾洗开明媚眼，东风摇弄好腰肢，烟雨更相宜。
环曲岸，阴覆画桥低。
线拂行人春晚后，絮飞晴雪暖风时，幽意更依依。
\n");
	set("attitude", "friendly");
	set("title", HIM "湖上八娇"NOR);

	set("age", 17);
        set("gender", "女性" );

	set("per", 40);
	set("combat_exp", 120000);
        set("chat_chance", 1);
        set("chat_msg", ({
"湖上柳挥动舞器，轻歌漫舞：
风萧萧兮易水寒
壮士一去兮不复还\n",
        }) );

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("dagger", 100);
	setup();
        carry_object(__DIR__"obj/liu")->wear();
	carry_object(__DIR__"obj/wuqi")->wield();


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
    
    if( (int) obj->value() >=  50000)
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
		command("say 哇．．我最喜欢的耶！太谢谢你了！这个给你！\n");
		pai = new(__DIR__"obj/liupai");
		if(pai)
		pai->move(me);
	        message_vision("$N拿出柳玉璧给$n。\n",this_object(),me);
		return 1;	
	}

	ccommand("say 你当我是东城的土娼啊！");
	return 0;
}

