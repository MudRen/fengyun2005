#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void look_for_company(object me, object room, int n);
void summon_npc(object me, object next_room);
int kill_him();
int hu();

void create()
{
    	set_name("张老实",({"zhang laoshi","zhang","laoshi"}));
	set("title","面馆老板");
   	set("long","
张老实真的是个老实人，他不但是这小面馆的老板，也是厨子和伙计，
所以一年到头，身上总是围着块油腻腻的围裙，从早上一直忙到大黑，
赚来的钱却连个老婆都养不起。。\n");

     	set("gender","男性");
    	set("group","citizen");	
    	
    	set("combat_exp",1400000);  
    	set("age",42);
    	   	    	
    	set("inquiry", ([
             	"江湖五毒"	:	(: kill_him :),
             	"潘伶"	:		(: kill_him :),
             	"胡歪瓜":		(: hu :),
             	"保护费":		(: hu :),	
   	]));
    	
    	
    	set("death_msg",CYN"\n$N悔恨地说：“我看来是没希望娶媳妇了。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: name()+"叫道：“来人啊，强盗打劫店铺啦！”\n",
        ]) );    	

    	set("chat_chance",1);
    	set("chat_msg",({
		"张老实笑眯眯地道：“吃面，吃面。”\n",
		"张老实叹了口气说：“这日子可怎么过下去呀！”\n",
		"张老实拿起阳春面划拉了几下，又愁眉苦脸地放下。\n",
    	}) );    	    	
    	
    	
		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","tigerstrike",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/food_item/soup6");
    
}

int hu(){
	if (REWARD_D->check_m_success(this_player(),"义助张老实"))
		command("say 英雄，谢谢你救了我啊。");
	else if (!this_player()->query_temp("marks/wanma/胜地痞"))
		message_vision(CYN"张老实惊恐地看了你一眼，慌慌张张地低下头。\n"NOR,this_object());
	else
		command("say 你教训了胡歪瓜？太好了。。。可是，我的钱已经被他挥霍完了。。");
	return 1;
}
	

int accept_object(object who, object ob)
{
	if (ob->value()>=30000) {
		if (!who->query_temp("marks/wanma/胜地痞")) {
				command("say 你给我也没用。。胡歪瓜一来又要拿走。。。");
				command("sigh");
				return 0;
		} else {
			command("touch "+who->get_id());
			command("say 太感谢了，我决不会忘记英雄的大恩大德的！");
			if (!REWARD_D->check_m_success( who, "义助张老实"))
			{
				REWARD_D->riddle_done( who, "义助张老实",20, 1);
				who->set("marks/e_wanma/义助张老实",1);
				tell_object(who,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
			}
			return 1;
		}	
	}
	command("shake");
	command("say 这点哪够糊口啊。");
	return 0;
}


int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"张老实现在没空回答你。\n");
 		return 1;
 		}
 	if(!me->query("marks/wanma/棺材之谜")) {
        	tell_object(me,"张老实说：没听说过，这名字邪气得紧。\n");
        	return 1;
        }
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现在他脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n"NOR,this_object());
        another = new(__DIR__"panling");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}
