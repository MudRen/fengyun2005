#include <ansi.h>
inherit SMART_NPC;

void create()
{
    set_name("丁干", ({"ding gan","ding"}) );
    set("gender", "男性" );
    set("nickname", CYN"七巧手"NOR);
    set("title", "青龙会 刺客");
    set("long", "一个很高大的人，高大的有些臃肿，但一双手却灵巧得很，谁又会知道
这双灵巧的手竟可以瞬息之间撕裂猎物的咽喉。。\n");
 		set("class","wolfmount");
 		set("attitude", "friendly");
    	set("age", 35);
    	set("per", 11);
    	
    	set("reward_npc", 1);
        set("difficulty", 2);
        set("combat_exp", 3000000);
        
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        		(: auto_smart_fight(20) :),    
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"丁干仔仔细细修理着指甲，目中突然露出一种残酷的笑容。\n",
        }) );

        setup();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
        auto_npc_setup("guardian",150,150,0,"/obj/weapon/","fighter_w","wolf-strike",1);
        carry_object(__DIR__"obj/xiuzhiblade");
        carry_object("obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/waternut");
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	if( !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	if (!ob->query("vendetta/authority")){
            message_vision("$N嘿嘿道：够胆量！私闯青龙会的地头，拿命来吧！\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}
