#include <ansi.h>
inherit SMART_NPC;
void create()
{
	set_name("南宫平", ({ "nangong ping","nangong" }) );
	set("gender", "男性" );
	set("title", "南宫世家 少主" );
	set("nickname", HIR"护花铃"NOR );
	set("long",
            "南宫平本是南宫世家子弟，但自小投入止效山庄“不死神龙”龙布诗门下，看起来虽只是一个\n文弱俊秀的白面书生，面容甚至有些苍白，但其实，这是一个何等坚强，冷静和执着的少年啊。\n"
		);
	set("attitude", "peaceful");
	set("reward_npc", 1);
	set("difficulty", 10);
	set("combat_exp",8000000);
	set("age", 23);
	set("chat_chance", 1);
	set("chat_msg", ({
		
"南宫平面向大海，静静道：无论这世上所有人都说她什么，我知道，她是世上最最多
情、最最温柔、最最伟大的女孩子。她为了要救别人，要保护别人，不惜自己受苦难受
侮辱，她纵然声名不好，她年纪纵然比我大上许多，但她只要能让我跪在她脚下，我已
完全心满意足。\n",
"南宫平目中一片深情，缓缓道：她是个最爱干净的人，但为了我却不惜忍受污秽，她
是个骄傲的人，但为了我却不惜忍受屈辱。她虽然对我千种柔情，万种体贴，但在我
生存的时候却不告诉我，只是独自忍受着痛苦，只是有一次在我将死的时候，才露出了
一些，这不过是为了……为了……。话未说完，已是热泪盈眶。\n"
		}));
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",200,200,1,"/obj/weapon/","fighter_w","shortsong-blade",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
