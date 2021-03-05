#include <ansi.h>
inherit NPC;

void create()
{
        set_name("知客道人", ({ "waiter taoist", "taoist", "waiter" }) );
        set("gender", "男性");
        set("long",
		"武当派知客道人，身着青色道袍、头戴黄色道冠。\n"
	);
        set("combat_exp", 10000+random(20000));
        set("score", 200);
        set("class", "wudang");

        create_family("武当派", 58, "弟子");

        set_skill("move", 30+random(20));
        set_skill("force", 30+random(20));
        set_skill("unarmed", 30+random(20));
        set_skill("dodge", 30+random(20));
        set_skill("taijiforce", 30+random(20));
        set_skill("taiji", 30+random(20));
        set_skill("five-steps", 30+random(20));

        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        set_skill("changelaw", 60);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.nianzijue" :),
        }) );
        
        
        setup();

        carry_object(__DIR__"obj/cloth1")->wear();
        carry_object(__DIR__"obj/hat")->wear();

}

void init()
{
	object 		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
		if( me->query_temp("marks/许廉龙")) call_out("rockkill", 1, me);
		if( me->query_temp("marks/偷书"))   call_out("stealbook", 1, me);
		if( me->query_temp("marks/七星剑")) call_out("stealsword", 1, me);
        }
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
}


int rockkill(object me)
{
	me->set_temp("marks/许廉龙", 0);
	message_vision(HIR"知客道人对$N喝道：" + RANK_D->query_rude(me)+"，竟敢在武当山杀我武当弟子！拿命来！\n"NOR,me);
	this_object()->kill_ob(me);
	return 1;
}
 
int stealbook(object me)
{
	me->set_temp("marks/偷书", 0);
	if(random(me->query("kar")) < 15) {
		say( HIR "知客道人对" + me->name() + "喝道：" + RANK_D->query_rude(me)
			+ "，竟敢在武当山偷东西！拿命来！\n"NOR);
		this_object()->kill_ob(me);
	}
	return 1;
}

/*
int stealsword(object me)
{
	string	*skname;
	mapping skills;
	int	i;

	me->set_temp("marks/七星剑", 0);
	if(random(me->query("kar")) < 29){
		if( (string)me->query("family/family_name")=="武当派" ) {
			say( HIR "知客道人对" + me->name() + "喝道：" + RANK_D->query_rude(me)
			+ "，你身为武当弟子，竟敢偷我武当山镇山之宝！你不配作武当弟子！\n"NOR);
			me->delete("family");
			me->set("title", "武当弃徒");
			me->set("score", 0);
			skills = me->query_skills();
			if( mapp(skills) ) {
				skname = keys(skills);
				for(i=0; i<sizeof(skname); i++)
				skills[skname[i]] /= 2;
			}
			me->add("betrayer", 1);
			me->set("marks/武当弃徒", 1);
                	tell_object(me, "\n你被开革出师门了！\n\n");
		}
		else {
			say( HIR "知客道人对" + me->name() + "喝道：" + RANK_D->query_rude(me)
				+ "，竟敢偷我武当山镇山之宝！拿命来！\n"NOR);
			this_object()->kill_ob(me);                
		}
	}
	return 1;
}
*/