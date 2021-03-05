// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "湖上月", ({ "girl yue","yue", "girl" }) );
	set("long", "这是千金楼湖上八娇之一．
湖上月，偏照列仙家。
水浸寒光铺枕簟，浪摇晴影走金蛇，偏称泛灵槎。
光景好，轻彩望中斜。
清露冷侵银兔影，西风吹落桂花枝，开宴思无涯。
\n");
	set("attitude", "friendly");
	set("title", HIM "湖上八娇"NOR);
	set("age", 17);
        set("gender", "女性" );

	set("per", 40);
	set("combat_exp", 120000);
        set("chat_chance", 1);
        set("chat_msg", ({
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
关关雎鸠， 在河之洲。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
窈窕淑女， 君子好逑。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
参差荇菜， 左右流之。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
窈窕淑女， 寤寐求之。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
求之不得， 寤寐思服。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
悠哉悠哉， 辗转反侧。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
参差荇菜， 左右采之。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
窈窕淑女， 琴瑟友之。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
参差荇菜， 左右毛之。\n",
"湖上月调了调弦，轻轻的和着琵琶唱了起来：
窈窕淑女， 钟鼓乐之。\n",
        }) );

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("hammer", 100);
	setup();
        carry_object(__DIR__"obj/yue")->wear();
	carry_object(__DIR__"obj/piba")->wield();

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
    if( (string) obj->query("name") == "生烧扒翅")
	{
        message_vision("$N向$n道了个万福：\n",this_object(),me);
        command("smile");
		command("say 哇．．我最喜欢吃的耶！太谢谢你了！这个给你！\n");
		pai = new(__DIR__"obj/yuepai");
		if(pai)
		pai->move(me);
        message_vision("$N拿出月玉璧给$n。\n",this_object(),me);
		return 1;	
	}
	command("say 这可不是本姑娘喜欢的耶！");
	return 0;
	
}

