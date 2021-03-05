#include <ansi.h>
#include <command.h>
inherit INQUIRY_MSG;
inherit SMART_NPC;

void create()
{

		set_name("唐大",({"tang da","tang"}));
    	set("title",RED"戴红缨帽的官差"NOR);
    	set("long", "唐大出自唐门，是常笑座下精研药物的三个人之一，无论什么毒，只要在人世间曾
经出现，他都能够分辨得出。\n");
		set("age",47);
		set("combat_exp", 6000000);
	        set("attitude", "friendly");	
	
		set("reward_npc",5);
		set("inquiry", ([
        	"红蝙蝠" : "红蝙蝠原产泷洲双伏红蕉花间，它的血液，无需制炼就已是一种媚药，
却绝对不是毒药。",
		"red bat" : "红蝙蝠原产泷洲双伏红蕉花间，它的血液，无需制炼就已是一种媚药，
却绝对不是毒药。",
		"bat" : "红蝙蝠原产泷洲双伏红蕉花间，它的血液，无需制炼就已是一种媚药，
却绝对不是毒药。",
        	 "粉蝶儿" : "粉蝶儿，听这名字就是采花贼喽，天网恢恢，疏而不漏，他早死了。",
           	 "铁恨": "铁捕头和常老爷齐名，是天下四大名捕之一。",
           	 "tie hen": "铁捕头和常老爷齐名，是天下四大名捕之一。",
           	 "tiehen": "铁捕头和常老爷齐名，是天下四大名捕之一。",
   		]));
	
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	
        ]) );    	
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) ); 		

		auto_npc_setup("wang",250,200,1,"/obj/weapon/","fighter_w","herb",1);
	
		set_skill("iron-cloth",150);
		set_skill("xisui",100);
		map_skill("iron-cloth","xisui");
		
	setup();
	carry_object(__DIR__"obj/o_cloth3")->wear();
	carry_object(__DIR__"obj/redhat")->wear();
}

int accept_object(object who, object ob)
{
	if( ob->name()==HIR"红石"NOR) {
                command("hmm");
		who->set("marks/parrot/红石的秘密",1);                 
        	call_out("event1",1,who,0);
        	return 1;
        }     
        if (ob->is_corpse())
     		command("say 验尸是林二的拿手好戏。");   
        return 0;
} 

string *event1_msg=	({
	
	CYN"\n  唐大说：“这上面的不是毒药。。”\n",
	
	CYN"  “这块红石是普通的石头，只因为在"NOR+HIR"红蝙蝠"NOR+CYN"的血液中浸过相当时候，所以才变成
了血红的颜色。\n"NOR,

    	CYN"    要将石头变成这颜色，不单需要时间，更需大量的血液，这三块石头简直就已
是"+HIR"红蝙蝠"NOR+CYN"的结晶，就放在水中片刻，将那水喝下的如果是女人，即使是三贞九烈的
女人，只怕也不由自己，变成了荡妇。\n"NOR,
	
	CYN"    这种媚药很少在中土出现，我唯一记得就只有‘千里踏花’"+HIM"粉蝶儿"NOR+CYN"曾以之迷遍
大江南北，糟践良家妇女无数。\n"NOR,

});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) 
		|| this_object()->is_fighting()) 	return;
	message_vision(event1_msg[count]+"\n",me);
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"    可是，"+HIM"粉蝶儿"NOR+CYN"已在多年前就授首"+WHT"铁恨"+CYN"刀下。”\n"NOR,this_object(),me);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}