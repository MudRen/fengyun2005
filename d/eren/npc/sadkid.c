inherit NPC;
#include <ansi.h>
inherit INQUIRY_MSG;
int give_mission();
int give_flower();

void create()
{
        set_name("闷闷不乐的小孩", ({ "sad kid","kid" }) );
        set("gender", "男性");
        set("age", 12);
        set("long",	"一个十二三岁的小孩，闷闷不乐地坐在田埂上。\n"	);
		set("chat_chance", 1);
        set("chat_msg", ({
        	"小孩说：小烟怎么不见了？没人和我一起玩了。\n",	
        }) );
		set("inquiry", ([
        	"小烟" : (: give_mission :),
        	"xiaoyan" : (: give_mission :),
        	"七枝一叶花":	(: give_flower :),
   		]));


		set("combat_exp",5000);
        setup();
		carry_object("/obj/armor/cloth")->wear();
}

int give_mission()	{
	object ob;
	ob=this_player();
	command("say 小烟是我的好朋友，刚才我们还在竹林边堆泥人玩，一晃就不见了。");
	if (!REWARD_D->riddle_check(ob,"司马小烟"))
		REWARD_D->riddle_set(ob,"司马小烟",1);
	
	return 1;
	
}	


int accept_object(object me, object obj){
	if (obj->query("24dao")) {
		command("ack");
		command("say 这画上的就是小烟啊！请你一定要找到他。");
		REWARD_D->riddle_set(me,"司马小烟",2);		// yeh, step 1 is not necessary.
	}
	
	if (obj->query("24dao_ren")) {
		command("cry");
		command("say 这就是小烟的泥人儿，他平时从来不让人碰，他一定是出意外了。");
		REWARD_D->riddle_set(me,"司马小烟",2);
	}	
	return 0;
}

int give_flower() {
	
	object me, flower;
	me = this_player();
	
	if (!REWARD_D->check_m_success(me,"司马小烟")) {
		command("say 那朵花叫这个名字么？我也不知道啊，不过，这是
小烟哥哥送给我的，我把它藏好了，可不会随便给人。");
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"小村神医")) {
		command("say 我的花儿已经送给别人了。");
		return 1;
	}
	
	if (me->query_temp("marks/eren/7flower")) {
		command("say 我不是已经给你了么？");
		return 1;
	}
			
	command("sob");
	command("say 小烟哥哥走了，再也不会回来了。");	
	command("say 这朵花是我们一起挖到的，看了就伤心，你拿去吧。");
	flower=new(__DIR__"obj/flower");
	message_vision(CYN"$N给你一朵花。\n"NOR,this_object());
	me->set_temp("marks/eren/7flower",1);
	flower->move(me);	
	return 1;
}

