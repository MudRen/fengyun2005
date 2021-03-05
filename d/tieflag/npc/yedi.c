// zhuzao.c
#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("夜帝",({"ye di","ye","di"}));
    	set("long","他容光焕发，须发有如衣衫般轻柔，\n看来虽是潇洒飘逸，又带有一种不可抗拒之威严。\n");
    	set("title","");
    	set("gender","男性");
    	set("no_arrest",1);
    	set("age",42);

    	set("combat_exp",9500000);  
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	set("no_busy",2);
	
    	set_skill("unarmed", 300);
    	set_skill("sword", 200);
    	set_skill("force", 200);
    	set_skill("parry", 200);
    	set_skill("dodge", 200);
    	set_skill("ill-quan", 200);
    	set_skill("jiayiforce", 150);
    	set_skill("tie-steps", 200);
    	
    	map_skill("unarmed", "ill-quan");
    	map_skill("force", "jiayiforce");
    	map_skill("dodge", "tie-steps");  
    
    	set("attitude", "heroism");
    
    	set("chat_chance",1);     
    	set("chat_msg",({
          	"夜帝开怀大笑。\n",
          }) );

    	setup();
    	carry_object(__DIR__"obj/sicloth")->wear();   
//    	add_money("gold", random(10));
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    
    command("say 你竟能走过我的迷宫，很了不起，你看看老夫这地方如何！");
    
    if (QUESTS_D->verify_quest(me,"长春迷宫"))
		QUESTS_D->special_reward(me,"长春迷宫");
    
    REWARD_D->riddle_done(me,"长春迷宫",10,1);
    
    return 1;
}
 
