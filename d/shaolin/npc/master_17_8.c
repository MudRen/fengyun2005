
#include <ansi.h>
inherit NPC;
#include <ansi.h>
void getting();
int kill_him();
void create()
{
        set_name("心鉴", ({ "master jian", "master"}) );
        set("gender", "男性" );
        set("class", "shaolin");
        set("age", 44);
		set("per", 35);
		set("attitude","friendly");
        
        set("long","\n");
        create_family("少林寺", 17, "长老");
        
        set("combat_exp", 1500000);
        
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("unarmed",160);
		set_skill("puti-steps",150);
		set_skill("dabei-strike",150);
		set_skill("xiaochengforce",100);
		set_skill("parry",150);
		set_skill("perception",50);
	
		map_skill("parry","dabei-strike");
        map_skill("dodge", "puti-steps");
		map_skill("force", "xiaochengforce");
		map_skill("unarmed", "dabei-strike");
	        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
            (: perform_action, "unarmed.qianshouqianbian" :),
            (: perform_action, "dodge.wuwuwuwo" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/skinmask")->wear();
		carry_object("/obj/armor/cloth")->wear();
}


void unconcious()
{
	die();
}

void die()
{
        int i;
        object killer, owner;
		object me;
        if(objectp(killer = query_temp("last_damage_from")))
		{
				if(owner=killer->query("possessed"))
					killer = owner;

				me = killer;
				if (REWARD_D->riddle_check(me,"多事之秋") == 3 && REWARD_D->riddle_check(me,"守经楼") == 4)
				{
					REWARD_D->riddle_set(me,"多事之秋",4);
					message_vision(CYN"\n\n$N突然大叫道：住……住手！\n",this_object());
					message_vision("$N抹去嘴边鲜血，颤声道：别杀我，我告诉你谁让我来偷经书！\n\n",this_object());
					me->ccommand("nod");
					message_vision(CYN"\n$N的脸上现出一抹诡异的微笑：那个主谋就是．．．\n\n"NOR,this_object());
					message_vision(HIC"一把长剑突然自藏经顶楼的窗户中射出，不偏不倚地穿过$N心口。\n"NOR,this_object());
					message_vision(HIW"$N猛低下头，不敢相信地看着胸前剑柄，喃喃道：拜．．．拜．．．\n\n"NOR,this_object());
					REWARD_D->riddle_done(me,"守经楼",50,1);
				}

		}
        ::die();

}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/


