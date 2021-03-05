#include <ansi.h>
inherit NPC;

int do_answer(string arg);
int lixia();
int gother();

void create()
{
        set_name("蓝胡子", ({ "lan huzi", "lan" }) );
        set("long","蓝胡子是银钩赌坊的大老板．\n");
        set("attitude", "heroism");
		set("title", HIB "银钩赌坊大老板"NOR);
		set("age",33);
		set("per", 30);
        set("combat_exp", 100000);
        set("chat_chance", 1);
        
        set("inquiry",	([
            	"罗刹牌":"罗刹牌是西方玉罗刹的镇教之宝，他儿子输给了我，却被我老婆偷走了。\n",
            	"罗刹":	 "罗刹牌是西方玉罗刹的镇教之宝，他儿子输给了我，却被我老婆偷走了。\n",	
        		"老婆":	"我有三四个呢，你问哪一个？\n",
        		"李霞":	 (: lixia () :),
        		"老屋":	 (: gother() :),
        ]));
        				
        set("chat_msg", ({
				"蓝胡子叹道：罗刹牌失窃，这可怎么得了！\n",
        }) );

        set_skill("unarmed", 170);
        set_skill("sword", 170);
        set_skill("parry", 170);
        set_skill("dodge", 170);
        set_skill("move", 100);

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        
        setup();
        carry_object(__DIR__"obj/yincloth")->wear();
}


int lixia(){
	
	object who, ob;
	
	who = this_player();
	ob = this_object();
	
	if (REWARD_D->riddle_check(who,"计取罗刹")< 1)
	{
		command("shake");
		command("say 我劝你还是不要搅这趟浑水的好！");
		return 1;
	}
	
	command("say 李霞、就是这贱人偷走了我的罗刹牌，不知道跑哪儿去了！");
	return 1;

}

void init(){
	::init();
	add_action("do_answer","answer");
}


int do_answer(string arg){
	if (arg!="老屋") {
		command("doubt");
		return 1;
	}
	
	gother();
	return 1;
}



int gother(){
	
	object who, ob;
	
	who = this_player();
	ob = this_object();
	
	if (REWARD_D->riddle_check( who,"计取罗刹")< 1)
	{
		command("hmm");
		command("say 老屋，老屋，我这赌场不算很老啊！");
		return 1;
	}
	
	command("say 原来这贱人躲在那里，你去找她，对她说，如果不交出罗刹牌，
想杀她的可不只是我蓝胡子！");
	if (REWARD_D->riddle_check(who,"计取罗刹") ==1) 
		REWARD_D->riddle_set(who,"计取罗刹",2);
	return 1;

}
			