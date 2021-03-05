#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("林仙儿", ({ "linxian" }) );
	set("title", HIR "武林第一美人"NOR);
	set("gender", "女性" );
	set("age", 22);
	set("max_kee",20);
	set("long", @LONG
两弯似戚非戚笼烟眉，一双似喜非喜含情目．
行动如弱柳扶风，闲静似娇花照水．
LONG
);
	set("combat_exp", 100000);
	set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
		"林仙儿又意无意地撩起长裙，向你露出她那双白如羊脂的细足。\n",
		"林仙儿似乎怕热，拎起领口扇了扇，半边雪白的坚挺的胸膛尽收眼底。\n",
		"林仙儿向你笑了笑，又满眼愤毒的瞥了阿飞一眼。\n",
        }) );
	set_skill("charm", 150);
	set("skill_public",1);
	setup();
	carry_object(__DIR__"obj/sskirt")->wear();
}


int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}

int recognize_apprentice(object ob)
{
    	if( (time()-ob->query_temp("marks/linxian_charm")) < 900)
        return 1;
		return 0;
}

int accept_object(object who, object ob)
{

	if (ob->query("id") == "huaqun")
	{
		message_vision("$N对$n道：“真是谢谢你帮我找到金红散花衣。”\n",this_object(),who);
		who->set_temp("marks/linxian_charm",time());
		return 1;
	}
	return 0;
}

void reset(){
	if (!present("silver skirt",this_object()))
		carry_object(__DIR__"obj/sskirt")->wear();
}
	