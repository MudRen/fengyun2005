inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name("赤虚", ({ "chi xu","chixu"}) );
    	set("nickname", CYN"三清宫 妖道 "NOR);
    	set("gender", "男性" );
    	set("class", "taoist");
       	set("age", 120);
    	set("attitude","friendly");
	set("long","
一个仙风道骨般出尘脱俗的道士，须发洁白，浑身的肌肤仿佛处子一般光滑柔嫩， 
他漂浮在半空中，怀中搂着半裸的梅花盗，一边品着梅花盗正在喂他的佳酿，一边 
在林仙儿洁白的上身上肆意抚摩。 \n");
    	
       	set("combat_exp", 8000000);
    	             
	set("NO_KILL","赤虚悬浮在半空之中，你根本无法碰到他 ！\n");
	set_temp("condition_type",WHT "<半空中>" NOR);
	
	auto_npc_setup("liaoyin",350,200,0,"/obj/weapon/","fighter_w","necromancy",2);
	setup();
}

