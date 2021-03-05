inherit NPC;
#include <ansi.h>
void create()
{
        set_name("驼子喇嘛", ({ "travel lama","lama" }) );
        set("title","行走四方的");
        set("gender", "男性" );
        set("class", "lama");
        set("age", 32);
          
        set("long", "树荫下坐着个歇脚的喇嘛，微驼的背，脸上布满了沙尘。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "驼子喇嘛叹了口气，揉了揉腿。\n",
                "驼子喇嘛说：“听说南方沼泽里有条恶龙，不知道谁能把它除了。”\n",  
                "驼子喇嘛说：“练武不练功，到头一场空！”\n",                
                }) );	
                
        set("combat_exp", 500000);
        set("attitude", "friendly");
        
        set("inquiry", ([
                "恶龙" : 	"据说在火沼泽中有一条烈火孽龙。\n",
                "烈火孽龙" : "这烈火孽龙在火沼中汲天地精华，有烈焰护身，非凡人能挡。\n",
                "烈焰" : 	"这烈焰非凡火，亦不能用寻常方法扑灭，唯有以毒攻毒。\n",
                "以毒攻毒" : "这个么只是我的猜测罢了，当然我是不会去试的。\n",
				"沼泽":		"沼泽就是沉香镇南面的火沼泽，凶险无比，有去无回，十年前
少林空闻大师与武当、兴国、大昭寺等数十高僧闯入其中，能活着回来的只有
一个兴国的和尚－－他是断了腿爬回来的。\n",
				"兴国的和尚": "废话，兴国的和尚自然是在兴国了。\n",
	]));
                
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("unarmed",100);
        set_skill("parry",100);
        set_skill("bloodystrike",50);
        
        set_skill("force",170);
        
        map_skill("unarmed","bloodystrike");
        
        set("skill_public",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init() {
	object ob;
	::init();
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob) {
	if(!ob || environment(ob) != environment()) {
		return;
	}
	switch( random(6)){
		case 0:
			say("驼子喇嘛叹了口气，揉了揉腿。\n");
			break;
		case 1:
			say( "驼子喇嘛说：“练武不练功，到头一场空！”\n");
			break;
		case 2:
			say( "驼子喇嘛说：“听说南方沼泽里有条恶龙，不知道谁能把它除了。”\n");
			break;
	}
}


int recognize_apprentice(object ob)
{
	if(ob->query("free_learn/force"))
	return 1;
        else {
                if (!random(3)) {
                command ("say 在下只结交英雄好汉。\n");
                } 
		return 0;
	}
}


int accept_object(object who, object ob)
{	
	if (ob->query("name")==HIR "火龙赤皮" NOR)
	{
		message_vision("$N两眼放出光来，“火龙赤皮！，真是你杀了那条恶龙？\n\n",this_object(),this_player());		
		if( who->query("m_success/勇杀孽龙")) 
		{ 
			command("praise"+who->query("id"));
			message_vision(HIR"$N一拱手，“英雄若不嫌弃，在下懂一点吐纳法门可与英雄分享。”\n"NOR,this_object(),this_player());
			who->set("free_learn/force",1);
			return 1;
		}
		else {
			message_vision(HIW"$N嘿嘿冷笑了几声。\n"NOR,this_object(),this_player());
			message_vision(HIW"$N说道，“世上也有如此滥竽充数之辈”\n"NOR,this_object(),this_player());
			message_vision(HIW"“火龙赤皮我收了，你，可以走了。”\n"NOR,this_object(),this_player());
		return 1;
		}	
	}

	else {
		message_vision("$N扫了一眼$n手中的东西说，“这种东西有什么用。”\n",this_object(),this_player());
		return 0;
		}
}

int prevent_learn(object me, string skill)
{
  	if (skill != "force")
  	{
      		command("shake");
      		command("say 我可只答应教你基本内功啊。");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/force")	&& skill == "force")
		return 0;
	
	return 1;
}