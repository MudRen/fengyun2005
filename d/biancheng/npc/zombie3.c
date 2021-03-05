#include <ansi.h>
inherit SMART_NPC;

void do_bite();

void create()
{
    	set_name("高僵尸",({"zombie"}));
	set("title","人间地狱");
   	set("long","两个洞算是眼睛，一个扁平的肉瘤下两个窟窿算是鼻子和鼻孔，一道裂缝
算是嘴巴，嘴唇没有了，两排牙齿露在外面。一只手臂扭曲到背后，两条
腿一高一低，这是人还是从鬼门关上走回来的僵尸？\n");

     	set("gender","男性");
    	set("attitude", "aggressive");
    	
    	set("combat_exp",4000000);  
    	set("age",42);
	    	
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10: name()+"喉咙里发出希里呼噜的声音：“杀。。。杀。。。！”\n",
			20: (: do_bite() :),
        ]) );    	
    	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
        }) );
	
		auto_npc_setup("guardian",200,170,0,"/obj/weapon/","fighter_w","necromancy",1); 
    	setup();
    
}

void do_bite()
{
        object *enemy;
        message_vision(HIB"$N口中喷出一股中人欲呕的臭气，使你觉得头晕脑胀。\n"NOR,this_object());
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("sen", 250,this_object());
                COMBAT_D->report_status(enemy[i]);
        }
}

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
			me = owner;
		} 
        if (me)
        	me->add("marks/wanma/zombie",3);
        message_vision("$N慢慢地倒下去消失了。\n",this_object());
        ::die();
}
