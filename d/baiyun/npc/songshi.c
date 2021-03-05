// XXDER@FY3

inherit SMART_NPC;
#include <ansi.h>

int leave();
void create()
{
    set_name("松实" , ({ "song shi","song" }) );
    set("nickname",HIY"啖松实"NOR);
    set("long", "乍一看去，这汉子敞衣赤足，眉目粗豪，但仔细打量，竟令人觉得他着实是个\n灵秀之人。\n");
	set("attitude", "friendly");
    set("age", 32);
        set("gender", "男性" );
        create_family("白云城",1, "狂生");
    set("per",40);
    set("combat_exp", 5500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "松实拈着黑子沉吟半晌，忽然双眉一轩，下了一着，轻轻吁了口气。\n",
        "松实剑眉微皱，轻叹一声：这一局劫中有劫，既有共活，又有长生，何得破解？\n",
	}) );
          set("inquiry",  ([
				"救治剑胆" :  (: leave :),
        ]) );

   	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) ); 		

	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","qiusheng-blade",1);
   	setup();
    carry_object("/obj/armor/cloth")->wear();
    if (!random(10)) carry_object(BOOKS"blade_75");
}


int leave()
{
	object room = load_object("/d/baiyun/dragonplace");
	int i = REWARD_D->riddle_check(this_player(),"王图一梦");
	if ( i !=4 && i != 5 && i != 6)
		return 0;
	
	if (is_fighting())
	{
		tell_object(this_player(),name()+"正忙，顾不上与你搭话。\n");
		return 1;
	}
	if (environment() == room)
		return 0;
	delete("chat_msg");
	message_vision(WHT"$N大怒道：叶孤城啊叶孤城，相煎何急啊！除去剑胆，莫非你的天外飞仙就是天下第一了么？\n$N几个起纵，仿佛流星一般飞身离去。\n"NOR, this_object());
	move(room);
	return 1;
}
/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
