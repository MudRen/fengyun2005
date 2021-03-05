// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上花", ({ "girl hua","hua", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上花，天水浸灵芽。
浅蕊水边匀玉粉，浓苞天外剪明霞，日在列仙家。
开烂熳，插鬓若相遮。
水殿春寒幽冷艳，玉轩晴照暖添华，清赏思何赊。
\n");
	set("attitude", "friendly");
	set("title", HIM "湖上八娇"NOR);
	set("age", 17);
        set("gender", "女性" );

	set("per", 40);
	set("combat_exp", 45000);
        set("chat_chance", 1);
        set("chat_msg", ({
"湖上花轻皱黛眉道：我的黑玉发簪不见了\n",
        }) );

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(100));
	setup();
        carry_object(__DIR__"obj/hua")->wear();

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
    if( (string) obj->query("name") == "黑玉发簪")
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
		command("say 哇．．太谢谢你了！这个给你！\n");
		pai = new(__DIR__"obj/huapai");
		if(pai)
		pai->move(me);
        message_vision("$N拿出花玉璧给$n。\n",this_object(),me);
		return 1;	
	}
	command("say 这可不是本姑娘喜欢的耶！");
	return 0;
}

