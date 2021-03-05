#include <ansi.h>
inherit NPC;  
int tell_test();

void create()
{
        set_name("水灵光", ({ "shui lingguang","shui","lingguang" }) );
        set("gender", "女性");
        set("age", 18);
		set("long","她满面愁容，手里虽然拿着本书，却只是呆呆的出神。\n");
		set("combat_exp", 50000); 
		set("per",50);
		set("attitude", "friendly");
		set("rank_info/respect", "小仙女"); 
        set("inquiry", ([
			"铁中棠":(: tell_test:),
			"tie zhongtang" : (: tell_test:),
			"tie" : (: tell_test:)
        ]) );
		set("chat_chance", 1);
        set("chat_msg", ({
                "水灵光呆了一呆，道：男、、、男人都这样贱么？\n"
        }) ); 
        setup(); 
		carry_object("/obj/armor/cloth")->wear();
	
}


int tell_test()
{
	object	me,silkbook;
	me = this_player(); 
	if( query_temp("mark/been_get") > 5) 
	{
		command("say 铁中棠是铁血大旗门的现任掌门，正在海外常春岛上。");
		return 1;
	}
	if(me->query_temp("mark/silkbook")+120 < time() )
	{
		command("say 铁中棠是铁血大旗门的现任掌门，正在海外常春岛上。");
		command("say 我这有他父亲手写的一本书，望你转交。" );
		silkbook=new(BOOKS"skill/jiayiforce_50");
		silkbook->move(me);
		me->set_temp("mark/silkbook",time());
		add_temp("mark/been_get",1);
	}
	else
	{
		command( "say 怎么还不帮我把书送去。" );
	}
	return 1;
}


void reset()
{   
    	delete_temp("mark/been_get");
}
